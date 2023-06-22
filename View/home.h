#ifndef HOME_H
#define HOME_H
#include"View/view.h"
#include<QPushButton>
#include<QHBoxLayout>
#include<QMessageBox>
#include<QHBoxLayout>
#include<QLabel>
#include<QDebug>
#include<QFont>
#include<QVBoxLayout>
#include<QObject>
#include<QTranslator>

class Home : public View
{
    /*
     *Classe Home. Rappresenta la Schermata Home.
    */
    //Usa il dustruttore di View.
    Q_OBJECT
    QHBoxLayout* m;
    QPushButton* New;
    QPushButton* Open;
    //Metodi di utlità per la creazione della View
    QLayout* Top();
    QLayout* Bottom();
protected:
    //Costruttore
     explicit Home();
public:
    //Costruttori
    explicit Home(const QSize& , View* =nullptr);

    //Metodo di chiusura in override
    void closeEvent(QCloseEvent *event) override;
signals:
    //Segnale New_File, segnale lanciato nel momento inn cui si preme il pulsante New
    void New_File() const;
    //Seganel Open_File, segnale lanciato nel moemnto inc ui si preme il pulsante Open
    void Open_File() const;

};

#endif // HOME_H
