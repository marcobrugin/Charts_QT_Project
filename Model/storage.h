#ifndef STORAGE_H
#define STORAGE_H
#include"libro.h"
#include "model.h"
#include <QStringList>
#include<QDebug>
#include<QVector>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
class Storage : public Model
{
    /*
     * Modello per l'archiviazione delle info riguardanti la biblioteca
     */
    QStringList* generi;
    QStringList* autori;
    QList<Libro*> album;
    QString file;
protected:
    //Costruttore
    explicit Storage();
public:
    //Costruttori
    explicit Storage(QJsonDocument*,const QString&);
    //getter
    QStringList* getGeneri() const;
    QStringList* getAutori() const;
    const QList<Libro*>& getAlbum() const;
    QString getPath() const;
    uint getDim() const;
    uint getDimGeneri() const;
    uint getDimAutori() const;
    //Setter: setta il path di archiviazione della biblioteca
     void SetPath(const QString&);
     //Distruttore polimorfo ridefinito
    ~Storage() override;
     //Ridefinizione metodi contains verificano la presenza oppure no di un  Libro, Genere o Autore. Per le sstrighe si usa la verifica CaseInsensitive.
    virtual bool contains(const Libro&) const;
    virtual bool containsGeneri(const QString&) const;
    virtual bool containsAutori(const QString&) const;
     //Metodi add, permettono di aggiungere un Libro, Genere o Autore alla Biblioteca, non verficano se è già presente
    void addGenere(const QString&) ;
    void addAutore(const QString&) ;
     void add(Libro*);
     //Metodi remove permette di rimuovere un Libro, Genere o Autore dalla Biblioteca
    void removeGeneri(uint) ;
    void removeAutori(uint) ;
    void remove(uint);
    //Metodi Create permettono di caricare le informazioni della Biblioteca da un file Json
    void CreateGeneri(QJsonDocument*);
    void CreateAutori(QJsonDocument*);
    void CreateData(QJsonDocument*);
    //Metodo di Verifica permette di verificare se è possibile inserire un detrminato Libro
    bool verifica(const Libro* )const;
    //Metodi Search: permettono di verificare se sono presenti libri con quel detrminato Autore o Genere
    bool Search_Autori(const QString&);
    bool Search_Generi(const QString&);
};

#endif // STORAGE_H
