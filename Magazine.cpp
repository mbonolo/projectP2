#include "Magazine.h"

Magazine::Magazine() {
    //Item();
}

Magazine::Magazine(int id, const QString& t, int e, int l): Item(id, t, e, l) {}

Magazine::Magazine(const Magazine& m): Item(m) {}

int Magazine::loanTime() const {
    return 15;
}

QString Magazine::type() const {
    return QString("Rivista");
}

Magazine::~Magazine() {
}
