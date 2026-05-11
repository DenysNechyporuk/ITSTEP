#include "student.h"

Student::Student(std::string name) : name(name) {}

void Student::print() {
    std::cout << "Student: " << name << std::endl;
}

Aspirant::Aspirant(std::string name, std::string topic) : Student(name), topic(topic) {}

void Aspirant::print() {
    Student::print();
    std::cout << "Topic: " << topic << std::endl;
}