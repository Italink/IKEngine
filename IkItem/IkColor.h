#ifndef IKCOLOR_H
#define IKCOLOR_H

#include <IkItem.h>

class IkColor :public IkItem{
    Q_OBJECT

public:
    Q_INVOKABLE IkColor(QObject* ikObject,QMetaProperty ikVar);
    // IkItem interface
public:
    virtual QWidget *createWidget() override;
};
#endif // IKCOLOR_H
