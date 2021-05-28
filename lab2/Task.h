#ifndef BSUIR_CPP_LABS_LAB2_TASK_H
#define BSUIR_CPP_LABS_LAB2_TASK_H

#include <iostream>
#include <string>
#include <set>
#include <stdexcept>


class Task {
public:
  Task();
  ~Task() = default;
  Task(const std::string& name);
  Task(int id, const std::string& name);

  friend class Inspector;
  friend void Print(const Task& task);
  friend void Log();
private:
  int id;
  std::string name = "Default";
  int result = 0;
  static std::set<int> id_base;
};

#endif //BSUIR_CPP_LABS_LAB2_TASK_H
