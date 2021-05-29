#include <iostream>
#include <vector>
#include "Task.h"
#include "Inspector.h"


void Print(const Task& task) {
  std::cout << "Id is: " << task.id << '\n'
            << "Name is: " << task.name << '\n'
            << "Result is: " << task.result << '\n';
}

int main() {
  try {
    Task first_task;
    Task second_task("C++ Multiple Inheritance");
    Task third_task(2, "C++ std::shared_ptr");

    Print(first_task);
    Print(second_task);
    Print(third_task);
    std::cout << '\n';

    Inspector me;
    me.SetResult(first_task, 10);
    me.SetResult(second_task, 50);
    me.SetResult(third_task, 100);

    Print(first_task);
    Print(second_task);
    Print(third_task);
    std::cout << '\n';

    std::vector<Task> Tasks {first_task, second_task};
    Tasks.push_back(third_task);

    me.SetResult(Tasks[0], 100);
    me.SetResult(Tasks[1], 20);
    me.SetResult(Tasks[2], 0);

    Print(Tasks[0]);
    Print(Tasks[1]);
    Print(Tasks[2]);

  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
  }
}