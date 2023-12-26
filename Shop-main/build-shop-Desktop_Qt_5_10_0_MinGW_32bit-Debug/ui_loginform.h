/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QCheckBox *userCheckBox;
    QCheckBox *adminCheckBox;
    QLabel *login;
    QLineEdit *usernameLabel;
    QLabel *pass;
    QLineEdit *passwordLabel;
    QPushButton *loginButton;

    void setupUi(QWidget *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QStringLiteral("LoginForm"));
        LoginForm->resize(461, 245);
        gridLayout = new QGridLayout(LoginForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(LoginForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 1, 1, 2);

        userCheckBox = new QCheckBox(LoginForm);
        userCheckBox->setObjectName(QStringLiteral("userCheckBox"));

        gridLayout->addWidget(userCheckBox, 1, 1, 1, 1);

        adminCheckBox = new QCheckBox(LoginForm);
        adminCheckBox->setObjectName(QStringLiteral("adminCheckBox"));

        gridLayout->addWidget(adminCheckBox, 1, 2, 1, 1);

        login = new QLabel(LoginForm);
        login->setObjectName(QStringLiteral("login"));

        gridLayout->addWidget(login, 2, 0, 1, 1);

        usernameLabel = new QLineEdit(LoginForm);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        gridLayout->addWidget(usernameLabel, 3, 0, 1, 3);

        pass = new QLabel(LoginForm);
        pass->setObjectName(QStringLiteral("pass"));

        gridLayout->addWidget(pass, 4, 0, 1, 1);

        passwordLabel = new QLineEdit(LoginForm);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        gridLayout->addWidget(passwordLabel, 5, 0, 1, 3);

        loginButton = new QPushButton(LoginForm);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        gridLayout->addWidget(loginButton, 6, 1, 1, 1);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QWidget *LoginForm)
    {
        LoginForm->setWindowTitle(QApplication::translate("LoginForm", "Authorization", nullptr));
        label->setText(QApplication::translate("LoginForm", "Choose who are you", nullptr));
        userCheckBox->setText(QApplication::translate("LoginForm", "User", nullptr));
        adminCheckBox->setText(QApplication::translate("LoginForm", "Administrator", nullptr));
        login->setText(QApplication::translate("LoginForm", "Login", nullptr));
        pass->setText(QApplication::translate("LoginForm", "Password", nullptr));
        loginButton->setText(QApplication::translate("LoginForm", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
