#include "Array3D_Complex.h"


void Array3D_Complex::resize(size_t n, const Complex& c) {
  //
  if (n > Mcap) {
    //reserve(n);
  }
  for(size_t i = m; i < n; ++i) {
    new (arr + i) Complex(c);
  }

  if (n < m) {
    m = n;
  }
}

void Array3D_Complex::reserve(size_t Msz, size_t Nsz, size_t Ksz) {
  if (Msz <= Mcap && Nsz <= Ncap && Ksz <= Kcap) { return; }
  auto*** newarr = new Complex**[Msz];
  for(size_t i = 0; i < Msz; ++i) {
    newarr[i] = new Complex*[Nsz];
    for(size_t j = 0; j < Ksz; ++j) {
      newarr[i][j] = new Complex[Ksz];
    }
  }

  // Complex*** arr =  *(arr+0) = [Complex**] *(arr+1) = [Complex**] *(arr+2) = [Complex**] *(arr+m) = [Complex**] - size m
  //         Complex** *(arr+0) = *arr = [Complex*] *(arr+1)= [Complex*] *(arr+2) = [Complex*] *(arr+n) = [Complex*] - size n
  //                Complex* *(*(arr+0) + 0) = *(*(arr+0)+0) = [Complex] *(*(arr+0)+1)= [Complex] *(*(arr+0)+2) = [Complex] *(*(arr+0)+k) = [Complex] - size k


  //                            arr                                                            arr+m
  // Complex*** arr =  arr[0] = [Complex**] arr[1] = [Complex**] arr[2] = [Complex**] arr[m] = [Complex**] - size m
  //                               arr[i]+0                                                                         arr[i]+n
  //         Complex** arr[0][0] = arr[0][0] = [Complex*] arr[0][1] = [Complex*] arr[0][2] = [Complex*] arr[0][n] = [Complex*] - size n
  //                                        arr[i][j]+0                                                                               arr[i][j]+k
  //                Complex* arr[0][0][0] = arr[0][0][0] = [Complex] arr[0][0][1] = [Complex] arr[0][0][2] = [Complex] arr[0][0][k] = [Complex] - size k

  
  try {
    std::uninitialized_copy(arr, arr + m, newarr);
    for(size_t i = 0; i < m; ++m) {
      std::uninitialized_copy(arr[i], arr[i] + n, newarr[i]);
      for(size_t j = 0; j < n; ++j) {
        std::uninitialized_copy(arr[i][j], arr[i][j] + k, newarr[i][j]);
      }
    }
  } catch (...) {
    for(size_t i = 0; i < Msz; ++i) {
      for(size_t j = 0; j < Nsz; ++j) {
        delete[] newarr[i][j];
      }
      delete[] newarr[i];
     }
    throw;
  }

  for(size_t i = 0; i < m; ++i) {
    for(size_t j = 0; j < n; ++j) {
      for(size_t r = 0; r < k; ++r) {
        (arr[i][j] + r)->~Complex();
      }
    }
  }

  if(Mcap != 0) {
    for(size_t i = 0; i < m; ++i) {
      for(size_t j = 0; j < n; ++j) {
        delete[] arr[i][j];
      }
      delete[] arr[i];
    }
  }
  arr = newarr;
  Mcap = Msz;
  Ncap = Nsz;
  Kcap = Ksz;
}

// 3 3 3
// 1 5 2

void Array3D_Complex::push_back(size_t m, size_t n, const Complex &c) {
  if (Mcap == this->m || Ncap == this->n || Kcap == k) {
    reserve(2 * m, 2 * n, 2 * k);
  }
  if (Mcap == 0) {
    reserve(1, 1, 1);
  }
  new (arr[m][n]+k) Complex(c);
  ++k;
}
void Array3D_Complex::pop_back() {
  //(arr+m)->~Complex();
  --m;
}
Complex& Array3D_Complex::operator()(size_t Msz, size_t Nsz,size_t Ksz) {
  return arr[Msz][Nsz][Ksz];
}
void Array3D_Complex::print() const {
  for(int i = 0; i < this->size(); ++i) {
    std::cout << this->size() << ' ' << this->capacity() << '\n';
  }
}
