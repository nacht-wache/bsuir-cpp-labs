#ifndef BSUIR_CPP_LABS_LAB5_TASK_H
#define BSUIR_CPP_LABS_LAB5_TASK_H

#include <iostream>

class Shape {
 public:
  virtual long double ComputeArea() = 0;
  virtual void print(std::ostream& os) const = 0;
  virtual ~Shape() = 0;
};

class Quadrilateral : virtual public Shape {
 public:
  Quadrilateral() = default;
  Quadrilateral(long double length, long double width)
	  : length(length), width(width) {}
  ~Quadrilateral() override = default;

  long double ComputeArea() override;
  void print(std::ostream& os) const override;
  friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& value);

 private:
  long double length = 0.0;
  long double width = 0.0;
};

class Square final : public Quadrilateral {
 public:
  Square() = default;
  explicit Square(long double side)
	  : side(side) {}
  ~Square() noexcept final;

  long double ComputeArea() final;
  void print(std::ostream& os) const final;
  friend std::ostream& operator<<(std::ostream& os, const Square& value);

 private:
  long double side = 0.0;
};

class Disk final : public Shape {
 public:
  Disk() = default;
  explicit Disk(long double radius)
	  : radius(radius) {}
  ~Disk() final = default;

  long double ComputeArea() final;
  void print(std::ostream& os) const final;
  friend std::ostream& operator<<(std::ostream& os, const Disk& value);

 private:
  const double pi = 3.14;
  long double radius = 0.0;
};

#endif //BSUIR_CPP_LABS_LAB5_TASK_H
