#ifndef ANIMAL_H
#define ANIMAL_H 1
#include <string>
enum COLOR { Green, Blue, White, Black, Brown };

class Animal {
public:
  Animal();
  Animal(std::string n, COLOR c);
  ~Animal();
  virtual void speak() const;
  virtual void move() const = 0;

protected:
  std::string _name;
  COLOR _color;
};

class Mammal : public Animal {
public:
  Mammal();
  Mammal(std::string n, COLOR c) : Animal(n, c){};
  ~Mammal();
  void eat() const;
  virtual void move() const;
};

#endif /* ifndef ANIMAL_H */
