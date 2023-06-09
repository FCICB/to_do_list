//
// Created by EGYPT on 2023-04-13.
//

#include "screen.h"

void screen::run(string &fileName)
{

    cout<<"welcome to our To Do List.\n";
    cout<<"==============================================\n";
    list ToDoList;

    while(true){
        size_t choice;
        cout<<"Here is all the features that you have.\n";
        cout<<"1. Add new tasks.\n2.Edit specific task.\n3. View tasks.\n4.delete specific task\n5.Swap two tasks.\n6.Exit.\n";
        cout<<"enter the feature you want to try.\n";
        cin>>choice;
        if(choice == 1)
        {
            addTasks(ToDoList,fileName);
        }
        else if(choice == 2)
        {
            cout<<"welcome to the modification feature.\n  here is the content of the file.\n";
            try
            {
                editTasks(ToDoList,fileName);
            }
            catch (const std::exception& ex)
            {
                cout << "Error: " << ex.what();
            }
        }
        else if(choice == 3)
        {
            viewData(ToDoList,fileName);
        }
        else if(choice == 4)
        {
            cout<<"please enter the index to be deleted.";
            int index;cin>>index;
            ToDoList.deleteTask(fileName,index);
        }
        else if(choice == 5)
        {
            cout<<"Welcome to the swap feature!\n";
            cout<<"please enter the rwo indices you want to swap.";
            int firstIndex,secondIndex;

            cin>>firstIndex>>secondIndex;

            if(firstIndex < 0  || firstIndex > ToDoList.getArraySize() || secondIndex < 0  || secondIndex > ToDoList.getArraySize() )throw invalid_argument("The index you entered does not exsit, please enter valid index.");

            ToDoList.swapTasks(fileName, firstIndex, secondIndex);
        }

        else if(choice == 6)break;

        else throw invalid_argument("You have entered an invalid input please enter a number between 1 and 5.");


    }
    cout<<"End of program!\nThanks for using our list.\n";
}

void screen::addTasks(list& ToDoList, string& fileName)
{
    cout<<"How many tasks you want to add?\n";
    int numberOfTasks;cin>>numberOfTasks;
    task in;
    vector<task>tasks;
    while (numberOfTasks--)
    {
        cout<<"Enter the task description, due date and complete status.\n";
        try
        {
            cin>>in;
        }
        catch (const std::exception& ex)
        {
            cout << "Error: " << ex.what();
        }
        tasks.push_back(in);
    }
    try
    {
        ToDoList.AddTask(tasks,fileName);
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what();
    }
}

void screen::editTasks(list& ToDoList,string& fileName)
{
    cout<<"welcome to the modification feature.\n  here is the content of the file.\n";
    ToDoList.viewFileData(fileName);
    int index ,choice;
    cout<<"enter the index to modify:\n";cin>>index;
    cout<<"=============================================\n";
    cout<<"1. modify description,\n2. modify due date,\n3. modify status.\n";
    cin>>choice;
    string update;
    if(choice == 1)
    {
        cout<<"enter the modified description:\n";
        cin.ignore();
        getline(cin,update);
    }
    else if(choice == 2)
    {
        cout<<"enter the modified date: \n";
        cin>>update;
    }
    else if(choice == 3)
    {
        cout<<"enter the modified status: \n";
        cin.ignore();
        getline(cin,update);
    }
    try
    {
        ToDoList.ediTask(fileName,index,choice,update);
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what();
    }
}

void screen::viewData(list& ToDoList, string& fileName) {
    cout<<"here is your to do list.\n=================================================================================\n";
    try
    {
        ToDoList.viewFileData(fileName);
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what();
    }
    cout<<"===============================================================================================\n";

}
