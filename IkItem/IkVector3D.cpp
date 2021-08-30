#include "IkVector3D.h"
#include <IkItem/Widgets/NumberBox.h>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QVector3D>

namespace IKEngine {

QWidget *IkVector3D::createWidget()
{
    QWidget* widget=new QWidget;
    QHBoxLayout* layout=new QHBoxLayout(widget);
    QVector3D vec=getVar().value<QVector3D>();
    QDoubleSpinBox *sbX=new QDoubleSpinBox();
    QDoubleSpinBox *sbY=new QDoubleSpinBox();
    QDoubleSpinBox *sbZ=new QDoubleSpinBox();
    sbX->setSingleStep(0.05);
    sbY->setSingleStep(0.05);
    sbZ->setSingleStep(0.05);
    layout->setMargin(0);
    layout->addWidget(sbX);
    layout->addWidget(sbY);
    layout->addWidget(sbZ);
    sbX->setValue(vec.x());
    sbY->setValue(vec.y());
    sbZ->setValue(vec.z());
    connect(sbX,static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,sbX,sbY,sbZ](double){
        QVector3D vec(sbX->value(),sbY->value(),sbZ->value());
        setValue(vec);
    });
    connect(sbY,static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,sbX,sbY,sbZ](double){
        QVector3D vec(sbX->value(),sbY->value(),sbZ->value());
        setValue(vec);
    });
    connect(sbZ,static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,sbX,sbY,sbZ](double){
        QVector3D vec(sbX->value(),sbY->value(),sbZ->value());
        setValue(vec);
    });
    return widget;
}

}
