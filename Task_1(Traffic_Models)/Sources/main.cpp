#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Traffic_Model.h"
#include "File_Manager.h"
#include "Poisson_Model.h"
#include "Uniform_Model.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Enter file name\n";
        return 1;
    }
    std::ifstream infile(argv[1]);
    if (!infile) return 1;
    File_Manager manager;
    Traffic_Model* model;
    std::vector<packet> packets;

    double time, param_1, param_2;
    std::string model_name;
    infile >> time >> model_name >> param_1 >> param_2;

    if (model_name == "Uniform") {
        model = new Uniform_Model(param_1, static_cast<int>(param_2));
    } else if (model_name == "Poisson") {
        model = new Poisson_Model(param_1, param_2);
    } else {
        std::cerr << "Unknown model name\n";
    }

    packets = model->Simulation(time);
    manager.Create_CSV(std::string(argv[1]) + ".csv", packets);

    delete model;

    return 0;
}
