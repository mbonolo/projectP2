#include "ViewBookWidget.h"
#include <QStringList>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QMessageBox>

ViewBookWidget::ViewBookWidget(LibrarianController* c, QWidget *parent) : QWidget(parent), controller(c) {
    remove = new QPushButton(QString("ELIMINA"), this);
    remove->setMinimumHeight(50);
    connect(remove, SIGNAL(clicked(bool)), this, SLOT(removeItem()));
    loanEnd = new QPushButton(QString("FINE PRESTITO"), this);
    loanEnd->setMinimumHeight(50);
    connect(loanEnd, SIGNAL(clicked(bool)), this, SLOT(endLoan()));
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
    vLayout = new QVBoxLayout;
    vLayout->addWidget(remove);
    vLayout->addWidget(loanEnd);
    hLayout = new QHBoxLayout;
    hLayout->addWidget(table);
    hLayout->addLayout(vLayout);
    //setContentsMargins(100, 100, 100, 100);
    setLayout(hLayout);
}

void ViewBookWidget::updateTable() {
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

void ViewBookWidget::removeItem() const {
    QMessageBox msgBox;
    if(table->rowCount() && table->currentRow() >= 0) {
        msgBox.setWindowTitle("Eliminazione");
        msgBox.setText("Confermi di voler eliminare l'articolo: " + table->item(table->currentRow(), 1)->text() + "?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        msgBox.setIcon(QMessageBox::Question);
        int result = msgBox.exec();
        if(result == QMessageBox::Yes) {
            controller->removeItem(table->item(table->currentRow(), 0)->text());
            const_cast<ViewBookWidget*>(this)->updateTable();
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

void ViewBookWidget::endLoan() const {
    QMessageBox msgBox;
    if(table->rowCount() && table->currentRow() >= 0) {
        if(table->item(table->currentRow(), 3)->text() == "NO") {
            msgBox.setWindowTitle("Errore");
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setText("L'articolo " + table->item(table->currentRow(), 1)->text() + " non e' in prestito");
            msgBox.exec();
        } else {
            msgBox.setWindowTitle("Fine prestito");
            msgBox.setText("Confermi di aver ricevuto l'articolo: " + table->item(table->currentRow(), 1)->text() + "?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            msgBox.setIcon(QMessageBox::Question);
            int result = msgBox.exec();
            if(result == QMessageBox::Yes) {
                controller->endItemLoan(table->item(table->currentRow(), 0)->text());
                const_cast<ViewBookWidget*>(this)->updateTable();
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

ViewBookWidget::~ViewBookWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete table;
    delete loanEnd;
    delete remove;
}
