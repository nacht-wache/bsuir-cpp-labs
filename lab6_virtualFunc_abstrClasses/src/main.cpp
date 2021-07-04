#include <iostream>
#include <task.h>

int main() {
  auto sp = new Shape*[9];

  for(size_t i = 0; i < 3; ++i) {
    sp[i] = new Quadrilateral(.3, .4);
  }
  for(size_t i = 3; i < 6; ++i) {
	sp[i] = new Square(.2);
  }
  for(size_t i = 6; i < 9; ++i) {
	sp[i] = new Disk(.5);
  }

  for(size_t i = 0; i < 9; ++i) {
    Shape& rsh = *sp[i];
    std::cout << rsh.ComputeArea() << '\n';
  }

  for(size_t i = 0; i < 9; ++i) {
	delete sp[i];
  }
  delete[] sp;
}
