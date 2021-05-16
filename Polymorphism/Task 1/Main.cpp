#include "Dog.hpp"
#include "Cat.hpp"
#include "Snake.hpp"
#include <vector>
#include "Person.hpp"

int main() {
    Dog* dog = new Dog("dog");
    Cat* cat = new Cat("cat");
    Snake* snake = new Snake("Snake");

    Person person;
    person.adopt(dog);
    person.adopt(cat);
    person.adopt(snake);
    person.feedEmALl();
    person.petEmAll();
    person.walkAllDogs();

    delete dog;
    delete cat;
    delete snake;

    return 0;
}