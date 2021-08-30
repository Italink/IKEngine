#ifndef IkEnum_H
#define IkEnum_H

#include <IkItem.h>

namespace IKEngine {
class IkEnum :public IkItem{
    Q_OBJECT
public:
    Q_INVOKABLE IkEnum(QObject* ikObject,QMetaProperty ikVar);
    // IkItem interface
public:
    virtual QWidget *createWidget() override;
};
}

#endif // IkEnum_H
