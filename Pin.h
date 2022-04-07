#ifndef MAIN_CPP_PIN_H
#define MAIN_CPP_PIN_H

#include <cmath>
#include <iostream>
#include <vector>

// Klasse die wir zum speichern und rechnen von zweidimensionalen Koordinaten nutzen

using namespace std;

class Pin {
private:
    int x;
    int y;

public:
    Pin(int _x, int _y);
    Pin();

    void set_pin(int _x, int _y);

    int calculate_distance(Pin target);
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

int calculate_distance(Pin pin1, Pin pin2);

void print_pin_vector(vector<Pin> target);

#endif //MAIN_CPP_PIN_H
