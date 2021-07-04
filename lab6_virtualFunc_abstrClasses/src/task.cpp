#include <task.h>

Shape::~Shape() = default;

long double Quadrilateral::ComputeArea() {
  std::cout << "Quadrilateral Area" << ' ';
  return length * width;
}

void Quadrilateral::print(std::ostream& os) const {
  os << length << ' ' << width << ' ' << "Print Quadrilateral";
}

std::ostream& operator<<(std::ostream& os, const Quadrilateral& value) {
  value.print(os);
  return os;
}

Square::~Square() noexcept {}

long double Square::ComputeArea() {
  std::cout << "Square Area" << ' ';;
  return side * side;
}

void Square::print(std::ostream& os) const {
  os << side << ' ' << "Print Square";
}

std::ostream& operator<<(std::ostream& os, const Square& value) {
  value.print(os);
  return os;
}

long double Disk::ComputeArea() {
  std::cout << "Disk Area" << ' ';;
  return pi * radius * radius;
}

void Disk::print(std::ostream& os) const {
  os << radius << ' ' << "Print Disk";
}

std::ostream& operator<<(std::ostream& os, const Disk& value) {
  value.print(os);
  return os;
}
