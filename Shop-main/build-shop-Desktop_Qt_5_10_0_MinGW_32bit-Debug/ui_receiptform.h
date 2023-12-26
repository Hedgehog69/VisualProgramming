/********************************************************************************
** Form generated from reading UI file 'receiptform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPTFORM_H
#define UI_RECEIPTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receiptform
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextEdit *receiptTextEdit;
    QPushButton *savingButton;
    QPushButton *homeButton;

    void setupUi(QWidget *receiptform)
    {
        if (receiptform->objectName().isEmpty())
            receiptform->setObjectName(QStringLiteral("receiptform"));
        receiptform->resize(400, 300);
        gridLayout = new QGridLayout(receiptform);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(receiptform);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        receiptTextEdit = new QTextEdit(receiptform);
        receiptTextEdit->setObjectName(QStringLiteral("receiptTextEdit"));

        gridLayout->addWidget(receiptTextEdit, 1, 0, 1, 2);

        savingButton = new QPushButton(receiptform);
        savingButton->setObjectName(QStringLiteral("savingButton"));

        gridLayout->addWidget(savingButton, 2, 0, 1, 1);

        homeButton = new QPushButton(receiptform);
        homeButton->setObjectName(QStringLiteral("homeButton"));

        gridLayout->addWidget(homeButton, 2, 1, 1, 1);


        retranslateUi(receiptform);

        QMetaObject::connectSlotsByName(receiptform);
    } // setupUi

    void retranslateUi(QWidget *receiptform)
    {
        receiptform->setWindowTitle(QApplication::translate("receiptform", "\320\247\320\265\320\272", nullptr));
        label->setText(QApplication::translate("receiptform", "\320\247\320\265\320\272", nullptr));
        savingButton->setText(QApplication::translate("receiptform", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        homeButton->setText(QApplication::translate("receiptform", "\320\232 \320\277\320\276\320\272\321\203\320\277\320\272\320\260\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receiptform: public Ui_receiptform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPTFORM_H
