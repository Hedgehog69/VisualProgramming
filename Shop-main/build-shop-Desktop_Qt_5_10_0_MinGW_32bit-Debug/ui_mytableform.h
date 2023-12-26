/********************************************************************************
** Form generated from reading UI file 'mytableform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTABLEFORM_H
#define UI_MYTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyTableForm
{
public:
    QLineEdit *searchLineEdit;
    QGridLayout *gridLayout;
    QLabel *labeltable;
    QTableView *tableView;
    QHBoxLayout *buttonss;
    QPushButton *closeButton2;
    QPushButton *saveButton;
    QPushButton *addButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *MyTableForm)
    {
        if (MyTableForm->objectName().isEmpty())
            MyTableForm->setObjectName(QStringLiteral("MyTableForm"));
        MyTableForm->resize(872, 550);
        searchLineEdit = new QLineEdit(MyTableForm);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));
        searchLineEdit->setGeometry(QRect(40, 10, 611, 21));
        gridLayout = new QGridLayout(MyTableForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labeltable = new QLabel(MyTableForm);
        labeltable->setObjectName(QStringLiteral("labeltable"));

        gridLayout->addWidget(labeltable, 0, 0, 2, 2);

        tableView = new QTableView(MyTableForm);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 1, 1, 1);

        buttonss = new QHBoxLayout();
        buttonss->setSpacing(14);
        buttonss->setObjectName(QStringLiteral("buttonss"));
        buttonss->setContentsMargins(150, -1, 150, -1);
        closeButton2 = new QPushButton(MyTableForm);
        closeButton2->setObjectName(QStringLiteral("closeButton2"));

        buttonss->addWidget(closeButton2);

        saveButton = new QPushButton(MyTableForm);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        buttonss->addWidget(saveButton);

        addButton = new QPushButton(MyTableForm);
        addButton->setObjectName(QStringLiteral("addButton"));

        buttonss->addWidget(addButton);

        deleteButton = new QPushButton(MyTableForm);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        buttonss->addWidget(deleteButton);


        gridLayout->addLayout(buttonss, 2, 0, 1, 2);

        labeltable->raise();
        tableView->raise();
        searchLineEdit->raise();

        retranslateUi(MyTableForm);

        QMetaObject::connectSlotsByName(MyTableForm);
    } // setupUi

    void retranslateUi(QWidget *MyTableForm)
    {
        MyTableForm->setWindowTitle(QApplication::translate("MyTableForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        searchLineEdit->setPlaceholderText(QApplication::translate("MyTableForm", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\216 \321\202\320\276\320\262\320\260\321\200\320\260 \320\264\320\273\321\217 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        labeltable->setText(QString());
        closeButton2->setText(QApplication::translate("MyTableForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveButton->setText(QApplication::translate("MyTableForm", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        addButton->setText(QApplication::translate("MyTableForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteButton->setText(QApplication::translate("MyTableForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyTableForm: public Ui_MyTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTABLEFORM_H
