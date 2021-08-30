#include "IkEnum.h"
#include <QCheckBox>
#include <QComboBox>

IkEnum::IkEnum(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}

QWidget *IkEnum::createWidget()
{
    QComboBox* box=new QComboBox;
    for(int i=0;i<ikVar_.enumerator().keyCount();i++){
        box->addItem(ikVar_.enumerator().valueToKey(ikVar_.enumerator().value(i)));
    }
    connect(box,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,[this](int var){
        setVar(var);
    });
    return box;
}
