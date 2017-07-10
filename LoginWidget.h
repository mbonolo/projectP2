#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "LoginController.h"

class LoginWidget : public QWidget {
    Q_OBJECT
    public:
        LoginWidget(LoginController* = NULL, QWidget *parent = 0);
        ~LoginWidget();
    private:
        QLabel* usernameLabel;
        QLineEdit* username;
        QLabel* passwordLabel;
        QLineEdit* password;
        QPushButton* login;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        LoginController* controller;
    private slots:
        void tryLogin() const;
};

#endif // LOGINWIDGET_H
