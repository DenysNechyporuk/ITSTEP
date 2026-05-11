#include "Student.h"
#include "Passport.h"

int main() {
    Aspirant a("Ivan", "AI in Games");
    a.print();

    std::cout << "---" << std::endl;

    ForeignPassport fp("Ivan", "123456", "FP987654", "USA, EU");
    fp.show();
}