#ifndef VIEW_CHART_H
#define VIEW_CHART_H
#include<View/view.h>

class View_Chart: public View
{
    Q_OBJECT
    /*
     *Classe View_Chart. Rappresenta una schermata di visualizzazione di un grafico
    */
protected:
    //Costruttore
    explicit View_Chart();
public:
    //Costruttore
    explicit View_Chart(const QSize& , View* );
    //Metodi Virtuali Puri:
    //metodo Insert prende i dati dal model e li inserisce in una struttura dati compatibile con il grafico da visualizzare
    virtual  void Insert(const QMap<QString,uint>&)=0;
    //metodo Set_Up definisce la caratterrizzazione di una schermata di un graficoS
    virtual void Set_Up(const QString&)=0;
};

#endif // VIEW_CHART_H
