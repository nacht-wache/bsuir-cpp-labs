#ifndef BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
#define BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H

#include <Complex.h>
#include <vector>

class Array3D_Complex {
private:
  size_t sz = 0;
  size_t cap = 0;
  Complex* arr;

public:
  [[nodiscard]] size_t size() const { return sz; }
  [[nodiscard]] size_t capacity() const { return cap; }
  void reserve(size_t n);
  void resize(size_t n, const Complex& c = Complex());
  void push_back(const Complex& c);
  void pop_back();

  Complex& operator[](size_t i);
  const Complex& operator[](size_t i) const;
};

#endif //BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
