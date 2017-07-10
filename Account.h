#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QDate>

class Account {
    public:
        Account();
        Account(int, const QString&, const QString&, const QDate&);
        Account(const Account&);
        int getId() const;
        QString getUsername() const;
        QString getPassword() const;
        QDate getBirthday() const;
        void setId(int);
        void setUsername(const QString&);
        void setPassword(const QString&);
        void setBirthday(const QDate&);
        virtual QString accountType() const = 0;
        virtual ~Account();
    private:
        int id;
        QString username;
        QString password;
        QDate birthday;
};
#endif // ACCOUNT_H
