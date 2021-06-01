#ifndef BSUIR_CPP_LABS_LAB3_SRC_COMPLEX_H
#define BSUIR_CPP_LABS_LAB3_SRC_COMPLEX_H

#include <ostream>
#include <stdexcept>

class Complex {
private:
  double real;
  double img;

public:
  Complex();
  ~Complex() = default;

  Complex(const Complex& c) = default;

  explicit Complex(double real);
  Complex(double real, double img);

  Complex& operator++();
  Complex& operator=(const Complex& c) = default;
  Complex& operator+=(const Complex& c);
  Complex operator+(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex operator-(const Complex& c);
  bool operator==(const Complex& c) const;
  bool operator<(const Complex& c) const;

  //Modulo
  [[nodiscard]] double abs() const;

  friend Complex& operator--(Complex& c);
  friend Complex operator+(const Complex& rhs, const Complex& lhs);
  friend Complex operator-(const Complex& rhs, const Complex& lhs);
  friend bool operator>(const Complex& rhs, const Complex& lhs);
  friend bool operator!=(const Complex& rhs, const Complex& lhs);
  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif //BSUIR_CPP_LABS_LAB3_SRC_COMPLEX_H
