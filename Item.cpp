#include "Item.h"

Item::Item(){
    id = -1;
    title = QString("");
    edition = 1970;
    loan = -1;
}

Item::Item(int id, const QString& t, int e, int l): id(id), title(t), edition(e), loan(l) {}

Item::Item(const Item& i): id(i.id), title(i.title), edition(i.edition), loan(i.loan) {}

int Item::getId() const {
    return id;
}

QString Item::getTitle() const {
    return title;
}

int Item::getEdition() const {
    return edition;
}

int Item::onLoan() const {
    return loan;
}

void Item::setId(int newId) {
    id = newId;
}

void Item::setTitle(const QString& t) {
    title = t;
}

void Item::setEdition(int e) {
    edition = e;
}

void Item::setLoan(int l) {
    loan = l;
}

Item::~Item() {}
