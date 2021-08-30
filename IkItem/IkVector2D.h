#ifndef IkVector2D_H
#define IkVector2D_H

#include <IkItem.h>

class IkVector2D :public IkItem{
    Q_OBJECT
public:
    Q_INVOKABLE IkVector2D(QObject* ikObject,QMetaProperty ikVar)
      : IkItem(ikObject,ikVar){}

public:
    virtual QWidget *createWidget() override;
};

#endif // IKDOUBLE_H
