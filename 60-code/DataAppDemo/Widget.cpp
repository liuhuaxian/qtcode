#include "Widget.h"
#include "ScoreInfo.h"
#include "DataSource.h"
#include <QMessageBox>
#include <QEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //设置视图的大小及其位置
    m_view.setParent(this);
    m_view.move(10, 10);
    m_view.resize(345, 180);

    //视图安装事件过滤器。
    m_view.installEventFilter(this);

    m_refreshBtn.setParent(this);
    m_refreshBtn.move(10, 200);
    m_refreshBtn.resize(95, 30);
    m_refreshBtn.setText("Refresh");

    m_clearBtn.setParent(this);
    m_clearBtn.move(135, 200);
    m_clearBtn.resize(95, 30);
    m_clearBtn.setText("Clear");

    m_scoreBtn.setParent(this);
    m_scoreBtn.move(260, 200);
    m_scoreBtn.resize(95, 30);
    m_scoreBtn.setText("Score");

    m_menu.addAction("Delete");//给下拉菜单添加动作



    m_model.setView(m_view); //连接模型与视图

    connect(&m_refreshBtn, SIGNAL(clicked()), this, SLOT(onRefreshBtnClicked()));
    connect(&m_clearBtn, SIGNAL(clicked()), this, SLOT(onClearBtnClicked()));
    connect(&m_scoreBtn, SIGNAL(clicked()), this, SLOT(onScoreBtnClicked()));
    connect(m_menu.actions()[0], SIGNAL(triggered()), this, SLOT(onDeleteActionClicked()));

    onRefreshBtnClicked();
}

//删除当前所在的行
void Widget::onDeleteActionClicked()
{
    m_model.remove(m_view.currentIndex().row());
}

void Widget::onRefreshBtnClicked()
{
    DataSource ds;

    m_model.clear();

    if( ds.setDataPath("E:/github/qtcode/60-code/DataAppDemo/test.txt") )
    {
        m_model.add(ds.fetchData());
    }
    else
    {
        QMessageBox::critical(this, "Error", "Data source read error!", QMessageBox::Ok);
    }
}

void Widget::onClearBtnClicked()
{
    m_model.clear();
}

void Widget::onScoreBtnClicked()
{
    int min = 256;
    int max = 0;
    int average = 0;

    if( m_model.count() > 0 )
    {
        for(int i=0; i<m_model.count(); i++)
        {
            ScoreInfo info = m_model.getItem(i);

            if( info.score() < min )
            {
                min = info.score();
            }

            if( info.score() > max )
            {
                max = info.score();
            }

            average += info.score();
        }

        average /= m_model.count();

        QMessageBox::information(this, "Statistic", QString().sprintf("Min: %d\nMax: %d\nAverage: %d", min, max, average), QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this, "Statistic", "No data record!", QMessageBox::Ok);
    }
}

//按菜单按钮或单击鼠标右键将导致发送事件QEvent::ContextMenu。
//事件过滤器，需要对象进行安装事件过滤器，否则不会生效
bool Widget::eventFilter(QObject* obj, QEvent* evt)
{
    if( (obj == &m_view) && (evt->type() == QEvent::ContextMenu) )
    {
        m_menu.exec(cursor().pos());//在当前位置显示便签
    }

    return QWidget::eventFilter(obj, evt);
}

Widget::~Widget()
{
    
}
