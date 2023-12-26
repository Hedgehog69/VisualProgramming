#ifndef CARTMANAGER_H
#define CARTMANAGER_H

#include <QDialog>
#include <QMap>
#include <QListWidgetItem>
#include <QString>
#include <QSqlQuery>
#include "mytableform.h"
#include "buygoods.h"

namespace Ui {
class CartManager;
}

class CartManager : public QDialog
{
    Q_OBJECT

public:
    explicit CartManager(QWidget *parent = nullptr);
    ~CartManager();
    void addItemToCart(const QString &itemName, double price);
    void updatePrices(const QMap<QString, double> &prices);
    int getQuantity(const QString &itemName) const;
    void updateCartList();

signals:
    void cartUpdated();
    void itemsRemoved(const QMap<QString, int> &itemsToRemove);
    void startBuyGoodsFormTimer(int milliseconds);

private slots:
    void on_removeButton_clicked();
    void openBuyGoodsForm();
    void updateProgress();

public slots:
    void handleDataChanged();
    void on_doneButton_clicked();

private:
    MyTableForm *myTableForm;
    Ui::CartManager *ui;
    QMap<QString, QPair<double, int>> cartItems;
    QMap<QString, double> cartPrices;
    QSqlDatabase *db;
    PrinterPage* printerPage;
    buygoods* buyGoods;
    QTimer *progressTimer;
    bool isProgressTimerConnected;
    bool isLoadingComplete;

};

#endif // CARTMANAGER_H
