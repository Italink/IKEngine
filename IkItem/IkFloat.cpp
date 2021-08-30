#include "IkFloat.h"
#include <IkItem/Widgets/NumberBox.h>
IK_ITEM_BINDER(float,IkFloat)
QWidget *IkFloat::createWidget()
{
    NumberBox* box=new NumberBox(getVar().toDouble(),2);
    QObject::connect(box,&NumberBox::valueChanged,this,[this](float var){
        setVar(var);
    });
    return box;
}
