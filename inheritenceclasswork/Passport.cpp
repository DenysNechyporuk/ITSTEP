#include "Passport.h"

Passport::Passport(std::string owner, std::string number) : owner(owner), number(number) {}

void Passport::show() {
    std::cout << "Owner: " << owner << "\nPassport: " << number << std::endl;
}

ForeignPassport::ForeignPassport(std::string owner, std::string number, std::string fNumber, std::string visas)
    : Passport(owner, number), foreignNumber(fNumber), visas(visas) {
}

void ForeignPassport::show() {
    Passport::show();
    std::cout << "Foreign ID: " << foreignNumber << "\nVisas: " << visas << std::endl;
}