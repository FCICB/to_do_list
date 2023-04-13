//
// Created by EGYPT on 2023-04-13.
//

#ifndef UPDATED_TO_DO_LIST_TASK_H
#define UPDATED_TO_DO_LIST_TASK_H
#include <string>
#include <iostream>
using namespace std;

class task {
private:
    char description[200],dueDate[10],completeStatus[50];

public:
    task(string="" , string="" , string="");
    void setDescription(string &desc);
    void setDueDate(string &date);
    void setStatus(string status);
    string getStatus();
    string getDescription();
    string getDueDate();
    friend ostream& operator<<(ostream& output,  task& t);
    friend istream& operator>>(istream& input,  task& t);

};


#endif //UPDATED_TO_DO_LIST_TASK_H
