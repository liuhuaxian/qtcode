#ifndef _QCALCULATORUI_H_
#define _QCALCULATORUI_H_

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class QCalculatorUI : public QWidget
{
private:
    QLineEdit* m_edit;
    QPushButton* m_buttons[20];

    QCalculatorUI();
    bool construct();
public:
    static QCalculatorUI* NewInstance();
    void show();
    ~QCalculatorUI();
};

#endif
