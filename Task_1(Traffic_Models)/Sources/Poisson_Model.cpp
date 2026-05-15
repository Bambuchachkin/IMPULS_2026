#include "Poisson_Model.h"

Poisson_Model::Poisson_Model(double intensity, double average_size) : p_intensity(intensity), p_average_size(average_size) {
    P_interval = std::exponential_distribution<double>(p_intensity);
    P_size = std::exponential_distribution<double>(1.0/p_average_size);
    Generator = std::mt19937(std::random_device{}());
}

Poisson_Model::~Poisson_Model() {}


std::vector<packet> Poisson_Model::Simulation(double time) {
    double current_time = 0;
    std::vector<packet> packets;
    double current_size = 0;
    while (current_time < time) {
        current_time += P_interval(Generator);
        current_size = P_size(Generator);
        if (current_size < 1) {
            current_size = 1;
        }
        packets.push_back(packet{current_time, static_cast<int>(round(current_size))});
    }
    return packets;
}
