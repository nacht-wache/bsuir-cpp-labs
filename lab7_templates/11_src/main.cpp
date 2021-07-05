#include <task.h>
#include <specialization.h>

int main() {
  DoubleLinkedList<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for(int i = 0; i < 10; ++i) {
   std::cout << lst[i] << ' ';
  }
  std::cout << '\n';

  ops<int> oper;
  oper.print(lst);

  lst.push_back(10);
  oper.print(lst);
  lst.pop_back();
  oper.print(lst);

  ops<char*> spec_ops;

  char* ch0 = new char('9');
  char* ch1 = new char('7');
  char* ch2 = new char('4');
  DoubleLinkedList<char*> spec_list = {ch0, ch1, ch2};

  for(size_t i = 0; i < spec_list.size(); ++i) {
    std::cout << *(spec_list[i]) << '\n';
  }
  spec_ops.print(spec_list);
  delete ch0;
  delete ch1;
  delete ch2;
}

