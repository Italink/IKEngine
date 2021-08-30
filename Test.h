#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <IkDef.h>
#include <QVector2D>
#include <QVector3D>

#include <IkItem/IkBoundedNumber.h>

class Test : public QObject
{
    Q_OBJECT
public:
    enum ENUM{
        up,down
    };
    Q_ENUM(ENUM)
    explicit Test(QObject *parent = nullptr);
    IK_AUTO(int,intVar)=1;
    IK_AUTO(float,floatVar)=2;
    IK_AUTO(bool,boolVar)=true;
    IK_AUTO(QString,strVar)="hello";
    IK_AUTO(ENUM,enumVar);
    IK_AUTO(BoundedNumber,boundedNumber)=BoundedNumber(5,0,100,1);
    IK_AUTO(QColor,color)=QColor(255,0,0);
    IK_AUTO(QVector2D,vec2){1,2};
    IK_AUTO(QVector3D,vec3){1,2,3};
signals:

};

#endif // TEST_H
