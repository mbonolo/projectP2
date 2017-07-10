#include "Librarian.h"

Librarian::Librarian(): Account() {}

Librarian::Librarian(int id, const QString& u, const QString& p, const QDate& b): Account(id, u, p, b) {}

Librarian::Librarian(const Librarian& l): Account(l) {}

QString Librarian::accountType() const {
    return QString("Librarian");
}

Librarian::~Librarian() {}
