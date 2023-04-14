//
// Created by EGYPT on 2023-04-13.
//

#ifndef UPDATED_TO_DO_LIST_LIST_H
#define UPDATED_TO_DO_LIST_LIST_H
#include <string>
#include <iostream>
#include<vector>
#include <fstream>
#include "task.h"
#include "fileHandling.h"
class list {
private:
    vector<task>arr;
    fileHandling handler;
public:
    bool AddTask(vector<task>added_tasks, string filename);
    int getArraySize();
    bool viewFileData(string filename);
    void ediTask(string& filename,int index , int choice , string& update);
    void deleteTask(string& fileName , int index);
    void swapTasks(string& fileName, int firstIndex , int secondIndex);
};


#endif //UPDATED_TO_DO_LIST_LIST_H
