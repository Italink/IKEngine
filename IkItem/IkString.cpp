#include "IkString.h"
#include <QLineEdit>
IK_ITEM_BINDER(QString,IkString)
IkString::IkString(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}

QWidget *IkString::createWidget()
{
    QLineEdit* edit=new QLineEdit(getVar().toString());
    QObject::connect(edit,&QLineEdit::textChanged,this,[this](QString var){
        setVar(var);
    });
    return edit;
}
