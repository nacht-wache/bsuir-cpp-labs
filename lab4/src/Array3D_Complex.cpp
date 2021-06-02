#include "Array3D_Complex.h"


void Array3D_Complex::resize(size_t n, const Complex& c) {
  if (n > cap) {
    reserve(n);
  }
  for(size_t i = sz; i < n; ++i) {
    new (arr + i) Complex(c);
  }

  if (n < sz) {
    sz = n;
  }
}

void Array3D_Complex::reserve(size_t n) {
  if (n <= cap) { return; }
  auto* newarr = reinterpret_cast<Complex*>(new int8_t[n * sizeof(Complex)]);

  try {
    std::uninitialized_copy(arr, arr + sz, newarr);
  } catch (...) {
    delete[] (int8_t*)(newarr);
    throw;
  }

  for(size_t i = 0; i < sz; ++i) {
    (arr + i)->~Complex();
  }

  if(cap != 0) { delete[] reinterpret_cast<int8_t*>(arr); }
  arr = newarr;
  cap = n;
}
void Array3D_Complex::push_back(const Complex &c) {
  if (cap == sz) {
    reserve(2 * sz);
  }
  if (cap == 0) {
    reserve(1);
  }
  new (arr+sz) Complex(c);
  ++sz;
}
void Array3D_Complex::pop_back() {
  (arr+sz)->~Complex();
  delete[] reinterpret_cast<int8_t*>(arr+sz);
  --sz;
}
Complex& Array3D_Complex::operator[](size_t i) {
  return *(arr+i);
}
