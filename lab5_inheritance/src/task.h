#ifndef BSUIR_CPP_LABS_LAB5_TASK_H
#define BSUIR_CPP_LABS_LAB5_TASK_H

#include <ostream>

struct Animal {
private:
  int x = 0;

protected:
  int y = 1;

public:
  Animal() {}
  Animal(int x, int y): x(x), y(y) {}
  ~Animal() {}

};

std::ostream& operator<<(std::ostream& os, const Animal& a);

struct Mammal: public Animal {

};

struct Lion: public Mammal {

};

struct Bird: public Animal {

};

struct Eagle: public Bird {

};

struct Gryphon: virtual public Lion, virtual public Eagle {

};


#endif //BSUIR_CPP_LABS_LAB5_TASK_H
