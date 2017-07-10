#ifndef ADMIN_H
#define ADMIN_H

#include "Account.h"

class Admin: public Account {
    public:
        Admin();
        Admin(int, const QString&, const QString&, const QDate&);
        Admin(const Admin&);
        virtual QString accountType() const;
        virtual ~Admin();
};

#endif // ADMIN_H
