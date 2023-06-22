#ifndef CHARTS_CONTROLLER_H
#define CHARTS_CONTROLLER_H
#include"controller.h"
#include"Model/model_data.h"
#include"View/view_chart.h"
class Charts_Controller:public Controller
{
    Q_OBJECT
    /*
     *Classe Charts_Controller rappresneta il modello per un controller di una view contenente un chart
    */
protected:
    //Costruttore
    explicit Charts_Controller();
public:
    //Costruttore
    explicit Charts_Controller(Model_Data*,View_Chart*,Controller*);
    //getter overridati
    Model_Data* getModel()const override;
    View_Chart* getView() const override;
public slots:
    //Slot overridato
    void onViewClosed() const override;

};

#endif // CHARTS_CONTROLLER_H
