#include "String.h"
#include <cstring>
#include <memory>
#include <algorithm>

String::String() : str(new char[15]) {}

String::~String() {
  delete[] str;
}

String::String(const char* ch) {
  this->reserve(15);
  for (size_t i = 0; ch[i] != '\0'; ++i) {
	if (sz == cap) {
	  reserve(2 * cap);
	}
	str[i] = ch[i];
	++sz;
  }
}

String::String(const String& s) : String(s.sz, 0) {
  std::memcpy(str, s.str, s.sz);
}

String::String(size_t sz, char ch) {
  str = new char[2 * sz];
  memset(str, ch, sz);
  this->sz = sz;
  cap = 2 * sz;
}

String::String(const std::initializer_list<char>& lst) {
  sz = lst.size();
  str = new char[sz];
  std::copy(lst.begin(), lst.end(), str);
}

void String::reserve(size_t n) {
  if (n < cap) { return; }
  auto* new_s = new char[n];

  try {
	std::uninitialized_copy(str, str + sz, new_s);
  } catch (...) {
	delete[] new_s;
	throw;
  }

  this->~String();
  str = new_s;
  cap = n;
}

void String::sort() {
  std::sort(str, str + sz);
}

String& String::operator=(const String& s) {
  String new_s = s;
  swap(new_s);
}

std::ostream& operator<<(std::ostream& os, const String& s) {
  for (size_t i = 0; i < s.size(); ++i) {
	os << s[i];
  }
  return os;
}

bool String::operator<(const String& s) {}

// copy-and-swap idiom
String& String::swap(String& s) {
  std::swap(str, s.str);
  std::swap(sz, s.sz);
}

String::iterator operator+(int n, String::iterator& iter) {
  return iter + n;
}
