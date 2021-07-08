#include <task.h>
#include <My_exception.h>

int main() {
  try {
	DoubleLinkedList<Helper_throw> lst_except;
	lst_except.reserve(4);
	for (int i = 0; i < 4; ++i) {
	  lst_except.push_back(Helper_throw('c'));
	}
  } catch (My_exception) {
	std::cerr << "My_exception caught!\n";
  } catch (...) {
	std::cerr << "Terminate!\n";
  }
}

