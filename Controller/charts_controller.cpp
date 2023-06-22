#include "charts_controller.h"

Charts_Controller::Charts_Controller(){}

Charts_Controller::Charts_Controller(Model_Data* m,View_Chart* v,Controller* c):Controller(m,v,c){}

Model_Data* Charts_Controller::getModel()const {
    return static_cast<Model_Data*>(model);
}
View_Chart* Charts_Controller::getView() const{
    return static_cast<View_Chart*>(view);
}
void Charts_Controller::onViewClosed() const{
    delete this;
}
