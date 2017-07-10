#include "UpdateUserWidget.h"
#include <QString>
#include <QMessageBox>
#include "AdminWidget.h"
#include "LibrarianWidget.h"
#include "UserWidget.h"

UpdateUserWidget::UpdateUserWidget(Controller* c, QWidget *parent) : QWidget(parent), controller(c) {
    tabDescription = new QLabel(QString("Modifica i tuoi dati"), this);
    tabDescription->setAlignment(Qt::AlignCenter);
    username = new QLineEdit(this);
    username->setPlaceholderText(QString("Inserisci il tuo nuovo username"));
    password = new QLineEdit(this);
    password->setPlaceholderText(QString("Inserisci la nuova password"));
    password->setEchoMode(QLineEdit::Password);
    confirmPassword = new QLineEdit(this);
    confirmPassword->setPlaceholderText(QString("Re-Inserisci la nuova password"));
    confirmPassword->setEchoMode(QLineEdit::Password);
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
    update = new QPushButton(QString("Modifica"), this);
    update->setMinimumHeight(50);
    connect(update, SIGNAL(clicked(bool)), this, SLOT(updateUser()));
    hLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout();
    QHBoxLayout* dateLayout = new QHBoxLayout();
    dateLayout->addWidget(day);
    dateLayout->addWidget(month);
    dateLayout->addWidget(year);
    vLayout->addWidget(tabDescription);
    vLayout->addWidget(username);
    vLayout->addWidget(password);
    vLayout->addWidget(confirmPassword);
    vLayout->addWidget(dateLabel);
    vLayout->addLayout(dateLayout);
    vLayout->addWidget(update);
    hLayout->addLayout(vLayout);
    setContentsMargins(75, 75, 75, 75);
    setLayout(hLayout);
}

void UpdateUserWidget::updateUserInfo() {
    Account* u = controller->getLoggedUser();
    username->setText(u->getUsername());
    password->setText(u->getPassword());
    confirmPassword->setText(u->getPassword());
    day->setCurrentIndex(u->getBirthday().day());
    month->setCurrentIndex(u->getBirthday().month());
    year->setCurrentIndex(u->getBirthday().year() - 1940 + 1);
}

void UpdateUserWidget::updateUser() const {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Errore!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Critical);
    if(username->text().isEmpty()) {
        msgBox.setText("Devi inserire l'username (vecchio o nuovo).");
        msgBox.exec();
    } else {
        if(password->text().isEmpty()) {
            msgBox.setText("Devi inserire la password (vecchia o nuova).");
            msgBox.exec();
        } else {
            if(confirmPassword->text().isEmpty()) {
                msgBox.setText("Devi inserire la password di conferma (vecchia o nuova).");
                msgBox.exec();
            } else {
                /*if(password->text() == confirmPassword->text()) {
                    msgBox.setText("Le due password devono essere uguali.");
                    msgBox.exec();
                } else {*/
                    if(day->currentIndex() < 1) {
                        msgBox.setText("Devi inserire il giorno di nascita (vecchio o nuovo).");
                        msgBox.exec();
                    } else {
                        if(month->currentIndex() < 1) {
                            msgBox.setText("Devi inserire il mese di nascita (vecchio o nuovo).");
                            msgBox.exec();
                        } else {
                            if(year->currentIndex() < 1) {
                                msgBox.setText("Devi inserire l'anno di nascita (vecchio o nuovo).");
                                msgBox.exec();
                            } else {
                                bool found = controller->checkUsername(username->text());
                                if(!found) {
                                    bool updated = controller->updateUser(username->text(), password->text(), day->currentText(), month->currentText(), year->currentText());
                                    if(updated) {
                                        msgBox.setWindowTitle("Aggiornamento!");
                                        msgBox.setIcon(QMessageBox::Information);
                                        msgBox.setText("Le tue informazioni sono state aggiornate.");
                                        msgBox.exec();
                                    } else {
                                        msgBox.setText("Si è verificato un errore durante l'aggiornamento. Controlla i dati e riprova.");
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
}

UpdateUserWidget::~UpdateUserWidget() {
    delete controller;
    delete hLayout;
    delete vLayout;
    delete update;
    delete year;
    delete month;
    delete day;
    delete dateLabel;
    delete confirmPassword;
    delete password;
    delete username;
    delete tabDescription;
}
