#include <QHeaderView>
#include <QApplication>
#include <QTreeWidgetItem>
#include "IkItem.h"
#include "IkPanel.h"
#include "IkFactroy.h"
namespace IKEngine {

IkPanel::IkPanel(QObject* ikObject,QWidget *parent)
    : QTreeWidget(parent)
    , ikObject_(ikObject)
{
   initilizeUI();
   createPanel();
}

void IkPanel::initilizeUI()
{
//    setWindowFlag(Qt::WindowStaysOnTopHint);
    setColumnCount(2);      //2列
    setIndentation(8);
    setHeaderLabels(QStringList({"name","attribute"}));
    headerItem()->setTextAlignment(0,Qt::AlignCenter);
    setMinimumWidth(290);
    connect(header(),&QHeaderView::sectionResized,this,[this](int logicalIndex, int , int newSize){
        if(logicalIndex==1&&newSize>170){
            header()->resizeSection(logicalIndex,170);
        }
    });
    headerItem()->setTextAlignment(1,Qt::AlignCenter);
    setContextMenuPolicy(Qt::CustomContextMenu);
    setColumnWidth(0,120);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setFrameStyle(QFrame::NoFrame);
    connect(this,&QTreeWidget::itemPressed,this,[](QTreeWidgetItem *item,int ){
        if(qApp->mouseButtons()&Qt::RightButton){
            /*show menu*/
        }
    });

    setStyleSheet(
              "QTreeView{"
                " background-color: rgb(230,241,255);"
              "}"
    );
}



void IkPanel::createPanel()
{
    for(int i=ikObject_->metaObject()->propertyOffset();i<ikObject_->metaObject()->propertyCount();i++){
        QMetaProperty property=ikObject_->metaObject()->property(i);
        IkItem* item= IkFactroy::createItem(property.userType(),ikObject_,property);
        if(item!=nullptr)
            item->setUp(this);
    }
}
}
