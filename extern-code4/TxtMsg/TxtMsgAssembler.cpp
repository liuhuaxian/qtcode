#include "TxtMsgAssembler.h"

TxtMsgAssembler::TxtMsgAssembler(QObject* parent) : QObject(parent)
{

}

void TxtMsgAssembler::clear()
{
    m_type = "";
    m_length = 0;
    m_data = "";
}

//因为此处是按照一个字符(8bit)解析为一个字串，所以此时的中文是无法按照此方法解析，因为中文不是一个字符(8bit)表示。
QString TxtMsgAssembler::fetch(int n)
{
    QString ret = "";

    for(int i=0; i<n; i++)
    {
        ret += m_queue.dequeue();
    }

    return ret;
}

void TxtMsgAssembler::prepare(const char* data, int len)
{
    if( data != NULL )
    {
        for(int i=0; i<len; i++)
        {
            m_queue.enqueue(data[i]);
        }
    }
}

QSharedPointer<TextMessage> TxtMsgAssembler::assemble()
{
    TextMessage* ret = NULL;
    bool tryMakeMsg = false;

    if( m_type == "" )
    {
        tryMakeMsg = makeTypeAndLength();
    }
    else
    {
        tryMakeMsg = true;
    }

    if( tryMakeMsg )
    {
        ret = makeMessage();
    }

    //不为空说明数据组装完成，清空本次的保存的数据。
    if( ret != NULL )
    {
        clear();
    }

    return QSharedPointer<TextMessage>(ret);
}

QSharedPointer<TextMessage> TxtMsgAssembler::assemble(const char* data, int len)
{
    prepare(data, len);

    return assemble();
}

bool TxtMsgAssembler::makeTypeAndLength()
{
    bool ret = (m_queue.length() >= 8);

    if( ret )
    {
        QString len = "";

        m_type = fetch(4);

        len = fetch(4);

        m_length = len.trimmed().toInt(&ret, 16);

        if( !ret )
        {
            clear();
        }
    }

    return ret;
}

TextMessage* TxtMsgAssembler::makeMessage()
{
    TextMessage* ret = NULL;

    if( m_type != "" )
    {
        int needed = m_length - m_data.length();
        int n = (needed <= m_queue.length()) ? needed : m_queue.length();

        m_data += fetch(n);

        //数据全部接收完毕 则组装。
        if( m_length == m_data.length() )
        {
            ret = new TextMessage(m_type, m_data);
        }
    }

    return ret;
}

void TxtMsgAssembler::reset()
{
    clear();
    m_queue.clear();
}
