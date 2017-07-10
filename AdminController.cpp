#include "AdminController.h"
#include "Admin.h"
#include "Librarian.h"
#include "User.h"

AdminController::AdminController(Data* d): data(d) {
}

Data* AdminController::getData() const {
    return data;
}

bool AdminController::checkUsername(const QString& u) const {
    QList<Account*>::iterator it = data->getUsers().begin();
    bool found = false;
    for(; it != data->getUsers().end() && !found; ++it) {
        if((*it)->getUsername() == u && (*it)->getUsername() != getLoggedUser()->getUsername())
            found = true;
    }
    return found;
}

bool AdminController::insertUser(const QString& u, const QString& t, const QString& d, const QString& m, const QString& y) const {
    if(t == QString("AMMINISTRATORE"))
        return data->insertUser(new Admin(data->getNextUserId(), u, u, QDate(y.toInt(), m.toInt(), d.toInt())));
    else if(t == QString("BIBLIOTECARIO"))
        return data->insertUser(new Librarian(data->getNextUserId(), u, u, QDate(y.toInt(), m.toInt(), d.toInt())));
    else if(t == QString("UTENTE"))
        return data->insertUser(new User(data->getNextUserId(), u, u, QDate(y.toInt(), m.toInt(), d.toInt())));
    return false;
}

QList<Account*> AdminController::getUsers() const {
    return data->getUsers();
}

Account* AdminController::getLoggedUser() const {
    return data->getLoggedUser();
}

bool AdminController::removeUser(const QString& id) const {
    return data->removeUser(id.toInt());
}

bool AdminController::updateUser(const QString& u, const QString& p, const QString& d, const QString& m, const QString& y) const {
    Account* a = getLoggedUser();
    a->setUsername(u);
    a->setPassword(p);
    a->setBirthday(QDate(y.toInt(), m.toInt(), d.toInt()));
    return true;
}

AdminController::~AdminController() {
    delete data;
}
