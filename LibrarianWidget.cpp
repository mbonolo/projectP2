#include "LibrarianWidget.h"
#include <QString>
#include <QMessageBox>

LibrarianWidget::LibrarianWidget(LibrarianController* c, QWidget *parent) : QTabWidget(parent), controller(c) {
    insertBookWidget = new InsertBookWidget(controller, this);
    viewBookWidget = new ViewBookWidget(controller, this);
    updateUserWidget = new UpdateUserWidget(controller, this);
    addTab(insertBookWidget, QString("INSERISCI LIBRO"));
    addTab(viewBookWidget, QString("VISUALIZZA LIBRI"));
    addTab(updateUserWidget, QString("PROFILO"));
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(tabChanged()));
}

void LibrarianWidget::tabChanged() const {
    if(this->currentIndex() == 1)
        this->viewBookWidget->updateTable();
    if(this->currentIndex() == 2)
        this->updateUserWidget->updateUserInfo();
}

void LibrarianWidget::closeEvent(QCloseEvent* event) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Chiudi?");
    msgBox.setText("Sei sicuro di voler chiudere?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setIcon(QMessageBox::Question);
    int result = msgBox.exec();
    if(result == QMessageBox::Yes) {
        controller->getData()->saveUsers();
        controller->getData()->saveItems();
        event->accept();
    } else {
        event->ignore();
    }
}

LibrarianWidget::~LibrarianWidget() {
    delete controller;
    delete updateUserWidget;
    delete viewBookWidget;
    delete insertBookWidget;
}
