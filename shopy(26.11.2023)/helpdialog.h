#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = nullptr);
    ~HelpDialog();

private slots:
    void goBack();
    void goForward();
    void goHome();

private:
    void loadPage(const QString &page);

    Ui::HelpDialog *ui;
    QTextBrowser *textBrowser;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QPushButton *houmyButton;

    QStringList pages = {
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index.html",
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index1.html",
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index2.html",
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index3.html",
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index4.html",
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index5.html",
        "D:/Shop-main/build-shop-Desktop_Qt_5_12_4_MinGW_32_bit-Debug/index6.html"
    };

    int currentIndex;
};

#endif // HELPDIALOG_H
