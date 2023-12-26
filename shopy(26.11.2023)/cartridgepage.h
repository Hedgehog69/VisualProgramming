#ifndef CARTRIDGEPAGE_H
#define CARTRIDGEPAGE_H

#include <QWidget>
#include <QList>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QLabel>
#include <QXmlStreamAttribute>
#include <QSqlQuery>
#include "mytableform.h"
#include "cartmanager.h"
#include <QScrollArea>

namespace Ui {
class CartridgePage;
}

class CartridgePage : public QWidget {
    Q_OBJECT

public:
    explicit CartridgePage(CartManager *cartManager,QSqlDatabase *db, QWidget *parent = nullptr);
    ~CartridgePage();
    void loadPrintersFromDatabase();
    void readPricesFromDatabase();
    QMap<QString, double> printerPrices;

private slots:
    void buyCatridge(int index);
    void onCartButtonClicked() ;

public slots:
    void restoreCountStore(const QMap<QString, int> &itemsToRemove);

private:
    Ui::CartridgePage *ui;
    QSqlDatabase *db;
    CartManager* cartManager;

    QVector<QLineEdit*> modelLineEdits;
    QVector<QLineEdit*> priceDoubleSpinBoxes1;
    QVector<QTextEdit*> shortInfoTextEdits;
    QVector<QLabel*> photoLabels;
    QVector<QTextEdit*> countStores;
    QVector<QPushButton*> buyButtons;
    QMap<QString, QString> printerImages;
    void buyCatridge(const QString &itemName);
    void readCatridge(QSqlQuery &query);
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
};

#endif // CARTRIDGEPAGE_H
