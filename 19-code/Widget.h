#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton SimpleMsgBtn;
    QPushButton CustomMsgBtn;
    QPushButton OpenFileBtn;
    QPushButton SaveFileBtn;
    QPushButton ErrorMsgBtn;
    QPushButton ColorMsgBtn;
    QPushButton FontMsgBtn;
    QPushButton InputMsgBtn;
    QPushButton MessageBtn;
    QPushButton WizardMsgBtn;
    QPushButton ProgressMsgBtn;
private slots:
    void SimpleMsgBtn_Clicked();
    void CustomMsgBtn_Clicked();
    void OpenFileBtn_Clicked();
    void SaveFileBtn_Clicked();
    void ErrorMsgBtn_Clicked();
    void ColorMsgBtn_Clicked();
    void FontMsgBtn_Clicked();
    void InputMsgBtn_Clicked();
    void MessageBtn_Clicked();
    void WizardMsgBtn_Clicked();
    void ProgressMsgBtn_Clicked();
public:
    Widget(QWidget *parent = 0);
    void show();
    ~Widget();
};

#endif
