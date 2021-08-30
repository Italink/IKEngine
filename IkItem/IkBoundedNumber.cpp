#include "IkBoundedNumber.h"
#include <IkItem/Widgets/NumberSlider.h>

BoundedNumber::BoundedNumber(double number, double min, double max, int precision)
    :number_(number)
    ,min_(min)
    ,max_(max)
    ,precision_(precision)
{
}

void BoundedNumber::setRange(double min, double max)
{
    min_=min;
    max_=max;
}

int BoundedNumber::precision() const
{
    return precision_;
}

void BoundedNumber::setPrecision(int precision)
{
    precision_ = precision;
}

double BoundedNumber::min() const
{
    return min_;
}

void BoundedNumber::setMin(double min)
{
    min_ = min;
}

double BoundedNumber::max() const
{
    return max_;
}

void BoundedNumber::setMax(double max)
{
    max_ = max;
}

double BoundedNumber::number() const
{
    return number_;
}

void BoundedNumber::setNumber(double number)
{
    number_ = number;
}

bool BoundedNumber::operator==(const BoundedNumber &other)
{
    return this->number()==other.number();
}

namespace IKEngine {
IkBoundedNumber::IkBoundedNumber(QObject *ikObject, QMetaProperty ikVar)
    : IkItem(ikObject,ikVar)
{
}

QWidget *IkBoundedNumber::createWidget()
{
    BoundedNumber number=getVar().value<BoundedNumber>();
    NumberSlider *slider = new NumberSlider(number.number(),number.min(),number.max(),number.precision());
    connect(slider,&NumberSlider::valueChanged,this,[this](double value){
        BoundedNumber number=getVar().value<BoundedNumber>();
        number.setNumber(value);
        setVar(QVariant::fromValue(number));
    });
    return slider;
}
}

