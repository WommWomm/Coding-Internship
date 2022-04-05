#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "pin.h"

using namespace std;

void contolOpen(fstream& MyFile) {
    if(MyFile.is_open()) {                //Überprüft ob Datei Instanz geöffnet wurde
        cout << "Die Datei wurde erfolgreich geoeffnet." << endl;
    } else {
        cout << "FEHLER: Die Datei konnte nicht geöffnet werden." << endl;
        exit(1);            //Weist diesem Fehler einen Exitcode zu und beendet Programm
    }
}

void gotoNextSection(fstream& MyFile) {
    string speicher;

    MyFile >> speicher;

    while (MyFile.good()) {

        if(speicher == "SECTION") {
            break;
        }

        MyFile >> speicher;
        cout << "1";
    }
}

void einleseroutine() {

    string name;
    string StringSpeicher;
    int IntSpeicher;

    cout << "Geben Sie den Namen der Datei an, welche die Instanz enthaelt: ";  //Fragt Namen ab
    cin  >> name;

    fstream RSMT_Instanz(name.append(".stp"),ios_base::in);        //öffnet Instanz

    contolOpen(RSMT_Instanz);

    gotoNextSection(RSMT_Instanz);
    gotoNextSection(RSMT_Instanz);

    for(int i = 0; i < 3; i++) {
        RSMT_Instanz >> IntSpeicher;
    }

    RSMT_Instanz >> StringSpeicher;

    cout << IntSpeicher << endl;

    RSMT_Instanz.close();
}

int main() {

    einleseroutine();

    return 0;
}
