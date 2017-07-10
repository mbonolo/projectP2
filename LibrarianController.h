#ifndef LIBRARIANCONTROLLER_H
#define LIBRARIANCONTROLLER_H

#include "Data.h"
#include "Controller.h"

class LibrarianController: public Controller {
    public:
        LibrarianController(Data*);
        Data* getData() const;
        virtual bool checkUsername(const QString&) const;
        bool checkIsbn(const QString&) const;
        bool checkTitle(const QString&, const QString&) const;
        bool insertItem(const QString&, const QString&, const QString&, const QString&, const QString&) const;
        QList<Item*> getItems() const;
        bool removeItem(const QString&) const;
        bool endItemLoan(const QString&) const;
        virtual Account* getLoggedUser() const;
        virtual bool updateUser(const QString&, const QString&, const QString&, const QString&, const QString&) const;
        virtual ~LibrarianController();
    private:
        Data* data;
};

#endif // LIBRARIANCONTROLLER_H
