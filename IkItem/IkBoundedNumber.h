#ifndef IKBOUNDEDNUMBER_H
#define IKBOUNDEDNUMBER_H

#include <IkItem.h>


class BoundedNumber
{
public:
    BoundedNumber(){};
    BoundedNumber(double number,double min,double max,int precision = 0);

    int precision() const;
    void setPrecision(int precision);

    void setRange(double min,double max);

    double min() const;
    void setMin(double min);

    double max() const;
    void setMax(double max);

    double number() const;
    void setNumber(double number);

    bool operator==(const BoundedNumber& other);
private:
    double number_=0;
    double min_=0,max_=100;
    int precision_=0;
};
Q_DECLARE_METATYPE(BoundedNumber)

class IkBoundedNumber :public IkItem{
    Q_OBJECT

public:
    Q_INVOKABLE IkBoundedNumber(QObject* ikObject,QMetaProperty ikVar);

public:
    virtual QWidget *createWidget() override;
};


#endif // IKBOUNDEDNUMBER_H
