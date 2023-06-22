#ifndef SINGLEMODEL_H
#define SINGLEMODEL_H
#include "model.h"
#include<QMap>
class Model_Data : public Model{
    /*
     * Modello che rappresenta i dati da visulizzare in un grafico
     *
    */
public:
    //metodo virtuale puro; fornisce la coretta implementazione dei dati da visualizzare in un grafico secondo la coretta
    //implemnetazione
   virtual const QMap<QString,uint>& getData() const=0;
};

#endif // SINGLEMODEL_H
