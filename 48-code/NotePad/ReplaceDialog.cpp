#include "ReplaceDialog.h"

ReplaceDialog::ReplaceDialog(QWidget *parent,  QPlainTextEdit* pText) :
    FindDialog(parent, pText)
{
    initControl();
    connectSlot();
    setWindowTitle("Replace");
}

void ReplaceDialog::initControl()
{
    m_replaceLbl.setText("Replace To:");
    m_replaceBtn.setText("Replace");
    m_replaceAllBtn.setText("Replace All");

    m_layout.removeWidget(&m_matchChkBx);
    m_layout.removeWidget(&m_radioGrpBx);
    m_layout.removeWidget(&m_closeBtn);

    m_layout.addWidget(&m_replaceLbl, 1, 0);
    m_layout.addWidget(&m_replaceEdit, 1, 1);
    m_layout.addWidget(&m_replaceBtn, 1, 2);
    m_layout.addWidget(&m_matchChkBx, 2, 0);
    m_layout.addWidget(&m_radioGrpBx, 2, 1);
    m_layout.addWidget(&m_replaceAllBtn, 2, 2);
    m_layout.addWidget(&m_closeBtn, 3, 2);
}

void ReplaceDialog::connectSlot()
{
    connect(&m_replaceBtn, SIGNAL(clicked()), this, SLOT(onReplaceClicked()));
    connect(&m_replaceAllBtn, SIGNAL(clicked()), this, SLOT(onReplaceAllClicked()));
}

void ReplaceDialog::onReplaceClicked()
{
    QString target = m_findEdit.text();
    QString to = m_replaceEdit.text();

    if( (m_pText != NULL) && (target != "") && (to != "") )
    {
        //获取光标标识的文本内容
        QString selText = m_pText->textCursor().selectedText();

        //判断光标标识的文本内容是否为target。
        if( selText == target )
        {
            //将光标标识的内容替换为目标内容to
            m_pText->insertPlainText(to);
        }

        //直接调用查找槽函数，继续查找下一个目标字符
        onFindClicked();
    }
}

void ReplaceDialog::onReplaceAllClicked()
{
    QString target = m_findEdit.text();
    QString to = m_replaceEdit.text();

    if( (m_pText != NULL) && (target != "") && (to != "") )
    {
        QString text = m_pText->toPlainText();

        text.replace(target, to, m_matchChkBx.isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);

        //先将文本主编辑框清空内容，再将更换好的文本内容填入对话框中。
        m_pText->clear();

        m_pText->insertPlainText(text);
    }
}
