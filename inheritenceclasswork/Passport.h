#pragma once
#include <iostream>
#include <string>

class Passport {
protected:
    std::string owner;
    std::string number;
public:
    Passport(std::string owner, std::string number);
    void show();
};

class ForeignPassport : public Passport {
private:
    std::string foreignNumber;
    std::string visas;
public:
    ForeignPassport(std::string owner, std::string number, std::string fNumber, std::string visas);
    void show();
};