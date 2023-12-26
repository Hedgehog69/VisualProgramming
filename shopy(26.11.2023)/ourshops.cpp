#include "ourshops.h"
#include "ui_ourshops.h"
#include <QTextBrowser>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>

struct PickupPoint {
    QString name;
    QString address;
    QString schedule;
    QString phoneNumber;
};

std::vector<PickupPoint> pickupPoints = {
    {"Центральный государственный музей РК", "Республика Казахстан, Алматы,  мк-н Самал-1, д. 44",
     " СР-ПН 9:00 - 18:00 (касса: 09:00 - 17:30), ВТ - выходной.", "+7(727)264-26-80"},
    {"Музей искусств имени Абылайхана Кастеева/\"", "Республика Казахстан, Алматы, мкр. Коктем–3, д. 22/1", "ВТ-ВС 10:00-18:00", " +7(727)394-57-15"},
    {"Республиканский музей музыкальных инструментов имени Ыкыласа\"\"", "Республика Казахстан, Алматы, ул. Зенкова, 24а",
     "Ежедневно c 10:00 до 19:00", "+ 7(272)91-69-17"},
    {"Музей Первого президента РК\"\"", " Республика Казахстан, Астана, ул. Бокейхана 1А",
     "Ежедневно с 11:00 до 19:00, перерыв 12:00-13:00", "+7(747)095-07-13"},
    {"Музей памяти жертв политических репрессий п.Долинка", "Республика Казахстан, п.Долинка, ул. Школьная, 39", " с 9.00 до 18.00, выходной – понедельник; обед: 13.00–14.00 ч.", "+7(721)565-82-22"},

};


ourshops::ourshops(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ourshops)
{
    ui->setupUi(this);

    // Создаем виджеты для отображения результатов и ввода текста
    QTextBrowser *resultBrowser = new QTextBrowser(this);
    QLineEdit *searchLineEdit = new QLineEdit(this);
    searchLineEdit->setPlaceholderText("Поиск по музеям");
    // Создаем метку для подсказки поиска
    QLabel *searchLabel = new QLabel("Адреса музеев", this);
    searchLabel->setStyleSheet("border: none; background-color:none;");
    // Создаем компоновщик и устанавливаем его для основного виджета
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(searchLabel);
    layout->addWidget(searchLineEdit);
    layout->addWidget(resultBrowser);

    // Формируем текст для отображения всех магазинов
    QString resultText;
    for (const auto& point : pickupPoints) {
        resultText += "Название: " + point.name + "\n";
        resultText += "Адрес: " + point.address + "\n";
        resultText += "Расписание: " + point.schedule + "\n";
        resultText += "Телефон: " + point.phoneNumber + "\n";
        resultText += "---------------------------------------------------------------------------------\n";
    }
    resultBrowser->setText(resultText);

    // Пример использования функции поиска при вводе текста
    connect(searchLineEdit, &QLineEdit::textChanged, [=](const QString& searchString){
         QString searchStr = searchString.toLower();
        // Фильтрация результатов поиска
        std::vector<PickupPoint> results;
        for (const auto& point : pickupPoints) {
            if (point.name.contains(searchString, Qt::CaseInsensitive) ||
                point.address.contains(searchString, Qt::CaseInsensitive)) {
                results.push_back(point);
            }
        }

        // Формируем текст для отображения результатов
        QString filteredResultText;
        for (const auto& result : results) {
            filteredResultText += "Название: " + result.name + "\n";
            filteredResultText += "Адрес: " + result.address + "\n";
            filteredResultText += "Расписание: " + result.schedule + "\n";
            filteredResultText += "Телефон: " + result.phoneNumber + "\n";
            filteredResultText += "---------------------------\n";
        }

        resultBrowser->setText(filteredResultText);
    });
}

ourshops::~ourshops()
{
    delete ui;
}
