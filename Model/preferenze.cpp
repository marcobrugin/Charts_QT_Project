#include "preferenzemodel.h"

PreferenzeModel::PreferenzeModel(Storage* s){
    for(auto i: *(s->getAutori())){
        uint somma=0;
        for(auto k: s->getAlbum()){
            if(i.toLower()==k->getAutore().toLower()){
                somma+=k->getLettori();
            }
        }
        l.insert(i,somma);
    }
}
const QMap<QString,uint>& PreferenzeModel::getData()const{
    return l;
}
