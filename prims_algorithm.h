#include <vector>
#include "distance_matrix.h"

#ifndef MAIN_CPP_PRIMS_ALGORITHM_H
#define MAIN_CPP_PRIMS_ALGORITHM_H

int extract_min(vector<vector<int>> &heap);

bool contains(vector<vector<int>> &heap, int node);

bool distance_smaller_value(Distance_matrix distance_matrix,vector<vector<int>> heap, int node, int current_node);

vector<int> prims_algorithm(Distance_matrix distance_matrix, int number_nodes);

#endif //MAIN_CPP_PRIMS_ALGORITHM_H
