#include <iostream>
#include <vector>
#include <Array.h>

int main() {
  Array<Array<Array<Complex>>> arr;
  Array<Array<Complex>> arr_1;
  Array<Complex> arr_2;

  for(int i = 0; i < 1; ++i) {
    arr_2.push_back(Complex());
  }
  for(int i = 0; i < 1; ++i) {
	arr_1.push_back(std::move_if_noexcept(arr_2));
  }
  for(int i = 0; i < 1; ++i) {
	arr.push_back(std::move_if_noexcept(arr_1));
  }

  Array<Complex> array;
  for(int i = 0; i < 2; ++i) {
	array.push_back(Complex());
  }

  Array<Complex> array_copy;
  for(int i = 0; i < 2; ++i) {
	array_copy.push_back(Complex());
  }
  array = std::move_if_noexcept(array_copy);
  array_copy.push_back(Complex());
}
