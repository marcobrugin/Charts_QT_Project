#ifndef VIEW_H
#define VIEW_H
#include<QWidget>
#include<QSize>
#include<QString>
#include<QCloseEvent>
#include<QMessageBox>
#include<QTranslator>
#include<QObject>
#include<QDebug>
class View:public QWidget
{
    Q_OBJECT
    /*
     *Classe Base Polimorfa. Rappresenta la base della gerarchia delle varie schermate
    */
protected:
    //Costruttori protetti per non consentirne l'uso all'esterno
    explicit View(const QSize&, View* =nullptr);
    explicit View();
     View(const View&);
public:
     //Distruttore virtuale
    virtual ~View();
     //Metodi showMessage e showErorr per la visualizzazione di messaggi all'utente
    void showMessage(const QString&,const QString&) ;
    void showErorr(const QString&,const QString&);
    //Metodo setDim ->setta la dimensione delle schermate
    void setDim(const QSize&);
    //Metodo setViewTitle setta il titolo di una schermata
    void setViewTitle(const QString &);
    //Metodo closeEvent in override, definisce il comportamento da seguire alla chiusura di una schermata
    void closeEvent(QCloseEvent *) override;
signals:
    //Segnale di chiusura inviato al controller
    void viewClosed() const;


};

#endif // VIEW_H
