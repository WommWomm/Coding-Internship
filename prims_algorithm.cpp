#include "prims_algorithm.h"
/*
 Die Knoten werden durch die Zahlen 0,...,n-1 dargestellt und der Graph durch eine Adjazenzmatrix, welche an
 der Stelle a_ij das Gewicht der Kante enthält die i und j verbindet. Sollten i und j nicht adjazent seien enthält
 die Matrix eine 0 an dieser Stelle. Da wird von positiven ganzzahligen Gewichten ausgehen nehmen wir keine Kanten die
 nicht existieren. Außerdem ist in unser speziellen Situation eh nur die Diagonale 0, da wir einen vollständigen
 ungerichteten Graphen ohne Schleifen betrachten. Die Gewichte der Kante entsprechen genau dem Abstand zwischen dem
 Pins i,j und unsere Knoten repräsentieren die Pins.

 */
int extract_min(vector<int> key, vector<bool> nodes_mst, int number_nodes) {

    int min = INT_MAX;                                                              //gibt den Index eines Elementes
    int min_index;                                                                  //minimalen Schlüssels von einem Knoten
                                                                                    //der noch nicht im Spannbaum ist zurück
    for(int i = 0; i < number_nodes; i++) {
        if(nodes_mst[i] == false && key[i] < min) {                                  //mst_set hält fest, ob ein Knoten
            min = key[i];                                                           //bereits mit Spannbaum im Spannbaum
            min_index = i;                                                          //enthalten ist
        }
    }

    return min_index;
}

void print_mst(vector<int> parent, Distance_matrix distance_matrix, int number_nodes) {

    int storage_sum = 0;                                                                        //Momentane Variante den MST
                                                                                            //zurückzugeben: als Ausdruck
    cout << "Edge \tWeight\n";                                                              //in der Konsole

    for(int i = 1; i < number_nodes; i++) {
        cout << i+1 << "-" << parent[i]+1 << " \t" << distance_matrix.get_length(i,parent[i])<<endl;
    }

    for(int i = 1; i < number_nodes; i++) {
        storage_sum += distance_matrix.get_length(i,parent[i]);
    }

    cout << storage_sum << endl;
}

void prim(Distance_matrix distance_matrix, int number_nodes) {

    vector<int> parent(number_nodes);                      //Wird Am Ende in Position i den Elternknoten von i enthalten
    vector<int> key(number_nodes);                                  //realisiert Priority Queue
    vector<bool> nodes_mst(number_nodes);

    for(int i = 0; i < number_nodes; i++) {                      //setzt das Gewicht aller Knoten auf \infinty am Anfang
        key[i] = INT_MAX;
        nodes_mst[i] = false;                               //Am Anfang ist der Spannbaum leer
    }

    key[0] = 0;                              //setzt das Gewicht eines Knotens auf 0 damit dieser als erstes gewählt wird
    parent[0] = -1;                            //Dieser Knoten ist die Wurzel

    for(int count = 0; count < number_nodes - 1; count++) {             //Wir müssen n-1 Kanten hinzufügen,
                                                                        //um einen Baum zu erhalten
        int current_node = extract_min(key, nodes_mst, number_nodes);   //wählt Knoten minimales Gewichtes
        nodes_mst[current_node] = true;                                              //und fügt in Spannbaum hinzu

        for(int i = 0; i < number_nodes; i++) {                             //aktualisiert Gewichte der Knoten
                                                                            //ein Knoten hat als Gewicht stets
            int distance = distance_matrix.get_length(current_node,i);      //den Abstand zum current_node falls adjazent

            if(distance && nodes_mst[i] == false && distance < key[i]) {    //wir wählen später dann erneut Knoten
                parent[i] = current_node;                                   //anhand minimalen Gewichtes, also der gerade
                key[i] = distance;                                          //als nächstes zu erreichen ist und noch nicht
            }                                                               //erreicht wurde und speichern die Kante in dem
        }                                                                   //wir parent festsetzen
    }

    print_mst(parent, distance_matrix, number_nodes);
}
