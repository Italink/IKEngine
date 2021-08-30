#include "IkBool.h"
#include <QCheckBox>

namespace IKEngine {
IkBool::IkBool(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}

QWidget *IkBool::createWidget()
{
    QCheckBox* box=new QCheckBox();
    box->setChecked(getVar().toBool()?Qt::Checked:Qt::Unchecked);
    QObject::connect(box,&QCheckBox::toggled,this,[this](bool var){
        setVar(var);
    });
    return box;
}
}
