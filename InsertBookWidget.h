#ifndef INSERTBOOKWIDGET_H
#define INSERTBOOKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "LibrarianController.h"

class InsertBookWidget : public QWidget {
    Q_OBJECT
    public:
        InsertBookWidget(LibrarianController*, QWidget *parent = 0);
        void resetLayout();
        ~InsertBookWidget();
    private:
        QLineEdit* isbn;
        QLineEdit* title;
        QLineEdit* author;
        QComboBox* objectType;
        QComboBox* edition;
        QPushButton* insert;
        QVBoxLayout* vLayout;
        QHBoxLayout* hLayout;
        LibrarianController* controller;
    private slots:
        void renderForm();
        void insertItem() const;
};

#endif // INSERTBOOKWIDGET_H
