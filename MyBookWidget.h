#ifndef MYBOOKWIDGET_H
#define MYBOOKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "UserController.h"

class MyBookWidget : public QWidget {
    Q_OBJECT
    public:
        MyBookWidget(UserController*, QWidget *parent = 0);
        ~MyBookWidget();
    private:
        QPushButton* refresh;
        QTableWidget* table;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        UserController* controller;
    public slots:
        void update();
};

#endif // MYBOOKWIDGET_H
