// printer.h
#ifndef PRINTER_H
#define PRINTER_H

#include <QString>
#include <QDataStream>

class Printer {
public:
    Printer(QString model, double price);

    // Добавьте конструктор по умолчанию
    Printer();

    QString getModel() const;
    double getPrice() const;

    // Добавьте методы для сериализации и десериализации
    friend QDataStream &operator<<(QDataStream &out, const Printer &printer);
    friend QDataStream &operator>>(QDataStream &in, Printer &printer);

private:
    QString model;
    double price;
};

#endif // PRINTER_H
