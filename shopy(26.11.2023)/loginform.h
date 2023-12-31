#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>

namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void userAuthenticated(bool isAdmin);
    void authenticationSuccess();

private slots:
    void on_loginButton_clicked();
    void on_adminCheckBox_toggled(bool checked);
    void onCheckBoxStateChanged(int state);

private:
    Ui::LoginForm *ui;
};

#endif // LOGINFORM_H
