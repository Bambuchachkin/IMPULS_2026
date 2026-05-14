#include "File_Manager.h"
#include <fstream>

File_Manager::File_Manager() {}

File_Manager::~File_Manager() {}

void File_Manager::Create_CSV(std::string name, std::vector<packet> packets) {
    std::ofstream outfile(name);
    for (const auto& p : packets) outfile << p.time << "," << p.size << "\n";
}


