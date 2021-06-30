#ifndef BSUIR_CPP_LABS_LAB5_TASK_H
#define BSUIR_CPP_LABS_LAB5_TASK_H

#include <ostream>

class Animal {
 private:
  std::string private_animal = "private_animal";

 protected:
  std::string protected_animal = "protected_animal";

 public:
  Animal() = default;
  ~Animal() = default;

  friend std::ostream& operator<<(std::ostream& os, const Animal& a);
};

class Mammal : virtual public Animal {
 private:
  std::string private_mammal = "private_mammal";

 protected:
  std::string protected_mammal = "protected_mammal";

 public:
  Mammal() {
	protected_animal = "protected_animal_mammal";
  };
  ~Mammal() = default;

  friend std::ostream& operator<<(std::ostream& os, const Mammal& a);
};

class Lion : public Mammal {
 private:
  std::string private_lion = "private_lion";

 protected:
  std::string protected_lion = "protected_lion";

 public:
  Lion() {
	protected_mammal = "protected_mammal_lion";
	protected_animal = "protected_animal_lion";
  };
  ~Lion() = default;

  friend std::ostream& operator<<(std::ostream& os, const Lion& a);

};

class Bird : virtual public Animal {
 private:
  std::string private_bird = "private_bird";

 protected:
  std::string protected_bird = "protected_bird";

 public:
  Bird() {
	protected_animal = "protected_animal_bird";
  };
  ~Bird() = default;

  friend std::ostream& operator<<(std::ostream& os, const Bird& a);
};

class Eagle : public Bird {
 private:
  std::string private_eagle = "private_eagle";

 protected:
  std::string protected_eagle = "protected_eagle";

 public:
  Eagle() {
	protected_bird = "protected_bird_eagle";
	protected_animal = "protected_animal_eagle";
  };
  ~Eagle() = default;

  friend std::ostream& operator<<(std::ostream& os, const Eagle& a);
};

class Gryphon : public Lion, public Eagle {
 private:
  std::string private_gryphon = "private_gryphon";

 protected:
  std::string protected_gryphon = "protected_gryphon";

 public:
  Gryphon() {
	protected_animal = "protected_animal_gryphon";
	protected_mammal = "protected_mammal_gryphon";
	protected_bird = "protected_bird_gryphon";
	protected_lion = "protected_lion_gryphon";
	protected_eagle = "protected_eagle_gryphon";
  };
  ~Gryphon() = default;

  friend std::ostream& operator<<(std::ostream& os, const Gryphon& a);
};

#endif //BSUIR_CPP_LABS_LAB5_TASK_H
