# include "prims_algorithm.h"
#include <iostream>

bool compare_node_value(vector<int> node_1,vector<int> node_2) {
    if(node_1[1] == -1 ) {
        return true;
    } else if(node_1[1]>node_2[1]) {
        return true;
    } else {
        return false;
    }
}

int extract_min(vector<vector<int>> &heap) {
    vector<int> storage_node;

    storage_node = heap[0];

    for(int i = 1; i < heap.size(); i++) {
        if(compare_node_value(storage_node,heap[i]) && heap[i][1] != -1) {
            storage_node[0] = heap[i][0];
            storage_node[1] = heap[i][1];
        }
    }

    cout << storage_node[0] << endl;

    int storage_number = storage_node[0];

    heap.erase(heap.begin()+storage_number);

    //cout << storage_number<< endl;

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

bool distance_smaller_value(Distance_matrix distance_matrix,vector<vector<int>> heap, int current_node, int compare_node) { //ich denke hier liegt Problem

    if(distance_matrix.get_length(current_node,compare_node)<heap[compare_node][1] || heap[compare_node][1] == -1) {
        return true;
    }

    return false;
}

int find_position_of(vector<vector<int>> heap,int node) {
    for(int i = 0; i < heap.size(); i++) {
        if(node == heap[i][0]) {
            return i;
        }
    }
    cout << "Bitte geben Sie einen Knoten ein der in heap enthalten ist: 0 has been returned" << endl;
    return 0;
}

vector<int> prims_algorithm(Distance_matrix distance_matrix, int number_nodes) {
    int current_node;

    vector<int> parent;

    vector<vector<int>> heap;
    vector<int> node(2);

    for(int i = 0; i < number_nodes; i++) {
        node[0] = i;
        node[1] = -1;

        heap.push_back(node);

        parent.push_back(-1);
    }

    heap[0][0] = 0;

    while(!heap.empty()) {

        current_node = extract_min(heap);

        cout << current_node << endl;

        for(int i = 0; i < number_nodes; i++) {

            if(i != current_node) {
                //cout << i << endl;
                //cout << endl;

                if(contains(heap,i) && distance_smaller_value(distance_matrix,heap,i,current_node)) {

                    parent[i] = current_node;

                    int x = find_position_of(heap,i);

                    heap[x][1] = distance_matrix.get_length(i,current_node);

                    //cout << i << endl;
                    //cout << heap[x][1] << endl;

                    //cout << distance_matrix.get_length(i,current_node) << endl;
                }
            }
        }
    }

    return parent;
}