#include "LoginWidget.h"
#include <QString>
#include <QMessageBox>
#include "MainWindow.h"

LoginWidget::LoginWidget(LoginController* c, QWidget *parent) : QWidget(parent), controller(c) {
    setMinimumSize(400, 300);
    setMaximumSize(400, 300);
    usernameLabel = new QLabel(QString("Username"), this);
    usernameLabel->setAlignment(Qt::AlignCenter);
    username = new QLineEdit(this);
    username->setPlaceholderText(QString("Inserisci il tuo username"));
    passwordLabel = new QLabel(QString("Password"));
    passwordLabel->setAlignment(Qt::AlignCenter);
    password = new QLineEdit(this);
    password->setPlaceholderText(QString("Inserisci la tua password"));
    password->setEchoMode(QLineEdit::Password);
    login = new QPushButton(QString("Accedi"), this);
    login->setMinimumHeight(50);
    connect(login, SIGNAL(clicked(bool)), this, SLOT(tryLogin()));
    hLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout();
    QHBoxLayout* usernameLayout = new QHBoxLayout();
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(username);
    vLayout->addLayout(usernameLayout);
    QHBoxLayout* passwordLayout = new QHBoxLayout();
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(password);
    vLayout->addLayout(passwordLayout);
    vLayout->addWidget(login);
    hLayout->addLayout(vLayout);
    //setStyleSheet("background: white;");
    setContentsMargins(50, 50, 50, 50);
    setLayout(hLayout);
}

void LoginWidget::tryLogin() const {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Errore!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Critical);
    if(username->text().isEmpty()) {
        msgBox.setText("Devi inserire l'username.");
        msgBox.exec();
    } else {
        if(password->text().isEmpty()) {
            msgBox.setText("Devi inserire la password.");
            msgBox.exec();
        } else {
            Account* user = controller->checkUser(username->text(), password->text());
            if(user) {
                username->setText(QString(""));
                password->setText(QString(""));
                if(user->accountType() == "Admin")
                    ((MainWindow*)(parent()))->renderAdminWidget();
                else if(user->accountType() == "Librarian")
                    ((MainWindow*)(parent()))->renderLibrarianWidget();
                else if(user->accountType() == "User")
                    ((MainWindow*)(parent()))->renderUserWidget();
            } else {
                msgBox.setText("Le credenziali che hai inserito non sono corrette. Riprova.");
                msgBox.exec();
                password->setText(QString(""));
            }
        }
    }
}

LoginWidget::~LoginWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete login;
    delete password;
    delete passwordLabel;
    delete username;
    delete usernameLabel;
}
