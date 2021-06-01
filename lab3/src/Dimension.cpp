#include "Dimension.h"

Dimension::Dimension(): rows(0), columns(0) {}

Dimension::Dimension(size_t m, size_t n): rows(m), columns(n) {}

bool Dimension::operator!=(const Dimension& d) const {
  return rows != d.rows && columns != d.columns;
}

