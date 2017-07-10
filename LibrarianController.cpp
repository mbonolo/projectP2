#include "LibrarianController.h"
#include "Book.h"
#include "Magazine.h"

LibrarianController::LibrarianController(Data* d): data(d) {
}

Data* LibrarianController::getData() const {
    return data;
}

bool LibrarianController::checkUsername(const QString& u) const {
    QList<Account*>::iterator it = data->getUsers().begin();
    bool found = false;
    for(; it != data->getUsers().end() && !found; ++it) {
        if((*it)->getUsername() == u && (*it)->getUsername() != getLoggedUser()->getUsername())
            found = true;
    }
    return found;
}

bool LibrarianController::checkIsbn(const QString& i) const {
    QList<Item*>::iterator it = data->getItems().begin();
    bool found = false;
    for(; it != data->getItems().end() && !found; ++it) {
        if(dynamic_cast<Book*>(*it) && dynamic_cast<Book*>(*it)->getIsbn() == i)
            found = true;
    }
    return found;
}

bool LibrarianController::checkTitle(const QString& t, const QString& e) const {
    QList<Item*>::iterator it = data->getItems().begin();
    bool found = false;
    for(; it != data->getItems().end() && !found; ++it) {
        if(dynamic_cast<Magazine*>(*it) && (*it)->getTitle() == t && (*it)->getEdition() == e.toInt())
            found = true;
    }
    return found;
}

bool LibrarianController::insertItem(const QString& type, const QString& i, const QString& t, const QString& a, const QString& e) const {
    if(type == QString("LIBRO"))
        return data->insertItem(new Book(data->getNextItemId(), t, e.toInt(), -1, i, a));
    else if(type == QString("RIVISTA"))
        return data->insertItem(new Magazine(data->getNextItemId(), t, e.toInt(), -1));
    return false;
}

QList<Item*> LibrarianController::getItems() const {
    return data->getItems();
}

bool LibrarianController::removeItem(const QString& id) const {
    return data->removeItem(id.toInt());
}

bool LibrarianController::endItemLoan(const QString& id) const {
    QList<Item*>::iterator it = data->getItems().begin();
    bool found = false;
    for(; it != data->getItems().end() && !found; ++it) {
        if((*it)->getId() == id.toInt()) {
            (*it)->setLoan(-1);
            found = true;
        }
    }
    return found;
}

Account* LibrarianController::getLoggedUser() const {
    return data->getLoggedUser();
}

bool LibrarianController::updateUser(const QString& u, const QString& p, const QString& d, const QString& m, const QString& y) const {
    Account* a = getLoggedUser();
    a->setUsername(u);
    a->setPassword(p);
    a->setBirthday(QDate(y.toInt(), m.toInt(), d.toInt()));
    return true;
}

LibrarianController::~LibrarianController() {
    delete data;
}
