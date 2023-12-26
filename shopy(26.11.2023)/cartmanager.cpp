#include "cartmanager.h"
#include "ui_cartmanager.h"
#include "buygoods.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QTimer>
#include <QProgressDialog>
#include <QThread>

CartManager::CartManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CartManager),
    isProgressTimerConnected(false),
    isLoadingComplete(false),
    buyGoods(nullptr)

{
    ui->setupUi(this);
    connect(ui->closeButton, &QPushButton::clicked, this, &CartManager::reject);
    connect(ui->removeButton, &QPushButton::clicked, this, &CartManager::on_removeButton_clicked);
    // В конструкторе класса CartManager
    connect(ui->doneButton, &QPushButton::clicked, this, &CartManager::on_doneButton_clicked);
    isProgressTimerConnected = false;

}

CartManager::~CartManager()
{
    delete ui;
}

void CartManager::on_doneButton_clicked()
{
    if (cartItems.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Ваша корзина пуста. Пожалуйста, добавьте билеты перед оформлением."));
        return;
    }

    // Проверяем, завершилась ли загрузка
    if (isLoadingComplete) {
        // Если загрузка завершена, то просто открываем форму BuyGoods
        openBuyGoodsForm();
        handleDataChanged();
        return;
    }

    QProgressDialog progressDialog(tr("Оформление заказа..."), tr("Отмена"), 0, 100, this);
    progressDialog.setWindowTitle(tr("Загрузка"));
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setAutoClose(true);

    // Создаем таймер для обновления прогресс-бара
    if (!isProgressTimerConnected) {
        // Создаем таймер для обновления прогресс-бара
        QTimer *progressTimer = new QTimer(this);
        connect(progressTimer, &QTimer::timeout, this, &CartManager::updateProgress);
        progressTimer->start(40);  // Интервал обновления таймера в миллисекундах
        isProgressTimerConnected = true;  // Устанавливаем флаг, чтобы избежать повторного подключения
    }

    // Имитируем загрузку
    bool isCancelled = false;
    for (int i = 0; i <= 100; ++i) {
        progressDialog.setValue(i);
        qApp->processEvents();

        if (progressDialog.wasCanceled()) {
            // Процесс загрузки был отменен пользователем
            isCancelled = true;
            isLoadingComplete = false;
            break;
        }

        QThread::msleep(40);
    }

    // Проверяем, была ли отменена загрузка
    if (!isCancelled) {
        // Процесс загрузки завершен
        isLoadingComplete = true;

        // Проверяем, что форма BuyGoods не была открыта
        if (!buyGoods) {
            // Открываем форму BuyGoods
            openBuyGoodsForm();
        }
    }
}

void CartManager::updateProgress()
{
}

void CartManager::openBuyGoodsForm()
{
    if (!buyGoods) {
        buyGoods = new buygoods();  // Assuming the class is named BuyGoods
    }

    buyGoods->setWindowFlags(buyGoods->windowFlags() | Qt::WindowStaysOnTopHint);
    buyGoods->setWindowModality(Qt::WindowModal);
    buyGoods->show();
    buyGoods->raise();

    // Перед открытием формы BuyGoods, проверяем, есть ли товары в корзине
    if (!cartItems.isEmpty()) {
        buyGoods->displayCartInfo(cartItems, cartPrices);
    }
}


void CartManager::updatePrices(const QMap<QString, double> &prices) {
    // Обновляем цены
    cartPrices = prices;

    // Обновляем отображение списка в корзине
    updateCartList();
}


void CartManager::addItemToCart(const QString &itemName, double price)
{
    if (cartItems.contains(itemName)) {
        QPair<double, int> &itemData = cartItems[itemName];
        itemData.second++;
        itemData.first += price;
    } else {
        cartItems[itemName] = qMakePair(price, 1);
    }

    // Обновляем отображение списка в корзине
    updateCartList();
}

void CartManager::handleDataChanged() {
    cartItems.clear();
    updateCartList();

}

void CartManager::updateCartList() {
    ui->cartList->clear();

    QString header = QString("%1\t\t%2\t\t%3\t%4\t").arg("Наименование").arg("Цена").arg("Количество").arg("Итого");
    QListWidgetItem *headerWidget = new QListWidgetItem(header);
    ui->cartList->addItem(headerWidget);

    // Add items
    double totalPrice = 0.0;
    for (const QString &item : cartItems.keys()) {
        const QPair<double, int> &itemData = cartItems[item];
        double itemTotal = itemData.first;
        totalPrice += itemTotal;

        QString itemInfo = QString("%1\t\t%2 руб\t\t%3\t\t%4 руб\t").arg(item).arg(cartPrices[item]).arg(itemData.second).arg(itemTotal);
        QListWidgetItem *itemWidget = new QListWidgetItem(itemInfo);
        ui->cartList->addItem(itemWidget);
    }
    QString totalInfo = QString("%1: %2 руб").arg("Всего").arg(totalPrice);
    QListWidgetItem *totalWidget = new QListWidgetItem(totalInfo);
    ui->cartList->addItem(totalWidget);
}

void CartManager::on_removeButton_clicked()
{
    QList<QListWidgetItem *> selectedItems = ui->cartList->selectedItems();

    if (!selectedItems.isEmpty()) {
        QMap<QString, int> itemsToRemove;

        for (QListWidgetItem *selectedItem : selectedItems) {
            QString itemInfo = selectedItem->text();
            QStringList parts = itemInfo.split(QRegExp("[\t\n]"), QString::SkipEmptyParts);
            QString itemName = parts[0].trimmed();

            bool ok;
            int removeQuantity = QInputDialog::getInt(this, tr("Remove Items"),
                                                      tr("Сколько '%1' удалить из корзины?").arg(itemName),
                                                      1, 1, 10, 1, &ok);

            if (ok) {
                int currentQuantity = cartItems[itemName].second;
                qDebug() << "DEBUG: Текущее количество в корзине: " << currentQuantity;

                if (removeQuantity > currentQuantity) {
                    QMessageBox::warning(this, tr("Ошибка"), tr("Введенное количество для удаления больше, чем имеется в корзине."));
                    return;
                }

                qDebug() << "DEBUG: Количество для удаления2: " << removeQuantity;
                itemsToRemove[itemName] = removeQuantity;
            }
        }

        qDebug() << "DEBUG: Количество itemsToRemove: " << itemsToRemove;

        emit itemsRemoved(itemsToRemove);

        QMapIterator<QString, int> iterator(itemsToRemove);
        while (iterator.hasNext()) {
            iterator.next();

            QString itemName = iterator.key();
            int removeQuantity = iterator.value();

            double removedItemPrice = cartPrices[itemName] * removeQuantity;

            QPair<double, int> &itemData = cartItems[itemName];
            itemData.first -= removedItemPrice;
            itemData.second -= removeQuantity;

            if (itemData.second <= 0) {
                cartItems.remove(itemName);
            }
        }

        // Обновляем отображение списка в корзине
        updateCartList();
    }
}
