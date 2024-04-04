#include "Animal.h"
#include "ChildAnimal.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

Animal::Animal() : Animal("unknown", Green){};
Animal::Animal(string n, COLOR c) : _name(n), _color(c){};
Animal::~Animal() { cout << "destructing Animal object " << _name << endl; }
void Animal::speak() const { cout << "Animal speaks " << endl; }

Mammal::Mammal() : Animal(){};
void Mammal::move() const { cout << "Mammal moves" << endl; }
Mammal::~Mammal() { cout << "destructing Mammal object " << _name << endl; }

void Mammal::eat() const { cout << "Mammal eat " << endl; }

int main() {

  vector<unique_ptr<Mammal>> mammals;

  while (true) {
    cout << "Select the animal to send to Zoo :" << endl;
    cout << "(1) Dog (2) Cat (3) Lion (4) Move all animals (5) Quit" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
      mammals.push_back(make_unique<Dog>("Charile", Green, "Phil"));
      break;
    case 2:
      mammals.push_back(make_unique<Cat>("Max", Brown));
      break;
    case 3:
      mammals.push_back(make_unique<Lion>("Simba", Brown));
      break;
    case 4:
      for (unique_ptr<Mammal> &a : mammals) {
        a->move();
        a->speak();
        a->eat();
      }

      break;
    case 5:
      return 0;
    }
  }
  return 0;
}
