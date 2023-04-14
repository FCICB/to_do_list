//
// Created by EGYPT on 2023-04-13.
//

#include "fileHandling.h"

bool fileHandling::getFileData(string filename, vector<task> &arr)
{
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

bool fileHandling::writeDataToFile(string filename, vector<task> &arr)
{
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
