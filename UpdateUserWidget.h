#ifndef UPDATEUSERWIDGET_H
#define UPDATEUSERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Controller.h"

class UpdateUserWidget : public QWidget
{
    Q_OBJECT
    public:
        UpdateUserWidget(Controller*, QWidget *parent = 0);
        void updateUserInfo();
        ~UpdateUserWidget();
    private:
        QLabel* tabDescription;
        QLineEdit* username;
        QLineEdit* password;
        QLineEdit* confirmPassword;
        QLabel* dateLabel;
        QComboBox* day;
        QComboBox* month;
        QComboBox* year;
        QPushButton* update;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        Controller* controller;
    private slots:
        void updateUser() const;
};

#endif // UPDATEUSERWIDGET_H
