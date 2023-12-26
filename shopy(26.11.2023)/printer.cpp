// printer.cpp
#include "printer.h"

Printer::Printer(QString model, double price) : model(model), price(price) {}

// Реализуйте конструктор по умолчанию
Printer::Printer() : model(""), price(0.0) {}

QString Printer::getModel() const {
    return model;
}

double Printer::getPrice() const {
    return price;
}

// Реализация оператора << для сериализации
QDataStream &operator<<(QDataStream &out, const Printer &printer) {
    out << printer.getModel() << printer.getPrice();
    return out;
}

// Реализация оператора >> для десериализации
QDataStream &operator>>(QDataStream &in, Printer &printer) {
    QString model;
    double price;
    in >> model >> price;
    printer = Printer(model, price);
    return in;
}
