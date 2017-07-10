#include "Admin.h"

Admin::Admin(): Account() {}

Admin::Admin(int id, const QString& u, const QString& p, const QDate& b): Account(id, u, p, b) {}

Admin::Admin(const Admin& a): Account(a) {}

QString Admin::accountType() const {
    return QString("Admin");
}

Admin::~Admin() {}
