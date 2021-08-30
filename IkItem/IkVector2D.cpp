#include "IkVector2D.h"
#include <IkItem/Widgets/NumberBox.h>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QVector2D>

namespace IKEngine {
QWidget *IkVector2D::createWidget()
{
    QWidget* widget=new QWidget;
    QHBoxLayout* layout=new QHBoxLayout(widget);
    QVector2D vec=getVar().value<QVector2D>();
    QDoubleSpinBox *sbX=new QDoubleSpinBox();
    QDoubleSpinBox *sbY=new QDoubleSpinBox();
    sbX->setSingleStep(0.05);
    sbY->setSingleStep(0.05);
    layout->setMargin(0);
    layout->addWidget(sbX);
    layout->addWidget(sbY);
    sbX->setValue(vec.x());
    sbY->setValue(vec.y());
    connect(sbX,static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,sbX,sbY](double){
        QVector2D vec(sbX->value(),sbY->value());
        setValue(vec);
    });
    connect(sbY,static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,sbX,sbY](double){
        QVector2D vec(sbX->value(),sbY->value());
        setValue(vec);
    });
    return widget;
}
}
