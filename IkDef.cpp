#include "IkDef.h"
#include "IkFactroy.h"
#include "IkPanel.h"
#include <IkItem/IkBool.h>
#include <IkItem/IkBoundedNumber.h>
#include <IkItem/IkColor.h>
#include <IkItem/IkDouble.h>
#include <IkItem/IkFloat.h>
#include <IkItem/IkInt.h>
#include <IkItem/IkString.h>
#include <IkItem/IkVector2D.h>
#include <IkItem/IkVector3D.h>


#define IK_BINDER(VarType,ItemType) \
   IkFactroy::bindIk(QMetaTypeId2<VarType>::qt_metatype_id() ,ItemType::staticMetaObject);

namespace IKEngine {


void initialize(){
    IK_BINDER(int, IkInt);
    IK_BINDER(bool, IkBool);
    IK_BINDER(BoundedNumber,IkBoundedNumber);
    IK_BINDER(QColor,IkColor);
    IK_BINDER(double,IkDouble);
    IK_BINDER(float,IkFloat);
    IK_BINDER(QString,IkString);
    IK_BINDER(QVector2D,IkVector2D);
    IK_BINDER(QVector3D,IkVector3D);
}

IkPanel *createPanel(QObject *obj){
    return new IkPanel(obj);
}

void registerIkTypeImpl(int typeId, QMetaObject meta)
{
    IkFactroy::bindIk(typeId,meta);
}


}
