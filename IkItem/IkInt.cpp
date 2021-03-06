#include "IkInt.h"
#include <IkItem/Widgets/NumberBox.h>

namespace IKEngine {
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
}
