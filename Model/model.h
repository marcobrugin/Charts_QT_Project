#ifndef MODEL_H
#define MODEL_H


class Model
{
    /*
     * Classe base polimorfa Model rappresenta la base della gerarchia dei modelli
     */
protected:
    //Costruttore
    explicit Model();
public:
    //Distruttore Virtuale
   virtual  ~Model();
};

#endif // MODEL_H
