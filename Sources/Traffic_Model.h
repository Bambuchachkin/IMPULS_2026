#ifndef TRAFFIC_MODEL_H
#define TRAFFIC_MODEL_H
#include <vector>

struct packet {
    double time;
    int size;
};

class Traffic_Model {
public:
    Traffic_Model();
    virtual ~Traffic_Model();
    virtual std::vector<packet> Simulation(double time);
};



#endif //TRAFFIC_MODEL_H
