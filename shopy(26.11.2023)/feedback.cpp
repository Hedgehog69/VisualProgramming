#include "feedback.h"
#include "ui_feedback.h"
#include <QMessageBox>
#include <QRegExp>

feedback::feedback(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::feedback)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Тема обращения*");  // Подсказка
    ui->comboBox->addItem("Задать вопрос");
    ui->comboBox->addItem("Оставить жалобу");
    ui->comboBox->addItem("Внести предложение");

    ui->comboBox->setItemData(0, QVariant(0), Qt::UserRole - 1);

    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [=](int index){
        });
    connect(ui->sendButton, &QPushButton::clicked, this, &feedback::sendForms);
}

void feedback::sendForms() {
    QString topic = ui->comboBox->currentText();
    QString textEdit4 = ui->textEdit_4->toPlainText();
    QString textEdit5 = ui->textEdit_5->toPlainText();
    QString textEdit2 = ui->textEdit_2->toPlainText();

    // Регулярное выражение для проверки ввода email
    QRegExp emailRegExp("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b");

    // Проверка на заполненность обязательных полей и правильный формат email
    if (topic == "Тема обращения" || textEdit4.isEmpty() || !emailRegExp.exactMatch(textEdit5)) {

    } else {
        ui->textEdit_5->setStyleSheet("");
        ui->textEdit_5->setPlaceholderText("");
        QMessageBox::information(this, "Успех", "Ваш запрос отправлен. Ожидайте ответа от менеджера в течение часа.");
        this->close();
    }
    if (!emailRegExp.exactMatch(textEdit5)) {
        ui->textEdit_5->setStyleSheet("QTextEdit { border: 1px solid orange; }");
        ui->textEdit_5->setPlaceholderText("Укажите полный адрес электронной почты");
        QMessageBox::warning(this, "Ошибка", "Заполните адрес электронной почты корректно");
    }
    if (topic == "Тема обращения" || textEdit4.isEmpty()) {
        ui->textEdit_4->setStyleSheet("QTextEdit { border: 1px solid orange; }");
        QMessageBox::warning(this, "Ошибка", "Заполните все обязательные поля");
    }
}
feedback::~feedback()
{
    delete ui;
}
