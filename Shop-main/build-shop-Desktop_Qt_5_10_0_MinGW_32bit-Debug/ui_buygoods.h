/********************************************************************************
** Form generated from reading UI file 'buygoods.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYGOODS_H
#define UI_BUYGOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_buygoods
{
public:
    QLabel *endlabel;
    QListWidget *cartinfolist;
    QLabel *oformlabel;
    QLabel *label;
    QTextEdit *name;
    QTextEdit *lastname;
    QTextEdit *phone;
    QLabel *label2;
    QTextEdit *address;
    QLabel *label3;
    QTextEdit *number;
    QPushButton *payButton;
    QDateEdit *dateEdit;

    void setupUi(QWidget *buygoods)
    {
        if (buygoods->objectName().isEmpty())
            buygoods->setObjectName(QStringLiteral("buygoods"));
        buygoods->resize(698, 550);
        endlabel = new QLabel(buygoods);
        endlabel->setObjectName(QStringLiteral("endlabel"));
        endlabel->setGeometry(QRect(9, 9, 16, 16));
        cartinfolist = new QListWidget(buygoods);
        cartinfolist->setObjectName(QStringLiteral("cartinfolist"));
        cartinfolist->setGeometry(QRect(20, 410, 651, 71));
        oformlabel = new QLabel(buygoods);
        oformlabel->setObjectName(QStringLiteral("oformlabel"));
        oformlabel->setGeometry(QRect(20, 10, 281, 41));
        label = new QLabel(buygoods);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 191, 31));
        name = new QTextEdit(buygoods);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(390, 100, 261, 25));
        lastname = new QTextEdit(buygoods);
        lastname->setObjectName(QStringLiteral("lastname"));
        lastname->setGeometry(QRect(40, 100, 261, 25));
        phone = new QTextEdit(buygoods);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(210, 150, 261, 25));
        label2 = new QLabel(buygoods);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(20, 190, 191, 31));
        address = new QTextEdit(buygoods);
        address->setObjectName(QStringLiteral("address"));
        address->setGeometry(QRect(40, 230, 401, 25));
        label3 = new QLabel(buygoods);
        label3->setObjectName(QStringLiteral("label3"));
        label3->setGeometry(QRect(20, 270, 191, 31));
        number = new QTextEdit(buygoods);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(40, 310, 261, 25));
        payButton = new QPushButton(buygoods);
        payButton->setObjectName(QStringLiteral("payButton"));
        payButton->setGeometry(QRect(260, 490, 201, 31));
        dateEdit = new QDateEdit(buygoods);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(330, 310, 110, 25));

        retranslateUi(buygoods);

        QMetaObject::connectSlotsByName(buygoods);
    } // setupUi

    void retranslateUi(QWidget *buygoods)
    {
        buygoods->setWindowTitle(QApplication::translate("buygoods", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        endlabel->setText(QString());
        oformlabel->setText(QApplication::translate("buygoods", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        label->setText(QApplication::translate("buygoods", "1. \320\224\320\260\320\275\320\275\321\213\320\265 \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", nullptr));
        name->setPlaceholderText(QApplication::translate("buygoods", "\320\230\320\274\321\217*", nullptr));
        lastname->setPlaceholderText(QApplication::translate("buygoods", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217*", nullptr));
        phone->setPlaceholderText(QApplication::translate("buygoods", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275*", nullptr));
        label2->setText(QApplication::translate("buygoods", "2. \320\224\320\276\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        address->setPlaceholderText(QApplication::translate("buygoods", "\320\220\320\264\321\200\320\265\321\201 \320\264\320\276\321\201\321\202\320\260\320\262\320\272\320\270*", nullptr));
        label3->setText(QApplication::translate("buygoods", "3. \320\236\320\277\320\273\320\260\321\202\320\260", nullptr));
        number->setPlaceholderText(QApplication::translate("buygoods", "\320\235\320\276\320\274\320\265\321\200 \320\261\320\260\320\275\320\272\320\276\320\262\321\201\320\272\320\276\320\271 \320\272\320\260\321\200\321\202\321\213*", nullptr));
        payButton->setText(QApplication::translate("buygoods", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class buygoods: public Ui_buygoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYGOODS_H
