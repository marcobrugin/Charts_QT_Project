#include "libro.h"
Libro::Libro(const QString& t , const QString& a, const QDate& d,const QString& g,uint p,uint l,bool e):
titolo(t),autore(a),data(d),genere(g),pagine(p),lettori(l),ebook(e){}
QString Libro::getTitolo() const{
    return titolo;
}
bool Libro::getEbook() const{
    return ebook;
}
QString Libro::getAutore() const{
    return autore;
}
QDate Libro::getData() const{
    return data;
}
QString Libro::getGenere() const{
    return genere;
}
uint Libro::getPagine() const{
    return pagine;
}
uint Libro::getLettori() const{
    return lettori;
}
void Libro::setEbook(bool a){
    ebook=a;
}
void Libro::setTitolo(const QString& a){
    titolo=a;
}
void Libro::setAutore(const QString& a){
    autore=a;
}
void Libro::setData(const QDate& d){
    data=d;
}

void Libro::setGenere(const QString& g){
    genere=g;
}
void Libro::setPagine(uint p){
    pagine=p;
}
void Libro::setLettori(uint l){
    lettori=l;
}
bool Libro::operator==(const Libro& l) const{
    return titolo.toLower()==l.titolo.toLower() && autore.toLower()==l.autore.toLower();
}
