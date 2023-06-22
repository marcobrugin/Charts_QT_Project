#include "View/home.h"
#include "Controller/homecontroller.h"
#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include<QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("logo.ico"));
    QMessageBox::StandardButton l;
    l=QMessageBox::question(nullptr,QObject::tr("Benvenuto in Biblioteca UNIPD "),QObject::tr("Qui potrai avere il piacere di creare una biblioteca e visualizzare alcune statistiche su di essa"), QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if (l == QMessageBox::No) {
       QApplication::quit();
       qDebug()<<"QUIT";
       return 0;
     } else {
          Home*  home=new Home(QSize(500,300));
          HomeController* controller=new HomeController(home);
          controller->show();
          //Static Method
          return QApplication::exec();
     }
}
