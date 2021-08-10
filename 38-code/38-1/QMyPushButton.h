#ifndef _QMYPUSHBUTTON_H_
#define _QMYPUSHBUTTON_H_

#include <QPushButton>

typedef void (QButtonListener)(QObject*, QMouseEvent*);

class QMyPushButton : public QPushButton
{
    Q_OBJECT
protected:
    QButtonListener* m_listener; //自定义的事件处理函数

    void mouseReleaseEvent(QMouseEvent *e);
public:
    explicit QMyPushButton(QWidget* parent = 0, QButtonListener* listener = 0);
    
signals:
    
public slots:
    
};

#endif // _QMYPUSHBUTTON_H_
