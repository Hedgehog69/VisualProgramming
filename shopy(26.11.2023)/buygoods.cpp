#include "buygoods.h"
#include "ui_buygoods.h"
#include "receiptform.h"
#include "receiptform.h"
#include <QRandomGenerator>
#include <QMessageBox>

buygoods::buygoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buygoods)
{
    ui->setupUi(this);

    // Подключаем слот для обработки нажатия кнопки payButton
    connect(ui->payButton, &QPushButton::clicked, this, &buygoods::on_payButton_clicked);
}

buygoods::~buygoods()
{
    delete ui;
}

void buygoods::displayCartInfo(const QMap<QString, QPair<double, int>> &cartItems, const QMap<QString, double> &cartPrices)
{
    // Очистка предыдущей информации, если она была отображена
    ui->cartinfolist->clear();
    double totalPrice = 0.0;

    // Присваиваем значения переменным класса
    this->cartItems = cartItems;
    this->cartPrices = cartPrices;

    // Отображение информации из корзины
    for (const QString &item : cartItems.keys()) {
        const QPair<double, int> &itemData = cartItems[item];
        double itemTotal = itemData.first;

        QString itemInfo = QString("%1, %2 руб, %3 шт.").arg(item).arg(cartPrices[item]).arg(itemData.second);
        QListWidgetItem *itemWidget = new QListWidgetItem(itemInfo);
        ui->cartinfolist->addItem(itemWidget);

        totalPrice += itemTotal;
    }

    // Отображение разделителя и итоговой суммы в корзине
    QString totalInfo1= QString("------------------------------");
    QString totalInfo = QString("Итого: %1 руб").arg(totalPrice);
    QListWidgetItem *totalWidget1 = new QListWidgetItem(totalInfo1);
    QListWidgetItem *totalWidget = new QListWidgetItem(totalInfo);
    ui->cartinfolist->addItem(totalWidget1);
    ui->cartinfolist->addItem(totalWidget);
}

void buygoods::getUserInput(QString &recipientInfo, QString &deliveryAddress, QString &paymentInfo)
{
    recipientInfo = QString("%1 %2, %3").arg(ui->name->toPlainText()).arg(ui->lastname->toPlainText()).arg(ui->phone->toPlainText());
    deliveryAddress = ui->address->toPlainText();
    paymentInfo = QString("Номер карты: %1\nСрок действия: %2")
            .arg(ui->number->toPlainText())
            .arg(ui->dateEdit->date().toString("MM/yyyy"));
}



void buygoods::on_payButton_clicked()
{
    // Проверка на заполнение всех полей перед выполнением действий
    if (ui->name->toPlainText().isEmpty() || ui->lastname->toPlainText().isEmpty() ||
        ui->phone->toPlainText().isEmpty() || ui->address->toPlainText().isEmpty() ||
        ui->number->toPlainText().isEmpty() || !ui->dateEdit->date().isValid()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Заполните все поля перед оформлением заказа."));
        return;
    }

    // Получение данных от пользователя
    QString recipientInfo, deliveryAddress, paymentInfo;
    getUserInput(recipientInfo, deliveryAddress, paymentInfo);

    // Генерация случайного номера заказа из 8 символов (цифры и буквы)
    QString orderNumber = generateOrderNumber();

    // Создаем форму чека и передаем данные
    receiptform *ReceiptForm = new receiptform(this);

    // Подключаем сигнал closed формы ReceiptForm к слоту on_receiptForm_closed
    connect(ReceiptForm, &receiptform::closed, this, &buygoods::on_receiptForm_closed);

    // Вызываем метод для установки данных о корзине, номере заказа и других данных
    ReceiptForm->setReceiptData(recipientInfo, deliveryAddress, paymentInfo, cartItems, cartPrices, orderNumber);

    // Отображаем форму чека
    ReceiptForm->show();
}


void buygoods::clearCart()
{
    // Добавьте код для очистки корзины здесь
    // Например, сбросьте содержимое переменных cartItems и cartPrices
    cartItems.clear();
    cartPrices.clear();

    // Очистите виджеты отображения корзины, если это необходимо
    ui->cartinfolist->clear();
}

void buygoods::on_receiptForm_closed()
{
    // Закрываем buygoods
    this->close();
}

QString buygoods::generateOrderNumber()
{
    const QString characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Допустимые символы
    QString orderNumber;

    // Генерируем случайный номер заказа из 8 символов
    for (int i = 0; i < 8; ++i) {
        int index = QRandomGenerator::global()->bounded(characters.length());
        orderNumber.append(characters.at(index));
    }

    return orderNumber;
}


