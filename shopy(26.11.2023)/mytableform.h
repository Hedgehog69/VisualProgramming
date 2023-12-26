#ifndef MYTABLEFORM_H
#define MYTABLEFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QPointer>
#include <QDateTime>
#include "helpdialog.h"

class CartManager;

class PrinterPage;

class CartridgePage;

class InkPage;

namespace Ui {
class MyTableForm;
}

class MyTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyTableForm(QSqlDatabase db, PrinterPage* printerPage,CartridgePage* cartridgePage,InkPage* inkPage, QHash<QString, QPair<double, int>> &cartItems, CartManager* cartManager, QWidget *parent = nullptr);
    ~MyTableForm();

signals:
    void dataChanged();

private slots:
    void onSaveButtonClicked();
    void onCloseButtonClicked();
    void onDeleteButtonClicked();
    void onAddButtonClicked();
    void onQuestButtonClicked();
    void onSearchTextChanged(const QString &text);

private:
    Ui::MyTableForm *ui;
    QSqlTableModel *tableModel;
    PrinterPage* printerPage;
    CartridgePage* cartridgePage;
    InkPage* inkPage;
    CartManager* cartManager;
    QDateTime lastUpdateTimestamp;
    QHash<QString, QPair<double, int>> &cartItems;
    HelpDialog *helpDialog;
};

#endif // MYTABLEFORM_H
