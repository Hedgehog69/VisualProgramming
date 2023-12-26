// cartform.cpp
#include "cartform.h"
#include "ui_cartform.h"
#include "cartmanager.h"

CartForm::CartForm(QWidget* parent)
    : QWidget(parent), ui(new Ui::CartForm) {
    ui->setupUi(this);
}

CartForm::~CartForm() {
    delete ui;
}

void CartForm::updateCartInfo() {
    // Обновляем информацию о корзине на форме корзины
    const QList<CartItem>& cartItems = CartManager::instance().getCartItems();
    // Обновите ваш интерфейс с информацией о корзине
}
