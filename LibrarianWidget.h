#ifndef LIBRARIANWIDGET_H
#define LIBRARIANWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QCloseEvent>
#include "InsertBookWidget.h"
#include "ViewBookWidget.h"
#include "UpdateUserWidget.h"
#include "LibrarianController.h"

class LibrarianWidget : public QTabWidget {
    Q_OBJECT
    public:
        explicit LibrarianWidget(LibrarianController*, QWidget *parent = 0);
        ~LibrarianWidget();
    private:
        InsertBookWidget* insertBookWidget;
        ViewBookWidget* viewBookWidget;
        UpdateUserWidget* updateUserWidget;
        LibrarianController* controller;
        void closeEvent(QCloseEvent*);
    private slots:
        void tabChanged() const;
};

#endif // LIBRARIANWIDGET_H
