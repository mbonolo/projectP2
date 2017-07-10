#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Account.h"

class Librarian: public Account {
    public:
        Librarian();
        Librarian(int, const QString&, const QString&, const QDate&);
        Librarian(const Librarian&);
        virtual QString accountType() const;
        virtual ~Librarian();
};

#endif // LIBRARIAN_H
