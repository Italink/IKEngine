#ifndef IKPANEL_H
#define IKPANEL_H

#include <QTreeWidget>

namespace IKEngine {

class IkPanel : public QTreeWidget
{
    Q_OBJECT
public:
    explicit IkPanel(QObject* ikObject,QWidget *parent = nullptr);
    void initilizeUI();
    void createPanel();
private:
    QObject*const ikObject_;

};
}

#endif // IKPANEL_H
