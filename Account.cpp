#include "Account.h"

Account::Account() {
    id = -1;
    username = QString("");
    password = QString("");
    birthday = QDate(1970, 1, 1);
}

Account::Account(int id, const QString& u, const QString& p, const QDate& b): id(id), username(u), password(p), birthday(b) {}

Account::Account(const Account& a): id(a.id), username(a.username), password(a.password), birthday(a.birthday) {}

int Account::getId() const {
    return id;
}

QString Account::getUsername() const {
    return username;
}

QString Account::getPassword() const {
    return password;
}

QDate Account::getBirthday() const {
    return birthday;
}

void Account::setId(int newId) {
    id = newId;
}

void Account::setUsername(const QString& u) {
    username = u;
}

void Account::setPassword(const QString& p) {
    password = p;
}

void Account::setBirthday(const QDate& b) {
    birthday = b;
}

Account::~Account() {}
