#include <iostream>
#include <Matrix_Complex.h>
#include <Complex.h>

int main() {
  try{
    Complex c(-1.0);
    Complex c1(1.0, 2.0);
    Complex c3(3.0, 4.0);

    vector<Complex> v = {c, c1, c3};
    vector<Complex> v1 = {c1, c, c3};
    vector<Complex> v2 = {c1, c3, c};
    vector<vector<Complex>> vmc = {v, v1, v2};
    vector<vector<Complex>> vmc1 = {v2, v, v1};
    Matrix_Complex mc(vmc);
    Matrix_Complex mc1(vmc1);
    //mc+mc1;
    std::cout << mc << '\n' << mc1 << '\n';

    std::cout << "Operator++\n";
    std::cout << ++mc << '\n';

    std::cout << "Operator--\n";
    std::cout << --mc << '\n';

    std::cout << "Operator+\n";
    Matrix_Complex sum = mc + mc;
    std::cout << sum << '\n';

    std::cout << "Operator-\n";
    Matrix_Complex diff = mc - mc1;
    std::cout << diff << '\n';

    std::cout << "Operator==\n";
    std::cout << (mc == mc1) << '\n';

    std::cout << "Operator<\n";
    std::cout << (mc < mc1) << '\n';

    std::cout << "Operator[]\n";
    std::vector<Complex> vc = mc[0];
    for(const auto& i : vc) {
      std::cout << i << '\n';
    }

  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
}
