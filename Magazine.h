#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "Item.h"

class Magazine : public Item
{
    public:
        Magazine();
        Magazine(int, const QString&, int, int);
        Magazine(const Magazine&);
        virtual int loanTime() const;
        virtual QString type() const;
        virtual ~Magazine();
};

#endif // MAGAZINE_H
