#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {

    string name;
    cout << "Name des Graphen?" << endl;
    cin >> name;

    int a;

    ifstream myFile(name.append(".txt"));

    if(myFile.is_open()) {
        printf("The filed was opened correctly\n");
    }
    else{
        printf("Error: opening the file failed\n");
        exit(1);
    }

    while(myFile >> a) {
        printf("%d\n",a);
    }

    myFile.close();

    return 0;
}
