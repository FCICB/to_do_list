//
// Created by EGYPT on 2023-04-13.
//

#include "fileHandling.h"

bool fileHandling::getFileData(string filename, vector<task> &arr) {
    fstream myFile;
    myFile.open(filename, ios::in);
    if(myFile.is_open())
    {
        myFile.seekg(0);

        task temp;

        arr.clear();

        while(myFile >> temp)arr.push_back(temp);

        return true;
    }
    else
    {
        myFile.close();
        return false;
    }

}

bool fileHandling::writeDataToFile(string filename, vector<task> &arr) {
    fstream myFile;
    myFile.open(filename, ios::out);
    if(myFile.is_open())
    {
        myFile.seekg(0);
        for(auto &i : arr)
        {
            myFile << i;
        }
        return true;
    }
    else
    {
        myFile.close();
        return false;
    }

}

task fileHandling::ediTask(string& filename,int index , int choice , string& update,vector<task> &arr) {
    fstream myFile;

    myFile.open(filename, ios::in | ios::out);

    if(myFile.is_open())
    {
        myFile.seekg(0);

        task oldTask = arr[index-1];

        if(choice == 1)oldTask.setDescription(update);

        else if(choice == 2)oldTask.setDueDate(update);

        else if(choice == 3)oldTask.setStatus(update);

        else throw invalid_argument("invalid input, please enter valid one.\n");

        return oldTask;
    }
    else myFile.close();throw invalid_argument("file can not be opened.");


}
