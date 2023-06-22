#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include<QString>
#include<QJsonDocument>
#include<QFileDialog>
#include<QJsonObject>
class File_Manager
{
    /*
     *Classe File_Manager, classe statica utilizzata per il salvataggio e recupero file
    */
protected:
    //Costruttori protetti
    explicit File_Manager();
    explicit File_Manager(const File_Manager&)=delete;
public:
    //Distruttore Virtuale
     virtual ~File_Manager()=default;
    //Selettore path di un file json
     static QString Json_File_Select();
     //getter di un file json utilizzabile nella biblioteca da un detrminato path
     static QJsonDocument* getFileJson(const QString&);
     //Metodo Save_Model: salva il modello in formato json su disco
     static bool Save_Model(const QJsonDocument&,const QString&);
};

#endif // FILE_MANAGER_H
