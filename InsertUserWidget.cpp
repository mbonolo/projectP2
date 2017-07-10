#include "InsertUserWidget.h"
#include <QString>
#include <QMessageBox>

InsertUserWidget::InsertUserWidget(AdminController* c, QWidget *parent): QWidget(parent), controller(c) {
    usernameLabel = new QLabel(QString("Username:"), this);
    usernameLabel->setAlignment(Qt::AlignCenter);
    username = new QLineEdit(this);
    username->setPlaceholderText(QString("Inserisci il tuo username"));
    accountType = new QComboBox(this);
    accountType->setMinimumHeight(50);
    accountType->addItem(QString("-- TIPO DI ACCOUNT --"));
    accountType->addItem(QString("AMMINISTRATORE"));
    accountType->addItem(QString("BIBLIOTECARIO"));
    accountType->addItem(QString("UTENTE"));
    accountType->setEditable(true);
    accountType->lineEdit()->setReadOnly(true);
    accountType->lineEdit()->setAlignment(Qt::AlignCenter);
    for(int i = 0; i < accountType->count(); ++i) {
        accountType->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    dateLabel = new QLabel(QString("Data di nascita"), this);
    dateLabel->setAlignment(Qt::AlignCenter);
    day = new QComboBox(this);
    day->setMinimumHeight(50);
    day->addItem(QString("-- GIORNO --"));
    for(int i = 1; i <= 31; ++i)
        day->addItem(QString::number(i));
    day->setEditable(true);
    day->lineEdit()->setReadOnly(true);
    day->lineEdit()->setAlignment(Qt::AlignCenter);
    for(int i = 0; i < day->count(); ++i) {
        day->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    month = new QComboBox(this);
    month->setMinimumHeight(50);
    month->addItem(QString("-- MESE --"));
    for(int i = 1; i <= 12; ++i)
        month->addItem(QString::number(i));
    month->setEditable(true);
    month->lineEdit()->setReadOnly(true);
    month->lineEdit()->setAlignment(Qt::AlignCenter);
    for(int i = 0; i < month->count(); ++i) {
        month->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    year = new QComboBox(this);
    year->setMinimumHeight(50);
    year->addItem(QString("-- ANNO --"));
    for(int i = 1940; i < 2010; ++i)
        year->addItem(QString::number(i));
    year->setEditable(true);
    year->lineEdit()->setReadOnly(true);
    year->lineEdit()->setAlignment(Qt::AlignCenter);
    for(int i = 0; i < year->count(); ++i) {
        year->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    insert = new QPushButton(QString("Inserisci"), this);
    insert->setMinimumHeight(50);
    connect(insert, SIGNAL(clicked(bool)), this, SLOT(insertUser()));
    hLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout();
    QHBoxLayout* usernameLayout = new QHBoxLayout();
    QHBoxLayout* dateLayout = new QHBoxLayout();
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(username);
    dateLayout->addWidget(day);
    dateLayout->addWidget(month);
    dateLayout->addWidget(year);
    vLayout->addLayout(usernameLayout);
    vLayout->addWidget(accountType);
    vLayout->addWidget(dateLabel);
    vLayout->addLayout(dateLayout);
    vLayout->addWidget(insert);
    hLayout->addLayout(vLayout);
    setContentsMargins(75, 75, 75, 75);
    setLayout(hLayout);
}

void InsertUserWidget::insertUser() const {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Errore!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Critical);
    if(username->text().isEmpty()) {
        msgBox.setText("Devi inserire l'username.");
        msgBox.exec();
    } else {
        if(accountType->currentIndex() < 1) {
            msgBox.setText("Devi inserire il tipo di account.");
            msgBox.exec();
        } else {
            if(day->currentIndex() < 1) {
                msgBox.setText("Devi inserire il giorno.");
                msgBox.exec();
            } else {
                if(month->currentIndex() < 1) {
                    msgBox.setText("Devi inserire il mese.");
                    msgBox.exec();
                } else {
                    if(year->currentIndex() < 1) {
                        msgBox.setText("Devi inserire l'anno.");
                        msgBox.exec();
                    } else {
                        bool found = controller->checkUsername(username->text());
                        if(!found) {
                            bool inserted = controller->insertUser(username->text(), accountType->currentText(), day->currentText(), month->currentText(), year->currentText());
                            if(inserted) {
                                msgBox.setWindowTitle("Inserimento!");
                                msgBox.setIcon(QMessageBox::Information);
                                msgBox.setText("L'utente " + username->text() + " e' stato creato.");
                                msgBox.exec();
                                username->setText(QString(""));
                                accountType->setCurrentIndex(0);
                                day->setCurrentIndex(0);
                                month->setCurrentIndex(0);
                                year->setCurrentIndex(0);
                            } else {
                                msgBox.setText("Si è verificato un errore nell'inserimento. Controlla i dati e riprova.");
                                msgBox.exec();
                            }
                        } else {
                            msgBox.setText("Questo username esiste gia', usane un altro.");
                            msgBox.exec();
                        }
                    }
                }
            }
        }
    }
}

InsertUserWidget::~InsertUserWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete insert;
    delete year;
    delete month;
    delete day;
    delete dateLabel;
    delete accountType;
    delete username;
    delete usernameLabel;
}
