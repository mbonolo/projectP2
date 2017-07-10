#ifndef INSERTUSERWIDGET_H
#define INSERTUSERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "AdminController.h"

class InsertUserWidget : public QWidget {
    Q_OBJECT
    public:
        InsertUserWidget(AdminController*, QWidget *parent = 0);
        ~InsertUserWidget();
    private:
        QLabel* usernameLabel;
        QLineEdit* username;
        QComboBox* accountType;
        QLabel* dateLabel;
        QComboBox* day;
        QComboBox* month;
        QComboBox* year;
        QPushButton* insert;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        AdminController* controller;
    private slots:
        void insertUser() const;
};

#endif // INSERTUSERWIDGET_H
