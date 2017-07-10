#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include "Account.h"

class Controller {
    public:
        Controller();
        virtual bool checkUsername(const QString&) const = 0;
        virtual Account* getLoggedUser() const = 0;
        virtual bool updateUser(const QString&, const QString&, const QString&, const QString&, const QString&) const = 0;
        virtual ~Controller();
};

#endif // CONTROLLER_H
