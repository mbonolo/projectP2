#include "AdminWidget.h"
#include <QString>
#include <QMessageBox>

AdminWidget::AdminWidget(AdminController* c,QWidget *parent) : QTabWidget(parent), controller(c) {
    insertUserWidget = new InsertUserWidget(controller, this);
    viewUserWidget = new ViewUserWidget(controller, this);
    updateUserWidget = new UpdateUserWidget(controller, this);
    addTab(insertUserWidget, QString("INSERISCI UTENTE"));
    addTab(viewUserWidget, QString("VISUALIZZA UTENTI"));
    addTab(updateUserWidget, QString("PROFILO"));
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(tabChanged()));
}

void AdminWidget::tabChanged() const {
    if(this->currentIndex() == 1)
        this->viewUserWidget->update();
    if(this->currentIndex() == 2)
        this->updateUserWidget->updateUserInfo();
}

void AdminWidget::closeEvent(QCloseEvent* event) {
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

AdminWidget::~AdminWidget() {
    delete controller;
    delete updateUserWidget;
    delete viewUserWidget;
    delete insertUserWidget;
}
