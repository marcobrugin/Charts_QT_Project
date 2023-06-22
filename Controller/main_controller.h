#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H
#include"controller.h"
#include"Model/storage.h"
#include"View/main_view.h"
#include"Model/model_data.h"
#include"file_manager.h"
#include"View/view_chart.h"
#include"charts_controller.h"
#include"Model/generimodel.h"
#include"Model/autorimodel.h"
#include"View/pie_view.h"
#include"View/bar_view.h"
#include"Model/preferenzemodel.h"
#include"View/area_view.h"
#include<QDebug>
#include<QMessageBox>
#include<QFileDialog>
class Main_Controller: public Controller
{
    Q_OBJECT
    /*
     *Classe Main_Controller, rappresenta il controller della schermata Main
    */
protected:
    //Costruttore
    explicit Main_Controller();
public:
    //Costruttori   
    explicit Main_Controller(Storage*, Main_View* , Controller* );
    //getter overraidati
    Storage* getModel()const override;
    Main_View* getView() const override;
public slots:
    //Slot overridati
    void onViewClosed() const override;
    void onBack() const override;
    //Slot Add definiscono i comportamenti da assumere quando si ha premuto il pulsante + dalla view
    //rispettivamente per inserire: un libro, un genere o un autore
    void Add_Libro(const QString&,const QString&,const QDate&,const QString&,uint,uint,bool);
    void Add_Generi(const QString&);
    void Add_Autori(const QString&);
    //Slot remove definiscono i comportamenti da assumere quando si ha premuto il pulsante - dalla view
    //rispettivamente per rimuove: un libro, un genere o un autore
    void Remove_Book(uint);
    void Remove_Generi(uint);
    void Remove_Autori(uint);
    //Slot Save: definisce il comportamento da seguire nel momento in cui si è premuto dalla schermata Main il Pulsanate Save
    void Save_Model() const;
    //Slot che definiscono il comportamento da seguire nel momento in cui si preme un pulsante tra: Autori Chart,Generi Chart, Preferenze Chart
    void On_Autori() const;
    void On_Generi() const;
    void On_Preferenze() const;

};

#endif // MAIN_CONTROLLER_H
