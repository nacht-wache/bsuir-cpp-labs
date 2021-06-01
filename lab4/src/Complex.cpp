#include "Complex.h"
#include <cmath>

Complex::Complex(): real(0.0), img(0.0) {}

Complex::Complex(double real): real(real), img(0.0) {}

Complex::Complex(double real, double img): real(real), img(img) {}

Complex& Complex::operator+=(const Complex& c) {
  real += c.real;
  img += c.img;
  return *this;
}

Complex Complex::operator+(const Complex& c) {
  Complex cc = *this;
  cc += c;
  return cc;
}

Complex& Complex::operator-=(const Complex &c) {
  real -= c.real;
  img -= c.img;
  return *this;
}

Complex Complex::operator-(const Complex& c) {
  Complex cc = *this;
  cc -= c;
  return cc;
}

Complex& Complex::operator++() {
  ++real;
  return *this;
}

bool Complex::operator==(const Complex &c) const {
  return real == c.real && img == c.img;
}

bool Complex::operator<(const Complex &c) const {
  return real < c.real && img < c.img;
}

Complex& operator--(Complex& c) {
  --c.real;
  return c;
}

Complex operator+(const Complex& rhs, const Complex& lhs) {
  Complex cc = lhs;
  cc += rhs;
  return cc;
}

Complex operator-(const Complex& lhs, const Complex& rhs){
  Complex cc = lhs;
  cc -= rhs;
  return cc;
}

bool operator>(const Complex& lhs, const Complex& rhs) {
  return lhs.real > rhs.real && lhs.img > rhs.img;
}
bool operator!=(const Complex& lhs, const Complex& rhs) {
  return lhs.real != rhs.real && lhs.img != rhs.img;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  char ch;
  ch = c.img < 0 ? '-':'+';
  os << c.real;

  if(c.img != 0) {
    os <<  ' ' << ch << ' ' << std::abs(c.img) << "i";
  }
  return os;
}

double Complex::abs() const{
  double result = std::abs(std::sqrt(real*real + img*img));
  return result;
}
