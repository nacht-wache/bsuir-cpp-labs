#include <iostream>
#include <vector>
#include <Array.h>

void print(Array<Array<Array<Complex>>>& arr3D) {
  for(size_t i = 0; i < arr3D.size(); ++i) {
	for(size_t j = 0; j < arr3D[i].size(); ++j) {
	  for(size_t k = 0; k < arr3D[i][j].size(); ++k) {
		std::cout << arr3D[i][j][k] << ' ';
	  }
	  std::cout << '\n';
	}
	std::cout << '\n';
  }
}

void heap_obj(Array<Array<Array<Complex>>>& arr3D) {
  auto* new_arr3D = new Array<Array<Array<Complex>>>(arr3D);
  auto new_arr3D_copy = new Array<Array<Array<Complex>>>(*new_arr3D);

  for(size_t i = 0; i < new_arr3D->size(); ++i) {
	for(size_t j = 0; j < (*new_arr3D)[i].size(); ++j) {
	  for(size_t k = 0; k < (*new_arr3D)[i][j].size(); ++k) {
		(*new_arr3D)[i][j][k] = Complex(.5, .7);
	  }
	}
  }

  print(*new_arr3D);
  print(*new_arr3D_copy);

  delete new_arr3D;
  delete new_arr3D_copy;
}

void heap_arr(Array<Array<Array<Complex>>>& arr3D) {
  auto new_arr_of_arr3D = new Array<Array<Array<Complex>>>[4];
  for(size_t i = 0; i < 4; ++i) {
	new_arr_of_arr3D[i] = arr3D;
  }

  for(size_t i = 0; i < new_arr_of_arr3D->size(); ++i) {
	for(size_t j = 0; j < (*new_arr_of_arr3D)[i].size(); ++j) {
	  for(size_t k = 0; k < (*new_arr_of_arr3D)[i][j].size(); ++k) {
		(*new_arr_of_arr3D)[i][j][k] = Complex(.5, .7);
	  }
	}
  }

  for(size_t i = 0; i < 4; ++i) {
	print(*(new_arr_of_arr3D+i));
  }

  delete[] new_arr_of_arr3D;
}

int main() {
  Array<Array<Array<Complex>>> arr3D;
  Array<Array<Complex>> arr2D;
  Array<Complex> arr1D;

  for(int i = 0; i < 2; ++i) {
    arr1D.push_back(Complex(.3, .4));
  }
  for(int i = 0; i < 2; ++i) {
	arr2D.push_back(arr1D);
  }
  for(int i = 0; i < 2; ++i) {
	arr3D.push_back(arr2D);
  }

  heap_obj(arr3D);
  heap_arr(arr3D);
}
