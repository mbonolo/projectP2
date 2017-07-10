#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "Data.h"

class LoginController {
    public:
        LoginController(Data*);
        Account* checkUser(const QString&, const QString&) const;
        ~LoginController();
    private:
        Data* data;
};

#endif // LOGINCONTROLLER_H
