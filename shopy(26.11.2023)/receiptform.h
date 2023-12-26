#ifndef RECEIPTFORM_H
#define RECEIPTFORM_H

#include <QWidget>
#include <QDialog>
#include "buygoods.h"
#include <QPointer>

class buygoods;

class CartManager;

namespace Ui {
class receiptform;
}

class receiptform : public QDialog
{
    Q_OBJECT

public:
    explicit receiptform(QWidget *parent = nullptr);
    ~receiptform();
    void setReceiptData(const QString &recipientInfo, const QString &deliveryAddress, const QString &paymentInfo,
                        const QMap<QString, QPair<double, int>> &cartItems, const QMap<QString, double> &cartPrices,
                        const QString &orderNumber);

signals:
    void closed();

private slots:
    void on_savingButton_clicked();
    void on_homeButton_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Ui::receiptform *ui;
    bool isSaved;
    QPointer<buygoods> buyGoodsForm;
     QPointer<CartManager> cartManager;
};

#endif // RECEIPTFORM_H
