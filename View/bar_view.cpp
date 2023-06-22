#include "bar_view.h"
Bar_View::Bar_View(){}


Bar_View::Bar_View(const QSize& size,View* v):View_Chart(size,v),chart(new QChart()),series(new QBarSeries()){
    layout= new QVBoxLayout();
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Calibri",20));
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView * viewver = new QChartView(chart,this);
    viewver->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(viewver);
    setLayout(layout);
    setMinimumSize(size);
}
void Bar_View::Insert(const QMap<QString,uint>& m){
    chart->removeAllSeries();
    auto key=m.keys();
    auto value=m.values();
    QBarSet* set;
    for(auto i=0; i<key.size(); i++){
        set=new QBarSet(key.at(i));
        *set<<value.at(i);
        series->append(set);
    }
    chart->addSeries(series);
    QBarCategoryAxis * x = new QBarCategoryAxis();
    x->append(key);
    chart->addAxis(x, Qt::AlignBottom);
    qSort(value.begin(),value.end());
    QValueAxis *y = new QValueAxis();
    y->setRange(0,value.last());
    chart->addAxis(y,Qt::AlignLeft);
}
void Bar_View::Set_Up(const QString& s){
chart->setTitle(s);
chart->setTitleFont(QFont("Calibri",20));
chart->axisX()->setTitleText("Autori");
chart->axisY()->setTitleText("Quantità presente");
}
