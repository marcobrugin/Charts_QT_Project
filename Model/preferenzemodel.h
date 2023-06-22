#ifndef PREFERENZEMODEL_H
#define PREFERENZEMODEL_H
#include "model_data.h"
#include "storage.h"
#include <QMap>
class PreferenzeModel:public Model_Data
{
    /*
     * Modello per l'analisi delle statistiche riguardo agli preferenze dei libri  presenti nella Biblioteca
     */
    QMap<QString,uint> l;
public:
    //Costruttore
    explicit PreferenzeModel(Storage*);
    // Metodo getdata polimorfo fornisce i dati da visualizzare nel grafico secondo l'implementazione dell'analisi delle preferenze
    const QMap<QString,uint>& getData() const override;
};

#endif // PREFERENZE_H
