#include <iostream>
#include <vector>
#include "pin.h"
#include "get_data_stp.h"

using namespace std;

void print_matrix(vector<vector<int>> matrix) {

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size();j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int number_nodes = 0;
    vector<pin> coordinates;

    get_data_from_File(&number_nodes,&coordinates);               //schließt Instanz

    vector<vector<int>> distance_matrix;
    int storage_number;

    for(int i = 0; i < number_nodes; i++) {

        vector<int> row;

        for(int j = i + 1; j < number_nodes; j++) {
            storage_number = calculate_distance(coordinates[i],coordinates[j]);
            row.push_back(storage_number);
        }

        distance_matrix.push_back(row);
    }

    print_matrix(distance_matrix);
    cout << distance_matrix[2][5] << endl;

    return 0;
}
