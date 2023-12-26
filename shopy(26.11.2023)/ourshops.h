#ifndef OURSHOPS_H
#define OURSHOPS_H

#include <QWidget>

namespace Ui {
class ourshops;
}

class ourshops : public QWidget
{
    Q_OBJECT

public:
    explicit ourshops(QWidget *parent = nullptr);
    ~ourshops();

private:
    Ui::ourshops *ui;
};

#endif // OURSHOPS_H
