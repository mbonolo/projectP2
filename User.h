#ifndef USER_H
#define USER_H

#include "Account.h"

class User: public Account {
    public:
        User();
        User(int, const QString&, const QString&, const QDate&);
        User(const User&);
        virtual QString accountType() const;
        virtual ~User();
};

#endif // USER_H
