#include "CustomizedItemDelegate.h"
#include <QComboBox>
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>

CustomizedItemDelegate::CustomizedItemDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

QWidget* CustomizedItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget* ret = NULL;

    if( index.data().type() == QVariant::Char )
    {
        QComboBox* cb = new QComboBox(parent);

        cb->addItem("A");
        cb->addItem("B");
        cb->addItem("C");
        cb->addItem("D");

        ret = cb;
    }
    else
    {
        ret = QItemDelegate::createEditor(parent, option, index);
    }

    return ret;
}

void CustomizedItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

//根据用户选择的模型数据的index，设置委托的数据。
void CustomizedItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if( index.data().type() == QVariant::Char )
    {
        QComboBox* cb = dynamic_cast<QComboBox*>(editor);

        if( cb != NULL )
        {
            for(int i=0; i<cb->count(); i++)
            {
                if( cb->itemText(i) == index.data().toString() )
                {
                    cb->setCurrentIndex(i);
                    break;
                }
            }
        }
    }
    else
    {
        QItemDelegate::setEditorData(editor, index);
    }
}

//将委托中的数据，递交给模型数据中。
void CustomizedItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if( index.data().type() == QVariant::Char )
    {
        QComboBox* cb = dynamic_cast<QComboBox*>(editor);

        if( cb != NULL )
        {
            model->setData(index, cb->currentText().at(0), Qt::DisplayRole);
        }
    }
    else
    {
        QItemDelegate::setModelData(editor, model, index);
    }
}


//自定义绘制模型对应的视图样式。
void CustomizedItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //将模型中数据项为bool类型的显示框，使用自定的组件绘制出来。
    if( index.data().type() == QVariant::Bool )
    {
        bool data = index.data(Qt::DisplayRole).toBool();
        QStyleOptionButton checkBoxStyle;

        checkBoxStyle.state = data ? QStyle::State_On : QStyle::State_Off;
        checkBoxStyle.state |= QStyle::State_Enabled;
        checkBoxStyle.rect = option.rect;
        checkBoxStyle.rect.setX(option.rect.x() + option.rect.width() / 2 - 6);

        //QStyle是一个抽象类，其drawControl是纯虚函数怎么就直接调用了？？
        QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkBoxStyle, painter);
    }
    else
    {
        QItemDelegate::paint(painter, option, index);
    }
}

//当一个event的事件触发编辑操作时调用该函数。
bool CustomizedItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    bool ret = true;


    //当产生的是鼠标点击事件，并发发生该点击的事件为数据项为bool项的值中时。
    if( index.data().type() == QVariant::Bool )
    {
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(event);

        if( (event->type() == QEvent::MouseButtonPress) && option.rect.contains(mouseEvent->pos()) )
        {
            bool data = index.data(Qt::DisplayRole).toBool();

            qDebug() << "set model data: " << !data;
            qDebug() << model->setData(index, !data, Qt::DisplayRole);
        }
    }
    else
    {
        ret = QItemDelegate::editorEvent(event, model, option, index);
    }

    return ret;
}

