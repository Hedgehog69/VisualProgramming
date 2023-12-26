// buydialog.h
#pragma once

#include <QDialog>

namespace Ui {
class BuyDialog;
}

class BuyDialog : public QDialog {
    Q_OBJECT

public:
    explicit BuyDialog(QWidget* parent = nullptr);
    ~BuyDialog();

signals:
    void itemAddedToCart();

private slots:
    void on_addToCartButton_clicked();

private:
    Ui::BuyDialog* ui;
};
