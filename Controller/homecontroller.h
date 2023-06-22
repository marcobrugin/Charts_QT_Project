#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H
#include "controller.h"
#include"file_manager.h"
#include "View/home.h"
#include"Model/storage.h"
#include"View/main_view.h"
#include"main_controller.h"
#include<QDebug>
#include<QJsonDocument>
#include<QInputDialog>
#include<QLineEdit>
#include<QObject>
class HomeController : public Controller
{
    Q_OBJECT
    /*
     *Classe HomeController, rappresenta il controller della schermata Home
    */
protected:
    //Cosstruttore
    explicit  HomeController();
public:
    //Costruyttore
    explicit HomeController(Home* ,Controller* =nullptr);
    //getter overridati
    Home * getView() const override;
    Model* getModel()const override;
public slots:
    //Override Slot
    void onViewClosed() const override;
    //Slot Ex_New_File definisce il comportamento da seguire se è stato premuto il pulsante New dalla view.
    void Ex_New_File() const;
    //Slot Ex_Open_File definisce il comportamento da seguire se è stato premuto il pulsante Open dalla view.
    void Ex_Open_File() const;
};

#endif // HOMECONTROLLER_H
