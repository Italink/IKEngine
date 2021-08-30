#ifndef IkVector3D_H
#define IkVector3D_H

#include <IkItem.h>

namespace IKEngine {

class IkVector3D :public IkItem{
    Q_OBJECT
public:
    Q_INVOKABLE IkVector3D(QObject* ikObject,QMetaProperty ikVar)
      : IkItem(ikObject,ikVar){}

public:
    virtual QWidget *createWidget() override;
};
}

#endif // IKDOUBLE_H
