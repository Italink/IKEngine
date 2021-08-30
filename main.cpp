#include "IkPanel.h"

#include <QApplication>
#include <Test.h>
#include "IkPanel.h"
#include "IkDef.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    enableIk();
    Test test;
    IkPanel panel(&test);
    panel.show();
    return a.exec();
}
