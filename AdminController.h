#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include "Data.h"
#include "Controller.h"

class AdminController: public Controller {
    public:
        AdminController(Data*);
        Data* getData() const;
        virtual bool checkUsername(const QString&) const;
        bool insertUser(const QString&, const QString&, const QString&, const QString&, const QString&) const;
        QList<Account*> getUsers() const;
        bool removeUser(const QString&) const;
        virtual Account* getLoggedUser() const;
        virtual bool updateUser(const QString&, const QString&, const QString&, const QString&, const QString&) const;
        virtual ~AdminController();
    private:
        Data* data;
};

#endif // ADMINCONTROLLER_H
