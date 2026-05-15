#pragma once
#include <iostream>
#include <string>

class Student {
protected:
    std::string name;
public:
    Student(std::string name);
    void print();
};

class Aspirant : public Student {
private:
    std::string topic;
public:
    Aspirant(std::string name, std::string topic);
    void print();
};