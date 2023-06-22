#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"Model/model.h"
#include"View/view.h"
#include<QObject>
#include<QDebug>
#include<QMessageBox>
class Controller:public QObject
{
    Q_OBJECT
    /*
     *Classe Base Polimorfa astratta. Rappresenta la base della gerarchia dei  Controller delle varie Schermate
    */
protected:
    Model* model;
    View* view;
    //Costruttore
    explicit Controller();
public:
    //Costruttori
    explicit Controller(Model* ,View* ,Controller* =nullptr);
    //Distruttore virtuale, distrugge tutti i suoi figli
    virtual ~Controller();
    //getter virtuali puri
    virtual Model* getModel()const=0;
    virtual View* getView() const=0;
    //Metodi show e hide per mostare e nascodere le view
    void show() const;
    void hide() const;
public slots:
    //Slot virtuali
    //Slot onViewClosed= esprime il comportamento da adottare alla chiusura di una View
    virtual void onViewClosed() const=0 ;
    //Slot onBack= esprime il comportamento da adottare al momento del ritorno alla pagine precedente
    virtual void onBack() const;

};

#endif // CONTROLLER_H
