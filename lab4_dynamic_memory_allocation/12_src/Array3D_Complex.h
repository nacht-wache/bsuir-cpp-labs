#ifndef BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
#define BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H

#include <Complex.h>
#include <vector>
#include <iostream>

class Array3D_Complex {
private:
  //
  size_t** sz;
  size_t** cap;
  size_t m = 0;
  size_t n = 0;
  size_t k = 0;
  size_t Mcap = 0;
  size_t Ncap = 0;
  size_t Kcap = 0;
  Complex*** arr;

public:
  [[nodiscard]] size_t size() const { return m; }
  [[nodiscard]] size_t capacity() const { return Mcap; }
  void reserve(size_t Msz, size_t Nsz, size_t Ksz);
  void resize(size_t n, const Complex& c = Complex());
  void push_back(size_t m, size_t n, const Complex& c);
  void pop_back();
  void print() const;

  Complex& operator()(size_t Msz, size_t Nsz,size_t Ksz);
  const Complex& operator[](size_t i) const;
};

#endif //BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
