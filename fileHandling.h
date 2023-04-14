//
// Created by EGYPT on 2023-04-13.
//

#ifndef UPDATED_TO_DO_LIST_FILEHANDLING_H
#define UPDATED_TO_DO_LIST_FILEHANDLING_H
#include <string>
#include <iostream>
#include <vector>
#include "task.h"
#include <fstream>
using namespace std;

class fileHandling {
public:
    bool getFileData(string filename,vector<task>&arr );
    bool writeDataToFile(string filename, vector<task>&arr);
};


#endif //UPDATED_TO_DO_LIST_FILEHANDLING_H
