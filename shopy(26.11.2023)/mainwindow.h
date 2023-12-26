#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QStack>
#include "printerpage.h"
#include "cartridgepage.h"
#include "inkpage.h"
#include "cartform.h"
#include <printer.h>
#include "buydialog.h"
#include <QGraphicsItem>
#include <QMainWindow>
#include <QList>
#include <QtSql/QSqlDatabase>
#include "cartmanager.h"
#include "mytableform.h"
#include "loginform.h"
#include <QDesktopServices>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase *db, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void openYouTubeLink() {
        QDesktopServices::openUrl(QUrl("https://www.youtube.com"));
    }
    void openVkLink() {
        QDesktopServices::openUrl(QUrl("https://vk.com"));
    }
    void openTgLink() {
        QDesktopServices::openUrl(QUrl("https://t.me/+nSUGaeEBXmphZTVi"));
    }

private slots:
    void showPrinterForm();
    void showCartridgeForm();
    void showInkForm();
    void goBack();
    void loadSettings();
    void saveSettings();
    void About_uss();
    void Helper();
    void FeedBack();
    void OurShops();
    void on_actionOpenTableForm_triggered();
    void onCartButtonClicked();
    void onUserAuthenticated(bool isAdmin);

private:
    QSqlDatabase *db;
    Ui::MainWindow *ui;
    QList<Printer> printers;
    PrinterPage *printerPage;
    CartridgePage *cartridgePage;
    InkPage *inkPage;
    QWidget *currentWidget;
    void addBackButton(QWidget *page);
    QStack<QWidget *> formHistory;
    void switchForm(QWidget *newForm);
    QString printerImagePath;
    QString cartridgeImagePath;
    QString inkImagePath;
    QHash<QString, QPair<double, int>> cartItems;
    CartManager* cartManager;
    MyTableForm* tableForm;
    QMap<QString, double> printerPrices;
};

#endif // MAINWINDOW_H
