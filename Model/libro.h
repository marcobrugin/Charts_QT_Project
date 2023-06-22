#ifndef LIBRO_H
#define LIBRO_H
#include<QString>
#include<QDate>
class Libro
{
    /*
     * Classe Libro: rappresenta un modello per un aprte specifica della raccolta dati.
     *
     */
    QString titolo;
    QString autore;
    QDate data;
    QString genere;
    uint pagine;
    uint lettori;
    bool ebook;
public:
    //Costruttore
    explicit Libro(const QString&, const QString&, const QDate&,const QString&,uint =0,uint =0,bool =false);
    //metodo getTitolo() fornisce il titolo di un determinato Libro
    QString getTitolo() const;
    // metodo getEbook() fornisce l'informazione relativa alla disponibilità  in formato ebook di quel determinato libro
    bool getEbook() const;
    //metodo getAutore fornisce l'autore di un detrminato Libro.
    QString getAutore() const;
    //metodo getData fornisce la data di pubblicazione di un determinato Libro.
    QDate getData() const;
    //metodo getGenere fornisce il genere di un determinato Libro.
    QString getGenere() const;
    //metodo getPagine fornisce il numero di pagine di un determinato Libro.
    uint getPagine() const;
    //metodo getLettori fornisce il numero di lettori che ha avuto un detrminato Libro.
    uint getLettori() const;
    //distruttore virtuale per eventuali derivazioni.
    virtual ~Libro()=default;
    //metodo setEbook permette di aggiornare l'infomazione ebook di un determinato Libro.
    void setEbook(bool);
    //metodo setTitolo permette di aggiornare l'infomazione Titolo di un determinato Libro.
    void setTitolo(const QString&);
    //metodo setAutore permette di aggiornare l'infomazione Autore di un determinato Libro
    void setAutore(const QString&);
    //metodo setData permette di aggiornare l'infomazione data di pubblicazione di un determinato Libro.
    void setData(const QDate&);
    //metodo setGenere permette di aggiornare l'infomazione genere di un determinato Libro.
    void setGenere(const QString&);
    //metodo setPagine permette di aggiornare l'infomazione pagine di un determinato Libro.
    void setPagine(uint);
    //metodo setLettori permette di aggiornare l'infomazione Lettori di un detrminatio Libro.
    void setLettori(uint);
    //ridefinizione dell'operatore== due libri sono uguali <->hanno titolo e autore uguale.
    bool operator==(const Libro&) const;
};

#endif // LIBRO_H
