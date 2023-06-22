#ifndef BAR_VIEW_H
#define BAR_VIEW_H
#include"view_chart.h"
#include<QChart>
#include<QtCharts/QBarSeries>
#include<QVBoxLayout>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSet>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE

class Bar_View:public View_Chart
{
    /*
     * Classe Bar_View. Rappresenta la schermata di visualizzazione di un grafico a torta.
    */
    Q_OBJECT
    QVBoxLayout* layout;
    QChart * chart;
    QBarSeries*  series;

protected:
    //Costruttore
   explicit  Bar_View();
public:
    //Costruttore
    explicit Bar_View(const QSize&,View*);
    //Metodi overide definiti con il corretto comportamento del grafico a barre
    void Insert(const QMap<QString,uint>&) override;
    void Set_Up(const QString&) override;
};

#endif // BAR_VIEW_H
