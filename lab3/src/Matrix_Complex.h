#ifndef BSUIR_CPP_LABS_LAB3_SRC_MATRIX_COMPLEX_H
#define BSUIR_CPP_LABS_LAB3_SRC_MATRIX_COMPLEX_H

#include <vector>
#include <ostream>
#include <stdexcept>
#include <Complex.h>
#include <Dimension.h>

using std::vector;

class Matrix_Complex {
public:
  Matrix_Complex() = default;
  ~Matrix_Complex() = default;
  Matrix_Complex(const Matrix_Complex& mc) = default;
  Matrix_Complex& operator=(const Matrix_Complex& mc) = default;

  explicit Matrix_Complex(const vector<vector<Complex>>& mc);
  /*explicit Matrix_Complex(const vector<vector<double>>& mc); // needs review
  Matrix_Complex(const vector<double>& mc, size_t row_size);*/ // needs review

  Matrix_Complex& operator++();
  Matrix_Complex& operator+=(const Matrix_Complex& mc);
  Matrix_Complex operator+(const Matrix_Complex& mc);
  bool operator<(const Matrix_Complex& mc) const;
  //vector<Complex>& operator[](size_t i); // needs review
  vector<Complex>& operator[](size_t i);
  const vector<Complex>& operator[](size_t i) const;

  friend Matrix_Complex& operator--(Matrix_Complex& mc);
  friend Matrix_Complex operator-(const Matrix_Complex& lhs, const Matrix_Complex& rhs);
  friend bool operator==(const Matrix_Complex& lhs, const Matrix_Complex& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Matrix_Complex& mc);

  explicit operator Dimension() const;

  [[nodiscard]] size_t rows() const { return matrix.size(); }
  [[nodiscard]] size_t columns() const { return matrix[0].size(); }
  [[nodiscard]] bool empty() const { return matrix.empty(); }

private:
  vector<vector<Complex>> matrix;
};

void CheckDimensions(const Matrix_Complex& lhs, const Matrix_Complex& rhs);

void CheckDimensions(const vector<vector<Complex>>& lhs, const Matrix_Complex& rhs);

#endif //BSUIR_CPP_LABS_LAB3_SRC_MATRIX_COMPLEX_H
