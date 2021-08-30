#ifndef IKBOOL_H
#define IKBOOL_H

#include <IkItem.h>

class IkBool :public IkItem{
    Q_OBJECT

public:
    Q_INVOKABLE IkBool(QObject* ikObject,QMetaProperty ikVar);
    // IkItem interface
public:
    virtual QWidget *createWidget() override;
};


#endif // IKBOOL_H
