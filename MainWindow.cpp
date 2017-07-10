#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Biblio");
    setMinimumSize(400, 300);
    setMaximumSize(400, 300);
    data = new Data();
    loginController = new LoginController(data);
    loginWidget = new LoginWidget(loginController, this);
    adminController = new AdminController(data);
    adminWidget = new AdminWidget(adminController);
    librarianController = new LibrarianController(data);
    librarianWidget = new LibrarianWidget(librarianController);
    userController = new UserController(data);
    userWidget = new UserWidget(userController);
    setCentralWidget(loginWidget);
}

void MainWindow::renderLoginWidget() {
    show();
    adminWidget->hide();
    librarianWidget->hide();
    userWidget->hide();
}

void MainWindow::renderAdminWidget() {
    hide();
    adminWidget->show();
}

void MainWindow::renderLibrarianWidget() {
    hide();
    librarianWidget->show();
}

void MainWindow::renderUserWidget() {
    hide();
    userWidget->show();
}

MainWindow::~MainWindow() {
    delete data;
    delete userController;
    delete librarianController;
    delete adminController;
    delete loginController;
    delete userWidget;
    delete librarianWidget;
    delete adminWidget;
    delete loginWidget;
    delete centralWidget;
}
