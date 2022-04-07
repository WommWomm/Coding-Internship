#ifndef MAIN_CPP_DISTANCE_MATRIX_H
#define MAIN_CPP_DISTANCE_MATRIX_H

#include <vector>
#include "Pin.h"

using namespace std;

class Distance_matrix {
private:
    vector<vector<int>> distance_matrix;

public:
    Distance_matrix();
    Distance_matrix(int number_nodes,vector<Pin> coordinates);

    int get_length(int _x,int _y);

    vector<vector<int>> get_distance_matrix() {
        return distance_matrix;
    }

    void set_distance_matrix(vector<vector<int>> _distance_matrix) {
        distance_matrix = _distance_matrix;
    }

    void print_distance_matrix();
};

vector<vector<int>> calculate_distance_matrix(int number_nodes,vector<Pin> coordinates);


#endif //MAIN_CPP_DISTANCE_MATRIX_H
