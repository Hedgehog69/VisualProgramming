/********************************************************************************
** Form generated from reading UI file 'cartmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARTMANAGER_H
#define UI_CARTMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CartManager
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *cartlabel;
    QListWidget *cartList;
    QPushButton *removeButton;
    QPushButton *doneButton;
    QPushButton *closeButton;

    void setupUi(QWidget *CartManager)
    {
        if (CartManager->objectName().isEmpty())
            CartManager->setObjectName(QStringLiteral("CartManager"));
        CartManager->resize(698, 550);
        verticalLayout = new QVBoxLayout(CartManager);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cartlabel = new QLabel(CartManager);
        cartlabel->setObjectName(QStringLiteral("cartlabel"));

        verticalLayout->addWidget(cartlabel);

        cartList = new QListWidget(CartManager);
        cartList->setObjectName(QStringLiteral("cartList"));

        verticalLayout->addWidget(cartList);

        removeButton = new QPushButton(CartManager);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        verticalLayout->addWidget(removeButton);

        doneButton = new QPushButton(CartManager);
        doneButton->setObjectName(QStringLiteral("doneButton"));

        verticalLayout->addWidget(doneButton);

        closeButton = new QPushButton(CartManager);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        verticalLayout->addWidget(closeButton);


        retranslateUi(CartManager);

        QMetaObject::connectSlotsByName(CartManager);
    } // setupUi

    void retranslateUi(QWidget *CartManager)
    {
        CartManager->setWindowTitle(QApplication::translate("CartManager", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
        cartlabel->setText(QApplication::translate("CartManager", "\320\232\321\203\320\277\320\273\320\265\320\275\320\275\321\213\320\265 \320\261\320\270\320\273\320\265\321\202\321\213", nullptr));
        removeButton->setText(QApplication::translate("CartManager", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        doneButton->setText(QApplication::translate("CartManager", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214", nullptr));
        closeButton->setText(QApplication::translate("CartManager", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CartManager: public Ui_CartManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARTMANAGER_H
