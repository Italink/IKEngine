#ifndef IKDOUBLE_H
#define IKDOUBLE_H

#include <IkItem.h>

namespace IKEngine {
class IkDouble :public IkItem{
    Q_OBJECT
public:
    Q_INVOKABLE IkDouble(QObject* ikObject,QMetaProperty ikVar);
public:
    virtual QWidget *createWidget() override;
};
}

#endif // IKDOUBLE_H
