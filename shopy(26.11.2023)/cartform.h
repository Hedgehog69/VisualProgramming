// cartform.h
#pragma once

#include <QWidget>

namespace Ui {
class CartForm;
}

class CartForm : public QWidget {
    Q_OBJECT

public:
    explicit CartForm(QWidget* parent = nullptr);
    ~CartForm();

public slots:
    void updateCartInfo();

private:
    Ui::CartForm* ui;
};
