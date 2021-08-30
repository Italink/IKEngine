#include "IkFloat.h"
#include <IkItem/Widgets/NumberBox.h>

namespace IKEngine {
QWidget *IkFloat::createWidget()
{
    NumberBox* box=new NumberBox(getVar().toDouble(),2);
    QObject::connect(box,&NumberBox::valueChanged,this,[this](float var){
        setVar(var);
    });
    return box;
}
}
