#include "IkDouble.h"
#include <IkItem/Widgets/NumberBox.h>

IK_ITEM_BINDER(double,IkDouble)
IkDouble::IkDouble(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}

QWidget *IkDouble::createWidget()
{
    NumberBox* box=new NumberBox(getVar().toDouble(),3);
    QObject::connect(box,&NumberBox::valueChanged,this,[this](double var){
        setVar(var);
    });
    return box;
}
