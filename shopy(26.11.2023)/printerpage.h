#ifndef PRINTERPAGE_H
#define PRINTERPAGE_H

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
class PrinterPage;
}

class PrinterPage : public QWidget {
    Q_OBJECT

public:
    explicit PrinterPage(CartManager *cartManager,QSqlDatabase *db, QWidget *parent = nullptr);
    ~PrinterPage();
    Ui::PrinterPage *ui;
    void loadPrintersFromDatabase();
    void readPricesFromDatabase();
    QVector<QLineEdit*> modelLineEdits;
        QVector<QLineEdit*> priceDoubleSpinBoxes1;
        QVector<QTextEdit*> shortInfoTextEdits;
        QVector<QLabel*> photoLabels;
        QVector<QTextEdit*> countStores;
        QVector<QPushButton*> buyButtons;
        QMap<QString, double> printerPrices;

public slots:
    void restoreCountStore(const QMap<QString, int> &itemsToRemove);

private slots:
    void buyPrinter(int index);
    void onCartButtonClicked();

private:
    QMap<QString, QString> printerImages;
    void buyPrinter(const QString &itemName);
    void readPrinter(QSqlQuery &query);
    QSqlDatabase *db;
    CartManager* cartManager;
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
};

#endif // PRINTERPAGE_H
