#ifndef IKPANEL_H
#define IKPANEL_H

#include <QTreeWidget>

class IkPanel : public QTreeWidget
{
    Q_OBJECT
public:
    explicit IkPanel(QObject* ikObject,QWidget *parent = nullptr);
    void initilizeUI();
    void createPanel();
private:
    QObject*const ikObject_;
signals:

};

#endif // IKPANEL_H
