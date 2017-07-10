#include "ViewUserWidget.h"
#include <QStringList>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QMessageBox>

ViewUserWidget::ViewUserWidget(AdminController* c, QWidget *parent) : QWidget(parent), controller(c) {
    remove = new QPushButton(QString("ELIMINA"), this);
    remove->setMinimumHeight(50);
    connect(remove, SIGNAL(clicked(bool)), this, SLOT(removeUser()));
    table = new QTableWidget(0, 3, this);
    QStringList labels;
    labels << "ID" << "USERNAME" << "DATA DI NASCITA";
    table->setHorizontalHeaderLabels(labels);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setShowGrid(true);
    table->setStyleSheet("selection-background-color: red;");
    table->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    vLayout = new QVBoxLayout;
    vLayout->addWidget(remove);
    hLayout = new QHBoxLayout;
    hLayout->addWidget(table);
    hLayout->addLayout(vLayout);
    //setContentsMargins(100, 100, 100, 100);
    setLayout(hLayout);
}

void ViewUserWidget::update() {
    table->clearContents();
    table->setRowCount(0);
    QList<Account*> u = controller->getUsers();
    QList<Account*>::iterator it = u.begin();
    for(int i = 0; it != u.end(); ++it, ++i) {
        table->setRowCount(i + 1);
        QTableWidgetItem* p = new QTableWidgetItem(QString::number((*it)->getId()));
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 0, p);
        p = new QTableWidgetItem((*it)->getUsername());
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 1, p);
        p = new QTableWidgetItem((*it)->getBirthday().toString("dd.MM.yyyy"));
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 2, p);
    }
}

void ViewUserWidget::removeUser() const {
    QMessageBox msgBox;
    if(table->rowCount() && table->currentRow() >= 0) {
        if(table->item(table->currentRow(), 0)->text().toInt() == controller->getLoggedUser()->getId()) {
            msgBox.setWindowTitle("Errore");
            msgBox.setText("Non puoi eliminare il tuo account.");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
        } else {
            msgBox.setWindowTitle("Eliminazione");
            msgBox.setText("Confermi di voler eliminare l'utente: " + table->item(table->currentRow(), 1)->text() + "?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setIcon(QMessageBox::Question);
            int result = msgBox.exec();
            if(result == QMessageBox::Yes) {
                controller->removeUser(table->item(table->currentRow(), 0)->text());
                const_cast<ViewUserWidget*>(this)->update();
            }
        }
    }
    else {
        msgBox.setWindowTitle("Errore");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(table->rowCount() == 0)
            msgBox.setText("Devi inserire dei dati per poterli eliminare.");
        else
            msgBox.setText("Devi selezionare una riga per poterla eliminare.");
        msgBox.exec();
    }
}

ViewUserWidget::~ViewUserWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete table;
    delete remove;
}
