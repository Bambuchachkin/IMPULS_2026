#ifndef POISSON_MODEL_H
#define POISSON_MODEL_H
#include "Traffic_Model.h"
#include <random>

class Poisson_Model:public Traffic_Model {
private:
    double p_intensity;
    double p_average_size;
    std::exponential_distribution<double> P_interval;
    std::exponential_distribution<double> P_size;
    std::mt19937 Generator;
public:
    Poisson_Model(double intensity, double average_size);
    ~Poisson_Model();
    std::vector<packet> Simulation(double time) override;
};

#endif //POISSON_MODEL_H
