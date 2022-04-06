#include <iostream>
#include <vector>
#include "pin.h"
#include "get_data_stp.h"

using namespace std;

int main() {
    int number_nodes = 0;
    vector<pin> coordinates;

    get_data_from_File(&number_nodes,&coordinates);               //schließt Instanz

    return 0;
}
