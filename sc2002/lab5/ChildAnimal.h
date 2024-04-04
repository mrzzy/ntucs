#ifndef CHILD_ANIMAL_H
#define CHILD_ANIMAL_H 1
#include "Animal.h"
#include <iostream>

using namespace std;

class Dog : public Mammal {
public:
  Dog(string n, COLOR c, string owner) : Mammal(n, c), _owner(owner){};
  ~Dog() { cout << "destructing Dog object " << _name << endl; }

  virtual void speak() const { cout << "Dog Woofs" << endl; }

private:
  string _owner;
};

class Lion : public Mammal {
public:
  Lion(string n, COLOR c) : Mammal(n, c){};
  ~Lion() { cout << "destructing Lion object " << _name << endl; }

  virtual void speak() const { cout << "Lion Roars" << endl; }
};

class Cat : public Mammal {
public:
  Cat(string n, COLOR c) : Mammal(n, c){};
  ~Cat() { cout << "destructing Cat object " << _name << endl; }

  virtual void speak() const { cout << "Cat Meows" << endl; }
};
#endif /* ifndef CHILD_ANIMAL_H */
