#ifndef MAIN_CPP_DISTANCE_MATRIX_H
#define MAIN_CPP_DISTANCE_MATRIX_H

#include <vector>
#include <iostream>

using namespace std;

class Distance_matrix {
private:
    vector<vector<int>> distance_matrix;

public:
    Distance_matrix();
    Distance_matrix(vector<vector<int>> coordinates, int number_nodes);

    int get_length(int _x,int _y);

    void print_distance_matrix();
};

#endif //MAIN_CPP_DISTANCE_MATRIX_H
