#include "autorimodel.h"

AutoriModel::AutoriModel(Storage* s){
    for(auto i : *(s->getAutori())){
        int occorences=0;
    for(auto k: (s->getAlbum())){
        if(i.toLower()==k->getAutore().toLower())
            ++occorences;

    }
      l.insert(i,occorences);

    }
}
const QMap<QString,uint>& AutoriModel::getData()const{
    return l;
}
