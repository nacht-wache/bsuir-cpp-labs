#ifndef BSUIR_CPP_LABS_LAB2_TASK_H
#define BSUIR_CPP_LABS_LAB2_TASK_H

#include <iostream>
#include <set>
#include <stdexcept>
#include <string>

class Task {
public:
  Task();
  ~Task() = default;
  explicit Task(std::string&& name);
  Task(int id, std::string&& name);

  friend class Inspector;
  friend void Print(const Task& task);
private:
  size_t id;
  std::string name = "Default";
  size_t result = 0;
  static std::set<size_t> id_base;
};

#endif //BSUIR_CPP_LABS_LAB2_TASK_H
