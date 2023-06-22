#include "controller.h"
Controller::Controller(Model* m,View* v ,Controller* parent):QObject(parent),model(m),view(v){
     connect(view,SIGNAL(viewClosed()),this,SLOT(onViewClosed()));
}
 Controller::~Controller(){
    for (auto i:children()){
        delete i;
    }
    delete model;
    delete view;
}
Controller::Controller(){}
void Controller::show() const {
    view->show();
}
void Controller::hide() const {
    view->hide();
}
void Controller::onBack() const{
    if(QMessageBox::question(view,QObject::tr("Ritorno"),QObject::tr("Vuoi tornare indietro  davvero? \nattenzione le modifiche, se non salvate, andranno perse"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
      if(view->parent()){
          static_cast<View*>(view->parent())->show();
    hide();
    delete this;
      }}

}

