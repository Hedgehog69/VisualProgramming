/********************************************************************************
** Form generated from reading UI file 'ourshops.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OURSHOPS_H
#define UI_OURSHOPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ourshops
{
public:

    void setupUi(QWidget *ourshops)
    {
        if (ourshops->objectName().isEmpty())
            ourshops->setObjectName(QStringLiteral("ourshops"));
        ourshops->resize(471, 360);

        retranslateUi(ourshops);

        QMetaObject::connectSlotsByName(ourshops);
    } // setupUi

    void retranslateUi(QWidget *ourshops)
    {
        ourshops->setWindowTitle(QApplication::translate("ourshops", "\320\235\320\260\321\210\320\270 \320\274\321\203\320\267\320\265\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ourshops: public Ui_ourshops {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OURSHOPS_H
