#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QWidget>
#include <QComboBox>

namespace Ui {
class feedback;
}

class feedback : public QWidget
{
    Q_OBJECT

public:
    explicit feedback(QWidget *parent = nullptr);
    ~feedback();

private:
    Ui::feedback *ui;
    void sendForms();

};

#endif // FEEDBACK_H
