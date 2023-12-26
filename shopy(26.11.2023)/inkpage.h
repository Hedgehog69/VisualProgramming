#ifndef INKPAGE_H
#define INKPAGE_H


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
class InkPage;
}

class InkPage : public QWidget {
    Q_OBJECT

public:
    explicit InkPage(CartManager *cartManager,QSqlDatabase *db, QWidget *parent = nullptr);
    ~InkPage();
    void loadPrintersFromDatabase();
    void readPricesFromDatabase();

public slots:
    void restoreCountStore(const QMap<QString, int> &itemsToRemove);

private slots:
    void buyInk(int index);
    void onCartButtonClicked();

private:
    Ui::InkPage *ui;
    QSqlDatabase *db;
    CartManager* cartManager;
    QVector<QLineEdit*> modelLineEdits;
    QVector<QLineEdit*> priceDoubleSpinBoxes1;
    QVector<QTextEdit*> shortInfoTextEdits;
    QVector<QLabel*> photoLabels;
    QVector<QTextEdit*> countStores;
    QVector<QPushButton*> buyButtons;
    QMap<QString, QString> printerImages;
    QMap<QString, double> printerPrices;
    void buyInk(const QString &itemName);
    void readInk(QSqlQuery &query);
    QScrollArea* scrollArea;
    QWidget* scrollWidget;
};

#endif // INKPAGE_H
