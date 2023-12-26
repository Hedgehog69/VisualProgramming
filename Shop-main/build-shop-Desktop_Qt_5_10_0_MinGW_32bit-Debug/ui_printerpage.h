/********************************************************************************
** Form generated from reading UI file 'printerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTERPAGE_H
#define UI_PRINTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrinterPage
{
public:
    QGridLayout *gridLayout;
    QLabel *printerfon;
    QPushButton *cartButton;
    QFormLayout *formLayout;
    QLabel *printerfon2;

    void setupUi(QWidget *PrinterPage)
    {
        if (PrinterPage->objectName().isEmpty())
            PrinterPage->setObjectName(QStringLiteral("PrinterPage"));
        PrinterPage->resize(698, 550);
        gridLayout = new QGridLayout(PrinterPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        printerfon = new QLabel(PrinterPage);
        printerfon->setObjectName(QStringLiteral("printerfon"));

        gridLayout->addWidget(printerfon, 0, 0, 1, 1);

        cartButton = new QPushButton(PrinterPage);
        cartButton->setObjectName(QStringLiteral("cartButton"));

        gridLayout->addWidget(cartButton, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));

        gridLayout->addLayout(formLayout, 2, 0, 1, 1);

        printerfon2 = new QLabel(PrinterPage);
        printerfon2->setObjectName(QStringLiteral("printerfon2"));

        gridLayout->addWidget(printerfon2, 3, 0, 1, 1);

        printerfon->raise();
        cartButton->raise();
        printerfon2->raise();

        retranslateUi(PrinterPage);

        QMetaObject::connectSlotsByName(PrinterPage);
    } // setupUi

    void retranslateUi(QWidget *PrinterPage)
    {
        PrinterPage->setWindowTitle(QApplication::translate("PrinterPage", "\320\237\321\200\320\270\320\275\321\202\320\265\321\200", nullptr));
        printerfon->setText(QString());
        cartButton->setText(QApplication::translate("PrinterPage", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        printerfon2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PrinterPage: public Ui_PrinterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTERPAGE_H
