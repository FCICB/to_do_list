//
// Created by EGYPT on 2023-04-13.
//

#include "list.h"



bool list::AddTask(vector<task>added_tasks, string filename) {
    bool test;
    test =handler.getFileData(filename,arr);
    if(!test) throw invalid_argument("file can not be opened.");
    arr.insert(arr.end(),added_tasks.begin(),added_tasks.end());
    test =handler.writeDataToFile(filename,arr);
    if(!test) throw invalid_argument("file can not be opened.");
}

int list::getArraySize() {
    return arr.size();
}

bool list::viewFileData(string filename) {
    bool test;
    test =handler.getFileData(filename,arr);
    if(!test) throw invalid_argument("file can not be opened.");
    for(int i = 0 ; i < arr.size() ; i++){
        cout<<"==================================\n";
        cout<<"task"<<i+1<<endl;cout<<arr[i]<<endl;
        cout<<"==================================";
    }
}


void list::ediTask(string& filename,int index , int choice , string& update) {
    handler.getFileData(filename,arr);
    try {
        task oldTask= handler.ediTask(filename,index,choice,update,arr);
        arr[index-1] = oldTask;
        handler.writeDataToFile(filename,arr);
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what();
    }

}

void list::deleteTask(string &fileName, int index) {
    bool test = handler.getFileData(fileName,arr);
    if(!test) throw invalid_argument("file can not be opened.");
    arr.erase(arr.begin()+(index-1));
    test = handler.writeDataToFile(fileName,arr);
    if(!test) throw invalid_argument("file can not be opened.");
}
