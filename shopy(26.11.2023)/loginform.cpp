#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>
#include <QCloseEvent>

LoginForm::LoginForm(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::LoginForm)
{
    ui->setupUi(this);
    on_adminCheckBox_toggled(false);
    ui->usernameLabel->setVisible(false);
    ui->passwordLabel->setVisible(false);
    ui->login->setVisible(false);
    ui->pass->setVisible(false);
    ui->passwordLabel->setEchoMode(QLineEdit::Password);
    connect(ui->adminCheckBox, &QCheckBox::toggled, this, &LoginForm::on_adminCheckBox_toggled);
    connect(ui->loginButton, &QPushButton::click, this, &LoginForm::on_loginButton_clicked);
    connect(ui->adminCheckBox, &QCheckBox::stateChanged, this, &LoginForm::onCheckBoxStateChanged);
    connect(ui->userCheckBox, &QCheckBox::stateChanged, this, &LoginForm::onCheckBoxStateChanged);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_loginButton_clicked()
{
    QString enteredUsername = ui->usernameLabel->text();
    QString enteredPassword = ui->passwordLabel->text();

    if (ui->adminCheckBox->isChecked()) {
        if (enteredUsername == "Vladislav" && enteredPassword == "115") {
            emit userAuthenticated(true);
            emit authenticationSuccess();
            accept();
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password for admin.");
        }
    } else {
        emit userAuthenticated(false);
        emit authenticationSuccess();
        accept();
    }
}

void LoginForm::on_adminCheckBox_toggled(bool checked)
{
    ui->usernameLabel->setVisible(checked);
    ui->passwordLabel->setVisible(checked);
    ui->login->setVisible(checked);
    ui->pass->setVisible(checked);
}
void LoginForm::onCheckBoxStateChanged(int state)
{
    if (state == Qt::Checked) {
        if (sender() == ui->adminCheckBox) {
            ui->userCheckBox->setChecked(false);
        } else if (sender() == ui->userCheckBox) {
            ui->adminCheckBox->setChecked(false);
        }
    }
}

