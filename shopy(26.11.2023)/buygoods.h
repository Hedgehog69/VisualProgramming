#ifndef BUYGOODS_H
#define BUYGOODS_H

#include <QWidget>
#include <QMap>
#include <QPair>


namespace Ui {
class buygoods;
}

class buygoods : public QWidget
{
    Q_OBJECT

public:
    explicit buygoods(QWidget *parent = nullptr);
    ~buygoods();
     void displayCartInfo(const QMap<QString, QPair<double, int>> &cartItems, const QMap<QString, double> &cartPrices);
     void getUserInput(QString &recipientInfo, QString &deliveryAddress, QString &paymentInfo);
     void on_payButton_clicked();
     QString generateOrderNumber();
     void on_receiptForm_closed();

private slots:
    void clearCart();

private:
    Ui::buygoods *ui;
    QMap<QString, QPair<double, int>> cartItems;
    QMap<QString, double> cartPrices;
};

#endif // BUYGOODS_H
