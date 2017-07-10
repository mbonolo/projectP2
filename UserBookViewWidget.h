#ifndef USERBOOKVIEWWIDGET_H
#define USERBOOKVIEWWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "UserController.h"

class UserBookViewWidget : public QWidget {
    Q_OBJECT
    public:
        UserBookViewWidget(UserController*, QWidget *parent = 0);
        void updateTable();
        ~UserBookViewWidget();
    private:
        QPushButton* getInformation;
        QPushButton* borrow;
        QTableWidget* table;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        UserController* controller;
    private slots:
        void getItemInfo() const;
        void borrowItem() const;
};

#endif // USERBOOKVIEWWIDGET_H
