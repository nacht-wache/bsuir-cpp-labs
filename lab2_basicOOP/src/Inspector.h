#ifndef BSUIR_CPP_LABS_LAB2_INSPECTOR_H
#define BSUIR_CPP_LABS_LAB2_INSPECTOR_H

#include "Task.h"

class Inspector {
public:
  void SetResult(Task& task, int result) {
    if (result > 100 || result < 0) {
      throw std::out_of_range("Result " + std::to_string(result) +
                                   " is out of range [0, 100]");
    }
    task.result = result;
  }
};

#endif //BSUIR_CPP_LABS_LAB2_INSPECTOR_H
