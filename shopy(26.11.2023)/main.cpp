#include "mainwindow.h"
#include "mytableform.h"
#include <QApplication>
#include <QDebug>
#include <QSqlError>

void insertOrUpdateSampleData(QSqlDatabase& db) {
    QSqlQuery sampleDataQuery("SELECT COUNT(*) FROM items", db);
    if (sampleDataQuery.exec() && sampleDataQuery.next() && sampleDataQuery.value(0).toInt() == 0) {
        QSqlQuery insertQuery(db);
        insertQuery.prepare("INSERT OR REPLACE INTO items (model, price, short_info, photo_path, count_store) VALUES "
                            "(:model, :price, :shortInfo, :photoPath, :countStore)");

        QList<QVariantList> itemsData = {
            {"Printer 1", 500.00, "Краткая информация о принтере 1", "D:\\Shop-main\\shopy(26.11.2023)\\printer.png", 11},
            {"Printer 2", 700.00, "Краткая информация о принтере 2", "D:/Shop-main/shopy(26.11.2023)/printer.png", 12},
            {"Printer 3", 900.00, "Краткая информация о принтере 3", "D:/Shop-main/shopy(26.11.2023)/printer.png", 8},
            {"Cartridge 1", 600.00, "Краткая информация о картридже 1", "D:/Shop-main/shopy(26.11.2023)/car.png", 11},
            {"Cartridge 2", 450.00, "Краткая информация о картридже 2", "D:/Shop-main/shopy(26.11.2023)/car.png", 12},
            {"Cartridge 3", 680.00, "Краткая информация о картридже 3", "D:/Shop-main/shopy(26.11.2023)/car.png", 8},
            {"Ink 1", 240.00, "Краткая информация о чернилах 1", "D:/Shop-main/shopy(26.11.2023)/ink.png", 11},
            {"Ink 2", 430.00, "Краткая информация о чернилах 2", "D:/Shop-main/shopy(26.11.2023)/ink.png", 12},
            {"Ink 3", 520.00, "Краткая информация о чернилах 3", "D:/Shop-main/shopy(26.11.2023)/ink.png", 8}
        };

        for (const auto& itemData : itemsData) {
            insertQuery.bindValue(":model", itemData[0]);
            insertQuery.bindValue(":price", itemData[1]);
            insertQuery.bindValue(":shortInfo", itemData[2]);
            insertQuery.bindValue(":photoPath", itemData[3]);
            insertQuery.bindValue(":countStore", itemData[4]);

            if (!insertQuery.exec()) {
                qDebug() << "Error inserting sample data into 'items' table:" << insertQuery.lastError().text();
                return;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleFile(":/styles/styles.css");
    styleFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleFile.readAll());
    qApp->setStyleSheet(styleSheet);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("shopbase.sqlite");

    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных:" << db.lastError().text();
        return 1;
    } else {
        qDebug() << "База данных открыта успешно!";
    }

    QSqlQuery addUniqueConstraint(db);
    addUniqueConstraint.exec("CREATE UNIQUE INDEX IF NOT EXISTS idx_unique_model ON items(model)");


    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT name FROM sqlite_master WHERE type='table' AND name='items'");

    if (checkQuery.exec() && checkQuery.next()) {
    } else {
        // The table doesn't exist, create it
        QSqlQuery createTableQuery(db);
        createTableQuery.prepare("CREATE TABLE IF NOT EXISTS items ("
                                 "item_id INTEGER PRIMARY KEY, "
                                 "category TEXT, "
                                 "model TEXT, "
                                 "price REAL, "
                                 "short_info TEXT, "
                                 "photo_path TEXT, "
                                 "count_store REAL)");

        if (!createTableQuery.exec()) {
            qDebug() << "Error creating 'items' table:" << createTableQuery.lastError().text();
            return 1;
        }

        insertOrUpdateSampleData(db);
    }

    MainWindow mainWindow(&db);
    mainWindow.show();

    return a.exec();
}
