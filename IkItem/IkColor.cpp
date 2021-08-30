#include "IkColor.h"
#include <QColorDialog>
#include <QPushButton>
IK_ITEM_BINDER(QColor,IkColor)
IkColor::IkColor(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}


QWidget *IkColor::createWidget()
{
    QPushButton *btColor=new  QPushButton;
    btColor->setMinimumWidth(100);
    btColor->setAutoFillBackground(true);

    btColor->setStyleSheet("background-color:"+getVar().value<QColor>().name(QColor::HexArgb)+";");
    connect(btColor,&QPushButton::clicked,this,[this,btColor](){
        QColorDialog dialog(getVar().value<QColor>());
        dialog.setOptions(QColorDialog::ShowAlphaChannel|QColorDialog::NoButtons);
        connect(&dialog,&QColorDialog::currentColorChanged,this,[this,btColor](const QColor&color){
            setVar(QVariant::fromValue<>(color));
            btColor->setStyleSheet("background-color:"+color.name(QColor::HexArgb)+";");
        });
        dialog.exec();

    });
    return btColor;
}
