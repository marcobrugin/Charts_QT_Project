#ifndef PIE_VIEW_H
#define PIE_VIEW_H
#include"view_chart.h"
#include<QChart>
#include<QtCharts/QPieSeries>
#include<QVBoxLayout>
#include<QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE

class Pie_View:public View_Chart
{
    /*
     *Classe Pie_view. Rappresenta la schermata di visualizzazione di un grafico a torta.
    */
    Q_OBJECT
    QVBoxLayout* layout;
    QChart * chart;
    QPieSeries*  series;

protected:
    //Costrutore
   explicit  Pie_View();
public:
    //Costruttore
    explicit Pie_View(const QSize&,View*);
    //Metodi overide definiti con il corretto comportamento del grafico a torta
    void Insert(const QMap<QString,uint>&) override;
    void Set_Up(const QString&) override;
};

#endif // PIE_VIEW_H
