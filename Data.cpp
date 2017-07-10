#include "Data.h"
#include <QDate>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QMessageBox>
#include "Admin.h"
#include "Librarian.h"
#include "User.h"
#include "Book.h"
#include "Magazine.h"

Data::Data() {
    loggedUser = NULL;
    Data::retrieveUsers();
    nextUserId = -1;
    for(QList<Account*>::iterator it = users.begin(); it != users.end(); ++it)
        if((*it)->getId() > nextUserId)
            nextUserId = (*it)->getId();
    Data::retrieveItems();
    nextItemId = -1;
    for(QList<Item*>::iterator it = items.begin(); it != items.end(); ++it)
        if((*it)->getId() > nextItemId)
            nextItemId = (*it)->getId();
    nextUserId++;
    nextItemId++;
}

void Data::retrieveUsers(){
    QFile fileUsers("file/users.txt");
    fileUsers.open(QIODevice::ReadOnly);
    QTextStream in(&fileUsers);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');
        if (fields.size() >= 0) {
            QString id = fields.at(0);
            QString u = fields.at(1);
            QString p = fields.at(2);
            QString d = fields.at(3);
            QString m = fields.at(4);
            QString y = fields.at(6);
            QString t = fields.at(5);
            if(t == QString("Admin"))
                users.push_front(new Admin(id.toInt(), u, p, QDate(y.toInt(), m.toInt(), d.toInt())));
            else if(t == QString("Librarian"))
                users.push_front(new Librarian(id.toInt(), u, p, QDate(y.toInt(), m.toInt(), d.toInt())));
            else if(t == QString("User"))
                users.push_front(new User(id.toInt(), u, p, QDate(y.toInt(), m.toInt(), d.toInt())));
        }
    }
}

void Data::saveUsers(){
    QFile fileUsers("file/users.txt");
    fileUsers.open(QIODevice::WriteOnly);
    QTextStream out(&fileUsers);
    QList<Account*>::iterator it = users.begin();
    for(; it != users.end(); ++it) {
        out << QString::number((*it)->getId()) << ",";
        out << (*it)->getUsername() << ",";
        out << (*it)->getPassword() << ",";
        out << QString::number((*it)->getBirthday().day()) << ",";
        out << QString::number((*it)->getBirthday().month()) << ",";
        out << (*it)->accountType() << ",";
        out << QString::number((*it)->getBirthday().year()) << endl;
    }
}

void Data::retrieveItems(){
    QFile fileItems("file/items.txt");
    fileItems.open(QIODevice::ReadOnly);
    QTextStream in(&fileItems);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');
        if (fields.size() >= 0) {
            QString id = fields.at(0);
            QString t = fields.at(1);
            QString e = fields.at(2);
            QString l = fields.at(3);
            QString i = fields.at(4);
            QString a = fields.at(5);
            QString type = fields.at(6);
            if(type == QString("Libro"))
                items.push_front(new Book(id.toInt(), t, e.toInt(), l.toInt(), i, a));
            else if(type == QString("Rivista"))
                items.push_front(new Magazine(id.toInt(), t, e.toInt(), l.toInt()));
        }
    }
}

void Data::saveItems() {
    QFile fileItems("file/items.txt");
    fileItems.open(QIODevice::WriteOnly);
    QTextStream out(&fileItems);
    QList<Item*>::iterator it = items.begin();
    for(; it != items.end(); ++it) {
        if(dynamic_cast<Book*>(*it)) {
            Book* b = dynamic_cast<Book*>(*it);
            out << QString::number(b->getId()) << ",";
            out << b->getTitle() << ",";
            out << QString::number(b->getEdition()) << ",";
            out << QString::number(b->onLoan()) << ",";
            out << b->getIsbn() << ",";
            out << b->getAuthor() << ",";
            out << b->type() << endl;
        } else {
            Magazine* m = dynamic_cast<Magazine*>(*it);
            out << QString::number(m->getId()) << ",";
            out << m->getTitle() << ",";
            out << QString::number(m->getEdition()) << ",";
            out << QString::number(m->onLoan()) << ",a,b,";
            out << m->type() << endl;
        }
    }
}

QList<Account*> Data::getUsers() const {
    return users;
}

QList<Item*> Data::getItems() const {
    return items;
}

Account* Data::getLoggedUser() const {
    return loggedUser;
}

void Data::setLoggedUser(Account* a) {
    loggedUser = a;
    if(a)
        loggedUserId = a->getId();
    else
        loggedUserId = -1;
}

int Data::getLoggedUserId() const {
    return loggedUserId;
}

bool Data::insertUser(Account* a) {
    users.push_front(a);
    ++nextUserId;
    return true;
}

bool Data::insertItem(Item* i) {
    items.push_front(i);
    ++nextItemId;
    return true;
}

int Data::getNextUserId() const {
    return nextUserId;
}

int Data::getNextItemId() const {
    return nextItemId;
}

bool Data::removeUser(int id) {
    QList<Account*>::iterator it = users.begin();
    bool erased = false;
    for(; it != users.end() && !erased; ++it) {
        if((*it)->getId() == id) {
            users.erase(it);
            erased = true;
        }
    }
    return erased;
}

bool Data::removeItem(int id) {
    QList<Item*>::iterator it = items.begin();
    bool erased = false;
    for(; it != items.end() && !erased; ++it) {
        if((*it)->getId() == id) {
            items.erase(it);
            erased = true;
        }
    }
    return erased;
}

Data::~Data() {
    delete loggedUser;
}
