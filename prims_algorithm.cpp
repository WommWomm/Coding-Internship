# include "prims_algorithm.h"

int extract_min(vector<vector<int>> &heap) {
    vector<int> storage_node;

    storage_node = heap[0];

    for(int i = 1; i < heap.size(); i++) {
        if(storage_node[1]>heap[i][1]) {
            storage_node[1] = heap[i][1];
        }
    }

    heap.erase(heap.begin()+(storage_node[0]-1));

    return storage_node[0];
}

bool contains(vector<vector<int>> &heap, int node) {

    for(int i = 0; i < heap.size(); i++) {
        if(heap[i][0] == node) {
            return true;
        }
    }

    return false;
}

bool distance_smaller_value(Distance_matrix distance_matrix,vector<vector<int>> heap, int node, int current_node) {

    for(int i = 0; i < heap.size(); i++) {
        if(heap[i][0] == node ) {
            if(distance_matrix.get_length(node,current_node)<heap[i][1] || heap[i][1] == -1) {
                return true;
            }
        }
    }

    return false;
}

vector<int> prims_algorithm(Distance_matrix distance_matrix, int number_nodes) {
    int current_node;

    vector<int> parent;

    vector<vector<int>> heap;

    for(int i = 0; i < number_nodes; i++) {
        heap[i][0] = i;
        heap[i][1] = -1;

        parent[i] = 0;
    }

    heap[0][0] = 0;

    while(!heap.empty()) {
        current_node = extract_min(heap);
        for(int i = 0; i < number_nodes, i != current_node; i++) {
            if(contains(heap,i) && distance_smaller_value(distance_matrix,heap,i,current_node)) {
                parent[i] = current_node;
                heap[i][1] = distance_matrix.get_length(i,current_node);
            }
        }
    }

    return parent;
}