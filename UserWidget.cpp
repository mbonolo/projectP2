#include "UserWidget.h"
#include <QString>
#include <QMessageBox>

UserWidget::UserWidget(UserController* c, QWidget *parent): QTabWidget(parent), controller(c) {
    myBookWidget = new MyBookWidget(controller, this);
    userBookViewWidget = new UserBookViewWidget(controller, this);
    updateUserWidget = new UpdateUserWidget(controller, this);
    addTab(myBookWidget, QString("I MIEI LIBRI"));
    addTab(userBookViewWidget, QString("VISUALIZZA LIBRI"));
    addTab(updateUserWidget, QString("PROFILO"));
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(tabChanged()));
    setCurrentIndex(0);
}

void UserWidget::tabChanged() const {
    if(this->currentIndex() == 0)
        this->myBookWidget->update();
    if(this->currentIndex() == 1)
        this->userBookViewWidget->updateTable();
    if(this->currentIndex() == 2)
        this->updateUserWidget->updateUserInfo();
}

void UserWidget::closeEvent(QCloseEvent* event) {
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

UserWidget::~UserWidget() {
    delete controller;
    delete updateUserWidget;
    delete userBookViewWidget;
    delete myBookWidget;
}
