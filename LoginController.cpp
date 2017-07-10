#include "LoginController.h"

LoginController::LoginController(Data* d): data(d) {
}

Account* LoginController::checkUser(const QString& u, const QString& p) const {
    QList<Account*>::iterator it = data->getUsers().begin();
    bool logged = false;
    for(; it != data->getUsers().end() && !logged; ++it) {
        if((*it)->getUsername() == u && (*it)->getPassword() == p) {
            logged = true;
            data->setLoggedUser((*it));
        }
    }
    if(logged)
        return data->getLoggedUser();
    return NULL;
}

LoginController::~LoginController() {
    delete data;
}
