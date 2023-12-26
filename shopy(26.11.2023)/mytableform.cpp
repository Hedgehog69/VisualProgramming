#include "mytableform.h"
#include "ui_mytableform.h"
#include "printerpage.h"
#include "cartridgepage.h"
#include "inkpage.h"
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

MyTableForm::MyTableForm(QSqlDatabase db, PrinterPage* printerPage,CartridgePage* cartridgePage,InkPage* inkPage, QHash<QString, QPair<double, int>> &cartItems, CartManager* cartManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTableForm),
    printerPage(printerPage),
    cartridgePage(cartridgePage),
    inkPage(inkPage),
    cartItems(cartItems),
    cartManager(cartManager)
{
    ui->setupUi(this);

    // Проверяем, было ли успешно открыто подключение к базе данных
    if (!db.isValid() || !db.isOpen()) {
        qDebug() << "Invalid database or not open!";
        return;
    }

     helpDialog = new HelpDialog(this);
     //connect(ui->questButton, &QPushButton::clicked, this, &MyTableForm::onQuestButtonClicked);

    tableModel = new QSqlTableModel(this, db);
    tableModel->setTable("items");
    tableModel->select();

    // Проверяем, были ли ошибки при установке модели
    if (tableModel->lastError().isValid()) {
        qDebug() << "Error setting up table model:" << tableModel->lastError().text();
        return;
    }

    // Устанавливаем модель на TableView
    ui->tableView->setModel(tableModel);

    connect(ui->saveButton, &QPushButton::clicked, this, &MyTableForm::onSaveButtonClicked);
    connect(ui->closeButton2, &QPushButton::clicked, this, &MyTableForm::onCloseButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MyTableForm::onDeleteButtonClicked);
    connect(ui->addButton, &QPushButton::clicked, this, &MyTableForm::onAddButtonClicked);
    connect(ui->searchLineEdit, &QLineEdit::textChanged, this, &MyTableForm::onSearchTextChanged);
    lastUpdateTimestamp = QDateTime::currentDateTime();
    connect(this, &MyTableForm::dataChanged, cartManager, &CartManager::handleDataChanged);

}

void MyTableForm::onSearchTextChanged(const QString &text)
{
    tableModel->setFilter(QString("model LIKE '%%1%' OR short_info LIKE '%%1%'").arg(text));
    tableModel->select();
}

void MyTableForm::onQuestButtonClicked()
{
    helpDialog->exec();
}

void MyTableForm::onAddButtonClicked()
{
    int rowCount = tableModel->rowCount();
    tableModel->insertRow(rowCount);

    QString defaultModel = "Модель по умолчанию_" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    tableModel->setData(tableModel->index(rowCount, tableModel->fieldIndex("model")), defaultModel);
    tableModel->setData(tableModel->index(rowCount, tableModel->fieldIndex("price")), 0.0);
    tableModel->setData(tableModel->index(rowCount, tableModel->fieldIndex("short_info")), "Краткая информация");
    tableModel->setData(tableModel->index(rowCount, tableModel->fieldIndex("photo_path")), "Путь/к/фото");
    tableModel->setData(tableModel->index(rowCount, tableModel->fieldIndex("count_store")), 0.0);
    emit dataChanged();

    if (tableModel->submitAll()) {
        qDebug() << "Row(s) added successfully!";
        emit dataChanged();
        // Update data in PrinterPage
        if (printerPage) {
            printerPage->loadPrintersFromDatabase();
            printerPage->readPricesFromDatabase();
        }
        if (cartridgePage) {
            cartridgePage->loadPrintersFromDatabase();
            cartridgePage->readPricesFromDatabase();
        }
        if (inkPage) {
            inkPage->loadPrintersFromDatabase();
            inkPage->readPricesFromDatabase();
        }
    } else {
        qDebug() << "Error adding row(s):" << tableModel->lastError().text();
    }
}



void MyTableForm::onDeleteButtonClicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        qDebug() << "No row selected for deletion.";
        return;
    }

    int choice = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите удалить выбранную(ые) строку(и)??", QMessageBox::Yes | QMessageBox::No);
    if (choice == QMessageBox::No) {
        return;
    }

    for (const QModelIndex &index : selectedRows) {
        tableModel->removeRow(index.row());
    }

    if (tableModel->submitAll()) {
        qDebug() << "Row(s) deleted successfully!";
        emit dataChanged();

        if (printerPage) {
            printerPage->loadPrintersFromDatabase();
            printerPage->readPricesFromDatabase();
        }
        if (cartridgePage) {
            cartridgePage->loadPrintersFromDatabase();
            cartridgePage->readPricesFromDatabase();
        }
        if (inkPage) {
            inkPage->loadPrintersFromDatabase();
            inkPage->readPricesFromDatabase();
        }

    } else {
        qDebug() << "Error deleting row(s):" << tableModel->lastError().text();

    }
}

void MyTableForm::onSaveButtonClicked()
{
    bool isCartEmptyBeforeUpdate = cartItems.isEmpty();
    tableModel->submitAll();

    // Проверяем, были ли ошибки при сохранении
    if (tableModel->lastError().isValid()) {
        qDebug() << "Error saving changes:" << tableModel->lastError().text();
    } else {
        qDebug() << "Changes saved successfully!";
        emit dataChanged();
        if (printerPage) {
            printerPage->loadPrintersFromDatabase();
            printerPage->readPricesFromDatabase();
        }
        if (cartridgePage) {
            cartridgePage->loadPrintersFromDatabase();
            cartridgePage->readPricesFromDatabase();
        }
        if (inkPage) {
            inkPage->loadPrintersFromDatabase();
            inkPage->readPricesFromDatabase();
        }

        if (isCartEmptyBeforeUpdate) {
            QMessageBox::information(this, "Инвентаризация", "Корзина была обновлена. Данные о билетах могли измениться.");
        }

        cartItems.clear();

        cartManager->updateCartList();
    }
    lastUpdateTimestamp = QDateTime::currentDateTime();
}


void MyTableForm::onCloseButtonClicked()
{
    close();
}

MyTableForm::~MyTableForm()
{
    delete ui;
}
