#include "helpdialog.h"
#include "ui_helpdialog.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QHBoxLayout>
#include <QPushButton>

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    ui->setupUi(this);

    textBrowser = new QTextBrowser(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textBrowser);

    backButton = new QPushButton("Назад", this);
    houmyButton = new QPushButton("На главную", this);
    forwardButton = new QPushButton("Вперёд", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(backButton);
    buttonLayout->addWidget(houmyButton);
    buttonLayout->addWidget(forwardButton);
    layout->addLayout(buttonLayout);

    connect(backButton, &QPushButton::clicked, this, &HelpDialog::goBack);
    connect(forwardButton, &QPushButton::clicked, this, &HelpDialog::goForward);
    connect(houmyButton, &QPushButton::clicked, this, &HelpDialog::goHome);  // Подключаем кнопку для возврата на главную

    setWindowTitle("Help");
    resize(800, 600);

    currentIndex = 0;
    loadPage(pages[currentIndex]);  // Загрузка стартовой страницы
}

void HelpDialog::goHome()
{
    currentIndex = 0;
    loadPage(pages[currentIndex]);
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

void HelpDialog::loadPage(const QString &page)
{
    QFile file(page);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        QString htmlContent = stream.readAll();
        textBrowser->setHtml(htmlContent);
        file.close();
    } else {
        textBrowser->setPlainText("Error loading " + page);
    }
}

void HelpDialog::goBack()
{
    if (currentIndex > 0) {
        currentIndex--;
        loadPage(pages[currentIndex]);
    }
}

void HelpDialog::goForward()
{
    if (currentIndex < pages.size() - 1) {
        currentIndex++;
        loadPage(pages[currentIndex]);
    }
}
