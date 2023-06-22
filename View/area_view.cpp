#include "area_view.h"
Area_View::Area_View()
{}
Area_View::Area_View(const QSize& size,View* v):View_Chart(size,v),chart(new QChart()),series(new QAreaSeries()){
    layout= new QHBoxLayout();
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView *viewver = new QChartView(chart,this);
    viewver->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(viewver);
    setLayout(layout);
    setMinimumSize(size);
}
void Area_View::Insert(const QMap<QString,uint>& m){
    chart->removeAllSeries();
    auto key=m.keys();
    auto value=m.values();
    QLineSeries* upper=new QLineSeries();
    QLineSeries* lower=new QLineSeries();

    for(auto i=0;i<key.size();i++)
    {    *upper<<QPointF((i+1),value.at(i));
         *lower<<QPointF((i+1),0);
    }

    series=new QAreaSeries(upper,lower);
    qSort(value.begin(),value.end());
    QValueAxis *y = new QValueAxis();
    y->setRange(0,value.last());
    QValueAxis * x=new QValueAxis();
    x->setRange(1,value.size());
    x->setTickCount(1);
    chart->addAxis(x,Qt::AlignBottom);
    chart->addAxis(y,Qt::AlignLeft);
    chart->addSeries(series);
}
void Area_View::Set_Up(const QString& s){
    chart->setTitle(s);
    chart->setTitleFont(QFont("Calibri",20));
    chart->axisX()->setTitleText("Generi");
    chart->axisY()->setTitleText("Quantità presente");
}
