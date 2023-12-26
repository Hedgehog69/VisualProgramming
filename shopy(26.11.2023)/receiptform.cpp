#include "receiptform.h"
#include "ui_receiptform.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"
#include <QDebug>

receiptform::receiptform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receiptform),
    isSaved(false),
    buyGoodsForm(new buygoods()),
    cartManager(new CartManager())
{
    ui->setupUi(this);
    connect(ui->savingButton, &QPushButton::clicked, this, &receiptform::on_savingButton_clicked);
    connect(ui->homeButton, &QPushButton::clicked, this, &receiptform::on_homeButton_clicked);

    //connect(buyGoodsForm, &QObject::destroyed, this, &receiptform::on_ReceiptForm_closed);
}

receiptform::~receiptform()
{
    delete ui;
}

void receiptform::closeEvent(QCloseEvent *event)
{
    emit closed();
    event->accept();
}

void receiptform::on_homeButton_clicked()
{
    // Закрываем текущую форму
    this->close();

    // Отображаем главное окно
    MainWindow *mainWindow = qobject_cast<MainWindow*>(this->parent());
    if (mainWindow) {
        mainWindow->show();
    }
    if (buyGoodsForm->isVisible()) {
        buyGoodsForm->close();
    }
    if (cartManager->isVisible()) {
        cartManager->close();
    }
}
void receiptform::on_savingButton_clicked()
{
    if (!isSaved) {  // Проверяем, было ли сохранение выполнено ранее
        // Открываем диалог сохранения файла
        QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить чек"), "", tr("Текстовые файлы (*.txt);;Все файлы (*.*)"));

        if (!fileName.isEmpty()) {
            // Открываем файл для записи
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << ui->receiptTextEdit->toPlainText();

                file.close();

                QMessageBox::information(this, tr("Подождите"), tr("Идет сохранение"));
                isSaved = true;  // Устанавливаем флаг, что сохранение выполнено
            } else {
                QMessageBox::critical(this, tr("Ошибка"), tr("Не удалось открыть файл для записи"));
            }
        }
    } else {
        QMessageBox::information(this, tr("Успех"), tr("Чек успешно сохранен"));
    }
}

void receiptform::setReceiptData(const QString &recipientInfo, const QString &deliveryAddress, const QString &paymentInfo,
                                  const QMap<QString, QPair<double, int>> &cartItems, const QMap<QString, double> &cartPrices,
                                  const QString &orderNumber)
{
    ui->receiptTextEdit->clear();
    ui->receiptTextEdit->append(QString("Информация о получателе:\n%1\n\nАдрес доставки:\n%2\n\nИнформация о платеже:\n%3\n\nНомер заказа: %4\n")
                                .arg(recipientInfo).arg(deliveryAddress).arg(paymentInfo).arg(orderNumber));
    ui->receiptTextEdit->append("Купленные товары:");
    for (const QString &item : cartItems.keys()) {
        const QPair<double, int> &itemData = cartItems[item];
        ui->receiptTextEdit->append(QString("%1, %2 руб, %3 шт.").arg(item).arg(cartPrices[item]).arg(itemData.second));
    }

    double totalPrice = 0.0;
    for (const QString &item : cartItems.keys()) {
        const QPair<double, int> &itemData = cartItems[item];
        totalPrice += itemData.first;
    }

    ui->receiptTextEdit->append(QString("\nИтого: %1 руб").arg(totalPrice));
}


