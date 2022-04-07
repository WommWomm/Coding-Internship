#include "distance_matrix.h"

Distance_matrix::Distance_matrix() {

}

Distance_matrix::Distance_matrix(int number_nodes,vector<Pin> coordinates) {
    distance_matrix = calculate_distance_matrix(number_nodes,coordinates);
}

int Distance_matrix::get_length(int _x, int _y) {
    int storage_number;

    if(_x < 1 || _x > distance_matrix.size()) {
        cout << "Bitte geben Sie eine gültige Kante ein!";
        exit(5);
    }

    if(_y < 1 || _y > distance_matrix.size()) {
        cout << "Bitte geben Sie eine gültige Kante ein!";
        exit(5);
    }

    if(_x>_y) {
        storage_number = _x;
        _x =_y;
        _y = storage_number;
    }
    return distance_matrix[_x-1][_y-1-_x];
}

vector<vector<int>> calculate_distance_matrix(int number_nodes,vector<Pin> coordinates) {

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

    return distance_matrix;
}

void Distance_matrix::print_distance_matrix() {

    for(int i = 0; i < distance_matrix.size(); i++) {

        for(int k = distance_matrix[i].size(); k < distance_matrix.size(); k++) {
            cout << 0 << " ";
        }

        for(int j = 0; j < distance_matrix[i].size();j++) {
            cout << distance_matrix[i][j] << " ";
        }
        cout << endl;
    }
}