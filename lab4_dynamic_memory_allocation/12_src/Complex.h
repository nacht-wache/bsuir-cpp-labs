#ifndef BSUIR_CPP_LABS_LAB4_SRC_COMPLEX_H
#define BSUIR_CPP_LABS_LAB4_SRC_COMPLEX_H

#include <ostream>

class Complex {
public:
  Complex();
  ~Complex() = default;

  Complex(const Complex& c) = default;
  Complex(double real, double img = 0);

  Complex& operator=(const Complex& c) = default;
  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

  Complex& operator++();
  Complex& operator--();
  Complex operator+() const;
  Complex operator-() const;


  bool operator==(const Complex& c) const;
  bool operator!=(const Complex& c) const;
  bool operator<(const Complex& c) const;

  //Modulo
  [[nodiscard]] double abs() const;
  friend std::ostream& operator<<(std::ostream& os, const Complex& c);

private:
  double real;
  double img;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

#endif //BSUIR_CPP_LABS_LAB4_SRC_COMPLEX_H
