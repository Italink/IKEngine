#ifndef IkString_H
#define IkString_H
#include <IkItem.h>

namespace IKEngine {
class IkString :public IkItem{
    Q_OBJECT

public:
    Q_INVOKABLE IkString(QObject* ikObject,QMetaProperty ikVar);
    // IkItem interface
public:
    virtual QWidget *createWidget() override;
};
}

#endif // IkString_H
