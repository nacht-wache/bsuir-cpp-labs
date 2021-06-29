#ifndef BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
#define BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H

#include <Complex.h>
#include <iostream>

template <typename T, typename Alloc = std::allocator<T>>
class Array {
 public:

  typedef T value_type;
  typedef Alloc allocator_type;
  typedef size_t size_type;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef value_type&& rvalue_reference;
  typedef const value_type&& const_rvalue_reference;
  typedef typename std::allocator_traits<allocator_type>::pointer pointer;
  typedef typename std::allocator_traits<allocator_type>::const_pointer const_pointer;

  Array() = default;
  Array(const Array& other);
  Array(Array&& other) noexcept;
  ~Array() noexcept;

  Array& operator=(const Array& other);
  Array& operator=(Array&& other) noexcept;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;


  void reserve(size_type count);
  void resize(size_type count);
  void push_back(const_reference value);
  void push_back(rvalue_reference value) noexcept;

  //helper func
  void sort();
  [[nodiscard]] size_type size() const { return sz; }
  [[nodiscard]] size_type capacity() const { return cap; }

  static void* operator new(size_t count) {
    std::cout << "allocated " << count << " bytes\n";
	return ::operator new(count);
  }

  static void* operator new(size_t, void* ptr) {
	std::cout << "placement new\n";
	return ptr;
  }

  static void* operator new[](size_t count) {
	std::cout << "allocated[] " << count << " bytes\n";
	return ::operator new(count);
  }

  static void* operator new[](size_t, void* ptr) {
	std::cout << "placement new\n";
	return ptr;
  }

  void operator delete(void* ptr) {
    std::cout << "deallocated\n";
    ::operator delete(ptr);
  }

  void operator delete[](void* ptr) {
	std::cout << "deallocated[]\n";
	::operator delete(ptr);
  }


 private:
  pointer arr = nullptr;
  size_type sz = 0;
  size_type cap = 0;
  allocator_type alloc;

  Array(pointer arr, size_type sz, size_type cap)
	  : arr(arr), sz(sz), cap(cap) {};
};

template <typename value_type, typename allocator_type>
void Array<value_type, allocator_type>::push_back(const_reference value) {
  if (capacity() == 0) { reserve(1); }
  if (size() == capacity()) { reserve(2 * sz); }

  new(arr + sz) value_type(value);
  ++sz;
}

template <typename value_type, typename allocator_type>
void Array<value_type, allocator_type>::push_back(rvalue_reference value) noexcept {
  if (capacity() == 0) { reserve(1); }
  if (size() == capacity()) { reserve(2 * sz); }

  new(arr + sz) value_type(std::move_if_noexcept(value));
  ++sz;
}

template <typename value_type, typename allocator_type>
Array<value_type, allocator_type>::~Array() noexcept {

  for (size_type i = 0; i < sz; ++i) {
	std::allocator_traits<allocator_type>::destroy(alloc, arr + sz - 1 - i);
  }

  ::operator delete(static_cast<void*>(arr), cap);
}

template <typename value_type, typename allocator_type>
Array<value_type, allocator_type>::Array(const Array& other)
	: Array(static_cast<pointer>(::operator new(other.cap * sizeof(value_type))), other.sz, other.cap) {
  try {
	std::uninitialized_copy(other.arr, other.arr + sz, arr);
  } catch (...) {
	::operator delete(static_cast<void*>(arr));
	throw;
  }
}

template <typename value_type, typename allocator_type>
Array<value_type, allocator_type>::Array(Array&& other) noexcept
	: Array(other.arr, other.sz, other.cap) {
  other.arr = nullptr;
  other.sz = 0;
  other.cap = 0;

}

template <typename value_type, typename allocator_type>
void Array<value_type, allocator_type>::reserve(size_type count) {
  if (count <= cap) { return; }

  auto newarr = static_cast<pointer>(::operator new(count * sizeof(value_type)));
  size_type i = 0;
  try {
	for (; i < sz; ++i) {
	  new(newarr + i) value_type(std::move_if_noexcept(arr[i]));
	}
  } catch (...) {
	for (size_type j = 0; j < i; ++j) {
	  std::allocator_traits<allocator_type>::destroy(alloc, newarr + i - j);
	}
	::operator delete(static_cast<void*>(newarr));
	throw;
  }

  for (size_type k = 0; k < sz; ++k) {
	std::allocator_traits<allocator_type>::destroy(alloc, arr + sz - 1 - k);
  }

  ::operator delete(static_cast<void*>(arr), cap);
  arr = newarr;
  cap = count;
}

template <typename value_type, typename allocator_type>
Array<value_type, allocator_type>& Array<value_type, allocator_type>::operator=(Array&& other) noexcept {
  //Handle self-assignment idiom
  if (this == &other) {
	return *this;
  }

  Array<value_type, allocator_type> copy(std::move_if_noexcept(*this));
  arr = other.arr;
  sz = other.sz;
  cap = other.cap;

  other.arr = nullptr;
  other.sz = 0;
  other.cap = 0;
}

template <typename value_type, typename allocator_type>
Array<value_type, allocator_type>& Array<value_type, allocator_type>::operator=(const Array<value_type,
																							allocator_type>& other) {
  //Handle self-assignment idiom
  if (this == &other) {
	return *this;
  }

  Array<value_type, allocator_type> copy(std::move_if_noexcept(*this));
  arr = static_cast<pointer>(::operator new(other.cap * sizeof(value_type)));
  try {
	std::uninitialized_copy(other.arr, other.arr + other.sz, arr);
  } catch (...) {
	::operator delete(static_cast<void*>(arr));
	throw;
  }

  sz = other.sz;
  cap = other.cap;
}

template <typename value_type, typename allocator_type>
void Array<value_type, allocator_type>::resize(size_type count) {
  if (count == size()) {
	return;
  }
  if (count > size()) {
	reserve(count);
	for (size_type i = sz; i < count; ++i) {
	  std::allocator_traits<allocator_type>::construct(alloc, arr + i, value_type());
	}
  }
  if (count < size()) {
    sz = count;
    // ... some magic
  }
}

template <typename T, typename Alloc>
typename Array<T, Alloc>::reference Array<T, Alloc>::operator[](Array::size_type pos) {
  return *(arr+pos);
}

template <typename T, typename Alloc>
typename Array<T, Alloc>::const_reference Array<T, Alloc>::operator[](Array::size_type pos) const {
  return *(arr+pos);
}
#endif //BSUIR_CPP_LABS_LAB4_SRC_ARRAY3D_COMPLEX_H
