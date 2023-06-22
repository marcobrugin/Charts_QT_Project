#include "pie_view.h"
Pie_View::Pie_View(){}
Pie_View::Pie_View(const QSize& size,View* v):View_Chart(size,v),chart(new QChart()),series(new QPieSeries()){
    layout= new QVBoxLayout();
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->setFont(QFont("Calibri",15));
    series->setHoleSize(0.4);
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView *viewver = new QChartView(chart,this);
    viewver->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(viewver);
    setLayout(layout);
    setMinimumSize(size);
}
void Pie_View::Insert(const QMap<QString,uint>& m) {
    auto key=m.keys();
    auto value=m.values();
    for(auto i=0; i<m.size();++i)
     {  if(value[i]!=0)
        series->append(key.at(i),value.at(i));}
     series->setLabelsPosition(QPieSlice::LabelInsideTangential);
     chart->addSeries(series);

}
void Pie_View::Set_Up(const QString& p){
    for(QPieSlice* slice : series->slices()){
            slice->setExploded();
            slice->setLabelVisible();
            slice->setPen(QPen(Qt::cyan, 1));
            slice->setLabelColor(Qt::white);
            slice->setLabelFont(QFont("Calibri",12));
        }
        chart->setTitle(p);
        chart->setTitleFont(QFont("Calibri",20));
}


