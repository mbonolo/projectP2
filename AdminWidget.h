#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QCloseEvent>
#include "InsertUserWidget.h"
#include "ViewUserWidget.h"
#include "UpdateUserWidget.h"
#include "AdminController.h"

class AdminWidget : public QTabWidget {
    Q_OBJECT
    public:
        explicit AdminWidget(AdminController* = NULL, QWidget *parent = 0);
        ~AdminWidget();
    private:
        InsertUserWidget* insertUserWidget;
        ViewUserWidget* viewUserWidget;
        UpdateUserWidget* updateUserWidget;
        AdminController* controller;
        void closeEvent(QCloseEvent*);
    private slots:
        void tabChanged() const;
};

#endif // ADMINWIDGET_H
