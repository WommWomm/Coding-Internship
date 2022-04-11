#include "get_data_stp.h"
#include <iostream>

string get_file_name() {
    string name;

    cout << "Type in Filename of STP: " << endl;  //Fragt Namen ab
    cin  >> name;

    return name.append(".stp");
}

void control_if_open(fstream& MyFile) {
    if(MyFile.is_open()) {                //Überprüft ob Datei Instanz geöffnet wurde
        cout << "Die Datei wurde erfolgreich geoeffnet." << endl;
    } else {
        cout << "FEHLER: Die Datei konnte nicht geöffnet werden." << endl;
        exit(1);            //Weist diesem Fehler einen Exitcode zu und beendet Programm
    }
}

void goto_section_comment(fstream& MyFile) {
    string storage_word1;                                       //Ich suche nach einer Kombination von zwei Wörten
    string storage_word2;                                       //Die Strings repräsentieren stets zwei hintereinander
    //stehender Wörter im Dokument
    MyFile.clear();
    MyFile.seekg(0, ios::beg);                                  //setzt den Courser and den Anfang des Dokuments

    MyFile >> storage_word1;                                    //setzt den Courser auf die ersten zwe Worte
    MyFile >> storage_word2;

    while (MyFile.good()) {                                 //läuft so lange wir nicht am Ende des Dokuments sind

        if(storage_word1 == "SECTION" && storage_word2 == "Comment") {          //Abbruch bei der richtigen Wortkombination
            return;
        }

        storage_word1 = storage_word2;                      //setzt den Courser zwei Worte weiter
        MyFile >> storage_word2;
    }

    cout << "There is no SECTION Comment in the given data! "<< endl;       //Gibt "Fehler" zurück falls die SECTION
    exit(4);                                                          //nicht existiert
}

void goto_section_graph(fstream& MyFile) {
    string storage_word1;                                           //Funktionsweise und Code analog zu
    string storage_word2;                                           //goto_section_comment

    MyFile.clear();
    MyFile.seekg(ios::beg);

    MyFile >> storage_word1;
    MyFile >> storage_word2;

    while (MyFile.good()) {

        if(storage_word1 == "SECTION" && storage_word2 == "Graph") {
            return;
        }

        storage_word1 = storage_word2;
        MyFile >> storage_word2;
    }

    cout << "There is no SECTION Graph in the given data! "<< endl;
    exit(2);
}

void goto_section_coordinates(fstream& MyFile) {            //Funktionsweise und Code analog zu
    string storage_word1;                                   //goto_section_comment
    string storage_word2;

    MyFile.clear();
    MyFile.seekg(ios::beg);

    MyFile >> storage_word1;
    MyFile >> storage_word2;

    while (MyFile.good()) {

        if(storage_word1 == "SECTION" && storage_word2 == "Coordinates") {
            return;
        }

        storage_word1 = storage_word2;
        MyFile >> storage_word2;
    }

    cout << "There is no SECTION Coordinates in the given data!" << endl;
    exit(3);
}

int extract_number_of_nodes(fstream& MyFile) {
    string storage_word;
    int storage_number;

    MyFile >> storage_word;

    if(storage_word != "Nodes") {                                       //Überprüft, ob wir und in SECTION Comment befinden
        cout << "This method can only be called if you are already "
                "in SECTION Graph! 0 has been returned." << endl;
        return 0;
    }

    MyFile >> storage_number;                           //speichert Anzahl an Knoten und gibt Anzahl zurück
    return storage_number;
}

vector<vector<int>> extract_coordinates(fstream& MyFile, int number_nodes) {

    vector<vector<int>> coordinates;

    vector<int> storage_pin(2);
    string storage_string;
    int storage_number;

    MyFile >> storage_string;

    if(storage_string != "DD") {                                        //Überprüft ob wir in SECTION Coordinates sind
        cout << "This method can only be called if you are already "
                "in SECTION Coordinates! Empty vector has been returned." << endl;
        return coordinates;
    }

    MyFile >> storage_string;                       //setzt und an korrekte stelle um mit dem for loop zu beginnen

    for(int i = 0; i < number_nodes; i++) {         //läuft Anzahl an Knoten oft und speichert
        MyFile >> storage_number;                   //Koordinaten in pin vector
        storage_pin[0] = storage_number;

        MyFile >> storage_number;
        storage_pin[1] = storage_number;

        coordinates.push_back(storage_pin);

        MyFile >> storage_string;                       //geht bestimmt smarter? springt zwei strings;
        MyFile >> storage_string;
    }

    return coordinates;
}

void print_comment(fstream& MyFile) {

}

void get_data_from_File(int &number_nodes,vector<vector<int>> &coordinates) {

    fstream RSMT_Instanz(get_file_name(),ios::in);        //öffnet Instanz

    control_if_open(RSMT_Instanz);

    goto_section_graph(RSMT_Instanz);                           //liest Anzahl Knoten aus
    number_nodes = extract_number_of_nodes(RSMT_Instanz);

    goto_section_coordinates(RSMT_Instanz);                 //liest Koordinaten aus
    coordinates = extract_coordinates(RSMT_Instanz,number_nodes);

    RSMT_Instanz.close();                       //schließt Instanz
}
