#include "IkFactroy.h"
#include <IkItem/IkEnum.h>
namespace IKEngine {

IkFactroy::IkFactroy(){
    qRegisterMetaType<QObject*>();
}

void IkFactroy::bindIk(int userType, QMetaObject meta)
{
    getInstance()->itemCreator.insert(userType,meta);
}

IkItem *IkFactroy::createItem(int userType,QObject* ikObject,QMetaProperty ikVar)
{
    if(ikVar.isEnumType()){
        return new IkEnum(ikObject,ikVar);
    }
    if(!getInstance()->itemCreator.contains(userType))
        return nullptr;
    else{
        QMetaObject& meta= getInstance()->itemCreator[userType];
        auto ins=meta.newInstance(Q_ARG(QObject*,ikObject),Q_ARG(QMetaProperty,ikVar));
        return (IkItem*)ins;
    }
}

IkFactroy *IkFactroy::getInstance()
{
    static IkFactroy ins;
    return &ins;
}

}
