#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "printerpage.h"
#include "cartridgepage.h"
#include "inkpage.h"
#include <QFileDialog>
#include <QSettings>
#include <QMenu>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "ui_about_us.h"
#include "about_us.h"
#include "feedback.h"
#include "mytableform.h"
#include "ourshops.h"
#include "helpdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "loginform.h"


MainWindow::MainWindow(QSqlDatabase *db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), db(db) {
    ui->setupUi(this);
    LoginForm loginForm;
        connect(&loginForm, &LoginForm::userAuthenticated, this, &MainWindow::onUserAuthenticated);

        if (loginForm.exec() != QDialog::Accepted) {
            QApplication::quit();
            return;
    }
    //db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("shopbase.sqlite");


    if (!db->open()) {
        qDebug() << "Error: Unable to open database";
    }


    connect(ui->ytButton, &QPushButton::clicked, this, &MainWindow::openYouTubeLink);
    connect(ui->vkButton, &QPushButton::clicked, this, &MainWindow::openVkLink);
    connect(ui->tgButton, &QPushButton::clicked, this, &MainWindow::openTgLink);
    connect(ui->menu_2, &QMenu::aboutToShow, this, &MainWindow::About_uss);
    connect(ui->menu_3, &QMenu::aboutToShow, this, &MainWindow::FeedBack);
    connect(ui->menu_4, &QMenu::aboutToShow, this, &MainWindow::OurShops);
    connect(ui->menu_5, &QMenu::aboutToShow, this, &MainWindow::Helper);
    connect(ui->action_2, &QAction::triggered, this, &MainWindow::on_actionOpenTableForm_triggered);

    cartManager = new CartManager(this);
    printerPage = new PrinterPage(cartManager,db, this);
    cartridgePage = new CartridgePage(cartManager,db, this);
    inkPage = new InkPage(cartManager,db, this);

    this->cartManager = cartManager;
    printerPage->hide();
    cartridgePage->hide();
    inkPage->hide();

    setCentralWidget(ui->centralWidget);
    currentWidget = ui->centralWidget;

    addBackButton(printerPage);
    addBackButton(cartridgePage);
    addBackButton(inkPage);

    connect(ui->printerButton, &QPushButton::clicked, this, &MainWindow::showPrinterForm);
    connect(ui->cartridgeButton, &QPushButton::clicked, this, &MainWindow::showCartridgeForm);
    connect(ui->inkButton, &QPushButton::clicked, this, &MainWindow::showInkForm);

    // Загрузка настроек при запуске
    loadSettings();

    printerImagePath = "D:\\Shop-main\\shopy(26.11.2023)\\nsk.jpg";
    cartridgeImagePath = "D:\\Shop-main\\shopy(26.11.2023)\\car.png";
    inkImagePath = "D:\\Shop-main\\shopy(26.11.2023)\\ink.png";

    QImage printerImage(printerImagePath);
    QLabel *printerImageLabel = new QLabel(ui->centralWidget);
    printerImageLabel->setPixmap(QPixmap::fromImage(printerImage));
    printerImageLabel->setFixedHeight(170);
    printerImageLabel->setFixedWidth(183);
    printerImageLabel->move(50, 110);
    printerImageLabel->setStyleSheet("font-size: 20px;"
                                      "font-weight: bold;"
                                      "background-color: white;"
                                      "text-align: center;"
                                      "border: 2px solid black;"
                                      "border-radius: 5px;"
                                      "padding: 5px;");

    QImage printerImage2(cartridgeImagePath);
    QLabel *printerImageLabel2 = new QLabel(ui->centralWidget);
    printerImageLabel2->setPixmap(QPixmap::fromImage(printerImage2));
    printerImageLabel2->setFixedHeight(170);
    printerImageLabel2->setFixedWidth(183);
    printerImageLabel2->move(250, 110);
    printerImageLabel2->setStyleSheet("font-size: 20px;"
                                      "font-weight: bold;"
                                      "background-color: white;"
                                      "text-align: center;"
                                      "border: 2px solid black;"
                                      "border-radius: 5px;"
                                      "padding: 5px;");

    QImage printerImage3(inkImagePath);
    QLabel *printerImageLabel3 = new QLabel(ui->centralWidget);
    printerImageLabel3->setPixmap(QPixmap::fromImage(printerImage3));
    printerImageLabel3->setFixedHeight(170);
    printerImageLabel3->setFixedWidth(183);
    printerImageLabel3->move(450, 110);
    printerImageLabel3->setStyleSheet("font-size: 20px;"
                                      "font-weight: bold;"
                                      "background-color: white;"
                                      "text-align: center;"
                                      "border: 2px solid black;"
                                      "border-radius: 5px;"
                                      "padding: 5px;");

    connect(ui->cartButton, SIGNAL(clicked()), this, SLOT(onCartButtonClicked()));

    connect(&loginForm, &LoginForm::userAuthenticated, this, &MainWindow::onUserAuthenticated);

    if (loginForm.exec() != QDialog::Accepted) {
        QApplication::quit();
        return;
    }

}




void MainWindow::onCartButtonClicked() {
    cartManager->exec();
    cartManager->updatePrices(printerPage->printerPrices);

}

void MainWindow::onUserAuthenticated(bool isAdmin)
{
    qDebug() << "isAdmin: " << isAdmin;
    if (isAdmin) {
            ui->action_2->setVisible(true);
        } else {
            ui->action_2->setVisible(false);
        }
}

void MainWindow::on_actionOpenTableForm_triggered()
{
    if (db) {
        MyTableForm *tableForm = new MyTableForm(*db, printerPage,cartridgePage,inkPage, cartItems, cartManager, this);
        tableForm->show();

    } else {
        qDebug() << "Invalid database!";
    }
}


void MainWindow::About_uss()
{
    About_us *dg = new About_us();
    dg->show();
}
void MainWindow::FeedBack()
{
    feedback *dg2 = new feedback();
    dg2->show();
}
void MainWindow::OurShops()
{
    ourshops *dg3 = new ourshops();
    dg3->show();
}

void MainWindow::Helper()
{
    HelpDialog *dg4 = new HelpDialog();
    dg4->show();
}
MainWindow::~MainWindow() {
    db->close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
    // Сохранение настроек при закрытии
    saveSettings();
    delete db;
    delete ui;
}

void MainWindow::showPrinterForm() {
    switchForm(printerPage);
}

void MainWindow::showCartridgeForm() {
    switchForm(cartridgePage);
}

void MainWindow::showInkForm() {
    switchForm(inkPage);
}

void MainWindow::addBackButton(QWidget *page) {
    QPushButton *backButton = new QPushButton("Назад", page);
    backButton->setGeometry(10, 20, 75, 30);
    connect(backButton, &QPushButton::clicked, this, &MainWindow::goBack);
}

void MainWindow::switchForm(QWidget *newForm) {

    currentWidget->hide();
    newForm->show();
    currentWidget = newForm;

     // Проверяем тип новой формы и скрываем QMenuBar при необходимости
        if (dynamic_cast<PrinterPage*>(newForm) || dynamic_cast<CartridgePage*>(newForm)|| dynamic_cast<InkPage*>(newForm)) {
            ui->menuBar->setVisible(false);
        } else {
            ui->menuBar->setVisible(true);
        }
}


void MainWindow::goBack() {
    currentWidget->hide();
    currentWidget = ui->centralWidget;
    currentWidget->show();

    // При возвращении на главную форму, восстанавливаем видимость QMenuBar
    ui->menuBar->setVisible(true);
}


void MainWindow::loadSettings() {
    QSettings settings("MyCompany", "MyAwesomeApp");

    printerImagePath = settings.value("printerImagePath", "D:\\Shop-main\\shopy(26.11.2023)\\printer.png").toString();
    cartridgeImagePath = settings.value("cartridgeImagePath", "D\\Shop-main\\shopy(26.11.2023)\\car.png").toString();
    inkImagePath = settings.value("inkImagePath", "D:\\Shop-main\\shopy(26.11.2023)\\ink.png").toString();
}

void MainWindow::saveSettings() {
    QSettings settings("MyCompany", "MyAwesomeApp");

    settings.setValue("printerImagePath", printerImagePath);
    settings.setValue("cartridgeImagePath", cartridgeImagePath);
    settings.setValue("inkImagePath", inkImagePath);
}
