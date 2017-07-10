#include "UserBookViewWidget.h"
#include <QStringList>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "Book.h"
#include "Magazine.h"

UserBookViewWidget::UserBookViewWidget(UserController* c, QWidget *parent) : QWidget(parent), controller(c) {
    getInformation = new QPushButton(QString("INFO"), this);
    getInformation->setMinimumHeight(50);
    connect(getInformation, SIGNAL(clicked(bool)), this, SLOT(getItemInfo()));
    borrow = new QPushButton(QString("PRENDI IN PRESTITO"), this);
    borrow->setMinimumHeight(50);
    connect(borrow, SIGNAL(clicked(bool)), this, SLOT(borrowItem()));
    table = new QTableWidget(0, 4, this);
    QStringList labels;
    labels << "ID" << "TITOLO" << "TIPO" << "IN PRESTITO";
    table->setHorizontalHeaderLabels(labels);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setShowGrid(true);
    table->setStyleSheet("selection-background-color: red;");
    table->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    table->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(getInformation);
    buttonLayout->addWidget(borrow);
    vLayout = new QVBoxLayout;
    vLayout->addWidget(table);
    vLayout->addLayout(buttonLayout);
    hLayout = new QHBoxLayout;
    hLayout->addLayout(vLayout);
    //setContentsMargins(100, 100, 100, 100);
    setLayout(hLayout);
}

void UserBookViewWidget::updateTable() {
    table->clearContents();
    table->setRowCount(0);
    QList<Item*> items = controller->getItems();
    QList<Item*>::iterator it = items.begin();
    for(int i = 0; it != items.end(); ++it, ++i) {
        table->setRowCount(i + 1);
        QTableWidgetItem* p = new QTableWidgetItem(QString::number((*it)->getId()));
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 0, p);
        p = new QTableWidgetItem((*it)->getTitle());
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 1, p);
        p = new QTableWidgetItem((*it)->type());
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 2, p);
        if((*it)->onLoan() == -1)
            p = new QTableWidgetItem(QString("NO"));
        else
            p = new QTableWidgetItem(QString("SI"));
        p->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 3, p);
    }
}

void UserBookViewWidget::getItemInfo() const {
    QMessageBox msgBox;
    if(table->rowCount() && table->currentRow() >= 0) {
        msgBox.setWindowTitle("Info");
        Item* i = controller->getItem(table->item(table->currentRow(), 0)->text());
        if(dynamic_cast<Book*>(i)) {
            Book* b = dynamic_cast<Book*>(i);
            msgBox.setText("ISBN: " + b->getIsbn() + "\nTitolo: " + b->getTitle() + "\nAutore: " + b->getAuthor() +  "\nEdition: " + QString::number(b->getEdition()));
        } else if(dynamic_cast<Magazine*>(i)){
            Magazine* m = dynamic_cast<Magazine*>(i);
            msgBox.setText("Titolo: " + m->getTitle() + "\nEdition: " + QString::number(m->getEdition()));
        }
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
    else {
        msgBox.setWindowTitle("Errore");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(table->rowCount() == 0)
            msgBox.setText("Devi inserire dei dati per poter operare su di essi.");
        else
            msgBox.setText("Devi selezionare una riga per poter operare su di essa.");
        msgBox.exec();
    }
}

void UserBookViewWidget::borrowItem() const {
    QMessageBox msgBox;
    if(table->rowCount() && table->currentRow() >= 0) {
        if(table->item(table->currentRow(), 3)->text() == "SI") {
            msgBox.setWindowTitle("Errore");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setText("L'articolo " + table->item(table->currentRow(), 1)->text() + " e' gia' in prestito");
            msgBox.exec();
        } else {
            msgBox.setWindowTitle("Inizio prestito");
            msgBox.setText("Sei sicuro di voler prendere in prestito l'articolo: " + table->item(table->currentRow(), 1)->text() + "?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setIcon(QMessageBox::Question);
            int result = msgBox.exec();
            if(result == QMessageBox::Yes) {
                controller->startItemLoan(table->item(table->currentRow(), 0)->text());
                const_cast<UserBookViewWidget*>(this)->updateTable();
            }
        }
    }
    else {
        msgBox.setWindowTitle("Errore");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setStandardButtons(QMessageBox::Ok);
        if(table->rowCount() == 0)
            msgBox.setText("Devi inserire dei dati per poter operare su di essi.");
        else
            msgBox.setText("Devi selezionare una riga per poter operare su di essa.");
        msgBox.exec();
    }
}

UserBookViewWidget::~UserBookViewWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete table;
    delete borrow;
    delete getInformation;
}
