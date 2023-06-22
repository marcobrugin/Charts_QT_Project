#include "generimodel.h"
const QMap<QString,uint>& GeneriModel::getData()const {
return l;
}
GeneriModel::GeneriModel(Storage* s){
    for(auto i: *(s->getGeneri())){
        int occorenze=0;
        for(auto j: s->getAlbum()){
            if(i.toLower()==j->getGenere().toLower())
                ++occorenze;

        }

        l.insert(i,occorenze);

    }
}
