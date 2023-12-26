// buydialog.cpp
#include "buydialog.h"
#include "ui_buydialog.h"
#include "cartmanager.h"

BuyDialog::BuyDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::BuyDialog) {
    ui->setupUi(this);
}

BuyDialog::~BuyDialog() {
    delete ui;
}

void BuyDialog::on_addToCartButton_clicked() {
    // Получаем информацию о товаре с формы
    QString model = ui->modelLineEdit->text();
    int quantity = ui->quantitySpinBox->value();
    double price = ui->priceDoubleSpinBox->value();

    // Добавляем товар в корзину
    CartManager::instance().addItemToCart(model, quantity, price);

    // Оповещаем главное окно о том, что товар добавлен в корзину
    emit itemAddedToCart();

    // Закрываем текущее диалоговое окно
    close();
}
