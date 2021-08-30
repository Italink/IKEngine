#include "IkFactroy.h"
#include "IkItem.h"
#include <QHBoxLayout>
#include <QLineEdit>

namespace IKEngine {

IkItem::IkItem(QObject* ikObject, QMetaProperty ikVar, QObject *parent)
    : QObject(parent)
    , ikObject_(ikObject)
    , ikVar_(ikVar)
{
    setText(0,QString(ikVar.name()).replace("_"," "));
}

QWidget *IkItem::createWidget()
{
    return nullptr;
}

void IkItem::setUp(QTreeWidgetItem *tree)
{
    QWidget *widget=new QWidget;
    QHBoxLayout *layout=new QHBoxLayout(widget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(10,2,10,2);
    layout->addWidget(createWidget());
    tree->addChild(this);
    treeWidget()->setItemWidget(this,1,widget);
}

void IkItem::setUp(QTreeWidget *tree)
{
    QWidget *widget=new QWidget;
    QHBoxLayout *layout=new QHBoxLayout(widget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(10,2,10,2);
    layout->addWidget(createWidget());
    tree->addTopLevelItem(this);
    treeWidget()->setItemWidget(this,1,widget);
}

void IkItem::rename()
{
    if(!ikObject_->dynamicPropertyNames().contains(ikVar_.name())){
        return;
    }
    QLineEdit *lineEdit=new QLineEdit;
    treeWidget()->setItemWidget(this,0,lineEdit);
    lineEdit->setText(text(0));
    lineEdit->selectAll();
    lineEdit->setFocus();
    connect(lineEdit,&QLineEdit::editingFinished,this,[this,lineEdit](){
        QVariant var=getVar();
        ikObject_->setProperty(ikVar_.name(),QVariant());    //remove
        ikObject_->setProperty(lineEdit->text().toLocal8Bit().data(),var);
        int newIndex=ikObject_->metaObject()->indexOfProperty(lineEdit->text().toLocal8Bit().data());
        ikVar_=ikObject_->metaObject()->property(newIndex);
        treeWidget()->removeItemWidget(this,0);
        lineEdit->deleteLater();
    });
}

void IkItem::setVar(QVariant var)
{
    ikObject_->setProperty(ikVar_.name(),var);
}

QVariant IkItem::getVar()
{
    return ikObject_->property(ikVar_.name());
}

}
