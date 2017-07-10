#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "Data.h"
#include "Controller.h"

class UserController: public Controller {
    public:
        UserController(Data*);
        Data* getData() const;
        virtual bool checkUsername(const QString&) const;
        QList<Item*> getItems() const;
        virtual Account* getLoggedUser() const;
        int getLoggedUserId() const;
        Item* getItem(const QString&) const;
        bool startItemLoan(const QString&) const;
        virtual bool updateUser(const QString&, const QString&, const QString&, const QString&, const QString&) const;
        virtual ~UserController();
    private:
        Data* data;
};

#endif // USERCONTROLLER_H
