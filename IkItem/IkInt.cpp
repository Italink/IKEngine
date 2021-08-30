#include "IkInt.h"
#include <IkItem/Widgets/NumberBox.h>
IK_ITEM_BINDER(int,IkInt)
IkInt::IkInt(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}

QWidget *IkInt::createWidget()
{
    NumberBox* box=new NumberBox(getVar().toDouble(),0);
    QObject::connect(box,&NumberBox::valueChanged,this,[this](int var){
        setVar(var);
    });
    return box;
}
