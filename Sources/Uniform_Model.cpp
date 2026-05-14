#include "Uniform_Model.h"
Uniform_Model::Uniform_Model(double interval, int size) : p_interval(interval), p_size(size) {}

Uniform_Model::~Uniform_Model() {}

std::vector<packet> Uniform_Model::Simulation(double time) {
    double current_time = 0;
    std::vector<packet> packets;
    while (current_time < time) {
        current_time += p_interval;
        packets.push_back(packet(current_time, p_size));
    }
    return packets;
}