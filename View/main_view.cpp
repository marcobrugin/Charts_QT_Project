#include "main_view.h"
Main_View::Main_View()
{}
Main_View::Main_View(const QSize& s,View*p):View(s,p),m(new QGridLayout(this)),data(new QTableWidget(this)), generi_table(new QTableWidget(this)),autori_table(new QTableWidget(this)){
    //set up
    //align by row and colu
    setMinimumSize(s);
    m->setSpacing(10);
    data->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    m->setMargin(10);
    save = new QPushButton(QObject::tr("Save"),this);
    save->setFont(QFont(QObject::tr("Calibri"),15));
    m->addWidget(save,0,0,1,1,Qt::AlignJustify);
    home = new QPushButton(QObject::tr("Home"),this);
    home->setFont(QFont("Calibri",15));
    m->addWidget(home,0,4,1,1,Qt::AlignRight);
//charts
    autori = new QPushButton(QObject::tr("Autori Chart"),this);
    autori->setFont(QFont("Calibri",15));
    m->addWidget(autori,2,2,1,1,Qt::AlignCenter);
    generi=new QPushButton(QObject::tr("Generi Chart"),this);
    generi->setFont(QFont("Calibri",15));
    m->addWidget(generi,2,3,1,2,Qt::AlignCenter);
    preferenze=new QPushButton(QObject::tr("Preferenze Chart"),this);
    preferenze->setFont(QFont("Calibri",15));
    m->addWidget(preferenze,2,1,1,1,Qt::AlignCenter);
    setLayout(m);
    connect(home,SIGNAL(clicked(bool)),this,SIGNAL(back()));
    connect(save,SIGNAL(clicked(bool)),this,SIGNAL(Save()));
    connect(autori,SIGNAL(clicked(bool)),this,SIGNAL(Autori_Charts()));
    connect(generi,SIGNAL(clicked(bool)),this,SIGNAL(Generi_Charts()));
    connect(preferenze,SIGNAL(clicked(bool)),this,SIGNAL(Preferenze_Charts()));
}
void Main_View::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,QObject::tr("Uscita"),QObject::tr("Vuoi uscire davvero?"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
void Main_View::createDataTable(const QStringList& headers) {
    //Prints Table
    data->setRowCount(0);
    data->setColumnCount(8);
    data->setHorizontalHeaderLabels(headers);
    data->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    data->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    data->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    data->setColumnWidth(7,25);
    m->addWidget(data,1,0,1,3);
}



void Main_View::createGeneriTable(const QStringList& headers) {
    generi_table->setRowCount(0);
    generi_table->setColumnCount(2);
    generi_table->setHorizontalHeaderLabels(headers);
    generi_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    generi_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    generi_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    generi_table->setColumnWidth(2,25);
    m->addWidget(generi_table,1,3,1,2);
}
void Main_View::createAutoriTable(const QStringList& headers) {
    autori_table->setRowCount(0);
    autori_table->setColumnCount(2);
    autori_table->setHorizontalHeaderLabels(headers);
    autori_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    autori_table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    autori_table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    autori_table->setColumnWidth(2,25);
    m->addWidget(autori_table,1,6,1,1);
}
void Main_View::added_Generi(uint i){
   generi_table->insertRow(i);
   text_generi = new QTextEdit(this);
   generi_table->setCellWidget(i,0,text_generi);
   add_generi = new QPushButton("+",this);
   generi_table->setCellWidget(i,1,add_generi);
   connect(add_generi, SIGNAL(clicked()),this,SLOT(Add_generi()));
}
void Main_View::Add_generi(){
    if(text_generi->toPlainText().isNull() || text_generi->toPlainText().isEmpty())
       static_cast<View*>(this)->showErorr(QObject::tr("Inserimento errato"), QObject::tr("Il valore inserito non è permesso"));
    else
        emit Generi_add(text_generi->toPlainText());
}
void Main_View::added_Autori(uint i){
   autori_table->insertRow(i);
   text_autori = new QTextEdit(this);
   autori_table->setCellWidget(i,0,text_autori);
   add_autori = new QPushButton("+",this);
   autori_table->setCellWidget(i,1,add_autori);
   connect(add_autori, SIGNAL(clicked()),this,SLOT(Add_autori()));
}
void Main_View::Add_autori(){
    if(text_autori->toPlainText().isNull() || text_autori->toPlainText().isEmpty())
       static_cast<View*>(this)->showErorr(QObject::tr("Inseriemento errato"), QObject::tr("Il valore inserito non è permesso"));
    else
        emit Autori_add(text_autori->toPlainText());
}
void Main_View::added_Libro(uint i,const QStringList* autori,const QStringList* generi){
    data->removeRow(i);
    data->insertRow(i);
    titolo=new QTextEdit(this);
    data->setCellWidget(i,0,titolo);
    autore=new QComboBox(this);
    autore->addItems(*autori);
    data->setCellWidget(i,1,autore);
    data_input = new QDateEdit(QDate::currentDate(),this);
    data->setCellWidget(i,2,data_input);
    genere=new QComboBox(this);
    genere->addItems(*generi);
    data->setCellWidget(i,3,genere);
    pagine = new QSpinBox(this);
    pagine->setRange(0,10000000);
    pagine->setSuffix(" page");
    data->setCellWidget(i,4,pagine);
    lettori = new QSpinBox(this);
    lettori->setRange(0,10000000);
    lettori->setSuffix(" people");
    data->setCellWidget(i,5,lettori);
    ebook=new QCheckBox(QObject::tr("Disponibilità\nebook"),this);
    data->setCellWidget(i,6,ebook);
    add=new QPushButton("+",this);
    data->setCellWidget(i,7,add);
    connect(add,SIGNAL(clicked(bool)),this,SLOT(Add_Libro()));

}
void Main_View::Add_Libro(){
    if(titolo->toPlainText().isEmpty() || titolo->toPlainText().isNull() || autore->currentText().isEmpty() || autore->currentText().isNull() || genere->currentText().isEmpty() || genere->currentText().isNull() || pagine->value()==0)
       static_cast<View*>(this)->showErorr(QObject::tr("Inseriemento errato"), QObject::tr("Il valore inserito non è permesso"));
else{
       emit Libro_add(titolo->toPlainText(),autore->currentText(),data_input->date(),genere->currentText(),pagine->value(),lettori->value(),ebook->isChecked());
    }

}
void Main_View::load_generi(const QStringList* g){
    int j=0;
    for(;j<generi_table->rowCount();j++){
        generi_table->removeRow(j);
    }
    j=0;
    for(auto i: *g )
       {generi_table->insertRow(j);
        QLabel* label=new QLabel(i,this);
        QPushButton* remove=new QPushButton("-",this);
        generi_table->setCellWidget(j,0,label);
        generi_table->setCellWidget(j,1,remove);
        connect(remove, &QPushButton::clicked,[this,remove]() {
                unsigned int row = generi_table->indexAt(remove->pos()).row();
              emit Remove_Generi(row);

    });
        j++;}
    added_Generi(j);
}
void Main_View::load_autori(const QStringList* g){
    int j=0;
    for(;j<autori_table->rowCount();j++){
        autori_table->removeRow(j);
    }
    j=0;
    for(auto i: *g)
       {autori_table->insertRow(j);
        QLabel* label=new QLabel(i,this);
        QPushButton* remove=new QPushButton("-",this);
        autori_table->setCellWidget(j,0,label);
        autori_table->setCellWidget(j,1,remove);
        connect(remove, &QPushButton::clicked,[this,remove]() {
        unsigned int row = autori_table->indexAt(remove->pos()).row();
        emit Remove_Autori(row);});
        j++;}
    added_Autori(j);
}
void Main_View::load_data(const QList<Libro*>& l){
    int j=0;
    for(;j<data->rowCount();j++){
        data->removeRow(j);
    }
    j=0;
    for(auto i: l ){
       data->insertRow(j);
       QLabel* titolo=new QLabel(i->getTitolo(),this);
       QLabel* autore=new QLabel(i->getAutore(),this);
       QLabel* datal= new QLabel(i->getData().toString(Qt::RFC2822Date),this);
       QLabel* genere=new QLabel(i->getGenere(),this);
       QLabel* pagine=new QLabel(QString::number(i->getPagine()),this);
       QLabel* preferenze= new QLabel(QString::number(i->getLettori()),this);
       QLabel* ebook=new QLabel(QVariant(i->getEbook()).toString(),this);
       data->setCellWidget(j,0,titolo);
       data->setCellWidget(j,1,autore);
       data->setCellWidget(j,2,datal);
       data->setCellWidget(j,3,genere);
       data->setCellWidget(j,4,pagine);
       data->setCellWidget(j,5,preferenze);
       data->setCellWidget(j,6,ebook);
       QPushButton* remove=new QPushButton("-",this);
       data->setCellWidget(j,7,remove);
       connect(remove, &QPushButton::clicked,[this,remove]() {
               uint row = data->indexAt(remove->pos()).row();
             emit Remove_Book(row);});
       j++;
    }
}
void Main_View::addGeneri(const QString& p){
     generi_table->insertRow(generi_table->rowCount()-1);
     generi_table->setCellWidget(generi_table->rowCount()-2,0,new QLabel(p,this));
     QPushButton* remove=new QPushButton("-",this);
     generi_table->setCellWidget(generi_table->rowCount()-2,1,remove);
     connect(remove, &QPushButton::clicked,[this,remove]() {
             unsigned int row = generi_table->indexAt(remove->pos()).row();
             emit Remove_Generi(row);
 });
}
void Main_View::addAutori(const QString& p){
    autori_table->insertRow(autori_table->rowCount()-1);
    autori_table->setCellWidget(autori_table->rowCount()-2,0,new QLabel(p,this));
    QPushButton* remove=new QPushButton("-",this);
    autori_table->setCellWidget(autori_table->rowCount()-2,1,remove);
    connect(remove, &QPushButton::clicked,[this,remove]() {
            unsigned int row = autori_table->indexAt(remove->pos()).row();
            emit Remove_Autori(row);
});
}
void Main_View::addLibro(const Libro* p){
    data->insertRow(data->rowCount()-1);
    data->setCellWidget(data->rowCount()-2,0,new QLabel(p->getTitolo(),this));
    data->setCellWidget(data->rowCount()-2,1,new QLabel(p->getAutore(),this));
    data->setCellWidget(data->rowCount()-2,2,new QLabel(p->getData().toString(Qt::RFC2822Date),this));
    data->setCellWidget(data->rowCount()-2,3,new QLabel(p->getGenere(),this));
    data->setCellWidget(data->rowCount()-2,4,new QLabel(QString::number(p->getPagine()),this));
    data->setCellWidget(data->rowCount()-2,5,new QLabel(QString::number(p->getLettori()),this));
    data->setCellWidget(data->rowCount()-2,6,new QLabel(QVariant(p->getEbook()).toString(),this));
    QPushButton* remove=new QPushButton("-",this);
    data->setCellWidget(data->rowCount()-2,7,remove);
    connect(remove, &QPushButton::clicked,[this,remove](){
           unsigned int row = data->indexAt(remove->pos()).row();
           emit Remove_Book(row);
});
}
void Main_View::removeAutori(uint i){
    autori_table->removeRow(i);
}
void Main_View::removeGeneri(uint i){
    generi_table->removeRow(i);
}
void Main_View::removeLibro(uint i){
    data->removeRow(i);
}
