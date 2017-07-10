#ifndef VIEWUSERWIDGET_H
#define VIEWUSERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "AdminController.h"

class ViewUserWidget : public QWidget
{
    Q_OBJECT
    public:
        ViewUserWidget(AdminController*, QWidget *parent = 0);
        void update();
        ~ViewUserWidget();
    private:
        QPushButton* remove;
        QTableWidget* table;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        AdminController* controller;
    private slots:
        void removeUser() const;
};

#endif // VIEWUSERWIDGET_H
