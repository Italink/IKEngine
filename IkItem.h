#ifndef IKITEM_H
#define IKITEM_H
#include <QMetaProperty>
#include <QObject>
#include <QTreeWidgetItem>

class IkItem :public QObject, public QTreeWidgetItem
{
    Q_OBJECT
public:
    explicit IkItem(QObject* ikObject,QMetaProperty ikVar,QObject *parent = nullptr);

    virtual QWidget* createWidget() ;
    virtual void setUp(QTreeWidgetItem* tree);
    virtual void setUp(QTreeWidget *tree);

    void rename();
    QTreeWidgetItem* parent(){return QTreeWidgetItem::parent();}

    void setVar(QVariant var);
    QVariant getVar();

    template<typename _Ty>
    void setValue(_Ty value){
        setVar(QVariant::fromValue<_Ty>(value));
    }
protected:
    QObject*const ikObject_;
    QMetaProperty ikVar_;
};

struct IkItemRegister{
    IkItemRegister(int userType,QMetaObject meta);
};

#define IK_ITEM_BINDER(VarType,ItemType) \
    static IkItemRegister VarType##Register = IkItemRegister(QMetaTypeId2<VarType>::qt_metatype_id() ,ItemType::staticMetaObject);

#define IK_ITEM_DECLARE(VarTypename,ItemTypename) \
        IK_ITEM_BINDER(VarTypename,ItemTypename)\
    public:\
        Q_INVOKABLE ItemTypename(QObject* ikObject,QMetaProperty ikVar):IkItem(ikObject,ikVar){} \
        virtual QWidget *createWidget() override;\


#define IK_ITEM_WIDGET(ItemTypename) QWidget* ItemTypename::createWidget()\

#endif // IKITEM_H
