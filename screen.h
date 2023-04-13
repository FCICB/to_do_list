//
// Created by EGYPT on 2023-04-13.
//

#ifndef UPDATED_TO_DO_LIST_SCREEN_H
#define UPDATED_TO_DO_LIST_SCREEN_H
#include <iostream>
#include<fstream>
#include <vector>
#include "task.h"
#include "list.h"
using namespace std;


class screen {

public:
    void run(string& fileName);
    void addTasks(list& ToDoList, string& fileName);
    void editTasks(list& ToDoList, string& fileName);
    void viewData(list& ToDoList, string& fileName);


};


#endif //UPDATED_TO_DO_LIST_SCREEN_H
