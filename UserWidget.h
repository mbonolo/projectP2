#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QCloseEvent>
#include "MyBookWidget.h"
#include "UserBookViewWidget.h"
#include "UpdateUserWidget.h"
#include "UserController.h"

class UserWidget : public QTabWidget
{
    Q_OBJECT
    public:
        UserWidget(UserController*, QWidget *parent = 0);
        ~UserWidget();
    private:
        MyBookWidget* myBookWidget;
        UserBookViewWidget* userBookViewWidget;
        UpdateUserWidget* updateUserWidget;
        UserController* controller;
        void closeEvent(QCloseEvent*);
    private slots:
        void tabChanged() const;
};

#endif // USERWIDGET_H
