#include "Pet.h"

Pet::Pet(string name, string characteristics) {
    this->name = name;
    this->characteristics = characteristics;
}

void Pet::display() {
    cout << "Name: " << name << ", Characteristics: " << characteristics << endl;
}