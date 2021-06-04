#include "Complex.h"
#include <cmath>

Complex::Complex(): real(0.0), img(0.0) {}

Complex::Complex(double real, double img): real(real), img(img) {}

Complex& Complex::operator+=(const Complex& c) {
  real += c.real;
  img += c.img;
  return *this;
}

Complex& Complex::operator-=(const Complex &c) {
  real -= c.real;
  img -= c.img;
  return *this;
}

Complex& Complex::operator*=(const Complex& c) {
  real *= c.real;
  img *= c.img;
  return *this;
}

Complex& Complex::operator/=(const Complex& c) {
  real /= c.real;
  img /= c.img;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex mul = lhs;
  mul *= rhs;
  return mul;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  Complex sum = lhs;
  sum += rhs;
  return sum;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex quot = lhs;
  quot /= rhs;
  return quot;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  Complex diff = lhs;
  diff -= rhs;
  return diff;
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

Complex& Complex::operator--() {
  --real;
  return *this;
}

Complex Complex::operator+() const {
  return Complex(real, img);
}


Complex Complex::operator-() const{
  return Complex(-real, -img);
}


bool Complex::operator!=(const Complex& c) const {
  return real != c.real && img != c.img;
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
