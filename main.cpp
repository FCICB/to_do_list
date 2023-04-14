#include <iostream>
#include "screen.h"
using namespace std;

int main() {
    string fileName = "data.txt";
    screen sc;
    try
    {
        sc.run(fileName);
    }
    catch (const std::exception& ex)
    {
        cout << "Error: " << ex.what();
    }

    return 0;
}
