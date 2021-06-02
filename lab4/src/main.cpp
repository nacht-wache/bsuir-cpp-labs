#include <iostream>
#include <Array3D_Complex.h>

int main() {
  Array3D_Complex ac;
  Complex c (1.,2.);

  for(int i = 0; i < 10; ++i) {
    ac.push_back(c);
    std::cout << ac.size() << ' ' << ac.capacity() << '\n';
  }

  for(int i = 0; i < ac.size(); ++i) {
    std::cout << ac[i] << ' ';
  }
  std::cout << '\n';
}
