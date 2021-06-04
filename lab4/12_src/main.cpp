#include <iostream>
#include <Array3D_Complex.h>

int main() {
  Array3D_Complex ac;
  Complex c (1.,2.);
  ac.reserve(1,1,4);
  ac.push_back(0,0, c);
  ac.reserve(0,0,1);
  std::cout << ac(0,0,0) << '\n';
  ac.reserve(2,1,3);
  std::cout << ac(0,0,0) << '\n';
  ac.push_back(1,0, c);
  ac.push_back(1,0, c);
  ac.reserve(2,2,3);
  std::cout << ac(1,0,0) << '\n';
  std::cout << ac(1,0,1) << '\n';
  /*ac.reserve(2,4,5);

  ac.reserve(4,5,6);

  ac.print();
  ac.push_back(0,0, c);

  ac.push_back(0,0, c);
  std::cout << ac(0,0,1) << '\n';
  ac.push_back(0,0, c);
  std::cout << ac(0,0,2) << '\n';
  ac.push_back(0,0, c);
  std::cout << ac(0,0,3) << '\n';
  ac.push_back(0,0, c);
  std::cout << ac(0,0,4) << '\n';*/


}
