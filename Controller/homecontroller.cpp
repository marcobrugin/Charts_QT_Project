#include "homecontroller.h"
HomeController::HomeController(Home * p,Controller* c):Controller(nullptr,p,c){
    connect(view,SIGNAL(New_File()),this,SLOT(Ex_New_File()));
    connect(view,SIGNAL(Open_File()),this,SLOT(Ex_Open_File()));
}
Home* HomeController::getView() const{
return static_cast<Home*>(view);
}
Model* HomeController::getModel()const{
    return nullptr;
}
void HomeController::onViewClosed() const {
    delete this;
}
void HomeController::Ex_New_File() const{

    bool ok;
    QString text = QInputDialog::getText(view, QObject::tr("Nuovo"),
                                             QObject::tr("Inserisci il titolo  della tua biblioteca, tale nome verrà usato anche come denominazione del file che conterrà la tua biblioteca, \n (L'estensione json viene aggiunta in automatico):"),QLineEdit::Normal,QObject::tr("Inserisci..."),&ok);

    if(ok && !text.isEmpty() && !text.isNull()){
    QStringList m=text.split(" ");
    text=m.at(0);
    if(!text.endsWith(".json"))
         text+=".json";
    if(text=="Inserisci..."){
        view->showErorr(QObject::tr("Errore"),QObject::tr("Nome non valido"));
              return;}

    Main_View* main_view = new Main_View(QSize(1250,500),view);
    Storage* store = new Storage(nullptr,text);
    main_view->show();
    Main_Controller* main_controller=new Main_Controller(store,main_view,const_cast<HomeController*>(this));
    main_controller->show();
    hide();
    }
    else{
       view->showErorr(QObject::tr("Errore"),QObject::tr("Nome non valido"));
    }
}


void HomeController::Ex_Open_File() const{

  QString file=File_Manager::Json_File_Select();
  if(file.isEmpty() || file.isNull())
   {   view->showErorr(QObject::tr("Errore Selezione File"),QObject::tr("Non hai selezionato alcun file."));
      return;}
  QJsonDocument* document=File_Manager::getFileJson(file);
  if(document->isNull()){
     view->showErorr(QObject::tr("Errore Selezione File errata "),QObject::tr("Hai selezionato un file errato"));
         return;}
  Main_View* main_view = new Main_View(QSize(1250,500),view);
  Storage* store = new Storage(document,file);
  Main_Controller* main_controller=new Main_Controller(store,main_view,const_cast<HomeController*>(this));
  main_controller->show();
  hide();
  delete document;
}
