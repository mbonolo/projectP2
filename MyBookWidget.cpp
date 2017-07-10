#include "MyBookWidget.h"
#include <QStringList>
#include <QTableWidgetItem>
#include <QHeaderView>

MyBookWidget::MyBookWidget(UserController* c, QWidget *parent) : QWidget(parent), controller(c) {
    refresh = new QPushButton(QString("AGGIORNA"), this);
    refresh->setMinimumHeight(50);
    connect(refresh, SIGNAL(clicked(bool)), this, SLOT(update()));
    table = new QTableWidget(0, 5, this);
    QStringList labels;
    labels << "ID" << "TITOLO" << "EDIZIONE" << "TIPO" << "PRESTITO";
    table->setHorizontalHeaderLabels(labels);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setShowGrid(true);
    table->setStyleSheet("selection-background-color: red;");
    table->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    vLayout = new QVBoxLayout;
    vLayout->addWidget(table);
    vLayout->addWidget(refresh);
    hLayout = new QHBoxLayout;
    hLayout->addLayout(vLayout);
    //setContentsMargins(100, 100, 100, 100);
    setLayout(hLayout);
    update();
}

void MyBookWidget::update() {
    table->clearContents();
    table->setRowCount(0);
    QList<Item*> items = controller->getItems();
    QList<Item*>::iterator it = items.begin();
    for(int i = 0; it != items.end(); ++it) {
        if((*it)->onLoan() == controller->getLoggedUserId()) {
            table->setRowCount(i + 1);
            QTableWidgetItem* p = new QTableWidgetItem(QString::number((*it)->getId()));
            p->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, 0, p);
            p = new QTableWidgetItem((*it)->getTitle());
            p->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, 1, p);
            p = new QTableWidgetItem(QString::number((*it)->getEdition()));
            p->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, 2, p);
            p = new QTableWidgetItem((*it)->type());
            p->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, 3, p);
            p = new QTableWidgetItem(QString::number((*it)->loanTime()) + " giorni");
            p->setTextAlignment(Qt::AlignCenter);
            table->setItem(i, 4, p);
            ++i;
        }
    }
}

MyBookWidget::~MyBookWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete table;
    delete refresh;
}
