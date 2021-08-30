#ifndef IKFLOAT_H
#define IKFLOAT_H

#include <IkItem.h>

class IkFloat :public IkItem{
    Q_OBJECT
public:
    Q_INVOKABLE IkFloat(QObject* ikObject,QMetaProperty ikVar)
      : IkItem(ikObject,ikVar){}
    // IkItem interface
public:
    virtual QWidget *createWidget() override;
};

#endif // IKDOUBLE_H
