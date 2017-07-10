#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
    public:
        Item();
        Item(int, const QString&, int, int);
        Item(const Item&);
        int getId() const;
        QString getTitle() const;
        int getEdition() const;
        int onLoan() const;
        void setId(int);
        void setTitle(const QString&);
        void setEdition(int);
        void setLoan(int);
        virtual int loanTime() const = 0;
        virtual QString type() const = 0;
        virtual ~Item();
    private:
        int id;
        QString title;
        int edition;
        int loan;
};

#endif // ITEM_H
