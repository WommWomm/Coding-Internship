#include <iostream>
#include <vector>
#include <algorithm>
#include "get_data_stp.h"
#include "distance_matrix.h"
#include "prims_algorithm.h"

using namespace std;

void print_matrix(vector<vector<int>> coordinates) {

    for(int i = 0; i < coordinates.size(); i++) {

        for(int j = 0; j < coordinates[i].size(); j++) {
            cout << coordinates[i][j] << " ";
        }

        cout << endl;
    }
}

void print_Baum(vector<int> Baum) {
    for(int i = 0; i < Baum.size(); i++) {
        cout << Baum[i] << endl;
    }
}

int main() {
    int number_nodes = 10;
    vector<vector<int>> coordinates;
    vector<int> Baum;

    vector<int> parent;

    vector<vector<int>> heap;
    vector<int> v1(2);

    get_data_from_File(number_nodes,coordinates);

    Distance_matrix distance_matrix(number_nodes, coordinates);

    //bool val = distance_smaller_value(distance_matrix,heap,7,5);

    //cout << val << endl;

    Baum = prims_algorithm(distance_matrix,number_nodes);

    //print_Baum(Baum);

    return 0;
}
