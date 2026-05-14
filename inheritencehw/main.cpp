#include "Dog.h"
#include "Cat.h"
#include "Parrot.h"

void main() {
    Dog dog("Sharik", "Loyal, energetic");
    Cat cat("Musya", "Independent, curious");
    Parrot parrot("Kesha", "Talkative, colorful");

    dog.display();
    cat.display();
    parrot.display();
}