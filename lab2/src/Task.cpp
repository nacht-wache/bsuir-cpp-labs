#include "Task.h"


std::set<int> Task::id_base;

void Log() {
  std::cout << Task::id_base.size() << '\n';
}

Task::Task() {
  id = Task::id_base.size();
  Task::id_base.insert(Task::id_base.size());
  Log();
}

Task::Task(const std::string &name) {
  id = Task::id_base.size();
  Task::id_base.insert(Task::id_base.size());
  this->name = name;
  Log();
}

Task::Task(int id, const std::string& name): id(id), name(name) {
  if (id < 0 || id > INT32_MAX) {
    throw std::out_of_range("Id " + std::to_string(id) + " is out of range [0, " + std::to_string(INT32_MAX) + "].");
  }

  if (Task::id_base.count(id)) {
    throw std::runtime_error("Task with id " + std::to_string(id) + " is already exists. "
                             "Next available is " + std::to_string(Task::id_base.size()) + '.');
  }
  Task::id_base.insert(id);
  Log();
}
