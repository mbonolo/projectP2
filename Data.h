#ifndef DATA_H
#define DATA_H

#include <QList>
#include "Account.h"
#include "Item.h"

class Data {
    public:
        Data();
        void retrieveUsers();
        void saveUsers();
        void retrieveItems();
        void saveItems();
        QList<Account*> getUsers() const;
        QList<Item*> getItems() const;
        Account* getLoggedUser() const;
        void setLoggedUser(Account*);
        int getLoggedUserId() const;
        bool insertUser(Account*);
        bool insertItem(Item*);
        int getNextUserId() const;
        int getNextItemId() const;
        bool removeUser(int);
        bool removeItem(int);
        ~Data();
    private:
        QList<Account*> users;
        QList<Item*> items;
        Account* loggedUser;
        int loggedUserId;
        int nextUserId;
        int nextItemId;
};

#endif // DATA_H
