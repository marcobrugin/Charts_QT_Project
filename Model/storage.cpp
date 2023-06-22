#include "storage.h"
Storage::Storage()
{
generi=new QStringList();
autori=new QStringList();
album=QList<Libro*>();
}
Storage::Storage(QJsonDocument * a, const QString & m):generi(new QStringList),autori(new QStringList),album(QList<Libro*>()),file(m){
    if(a){
        CreateGeneri(a);
        CreateAutori(a);
        CreateData(a);
    }
}
void Storage::CreateGeneri(QJsonDocument* d){
    QJsonObject object = d->object();
    QJsonArray array = object["generi"].toArray();
    for(auto  v : array)
        if(!containsGeneri(v.toString()))
            generi->append(v.toString());
}
void Storage::CreateAutori(QJsonDocument * d){
    QJsonObject object= d->object();
    QJsonArray array=object["autori"].toArray();
    for(auto i : array )
        if(!containsAutori(i.toString()))
            autori->append(i.toString());
}
void Storage::CreateData(QJsonDocument * d){
    QJsonObject object= d->object();
    QJsonArray array=object["data"].toArray();
    for(auto i : array ){
        Libro* l=new Libro(i.toObject().value("titolo").toString(),
                           i.toObject().value("autore").toString(),
                           QDate::fromString(i.toObject().value("data").toString(),"dd/MM/yyyy"),
                           i.toObject().value(("genere")).toString(),
                           i.toObject().value("pagine").toInt(),
                           i.toObject().value("lettori").toInt(),
                           i.toObject().value("ebook").toBool());
        if(verifica(l)){
         album.push_back(l);
        }
        else{
            delete l;
        }

    }
}
bool Storage::verifica(const Libro* l)const{
    return containsGeneri(l->getGenere()) && containsAutori(l->getAutore()) && !contains(*l);
}
QStringList* Storage::getGeneri() const{
    return generi;
}
QStringList* Storage::getAutori() const{
    return autori;
}
const QList<Libro*>& Storage::getAlbum() const{
    return album;
}
uint Storage::getDim() const{
    return album.size();
}
uint Storage::getDimGeneri() const{
    return generi->size();
}
uint Storage::getDimAutori() const{
    return autori->size();
}
//distruttore polimorfo
Storage::~Storage(){
    delete generi; delete autori;
    for(auto i : album)
        delete i;
}
//overloading del metodo contains per mantenere la scalabilità
bool Storage::contains(const Libro& l) const{
    for(auto i: album){
        if(*i==l) return true;
    }
    return false;
}
bool Storage::containsGeneri(const QString& l) const{
    return generi->contains(l,Qt::CaseInsensitive);
}
bool Storage::containsAutori(const QString& l) const{
    return autori->contains(l,Qt::CaseInsensitive);
}
QString Storage::getPath() const{
    return file;
}
void Storage::SetPath(const QString& p){
    file=p;
}
void Storage::addGenere(const QString& a) {
        generi->push_back(a);
}
void Storage::addAutore(const QString& a) {

        autori->push_back(a);
}
//Eseguibile solo se ne rimane almeno uno
void Storage::removeGeneri(uint i) {
    generi->removeAt(i);
}
void Storage::removeAutori(uint i) {
    autori->removeAt(i);
}
void Storage::add(Libro* p){
    album.push_back(p);
}
void Storage::remove(uint i){
    Libro* p=album.at(i);
    album.removeAt(i);
    delete p;
}
bool Storage::Search_Autori(const QString& p){
    for(auto i: album)
     {   if(i->getAutore().toUpper()==p.toUpper())
            return true;}
    return false;
}
bool Storage::Search_Generi(const QString& p){
    for(auto i: album)
     {   if(i->getGenere().toUpper()==p.toUpper())
            return true;}
    return false;
}
