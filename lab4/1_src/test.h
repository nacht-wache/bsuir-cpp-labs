#include <iostream>
#include "String.h"

void print() {
  String s(10, 'a');

  std::cout << s.size() << ' ' << s.capacity() << '\n';
  std::cout << s << '\n';
}

void print_cpp() {
  std::string s_cpp(16, 'a');

  std::cout << s_cpp.size() << ' ' << s_cpp.capacity() << '\n';
  std::cout << s_cpp << '\n';
}

void sum() {
  String s(16, 'a');
  String s1(16, 's');
  //std::cout << s + s1 << '\n';
  //std::cout << "aaa" + s1 << '\n';
}

void sum_cpp() {
  std::string s(16, 'a');
  std::string s1(16, 's');
  std::cout << s + s1 << '\n';
  std::cout << "aaa" + s1 << '\n';
}

void copy() {
  String s1(3, 'c');
  String s = s1;
  std::cout << s.size() << ' ' << s.capacity() << '\n';
}

void copy_cpp() {
  std::string s1(3, 'c');
  std::string s = s1;
  std::cout << s.size() << ' ' << s.capacity() << '\n';
}

void assign() {
  String s(16, 'a');
  String s1(16, 's');
  s = s1;
  std::cout << s << '\n';
  std::cout << s1 << '\n';
}

void sort() {
  String s1(16, 's');
}

struct C {
  int a = 0;
private:
  C(int x): a(x) {}
};