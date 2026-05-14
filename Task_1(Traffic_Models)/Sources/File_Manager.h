#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
#include <vector>
#include "Traffic_Model.h"

class File_Manager {
public:
    File_Manager();
    ~File_Manager();
    void Create_CSV(std::string name, std::vector<packet> packets);
};



#endif //FILE_MANAGER_H
