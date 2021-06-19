#ifndef BSUIR_CPP_LABS_LAB4_1_SRC_STRING_H
#define BSUIR_CPP_LABS_LAB4_1_SRC_STRING_H

#include <ostream>

class String {
 public:
  String();
  String(const char*);
  String(size_t sz, char ch);
  String(const std::initializer_list<char>& lst);
  String(const String& s);
  ~String();

  [[nodiscard]] size_t size() const { return sz; }
  [[nodiscard]] size_t capacity() const { return cap; }

  void reserve(size_t n);
  void sort();

  char& operator[](size_t i) { return str[i]; }
  char operator[](size_t i) const { return str[i]; }
  String& operator=(const String& s);
  bool operator<(const String& s);

 private:
  template <bool IsConst>
  struct common_iterator {
   private:
	using ConditionalPtr = std::conditional_t<IsConst, const char*, char*>;
	using ConditionalReference = std::conditional_t<IsConst, const char&, char&>;

	ConditionalPtr ptr;
   public:
	common_iterator() = default;
	explicit common_iterator(ConditionalPtr ptr): ptr(ptr) {}

	ConditionalReference operator*() {
	  return *ptr;
	};

	ConditionalPtr operator->() {
	  return ptr;
	};

	template <typename T>
	std::conditional_t<IsConst, const T&, T&> operator->*(T String::* p) {
	  return (*ptr).*p;
	};

	common_iterator<IsConst>& operator+=(int n) {
	  ptr += n;
	  return *this;
	}

	common_iterator<IsConst> operator+(int n) {
	  auto copy = *this;
	  copy += n;
	  return copy;
	}

	common_iterator<IsConst> operator++() {
	  ptr += 1;
	  return *this;
	}

	bool operator!=(const common_iterator<IsConst>& it) {
	  return ptr != it.ptr;
	}
  };

 public:

  using iterator = common_iterator<false>;
  using const_iterator = common_iterator<true>;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;


  iterator begin() { return iterator(str); }
  iterator end() { return iterator(str+sz); }
  const_iterator cbegin() { return const_iterator(str); }
  const_iterator cend() { return const_iterator(str+sz); }

 private:
  size_t sz = 0;
  size_t cap = 15;
  char* str = nullptr;

  String& swap(String& s);
};

std::ostream& operator<<(std::ostream& os, const String& s);

String::iterator operator+(int n, String::iterator& iter);

#endif //BSUIR_CPP_LABS_LAB4_1_SRC_STRING_H
