#ifndef BOOK_H
#define BOOK_H

#include "Item.h"

class Book : public Item {
    public:
        Book();
        Book(int, const QString&, int, int, const QString&, const QString&);
        Book(const Book&);
        QString getIsbn() const;
        QString getAuthor() const;
        void setIsbn(const QString&);
        void setAuthor(const QString&);
        virtual int loanTime() const;
        virtual QString type() const;
        virtual ~Book();
    private:
        QString isbn;
        QString author;
};

#endif // BOOK_H
