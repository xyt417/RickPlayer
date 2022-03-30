#include<QApplication>
#include"player.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Player Rick;
    Rick.show();
    app.exec();
}