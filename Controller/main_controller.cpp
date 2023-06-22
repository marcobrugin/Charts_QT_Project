#include "main_controller.h"

Main_Controller::Main_Controller()
{
}
Main_Controller::Main_Controller(Storage * m, Main_View * v, Controller * c):Controller(m,v,c){
     connect(view,SIGNAL(back()),this,SLOT(onBack()));
     connect(view,SIGNAL(Generi_add(QString)),this,SLOT(Add_Generi(QString)));
     connect(view,SIGNAL(Autori_add(QString)),this,SLOT(Add_Autori(QString)));
     connect(view,SIGNAL(Remove_Autori(uint)),this,SLOT(Remove_Autori(uint)));
     connect(view,SIGNAL(Remove_Generi(uint)),this,SLOT(Remove_Generi(uint)));
     connect(view,SIGNAL(Remove_Book(uint)),this,SLOT(Remove_Book(uint)));
     connect(view,SIGNAL(Save()),this,SLOT(Save_Model()));
     connect(view,SIGNAL(Libro_add(QString,QString, QDate, QString,uint,uint,bool)),SLOT(Add_Libro(QString,QString,QDate,QString,uint,uint,bool)));
     connect(view,SIGNAL(Autori_Charts()),this,SLOT(On_Autori()));
     connect(view,SIGNAL(Generi_Charts()),this,SLOT(On_Generi()));
     connect(view,SIGNAL(Preferenze_Charts()),this,SLOT(On_Preferenze()));
     //Use C++11 and definition inline QList
     getView()->createDataTable({"Titolo","Autore","Data","Genere","Pagine","Preferenze","Ebook"," "});
     getView()->createAutoriTable({"Autori"," "});
     getView()->createGeneriTable({"Generi"," "});
     getView()->load_data(getModel()->getAlbum());
     getView()->load_generi(getModel()->getGeneri());
     getView()->load_autori(getModel()->getAutori());
     getView()->added_Libro(getModel()->getAlbum().size(),getModel()->getAutori(),getModel()->getGeneri());
}
void Main_Controller::Save_Model() const{
    if(!getModel()->getAlbum().size() && !getModel()->getAutori()->size() && !getModel()->getGeneri()->size()){
        view->showErorr("Errore","Model vuoto");
        return;
    }
    QJsonDocument* doc=new QJsonDocument();
    QJsonObject container;
    QJsonArray archive;
    for(auto i: getModel()->getAlbum()){
        QJsonObject record;
        record.insert(QString::fromStdString("titolo"),i->getTitolo());
        record.insert(QString::fromStdString("autore"),i->getAutore());
        record.insert(QString::fromStdString("data"),i->getData().toString("dd/MM/yyyy"));
        record.insert(QString::fromStdString("genere"),i->getGenere());
        record.insert(QString::fromStdString("pagine"),static_cast<int>(i->getPagine()));
        record.insert(QString::fromStdString("lettori"),static_cast<int>(i->getLettori()));
        record.insert(QString::fromStdString("ebook"),i->getEbook());
        archive.push_back(record);
 }

  container.insert(QString::fromStdString("data"),archive);
  container.insert(QString::fromStdString("generi"),QJsonArray::fromStringList(*getModel()->getGeneri()));
  container.insert(QString::fromStdString("autori"),QJsonArray::fromStringList(*getModel()->getAutori()));
  doc->setObject(container);
  QString nome = QFileDialog::getSaveFileName(view,QObject::tr("Salva con nome"),getModel()->getPath(),"JSON Files (*.json)");
  if(nome.isEmpty() || nome.isNull()){
      view->showErorr(QObject::tr("Errore Salvataggio"),QObject::tr("Salvataggio fallito"));
          return;
      }
      if (!nome.endsWith(".json"))
          nome+= QObject::tr(".json");

      getModel()->SetPath(nome);
      if(File_Manager::Save_Model(*doc,nome))
            view->showMessage(QObject::tr("Salvataggio"),QObject::tr("Salvataggio riuscito"));
      else
          view->showErorr(QObject::tr("Errore di salvataggio"),QObject::tr("Salvataggio non riuscito"));
      delete doc;

}
Storage* Main_Controller::getModel()const {
    return static_cast<Storage*>(model);
}
Main_View* Main_Controller::getView() const  {
    return static_cast<Main_View*>(view);
}
void Main_Controller::onViewClosed() const{
    delete this;
}
void Main_Controller::onBack() const{
    Controller::onBack();
}
void Main_Controller::Add_Generi(const QString& p){
    if(getModel()->containsGeneri(p))
     {   getView()->showErorr("Già presente","Il genere inserito è già presente");
        return;}
    getModel()->addGenere(p);
    getView()->addGeneri(p);
    getView()->added_Libro(getModel()->getAlbum().size(),getModel()->getAutori(),getModel()->getGeneri());
}
void Main_Controller::Add_Autori(const QString& p){
    if(getModel()->containsAutori(p))
     {   getView()->showErorr("Già presente","L'autore inserito è già presente");
        return;}
    getModel()->addAutore(p);
    getView()->addAutori(p);
    getView()->added_Libro(getModel()->getAlbum().size(),getModel()->getAutori(),getModel()->getGeneri());
}
void Main_Controller::Add_Libro(const QString& t,const QString& a,const QDate& d,const QString& g,uint p ,uint l ,bool e){
    if(getModel()->contains(Libro(t,a,d,g,p,l,e))){
        getView()->showErorr("Già presente","Il libro inserito è già presente");
        qDebug()<<a;
        return;
    }
    Libro* libro=new Libro(t,a,d,g,p,l,e);
    getModel()->add(libro);
    getView()->addLibro(libro);
    getView()->added_Libro(getModel()->getAlbum().size(),getModel()->getAutori(),getModel()->getGeneri());

}
void Main_Controller::Remove_Autori(uint i){
    if(getModel()->Search_Autori(getModel()->getAutori()->at(i))){
        getView()->showErorr("Error","Cancellazione non possibile");
        return;}
     getModel()->removeAutori(i);
     getView()->removeAutori(i);
     getView()->added_Libro(getModel()->getAlbum().size(),getModel()->getAutori(),getModel()->getGeneri());
}
void Main_Controller::Remove_Generi(uint i){
    if(getModel()->Search_Generi(getModel()->getGeneri()->at(i))){
        getView()->showErorr("Error","Cancellazione non possibile");
    return;}
        getModel()->removeGeneri(i);
        getView()->removeGeneri(i);
        getView()->added_Libro(getModel()->getAlbum().size(),getModel()->getAutori(),getModel()->getGeneri());
}
void Main_Controller::Remove_Book(uint i){
    getModel()->remove(i);
    getView()->removeLibro(i);
}
void Main_Controller::On_Autori() const{
    if(!getModel()->getDim())
     {   view->showErorr(QObject::tr("Errore"),QObject::tr("Model vuoto")); return;}
    Model_Data* s=new AutoriModel(getModel());
    View_Chart* v= new Bar_View(QSize(1000,500),view);
    static_cast<View*>(v)->setViewTitle(QObject::tr("Autori"));
    Charts_Controller* c=new Charts_Controller(s,v,const_cast<Main_Controller*>(this));
    c->getView()->Insert(s->getData());
    c->getView()->Set_Up(QObject::tr("Distribuzione degli Autori"));
    c->show();
}
void Main_Controller::On_Generi() const{
    if(!getModel()->getDim())
      {   view->showErorr(QObject::tr("Errore"),QObject::tr("Model vuoto")); return;}
    Model_Data* s=new GeneriModel(getModel());
    View_Chart* v= new Area_View(QSize(1000,500),view);
    static_cast<View*>(v)->setViewTitle(QObject::tr("Generi"));
    Charts_Controller* c=new Charts_Controller(s,v,const_cast<Main_Controller*>(this));
    c->getView()->Insert(s->getData());
    c->getView()->Set_Up(QObject::tr("Distribuzione dei generi presenti"));
    c->getView()->showMessage("Avviso","I valori interi  dell'asse x corrspondono agli indici della tabella Generi");
    c->show();
}
void Main_Controller::On_Preferenze() const{
     if(!getModel()->getDim())
       {view->showErorr(QObject::tr("Errore"),QObject::tr("Model vuoto")); return;}
     Model_Data* s=new PreferenzeModel(getModel());
     View_Chart* v= new Pie_View(QSize(1000,500),view);
     static_cast<View*>(v)->setViewTitle(QObject::tr("Preferenze"));
     Charts_Controller* c=new Charts_Controller(s,v,const_cast<Main_Controller*>(this));
     c->getView()->Insert(s->getData());
     c->getView()->Set_Up(QObject::tr("Distribuzione delle preferenze dei consumatori riguardo i gli Autori"));
     c->show();
}
