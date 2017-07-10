#include "UserController.h"

UserController::UserController(Data* d): data(d){
}

Data* UserController::getData() const {
    return data;
}

bool UserController::checkUsername(const QString& u) const {
    QList<Account*>::iterator it = data->getUsers().begin();
    bool found = false;
    for(; it != data->getUsers().end() && !found; ++it) {
        if((*it)->getUsername() == u && (*it)->getUsername() != getLoggedUser()->getUsername())
            found = true;
    }
    return found;
}

QList<Item*> UserController::getItems() const {
    return data->getItems();
}

Account* UserController::getLoggedUser() const {
    return data->getLoggedUser();
}

int UserController::getLoggedUserId() const {
    return data->getLoggedUserId();
}

Item* UserController::getItem(const QString& id) const {
    QList<Item*>::iterator it = getItems().begin();
    Item* i = NULL;
    for(; it != getItems().end() && !i; ++it)
        if((*it)->getId() == id.toInt())
            i = *it;
    return i;
}

bool UserController::startItemLoan(const QString& id) const {
    QList<Item*>::iterator it = getItems().begin();
    bool found = false;
    for(; it != data->getItems().end() && !found; ++it) {
        if((*it)->getId() == id.toInt()) {
            (*it)->setLoan(getLoggedUserId());
            found = true;
        }
    }
    return found;
}

bool UserController::updateUser(const QString& u, const QString& p, const QString& d, const QString& m, const QString& y) const {
    Account* a = getLoggedUser();
    a->setUsername(u);
    a->setPassword(p);
    a->setBirthday(QDate(y.toInt(), m.toInt(), d.toInt()));
    return true;
}

UserController::~UserController() {
    delete data;
}
