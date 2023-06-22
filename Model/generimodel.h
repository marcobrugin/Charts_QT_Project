#ifndef GENERIMODEL_H
#define GENERIMODEL_H
#include "storage.h"
#include "model_data.h"
#include<QMap>
#include<QString>
class GeneriModel:public Model_Data        
{
    /*
     * Modello per l'analisi delle statistiche riguardo agli generi presenti nella Biblioteca
     */
    QMap<QString,uint> l;
public:
    //Costruttore
    explicit GeneriModel(Storage*);
    // Metodo getdata polimorfo fornisce i dati da visualizzare nel grafico secondo l'implementazione dell'analisi dei generi
    const QMap<QString,uint>& getData() const override;

};

#endif // GENERIMODEL_H
