#ifndef VIEWBOOKWIDGET_H
#define VIEWBOOKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "LibrarianController.h"

class ViewBookWidget : public QWidget {
    Q_OBJECT
    public:
        ViewBookWidget(LibrarianController*, QWidget *parent = 0);
        void updateTable();
        ~ViewBookWidget();
    private:
        QPushButton* remove;
        QPushButton* loanEnd;
        QTableWidget* table;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        LibrarianController* controller;
    private slots:
        void removeItem() const;
        void endLoan() const;
};

#endif // VIEWBOOKWIDGET_H
