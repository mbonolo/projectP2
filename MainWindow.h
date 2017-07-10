#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LoginWidget.h"
#include "AdminWidget.h"
#include "LibrarianWidget.h"
#include "UserWidget.h"
#include "LoginController.h"
#include "AdminController.h"
#include "LibrarianController.h"
#include "UserController.h"
#include "Data.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();
    public slots:
        void renderLoginWidget();
        void renderAdminWidget();
        void renderLibrarianWidget();
        void renderUserWidget();
    private:
        QWidget* centralWidget;
        LoginWidget* loginWidget;
        AdminWidget* adminWidget;
        LibrarianWidget* librarianWidget;
        UserWidget* userWidget;
        LoginController* loginController;
        AdminController* adminController;
        LibrarianController* librarianController;
        UserController* userController;
        Data* data;
};

#endif // MAINWINDOW_H
