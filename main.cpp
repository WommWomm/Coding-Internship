#include <iostream>
#include <vector>
#include <algorithm>
#include "get_data_stp.h"
#include "distance_matrix.h"
#include "prims_algorithm.h"

using namespace std;

void print_coordinates(vector<vector<int>> coordinates) {

    for(int i = 0; i < coordinates.size(); i++) {

        for(int j = 0; j < coordinates[i].size(); j++) {
            cout << coordinates[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {
    int number_nodes = 0;
    vector<vector<int>> coordinates;
    vector<int> Baum;

    get_data_from_File(number_nodes,coordinates);

    Distance_matrix distance_matrix(number_nodes, coordinates);

    Baum = prims_algorithm(distance_matrix,number_nodes);

    return 0;
}
