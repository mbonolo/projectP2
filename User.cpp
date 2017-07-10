#include "User.h"

User::User(): Account() {}

User::User(int id, const QString& u, const QString& p, const QDate& b): Account(id, u, p, b) {}

User::User(const User& u): Account(u) {}

QString User::accountType() const {
    return QString("User");
}

User::~User() {}
