#ifndef BSUIR_CPP_LABS_LAB4_1_SRC_STRING_H
#define BSUIR_CPP_LABS_LAB4_1_SRC_STRING_H

#include <ostream>

class String {
private:
  size_t sz = 0;
  size_t cap = 15;
  char* str = nullptr;

  String& swap(String& s);
public:
  String();
  String(const char*);
  String(size_t sz, char ch);
  String(const std::initializer_list<char>& lst);

  String(const String& s);

  ~String();

  [[nodiscard]] size_t size() const;
  [[nodiscard]] size_t capacity() const;

  void reserve(size_t n);
  void sort();

  char& operator[](size_t i);
  char operator[](size_t i) const;
  String& operator=(const String& s);
  bool operator<(const String& s);

};

std::ostream& operator<<(std::ostream& os, const String& s);

#endif //BSUIR_CPP_LABS_LAB4_1_SRC_STRING_H
