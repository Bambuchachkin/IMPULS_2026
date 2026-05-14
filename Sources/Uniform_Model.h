#ifndef UNIFORM_MODEL_H
#define UNIFORM_MODEL_H
#include "Traffic_Model.h"
#include "Uniform_Model.h"

class Uniform_Model:public Traffic_Model {
private:
    double p_interval;
    int p_size;
public:
    Uniform_Model(double interval, int size);
    ~Uniform_Model();
    std::vector<packet> Simulation(double time) override;
};

#endif //UNIFORM_MODEL_H
