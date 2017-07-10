#include "Book.h"

Book::Book() {
    isbn = QString("");
    author = QString("");
    //Item();
}

Book::Book(int id, const QString& t, int e, int l, const QString& i, const QString& a): Item(id, t, e, l), isbn(i), author(a) {}

Book::Book(const Book& b): Item(b), isbn(b.isbn), author(b.author) {}

QString Book::getIsbn() const {
    return isbn;
}

QString Book::getAuthor() const {
    return author;
}

void Book::setIsbn(const QString& i) {
    isbn = i;
}

void Book::setAuthor(const QString& a) {
    author = a;
}

int Book::loanTime() const {
    return 30;
}

QString Book::type() const {
    return QString("Libro");
}

Book::~Book() {
}
