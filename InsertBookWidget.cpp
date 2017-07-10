#include "InsertBookWidget.h"
#include <QString>
#include <QMessageBox>

InsertBookWidget::InsertBookWidget(LibrarianController* c, QWidget *parent): QWidget(parent), controller(c) {
    objectType = new QComboBox(this);
    objectType->setMinimumHeight(50);
    objectType->addItem(QString("-- TIPO --"));
    objectType->addItem(QString("LIBRO"));
    objectType->addItem(QString("RIVISTA"));
    objectType->setEditable(true);
    objectType->lineEdit()->setReadOnly(true);
    objectType->lineEdit()->setAlignment(Qt::AlignCenter);
    for(int i = 0; i < objectType->count(); ++i) {
        objectType->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    connect(objectType, SIGNAL(currentIndexChanged(int)), this, SLOT(renderForm()));
    isbn = new QLineEdit(this);
    isbn->setPlaceholderText(QString("Inserisci l'ISBN (10 cifre)"));
    isbn->setEnabled(false);
    title = new QLineEdit(this);
    title->setPlaceholderText(QString("Inserisci il titolo"));
    title->setEnabled(false);
    author = new QLineEdit(this);
    author->setPlaceholderText(QString("Inserisci l'autore"));
    author->setEnabled(false);
    edition = new QComboBox(this);
    edition->setMinimumHeight(50);
    edition->addItem(QString("-- EDIZIONE --"));
    for(int i = 1980; i <= 2017; ++i)
        edition->addItem(QString::number(i));
    edition->setEditable(true);
    edition->lineEdit()->setReadOnly(true);
    edition->lineEdit()->setAlignment(Qt::AlignCenter);
    edition->setEnabled(false);
    for(int i = 0; i < edition->count(); ++i) {
        edition->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    insert = new QPushButton(QString("Inserisci"), this);
    insert->setMinimumHeight(50);
    connect(insert, SIGNAL(clicked(bool)), this, SLOT(insertItem()));
    hLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout();
    vLayout->addWidget(objectType);
    vLayout->addWidget(isbn);
    vLayout->addWidget(title);
    vLayout->addWidget(author);
    vLayout->addWidget(edition);
    vLayout->addWidget(insert);
    hLayout->addLayout(vLayout);
    setContentsMargins(50, 50, 50, 50);
    setLayout(hLayout);
}

void InsertBookWidget::renderForm() {
    if(objectType->currentIndex() == 0) {
        isbn->setEnabled(false);
        title->setEnabled(false);
        author->setEnabled(false);
        edition->setEnabled(false);
    } else if(objectType->currentIndex() == 1) {
        isbn->setEnabled(true);
        title->setEnabled(true);
        author->setEnabled(true);
        edition->setEnabled(true);
    } else if(objectType->currentIndex() == 2) {
        isbn->setEnabled(false);
        isbn->setText(QString(""));
        title->setEnabled(true);
        author->setEnabled(false);
        author->setText(QString(""));
        edition->setEnabled(true);
    }
}

void InsertBookWidget::insertItem() const {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Errore!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Critical);
    if(objectType->currentIndex() < 1) {
        msgBox.setText("Devi inserire il tipo dell'oggetto.");
        msgBox.exec();
    } else {
        if(isbn->text().isEmpty() && objectType->currentIndex() == 1) {
            msgBox.setText("Devi inserire il codice ISBN.");
            msgBox.exec();
        } else {
            if(isbn->text().length() != 10 && objectType->currentIndex() == 1) {
                msgBox.setText("Il codice ISBN deve essere di 10 cifre.");
                msgBox.exec();
            } else {
                if(title->text().isEmpty()) {
                    msgBox.setText("Devi inserire il titolo.");
                    msgBox.exec();
                } else {
                    if(author->text().isEmpty()  && objectType->currentIndex() == 1) {
                        msgBox.setText("Devi inserire l'autore.");
                        msgBox.exec();
                    } else {
                        if(edition->currentIndex() < 1) {
                            msgBox.setText("Devi inserire l'edizione.");
                            msgBox.exec();
                        } else {
                            bool found;
                            if(objectType->currentIndex() == 1)
                                found = controller->checkIsbn(isbn->text());
                            else
                                found = controller->checkTitle(title->text(), edition->currentText());
                            if(!found) {
                                bool inserted = controller->insertItem(objectType->currentText(), isbn->text(), title->text(), author->text(), edition->currentText());
                                if(inserted) {
                                    msgBox.setWindowTitle("Inserimento!");
                                    msgBox.setIcon(QMessageBox::Information);
                                    msgBox.setText("L'articolo " + title->text() + " e' stato creato.");
                                    msgBox.exec();
                                    objectType->setCurrentIndex(0);
                                    isbn->setText(QString(""));
                                    title->setText(QString(""));
                                    author->setText(QString(""));
                                    edition->setCurrentIndex(0);
                                } else {
                                    msgBox.setText("Si è verificato un errore nell'inserimento. Controlla i dati e riprova.");
                                    msgBox.exec();
                                }
                            } else {
                                msgBox.setText("Esiste gia' un articolo in catalogo con questi dati.");
                                msgBox.exec();
                            }
                        }
                    }
                }
            }
        }
    }
}

InsertBookWidget::~InsertBookWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete insert;
    delete edition;
    delete objectType;
    delete author;
    delete title;
    delete isbn;
}
