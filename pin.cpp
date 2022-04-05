#include "pin.h"

pin::pin(int _x, int _y) {
    set_pin(_x,_y);
}

pin::pin() {

}

void pin::set_pin(int _x, int _y) {
    x = _x;
    y = _y;
}

void pin::print_pin() {
    cout << x << " " << y << endl;
}

int pin::calculate_distance(pin target) {

    int ergebnis = abs(x-target.get_x())+ abs(y-target.get_y());  //berechnet Abstand in Manhatten Norm
    return ergebnis;
}

int calculate_distance(pin pin1, pin pin2) {

    int ergebnis = abs(pin1.get_x()-pin2.get_x())+ abs(pin1.get_y()-pin2.get_y()); //berechnet Abstand in Manhatten Norm
    return ergebnis;
}