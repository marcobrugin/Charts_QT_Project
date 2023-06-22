#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H
#include"view.h"
#include"Model/libro.h"
#include<QSize>
#include<QPushButton>
#include<QGridLayout>
#include<QTableWidget>
#include<QTextEdit>
#include<QComboBox>
#include<QDateEdit>
#include<QSpinBox>
#include<QCheckBox>
#include<QLabel>
#include<QList>
#include<QtCharts/QChartView>
#include<QMessageBox>
#include<QObject>
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QDebug>
 QT_CHARTS_USE_NAMESPACE
class Main_View: public View
{
    /*
     *Classe Main_View. Rappresenta la Schermata Main
    */
    Q_OBJECT
    QGridLayout* m;
    QPushButton * save;
    QPushButton * home;
    QPushButton * autori;
    QPushButton * generi;
    QPushButton * preferenze;
    QTableWidget* data;
    QTableWidget* generi_table;
    QTableWidget* autori_table;
    QTextEdit * text_generi;
    QPushButton* add_generi;
    QTextEdit * text_autori;
    QPushButton* add_autori;
    QTextEdit * titolo;
    QComboBox* autore;
    QDateEdit* data_input;
    QComboBox* genere;
    QSpinBox* pagine;
    QSpinBox* lettori;
    QCheckBox* ebook;
    QPushButton* add;
    QPushButton* remove;
    QLabel* label;
protected:
    //Costruttore
     explicit Main_View();
public:
    //Costruttori
    explicit Main_View(const QSize&,View*);
    //Metodo di chiusura della finestra
    void closeEvent(QCloseEvent *event) override;
    //Metodi di creazione della tabella della schermata Main
    void createDataTable(const QStringList&);
    void createGeneriTable(const QStringList&);
    void createAutoriTable(const QStringList&);
    //Metodi per la creazione della tabella dui aggiunta Generi, Autori e Libri
    void added_Generi(uint);
    void added_Autori(uint);
    void added_Libro(uint,const QStringList*,const QStringList*);
    //Metodi load, permettono di caricare le informazioni dal Model alla View
    void load_generi(const QStringList*);
    void load_autori(const QStringList*);
    void load_data(const QList<Libro*>&);
    //Metodi add, permettono rispettivamente di aggiungere un genere, un autore o un libro alla view
    void addGeneri(const QString&);
    void addAutori(const QString&);
    void addLibro(const Libro*);
    //Metodi remove, permettono rispettivamente di rimuovere un genere, un autore o un libro dalla view
    void removeGeneri(uint);
    void removeAutori(uint);
    void removeLibro(uint);
signals:
    //segnale back, lanciato nel moemnto in cui si preme il pulsante Home
    void back() const;
    //segnali add, lanciati nel momento in cui viene premuto il pulsante + nelle varie tabelle
    void Generi_add(const QString&) const;
    void Autori_add(const QString&) const;
    void Libro_add(const QString&,const QString&,const QDate&,const QString&,uint,uint,bool);
    //segnali remove, lanciati nel momento in cui viene premuto il pulsante - nelle varie tabelle
    void Remove_Autori(uint) const;
    void Remove_Generi(uint) const;
    void Remove_Book(uint) const;
    //segnale save lanciato nel momento in cui è stato premuto il pulsante Save
    void Save() const;
    //segnali Charts, lanciati nel momento in cui si va a premere un pulsante di visualizzazione di un grafico
    void Autori_Charts() const;
    void Generi_Charts() const;
    void Preferenze_Charts() const;
public slots:
    //slot Add, definiscono il comportamento da seguire dopo aver premuto il pulsante + nelle rispettive tabelle
    void Add_generi();
    void Add_autori();
    void Add_Libro();

};

#endif // MAIN_VIEW_H
