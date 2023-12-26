#include "inkpage.h"
#include "ui_inkpage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>

InkPage::InkPage(CartManager *cartManager, QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InkPage),
    cartManager(cartManager), db(db) {
    ui->setupUi(this);
    scrollArea = new QScrollArea(this);
    scrollWidget = new QWidget(scrollArea);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);

    scrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollArea->setGeometry(0, 70, 698, 390);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    scrollWidget->setParent(scrollArea);
    int widgetWidth = 210;
    int widgetHeight = 360;
    for (int i = 0; i < 6; ++i) {
        int row = i / 3;
            int col = i % 3;

            int x = 30 + col * widgetWidth;
            int y = 160 + row * widgetHeight;

            QLineEdit* modelLineEdit = new QLineEdit(scrollWidget);
                QLineEdit* priceDoubleSpinBox = new QLineEdit(scrollWidget);
                QTextEdit* shortInfoTextEdit = new QTextEdit(scrollWidget);
                QLabel* photoLabel = new QLabel(scrollWidget);
                QTextEdit* countStore = new QTextEdit(scrollWidget);
                QPushButton* buyButton = new QPushButton("Купить", scrollWidget);

                modelLineEdit->setGeometry(x, y, 113, 20);
                modelLineEdit->setObjectName("modelLineEdit" + QString::number(i + 1));

                priceDoubleSpinBox->setGeometry(x + 120, y, 61, 21);
                priceDoubleSpinBox->setObjectName("Price" + QString::number(i + 1));

                shortInfoTextEdit->setGeometry(x, y + 30, 181, 101);
                shortInfoTextEdit->setObjectName("shortInfoTextEdit" + QString::number(i + 1));

                photoLabel->setGeometry(x, y - 110, 180, 100);
                photoLabel->setObjectName("photoLabel" + QString::number(i + 1));

                countStore->setGeometry(x, y + 140, 181, 31);
                countStore->setObjectName("countStore" + QString::number(i + 1));

                buyButton->setGeometry(x, y + 180, 181, 31);
                buyButton->setObjectName("buyButton" + QString::number(i + 1));

                // Добавляем виджеты в соответствующие контейнеры
                modelLineEdits.append(modelLineEdit);
                priceDoubleSpinBoxes1.append(priceDoubleSpinBox);
                shortInfoTextEdits.append(shortInfoTextEdit);
                photoLabels.append(photoLabel);
                countStores.append(countStore);
                buyButtons.append(buyButton);
                scrollWidget->setFixedSize(QSize(x + 200, y + 230));

                connect(buyButton, &QPushButton::clicked, [this, i]() {
                    buyInk(i);
                });
            }

    scrollWidget->adjustSize();
    loadPrintersFromDatabase();

    readPricesFromDatabase();
    connect(cartManager, &CartManager::itemsRemoved, this, &InkPage::restoreCountStore);
    connect(ui->cartButton, SIGNAL(clicked()), this, SLOT(onCartButtonClicked()));
}

void InkPage::onCartButtonClicked() {
    cartManager->exec();
    cartManager->updatePrices(printerPrices);
}

void InkPage::restoreCountStore(const QMap<QString, int> &itemsToRemove) {
    QSqlQuery updateQuery(*db);

    for (const QString &itemName : itemsToRemove.keys()) {
        int removeQuantity = itemsToRemove[itemName];
        int widgetIndex = -1;
        for (int i = 0; i < modelLineEdits.size(); ++i) {
            if (modelLineEdits[i]->text() == itemName) {
                widgetIndex = i;
                break;
            }
        }

        if (widgetIndex != -1) {
            double countStore = countStores[widgetIndex]->toPlainText().split(":").last().toDouble();

            if (countStore + removeQuantity >= 0) {
                updateQuery.prepare("UPDATE items SET count_store = :countStore WHERE model = :modelName");
                updateQuery.bindValue(":countStore", countStore + removeQuantity);
                updateQuery.bindValue(":modelName", itemName);

                if (!updateQuery.exec()) {
                    qDebug() << "Error updating count_store:" << updateQuery.lastError().text();
                    return;
                }

                countStores[widgetIndex]->setPlainText("Билетов в наличии: " + QString::number(countStore + removeQuantity, 'f', 0));
            } else {
                qDebug() << "Attempted to reduce count_store below 0 for item" << itemName;
            }
        }
    }
}


void InkPage::loadPrintersFromDatabase() {
    // Check if the table 'items' exists
    QSqlQuery checkQuery(*db);
    checkQuery.prepare("SELECT name FROM sqlite_master WHERE type='table' AND name='items'");

    if (checkQuery.exec() && checkQuery.next()) {
    } else {
        QSqlQuery createTableQuery(*db);
        createTableQuery.prepare("CREATE TABLE IF NOT EXISTS items ("
                                 "item_id INTEGER PRIMARY KEY, "
                                 "category TEXT, "
                                 "model TEXT, "
                                 "price REAL, "
                                 "short_info TEXT, "
                                 "photo_path TEXT, "
                                 "count_store REAL)");

        if (!createTableQuery.exec()) {
            QString error = createTableQuery.lastError().text();
            qDebug() << "Error creating 'items' table:" << error;
            QMessageBox::critical(this, "Error", "Unable to create 'items' table. Error: " + error);
            return;
        }

    }

    QSqlQuery query("SELECT * FROM items WHERE category = 'Караганда'", *db);
    int widgetIndex = 0;
    while (query.next() && widgetIndex < modelLineEdits.size()) {
        QString modelName = query.value("model").toString();
        double price = query.value("price").toDouble();
        QString shortInfo = query.value("short_info").toString();
        QString photoPath = query.value("photo_path").toString();
        double countStore = query.value("count_store").toDouble();

        modelLineEdits[widgetIndex]->setText(modelName);
        priceDoubleSpinBoxes1[widgetIndex]->setText(QString::number(price, 'f', 2));
        shortInfoTextEdits[widgetIndex]->setText(shortInfo);
        QPixmap pixmap(photoPath);
        photoLabels[widgetIndex]->setPixmap(pixmap);
        countStores[widgetIndex]->setPlainText("Билетов в наличии: " + QString::number(countStore, 'f', 0));

        modelLineEdits[widgetIndex]->show();
        priceDoubleSpinBoxes1[widgetIndex]->show();
        shortInfoTextEdits[widgetIndex]->show();
        photoLabels[widgetIndex]->show();
        countStores[widgetIndex]->show();
        buyButtons[widgetIndex]->show();

        widgetIndex++;
    }

    for (int i = widgetIndex; i < modelLineEdits.size(); ++i) {
        modelLineEdits[i]->hide();
        priceDoubleSpinBoxes1[i]->hide();
        shortInfoTextEdits[i]->hide();
        photoLabels[i]->hide();
        countStores[i]->hide();
        buyButtons[i]->hide();
    }
}

void InkPage::readPricesFromDatabase() {
    QSqlQuery query("SELECT * FROM items", *db);

    while (query.next()) {
        QString modelName = query.value("model").toString();
        double price = query.value("price").toDouble();
        QString image = query.value("photo_path").toString();

        qDebug() << "Model:" << modelName << ", Price:" << price;

        printerPrices[modelName] = price;
        printerImages[modelName] = image;
    }
    cartManager->updatePrices(printerPrices);
}


void InkPage::readInk(QSqlQuery &query) {
    QString modelName = query.value("model").toString();
    double price = query.value("price").toDouble();
    QString image = query.value("photo_path").toString();

    printerPrices[modelName] = price;
    printerImages[modelName] = image;
}

void InkPage::buyInk(const QString &itemName) {
    if (printerPrices.contains(itemName)) {
        double price = printerPrices[itemName];

        int widgetIndex = -1;
        for (int i = 0; i < modelLineEdits.size(); ++i) {
            if (modelLineEdits[i]->text() == itemName) {
                widgetIndex = i;
                break;
            }
        }

        if (widgetIndex != -1) {
            double countStore = countStores[widgetIndex]->toPlainText().split(":").last().toDouble();
            if (countStore > 0) {
                QSqlQuery updateQuery(*db);
                updateQuery.prepare("UPDATE items SET count_store = :countStore WHERE model = :modelName");
                updateQuery.bindValue(":countStore", countStore - 1);
                updateQuery.bindValue(":modelName", itemName);

                if (!updateQuery.exec()) {
                    qDebug() << "Error updating count_store:" << updateQuery.lastError().text();
                    return;
                }

                countStores[widgetIndex]->setPlainText("Билетов в наличии: " + QString::number(countStore - 1, 'f', 0));

                cartManager->addItemToCart(itemName, price);

                emit cartManager->cartUpdated();
            } else {
                qDebug() << "Товар " << itemName << " билеты закончились.";
                QMessageBox::information(this, "Упс.", "К сожалению эти билеты закончились. Выберите что-то другое или подождите поступления билетов.");
            }
        } else {
            qDebug() << "Ошибка поиска товара " << itemName;
        }
    } else {
        qDebug() << "Цена для товара" << itemName << "не найдена.";
    }
}

void InkPage::buyInk(int index) {
    if (index >= 0 && index < modelLineEdits.size()) {
        QString itemName = modelLineEdits[index]->text();
        buyInk(itemName);
    } else {
        qDebug() << "Недопустимый индекс для покупки билета.";
    }
}


InkPage::~InkPage() {
    delete ui;
}
