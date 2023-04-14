//
// Created by EGYPT on 2023-04-13.
//

#include "task.h"

void task::setDescription(string &desc)
{
    size_t length = desc.length();

    length = ((length < 200) ? length : 199);

    if(length == 199)throw invalid_argument("Too much characters the system will take the first 200 characters only.");

    desc.copy(description,length);

    description[length]='\0';

}

void task::setDueDate(string &date)
{
    size_t length = date.length();

    length = ((length < 10) ? length : 9);

    if(length == 9)throw invalid_argument("Too much characters the system will take the first 10 characters only.");

    date.copy(dueDate,length);

    dueDate[length]='\0';
}

void task::setStatus(string status)
{
    size_t length = status.length();

    length = ((length < 50) ? length : 49);

    if(length == 49)throw invalid_argument("Too much characters the system will take the first 50 characters only.");

    status.copy(completeStatus,length);

    completeStatus[length]='\0';
}

string task::getStatus()
{
    return completeStatus;
}

string task::getDescription()
{
    return description;
}

string task::getDueDate()
{
    return dueDate;
}

task::task(string description, string date, string status)
{
    setDescription(description);

    setDueDate(date);

    setStatus(status);
}

ostream &operator<<(ostream &output, task &t)
{
    output<<t.description<<"\n"<<t.dueDate<<"\n"<<t.completeStatus<<"\n";

    return output;
}

istream &operator>>(istream &input, task &t)
{
    if (input.peek() == '\n')
    {
        input.ignore();
    }
    input.get(t.description, 200,'\n');

    input.ignore();

    input >>t.dueDate;

    if (input.peek() == '\n')
    {
        input.ignore();
    }

    input.get(t.completeStatus, 50,'\n');

    return input;
}
