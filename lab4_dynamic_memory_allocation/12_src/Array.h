#ifndef BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
#define BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H

#include <Complex.h>
#include <vector>
#include <iostream>

template <typename T, typename Alloc = std::allocator<T>>
class Array {
 private:
  T* arr = nullptr;
  size_t sz = 0;
  size_t cap = 0;
  Alloc alloc;

 public:
  Array() = default;
  ~Array();

  [[nodiscard]] size_t size() const { return sz; }
  [[nodiscard]] size_t capacity() const { return cap; }
  void reserve(size_t n);
  void resize(size_t n);
  void push_back(T& value);
  void push_back(T&& value) noexcept;

  void operator()(size_t n);
  const T& operator[](size_t i) const;
  T& operator[](size_t i);

  //helper func
  void sort();
};

template <typename T, typename Alloc>
void Array<T, Alloc>::reserve(size_t n) {
  if (n <= cap) { return; }

  T* newarr = std::allocator_traits<Alloc>::allocate(alloc, n);
  //T* newarr = reinterpret_cast<T*>(::operator new(n * sizeof(T)));

  size_t i = 0;
  try {
    for(; i < sz; ++i) {
      std::allocator_traits<Alloc>::construct(alloc, newarr, arr[i]);
      //new (newarr) T(std::move_if_noexcept(arr[i]));
    }
  } catch (...) {
    for (size_t j = 0; j < i; ++j) {
      std::allocator_traits<Alloc>::destroy(alloc, newarr+j);
    }
    std::allocator_traits<Alloc>::deallocate(alloc, newarr, i);
    //delete[] reinterpret_cast<void*>(newarr);
	throw;
  }

  std::allocator_traits<Alloc>::deallocate(alloc, arr, cap);
  //delete[] reinterpret_cast<void*>(arr);
  arr = newarr;
  cap = n;
}

template <typename T, typename Alloc>
void Array<T, Alloc>::push_back(T& value) {
  if (cap == 0) { reserve(1); }
  if (sz <= cap) { reserve(2 * sz); }

  std::allocator_traits<Alloc>::construct(alloc, arr+sz, value);
  //new (arr+sz) T(value);
  ++sz;
}

template <typename T, typename Alloc>
void Array<T, Alloc>::push_back(T&& value) noexcept {
  if (cap == 0) { reserve(1); }
  if (sz <= cap) { reserve(2 * sz); }

  std::allocator_traits<Alloc>::construct(alloc, arr+sz, value);
  //new (arr+sz) T(std::move_if_noexcept(value));
  ++sz;
}

template <typename T, typename Alloc>
T& Array<T, Alloc>::operator[](size_t i) {
  return arr[i];
}

template <typename T, typename Alloc>
Array<T, Alloc>::~Array() {
  if(cap == 0) { return; }

  for(size_t i = 0; i < sz; ++i) {
    std::allocator_traits<Alloc>::destroy(alloc, arr+i);
	//(arr+i)->~T();
  }
  std::allocator_traits<Alloc>::deallocate(alloc, arr, cap);
  //if(arr != nullptr) { ::operator delete(reinterpret_cast<void*>(arr)); }
}

#endif //BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
