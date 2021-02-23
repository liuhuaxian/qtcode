#include "FindDialog.h"
#include <QEvent>
#include <QTextCursor>
#include <QMessageBox>

FindDialog::FindDialog(QWidget *parent, QPlainTextEdit* pText)
    : QDialog(parent, Qt::WindowCloseButtonHint | Qt::Drawer)
{
    initControl();
    connectSlot();
    setLayout(&m_layout);
    setWindowTitle("Find");
    setPlainTextEdit(pText);
}

void FindDialog::initControl()
{
    m_findLbl.setText("Find What:");
    m_findBtn.setText("Find Next");
    m_closeBtn.setText("Close");
    m_matchChkBx.setText("Match Case");
    m_backwardBtn.setText("Backward");
    m_forwardBtn.setText("Forward");
    m_forwardBtn.setChecked(true);
    m_radioGrpBx.setTitle("Direction");

    m_hbLayout.addWidget(&m_forwardBtn);
    m_hbLayout.addWidget(&m_backwardBtn);

    m_radioGrpBx.setLayout(&m_hbLayout);

    m_layout.setSpacing(10);
    m_layout.addWidget(&m_findLbl, 0, 0);
    m_layout.addWidget(&m_findEdit, 0, 1);
    m_layout.addWidget(&m_findBtn, 0, 2);
    m_layout.addWidget(&m_matchChkBx, 1, 0);
    m_layout.addWidget(&m_radioGrpBx, 1, 1);
    m_layout.addWidget(&m_closeBtn, 1, 2);

}

void FindDialog::connectSlot()
{
    connect(&m_findBtn, SIGNAL(clicked()), this, SLOT(onFindClicked()));
    connect(&m_closeBtn, SIGNAL(clicked()), this, SLOT(onCloseClicked()));
}

void FindDialog::setPlainTextEdit(QPlainTextEdit* pText)
{
    m_pText = pText;
}

QPlainTextEdit* FindDialog::getPlainTextEdit()
{
    return m_pText;
}

bool FindDialog::event(QEvent* evt)
{
    if( evt->type() == QEvent::Close )
    {
        hide();

        return true;
    }

    return QDialog::event(evt);
}

void FindDialog::onFindClicked()
{
    QString target = m_findEdit.text();

    if( (m_pText != NULL) && (target != "") )
    {
        QString text = m_pText->toPlainText(); //获取文本字串串对象
        QTextCursor c = m_pText->textCursor(); //获取文本光标对象
        int index = -1;

        if( m_forwardBtn.isChecked() )
        {
            //查找target所代表的字符串的所在的位置。
            index = text.indexOf(target, c.position(), m_matchChkBx.isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);

            if( index >= 0 )
            {
                c.setPosition(index, QTextCursor::MoveAnchor); //将光标移动到index所指定的位置
                c.setPosition(index + target.length(), QTextCursor::KeepAnchor); //保持光标当前位置设置成anchor，将光标显示的范围设置在index和index+target.length()之间

                m_pText->setTextCursor(c);
            }
        }

        if( m_backwardBtn.isChecked() )
        {
            index = text.lastIndexOf(target, c.position() - text.length() - 1, m_matchChkBx.isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);

            if( index >= 0 )
            {
                c.setPosition(index + target.length(), QTextCursor::MoveAnchor);
                c.setPosition(index, QTextCursor::KeepAnchor);

                m_pText->setTextCursor(c);
            }
        }

        if( index < 0 )
        {
            QMessageBox msg(this);

            msg.setWindowTitle("Find");
            msg.setText("Can not find \"" + target + "\" any more...");
            msg.setIcon(QMessageBox::Information);
            msg.setStandardButtons(QMessageBox::Ok);

            msg.exec();
        }
    }
}

void FindDialog::onCloseClicked()
{
    close();
}
