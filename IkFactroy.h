#ifndef IKFACTROY_H
#define IKFACTROY_H

#include <QObject>
#include <QMetaObject>
#include <QMap>
#include "IkItem.h"

namespace IKEngine {

class IkFactroy:public QObject
{
    Q_OBJECT
public:
    static void bindIk(int userType,QMetaObject meta);
    static IkItem* createItem(int userType,QObject* ikObject,QMetaProperty ikVar);
private:
    static IkFactroy* getInstance();
    IkFactroy();
    QMap<int,QMetaObject> itemCreator;
};

}


#endif // IKFACTROY_H
