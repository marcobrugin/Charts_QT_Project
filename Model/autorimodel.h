#ifndef AUTORIMODEL_H
#define AUTORIMODEL_H
#include"storage.h"
#include"model_data.h"
#include<QMap>
#include<QString>
class AutoriModel : public Model_Data
{
    /*
     * Modello per l'analisi delle statistiche riguardo agli autori presenti nella Biblioteca
    */
    QMap<QString,uint> l;
public:
    //Costruttore
    explicit  AutoriModel(Storage*);
    // Metodo getdata polimorfo  fornisce i dati da visualizzare nel grafico secondo l'implementazione dell'analisi degli autori
    const QMap<QString,uint>& getData()const override;
};

#endif // AUTORIMODEL_H
