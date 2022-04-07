#include <iostream>
#include <vector>
#include "Pin.h"
#include "get_data_stp.h"
#include "distance_matrix.h"

using namespace std;

int main() {
    int number_nodes = 0;
    vector<Pin> coordinates;

    get_data_from_File(&number_nodes,&coordinates);               //schließt Instanz

    Distance_matrix distance_matrix(number_nodes, coordinates);



    return 0;
}
