#ifndef IKBOOL_H
#define IKBOOL_H

#include <IkItem.h>

namespace IKEngine {
class IkBool :public IkItem{
    Q_OBJECT

public:
    Q_INVOKABLE IkBool(QObject* ikObject,QMetaProperty ikVar);

public:
    virtual QWidget *createWidget() override;
};
}
#endif // IKBOOL_H
