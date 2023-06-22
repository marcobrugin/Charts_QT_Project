#include "home.h"
Home::Home(const QSize & s, View * parent):View(s,parent){
    m = new QHBoxLayout(this);
    m->setSpacing(0);
    m->setMargin(0);
    m->addLayout(Top());
    m->addLayout(Bottom());
    setLayout(m);
    connect(New,SIGNAL(clicked()),this,SIGNAL(New_File()));
    connect(Open,SIGNAL(clicked()),this,SIGNAL(Open_File()));

}
QLayout* Home::Bottom(){
    QVBoxLayout* bottom = new QVBoxLayout;
    bottom->setMargin(10);
    bottom->setSpacing(50);
    bottom->setContentsMargins(25,10,12,10);
    bottom->setAlignment(Qt::AlignCenter);
    New=new QPushButton(QObject::tr("New"),this);
    Open=new QPushButton(QObject::tr("Open"),this);
    New->setFont(QFont("Calibri",15));
    Open->setFont(QFont("Calibri",15));
    New->setFixedSize(300,100);
    Open->setFixedSize(300,100);
    bottom->addWidget(New);
    bottom->addWidget(Open);
    return bottom;

}
QLayout* Home::Top(){
    QHBoxLayout* top = new QHBoxLayout;
    top->setMargin(10);
    top->setSpacing(40);
    top->setContentsMargins(25,40,12,40);
    top->setAlignment(Qt::AlignCenter);
    QLabel* m=new QLabel(QObject::tr("Scegli  una tra le  due scelte, \npotrai creare una biblioteca \no caricare una biblioteca esistente"));
    m->setFont(QFont("Calibri",20));
    top->addWidget(m);
    return top;
}
void Home::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,QObject::tr("Uscita"),QObject::tr("Vuoi uscire davvero?"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        hide();
        emit viewClosed();
    }
    else
        event->ignore();
}

