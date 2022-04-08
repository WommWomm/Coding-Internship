#include <iostream>
#include <vector>
#include "Pin.h"
#include "get_data_stp.h"
#include "distance_matrix.h"

using namespace std;

void print_edge_matrix(int edge_storage[][3], int number_edges) {

    for(int i = 0; i < number_edges; i++){
        for(int j = 0; j < 3; j++) {
            cout << edge_storage[i][j] << " ";
        }
        cout << endl;
    }
}

int compare_edges(const void* edge1 ,const void* edge2) {
    int* array1 = (int*)edge1;
    int* array2 = (int*)edge2;

    if(array1[2]<array2[2]) {
        return -1;
    } else if(array2[2]<array1[2]) {
        return 1;
    }else {
        return 0;
    }
}

int main() {
    int number_nodes = 0;
    vector<Pin> coordinates;

    get_data_from_File(&number_nodes,&coordinates);               //schließt Instanz

    Distance_matrix distance_matrix(number_nodes, coordinates);
    int storage_rounds = 0;

    int number_edges = number_nodes*(number_nodes-1);
    number_edges = number_edges/2;

    int edge_storage[number_edges][3];

    for(int i = 0; i < number_nodes; i++) {

        for(int j = i + 1; j < number_nodes; j++,storage_rounds++) {
            edge_storage[storage_rounds][0] = i+1;
            edge_storage[storage_rounds][1] = j+1;

            edge_storage[storage_rounds][2] = distance_matrix.get_length(i+1,j+1);
        }
    }

    print_edge_matrix(edge_storage,number_edges);

    qsort(edge_storage, number_edges, 3*sizeof(int),&compare_edges);

    cout << endl;

    print_edge_matrix(edge_storage,number_edges);

    return 0;
}
