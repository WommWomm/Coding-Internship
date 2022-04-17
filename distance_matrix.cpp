#include "distance_matrix.h"

int calculate_distance(vector<int> pin_1, vector<int> pin_2) {

    int result = abs(pin_1[0]-pin_2[0])+ abs(pin_1[1]-pin_2[1]);            //berechnet Abstand von vektoren in Manhatten
    return result;                                                                  //Metrik
}

vector<vector<int>> calculate_distance_matrix(vector<vector<int>> coordinates, int number_nodes) {

    vector<vector<int>> distance_matrix;
    int storage_number;

    for(int i = 0; i < number_nodes; i++) {                                 //berechnet eine Matrix bei der im Eintrag a_ij
                                                                            //der Abstand der Punkte i,j steht, wobei i und j
        vector<int> row;                                                    //i,j\in\mathbb{Z}^2 aus einer gegeben Liste an
                                                                            //ganzzahligen Koordinaten ist
        for(int j = 0; j < number_nodes; j++) {

            storage_number = calculate_distance(coordinates[i],coordinates[j]);
            row.push_back(storage_number);
        }
        distance_matrix.push_back(row);
    }
    return distance_matrix;
}

Distance_matrix::Distance_matrix() {                                            //Standart Konstruktor technisch gesehen
                                                                                //nicht notwendig
}

Distance_matrix::Distance_matrix(vector<vector<int>> coordinates, int number_nodes) {

    distance_matrix = calculate_distance_matrix(coordinates,number_nodes);
}

int Distance_matrix::get_length(int _x, int _y) {

    if(_x < 0 || _x > distance_matrix.size() || _y < 0 || _y > distance_matrix.size()) {
        cout << "Bitte geben Sie eine gültige Kante ein!";
        exit(5);
    }

    return distance_matrix[_x][_y];
}

void Distance_matrix::print_distance_matrix() {

    for(int i = 0; i < distance_matrix.size(); i++) {

        for(int j = 0; j < distance_matrix[i].size();j++) {

            cout << distance_matrix[i][j] << " ";
        }
        cout << endl;
    }
}