#ifndef MAIN_CPP_PIN_H
#define MAIN_CPP_PIN_H


#include <cmath>
#include <iostream>

// Klasse die wir zum speichern und rechnen von zweidimensionalen Koordinaten nutzen

using namespace std;

class pin {
private:
    int x;
    int y;

public:

    pin(int _x, int _y);
    pin();

    void set_pin(int _x, int _y);

    int calculate_distance(pin target);
    void print_pin();

    int get_x() const {
        return x;
    }

    void set_x(int new_x) {
        x = new_x;
    }

    int get_y() const {
        return y;
    }

    void set_y(int new_y) {
        y = new_y;
    }
};

int calculate_distance(pin pin1, pin pin2);

#endif //MAIN_CPP_PIN_H
