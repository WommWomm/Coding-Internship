#include "get_data_stp.h"
#include "distance_matrix.h"
#include "prims_algorithm.h"

using namespace std;

int main() {
    int number_nodes;
    vector<vector<int>> coordinates;

    get_data_from_File(number_nodes,coordinates);

    Distance_matrix distance_matrix(coordinates, number_nodes);

    prim(distance_matrix,number_nodes);

    return 0;
}
