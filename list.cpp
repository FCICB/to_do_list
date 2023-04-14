//
// Created by EGYPT on 2023-04-13.
//

#include "list.h"



bool list::AddTask(vector<task>added_tasks, string filename)
{
    bool test;
    test =handler.getFileData(filename,arr);

    if(!test) throw runtime_error("file can not be opened.");

    arr.insert(arr.end(),added_tasks.begin(),added_tasks.end());

    test =handler.writeDataToFile(filename,arr);

    if(!test) throw runtime_error("file can not be opened.");
}

int list::getArraySize() {
    return arr.size();
}

bool list::viewFileData(string filename)
{
    bool test;

    test =handler.getFileData(filename,arr);

    if(!test) throw runtime_error("file can not be opened.");

    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout<<"==================================\n";
        cout<<"task"<<i+1<<endl;cout<<arr[i]<<endl;
        cout<<"==================================";
    }
    return true;
}


void list::ediTask(string& filename,int index , int choice , string& update)
{
    try
    {
        handler.getFileData(filename,arr);
        task oldTask = arr[index-1];

        if(choice == 1)oldTask.setDescription(update);

        else if(choice == 2)oldTask.setDueDate(update);

        else if(choice == 3)oldTask.setStatus(update);

        else throw invalid_argument("invalid input, please enter valid one.\n");

        arr[index-1] = oldTask;

        handler.writeDataToFile(filename,arr);
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what();
    }

}

void list::deleteTask(string &fileName, int index)
{
    bool test = handler.getFileData(fileName,arr);

    if(!test) throw runtime_error("file can not be opened.");

    arr.erase(arr.begin()+(index-1));

    test = handler.writeDataToFile(fileName,arr);

    if(!test) throw runtime_error("file can not be opened.");
}


void list::swapTasks(string &fileName, int firstIndex, int secondIndex)
{
    bool test = handler.getFileData(fileName,arr);

    if(!test) throw runtime_error("file can not be opened.");

    swap(arr[firstIndex-1] , arr[secondIndex-1]);

    test = handler.writeDataToFile(fileName,arr);

    if(!test) throw runtime_error("file can not be opened.");

}
