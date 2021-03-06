#ifndef IKDEF_H
#define IKDEF_H

#include "IkPanel.h"
class QObject;


namespace IKEngine {

    void        initialize();

    IkPanel*    createPanel(QObject* obj);

    void registerIkTypeImpl(int typeId,QMetaObject meta);

    template<typename VarType,typename ItemType>
    void registerIkType(){
        registerIkTypeImpl(QMetaTypeId2<VarType>::qt_metatype_id() ,ItemType::staticMetaObject);
    }
}

#define REG_IK_TYPE(VarType,ItemType) \
    IKEngine::registerIkTypeImpl(QMetaTypeId2<VarType>::qt_metatype_id() ,ItemType::staticMetaObject);

#define IK_AUTO(type,name)\
    Q_PROPERTY(type name READ get_##name WRITE set_##name NOTIFY name##Changed) \
    type get_##name(){ return name; } \
    void set_##name(type var){ \
        if(name==var) \
            return; \
        name = var;  \
        emit name##Changed(var); \
    } \
    Q_SIGNAL void name##Changed(type); \
    type name

#define Q_OBJECT_IK \
    Q_OBJECT
//    public:
//        IkPanle *createPanel();
//        QByteArray toByteArray();
//        QByteArray toByteArray(const QString& propertyName);
//        void fromByteArray(QByteArray data);
//        void fromByteArray(const QString& propertyName,QByteArray data);


#endif // IKDEF_H
