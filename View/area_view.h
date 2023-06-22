#ifndef LINE_VIEW_H
#define LINE_VIEW_H
#include"view_chart.h"
#include<QChart>
#include<QHBoxLayout>
#include<QtCharts/QAreaSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QChartView>
#include<QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE

class Area_View:public View_Chart
{
    /*
     * Classe Area_View. Rappresenta la schermata di visualizzazione di un grafico ad area.
    */
    Q_OBJECT
    QHBoxLayout* layout;
    QChart * chart;
    QAreaSeries*  series;
protected:
    //Costruttore
   explicit  Area_View();
public:
    //Costruttore
    explicit Area_View(const QSize&,View*);
    //Metodi overide definiti con il corretto comportamento del grafico ad area
    void Insert(const QMap<QString,uint>&) override;
    void Set_Up(const QString&) override;
};

#endif // LINE_VIEW_H
