/********************************************************************************
** Form generated from reading UI file 'cartridgepage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTRIDGEPAGE_H
#define UI_CARTRIDGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CartridgePage
{
public:
    QPushButton *cartButton;
    QGridLayout *gridLayout;
    QLabel *printerfon;
    QVBoxLayout *verticalLayout;
    QLabel *printerfon2;

    void setupUi(QWidget *CartridgePage)
    {
        if (CartridgePage->objectName().isEmpty())
            CartridgePage->setObjectName(QStringLiteral("CartridgePage"));
        CartridgePage->resize(698, 550);
        cartButton = new QPushButton(CartridgePage);
        cartButton->setObjectName(QStringLiteral("cartButton"));
        cartButton->setGeometry(QRect(560, 20, 101, 28));
        gridLayout = new QGridLayout(CartridgePage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        printerfon = new QLabel(CartridgePage);
        printerfon->setObjectName(QStringLiteral("printerfon"));

        gridLayout->addWidget(printerfon, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        printerfon2 = new QLabel(CartridgePage);
        printerfon2->setObjectName(QStringLiteral("printerfon2"));

        gridLayout->addWidget(printerfon2, 2, 0, 1, 1);

        printerfon->raise();
        cartButton->raise();
        printerfon2->raise();

        retranslateUi(CartridgePage);

        QMetaObject::connectSlotsByName(CartridgePage);
    } // setupUi

    void retranslateUi(QWidget *CartridgePage)
    {
        CartridgePage->setWindowTitle(QApplication::translate("CartridgePage", "\320\232\320\260\321\200\321\202\321\200\320\270\320\264\320\266", nullptr));
        cartButton->setText(QApplication::translate("CartridgePage", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        printerfon->setText(QString());
        printerfon2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CartridgePage: public Ui_CartridgePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTRIDGEPAGE_H
