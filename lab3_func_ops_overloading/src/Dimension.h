#ifndef BSUIR_CPP_LABS_LAB3_SRC_DIMENSION_H
#define BSUIR_CPP_LABS_LAB3_SRC_DIMENSION_H

#include <cstdlib>

class Dimension {
public:
  Dimension();
  Dimension(const Dimension&) = default;
  Dimension(size_t m, size_t n);
  ~Dimension() = default;

  bool operator!=(const Dimension& d) const;
private:
  size_t rows;
  size_t columns;
};

#endif //BSUIR_CPP_LABS_LAB3_SRC_DIMENSION_H
