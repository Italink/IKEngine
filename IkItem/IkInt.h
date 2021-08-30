#ifndef IKINT_H
#define IKINT_H

#include <IkItem.h>

namespace IKEngine {
class IkInt :public IkItem{
    Q_OBJECT
public:
    Q_INVOKABLE IkInt(QObject* ikObject,QMetaProperty ikVar);
    // IkItem interface
public:
    virtual QWidget *createWidget() override;
};
}

#endif // IKINT_H
