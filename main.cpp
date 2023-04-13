#include <iostream>
#include "screen.h"
using namespace std;

int main() {
    string fileName = "data.txt";
    screen sc;
    sc.run(fileName);
    return 0;
}
