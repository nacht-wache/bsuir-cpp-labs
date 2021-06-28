#ifndef BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
#define BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H

#include <Complex.h>
#include <iostream>

template <typename T, typename Alloc = std::allocator<T>>
class Array {
 private:
  T* arr = nullptr;
  size_t sz = 0;
  size_t cap = 0;
  Alloc alloc;

  void copy_and_swap_idiom();

  Array(T* arr, size_t sz, size_t cap)
	  : arr(arr), sz(sz), cap(cap) {}

 public:
  Array() = default;
  Array(const Array& rhs);
  Array(Array&& rhs) noexcept;
  ~Array() noexcept;

  Array& operator=(const Array& rhs);
  Array& operator=(Array&& rhs) noexcept;

  void reserve(size_t n);
  void resize(size_t n);
  void push_back(const T& value);
  void push_back(T&& value) noexcept;

  //helper func
  void sort();
  [[nodiscard]] size_t size() const { return sz; }
  [[nodiscard]] size_t capacity() const { return cap; }
};

template <typename T, typename Alloc>
void Array<T, Alloc>::push_back(const T& value) {
  if (cap == 0) { reserve(1); }
  if (sz == cap) { reserve(2 * sz); }

  new(arr + sz) T(value);
  ++sz;
}

template <typename T, typename Alloc>
void Array<T, Alloc>::push_back(T&& value) noexcept {
  if (cap == 0) { reserve(1); }
  if (sz == cap) { reserve(2 * sz); }

  new(arr + sz) T(std::move_if_noexcept(value));
  ++sz;
}

template <typename T, typename Alloc>
Array<T, Alloc>::~Array() noexcept {

  for (size_t i = 0; i < sz; ++i) {
	std::allocator_traits<Alloc>::destroy(alloc, arr + sz - 1 - i);
  }

  ::operator delete(static_cast<void*>(arr), cap);
}

template <typename T, typename Alloc>
Array<T, Alloc>::Array(const Array& rhs)
	: Array(static_cast<T*>(::operator new(rhs.cap * sizeof(T))), rhs.sz, rhs.cap) {
  try {
	std::uninitialized_copy(rhs.arr, rhs.arr + sz, arr);
  } catch (...) {
	::operator delete(static_cast<void*>(arr));
	throw;
  }

  std::cout << "Copied array!\n";
}

template <typename T, typename Alloc>
Array<T, Alloc>::Array(Array&& rhs) noexcept
	: Array(rhs.arr, rhs.sz, rhs.cap) {
  rhs.arr = nullptr;
  rhs.sz = 0;
  rhs.cap = 0;

  std::cout << "Moved array!\n";
}

template <typename T, typename Alloc>
void Array<T, Alloc>::reserve(size_t n) {
  if (n <= cap) { return; }

  T* newarr = static_cast<T*>(::operator new(n * sizeof(T)));
  size_t i = 0;
  try {
	for (; i < sz; ++i) {
	  std::allocator_traits<Alloc>::construct(alloc, newarr + i, std::move_if_noexcept(arr[i]));
	}
  } catch (...) {
	for (size_t j = 0; j < i; ++j) {
	  std::allocator_traits<Alloc>::destroy(alloc, newarr + i - j);
	}
	::operator delete(static_cast<void*>(newarr));
	throw;
  }

  for (size_t i = 0; i < sz; ++i) {
	std::allocator_traits<Alloc>::destroy(alloc, arr + sz - 1 - i);
  }

  ::operator delete(static_cast<void*>(arr), cap);
  arr = newarr;
  cap = n;
}

template <typename T, typename Alloc>
void Array<T, Alloc>::copy_and_swap_idiom() {
  Array<T, Alloc> copy (std::move_if_noexcept(*this));
}

template <typename T, typename Alloc>
Array<T, Alloc>& Array<T, Alloc>::operator=(Array&& rhs) noexcept {
  //Handle self-assignment idiom
  if (this == &rhs) {
	return *this;
  }

  Array<T, Alloc> copy (std::move_if_noexcept(*this));
  arr = rhs.arr;
  sz = rhs.sz;
  cap = rhs.cap;

  rhs.arr = nullptr;
  rhs.sz = 0;
  rhs.cap = 0;
  std::cout << "Move-assigned array!\n";
}

template <typename T, typename Alloc>
Array<T, Alloc>& Array<T, Alloc>::operator=(const Array<T, Alloc>& rhs) {
  //Handle self-assignment idiom
  if (this == &rhs) {
	return *this;
  }

  Array<T, Alloc> copy (std::move_if_noexcept(*this));
  arr = rhs.arr;
  sz = rhs.sz;
  cap = rhs.cap;
  std::cout << "Copy-assigned array!\n";
}
#endif //BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
