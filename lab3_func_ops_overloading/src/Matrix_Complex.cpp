#include <iostream>
#include <iomanip>
#include "Matrix_Complex.h"

/*Matrix_Complex::Matrix_Complex(const vector<vector<double>>& mc) {
  if(mc.empty()) {return;}
  matrix.reserve(mc.size());

  size_t columns_size = mc[0].size();
  for(size_t i = 0; i < mc.size(); ++i) {
    if(mc[i].size() != columns_size) {
      throw std::domain_error("Sizes of columns are not equal: " +
                              std::to_string(i) + " i has " + std::to_string(mc[i].size()) +
                              "elements.");
    }
    matrix[i].reserve(mc[i].size());
    for(size_t j = 0; j < mc[i].size(); ++j) {
      matrix[i][j] = mc[i][j];
    }
  }
}*/

/*Matrix_Complex::Matrix_Complex(const vector<double> &mc, size_t row_size) {
  if(mc.empty()) {return;}
  if(mc.size() % row_size != 0) {
    throw std::domain_error("Sizes of columns are not equal: "
                            "size of a vector isn't a multiple of "
                             + std::to_string(row_size) + '.');
  }

  const size_t columns_size = mc.size() / row_size;
  matrix.reserve(columns_size);
  for(size_t i = 0; i < mc.size(); ++i) {
    matrix[i].reserve(columns_size);
    for (size_t j = 0; j < columns_size; ++j) {
      //matrix[i][j] = mc[j * (i)]; неккоректная логика
    }
  }
}*/

Matrix_Complex::Matrix_Complex(const vector<vector<Complex>>& mc) {
  matrix = mc;
}

Matrix_Complex& Matrix_Complex::operator++() {
  for(auto& i : matrix) {
    for(auto& j : i) {
      ++j;
    }
  }
  return *this;
}

vector<Complex>& Matrix_Complex::operator[](size_t i) {
  return matrix[i];
}

const vector<Complex>& Matrix_Complex::operator[](size_t i) const {
  return matrix[i];
}

Matrix_Complex& Matrix_Complex::operator+=(const Matrix_Complex& mc) {
  CheckDimensions(matrix, mc);
  for(size_t i = 0; i < matrix.size(); ++i) {
    for(size_t j = 0; j < matrix[i].size(); ++j) {
      matrix[i][j] += mc[i][j];
    }
  }
  return *this;
}

Matrix_Complex Matrix_Complex::operator+(const Matrix_Complex& mc) {
  CheckDimensions(matrix, mc);
  Matrix_Complex matrix_return = *this;
  matrix_return += mc;
  return matrix_return;
}

bool Matrix_Complex::operator<(const Matrix_Complex& mc) const {
  for(size_t i = 0; i < mc.rows(); ++i) {
    for(size_t j = 0; j < mc.columns(); ++j) {
      if(matrix[i][j] > mc[i][j]) {
        return false;
      }
    }
  }
  return true;
}

Matrix_Complex& operator--(Matrix_Complex& mc) {
  for(size_t i = 0; i < mc.rows(); ++i) {
    for(size_t j = 0; j < mc.columns(); ++j) {
      --mc[i][j];
    }
  }
  return mc;
}

Matrix_Complex operator-(const Matrix_Complex& lhs, const Matrix_Complex& rhs) {
  CheckDimensions(lhs, rhs);
  Matrix_Complex result = lhs;
  for(size_t i = 0; i < result.rows(); ++i) {
    for(size_t j = 0; j < result.columns(); ++j) {
      result[i][j] -= rhs[i][j];
    }
  }
  return result;
}

bool operator==(const Matrix_Complex& lhs, const Matrix_Complex& rhs){
  CheckDimensions(lhs, rhs);
  for(size_t i = 0; i < lhs.rows(); ++i) {
    for(size_t j = 0; j < lhs.columns(); ++j) {
       if(lhs[i][j] != rhs[i][j]) {
         return false;
       }
    }
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix_Complex& mc) {
  if(mc.empty()) { return os; }

  for(size_t i = 0; i < mc.rows(); ++i) {
    for(size_t j = 0; j < mc.columns(); ++j) {
      j != mc.columns() -1
      ? os << std::setw(15) << std::setfill(' ') << mc[i][j] << ' '
      : os << std::setw(15) << std::setfill(' ') << mc[i][j] << '\n';
    }
  }

  return os;
}

Matrix_Complex::operator Dimension() const{
  Dimension d(matrix.size(),matrix[0].size());
  return d;
}

//helper functions

void CheckDimensions(const Matrix_Complex& lhs, const Matrix_Complex& rhs) {
  if(static_cast<Dimension>(lhs) != static_cast<Dimension>(rhs)) {
    throw std::domain_error("Operation is impossible: matrices dimensions aren't equal!");
  }
}

void CheckDimensions(const vector<vector<Complex>>& lhs, const Matrix_Complex& rhs) {
  if(static_cast<Dimension>(static_cast<Matrix_Complex>(lhs)) != static_cast<Dimension>(rhs))  {
    throw std::domain_error("Operation is impossible: matrices dimensions aren't equal!");
  }
}

