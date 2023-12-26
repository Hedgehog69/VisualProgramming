/********************************************************************************
** Form generated from reading UI file 'inkpage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INKPAGE_H
#define UI_INKPAGE_H

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

class Ui_InkPage
{
public:
    QPushButton *cartButton;
    QGridLayout *gridLayout;
    QLabel *printerfon;
    QVBoxLayout *verticalLayout;
    QLabel *printerfon2;

    void setupUi(QWidget *InkPage)
    {
        if (InkPage->objectName().isEmpty())
            InkPage->setObjectName(QStringLiteral("InkPage"));
        InkPage->resize(698, 550);
        cartButton = new QPushButton(InkPage);
        cartButton->setObjectName(QStringLiteral("cartButton"));
        cartButton->setGeometry(QRect(560, 20, 101, 28));
        gridLayout = new QGridLayout(InkPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        printerfon = new QLabel(InkPage);
        printerfon->setObjectName(QStringLiteral("printerfon"));

        gridLayout->addWidget(printerfon, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        printerfon2 = new QLabel(InkPage);
        printerfon2->setObjectName(QStringLiteral("printerfon2"));

        gridLayout->addWidget(printerfon2, 2, 0, 1, 1);

        printerfon->raise();
        cartButton->raise();
        printerfon2->raise();

        retranslateUi(InkPage);

        QMetaObject::connectSlotsByName(InkPage);
    } // setupUi

    void retranslateUi(QWidget *InkPage)
    {
        InkPage->setWindowTitle(QApplication::translate("InkPage", "\320\247\320\265\321\200\320\275\320\270\320\273\320\260", nullptr));
        cartButton->setText(QApplication::translate("InkPage", "\320\221\320\270\320\273\320\265\321\202\321\213", nullptr));
        printerfon->setText(QString());
        printerfon2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class InkPage: public Ui_InkPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INKPAGE_H
