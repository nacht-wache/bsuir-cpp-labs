#include <String.h>
#include <test.h>

int main() {
  /*{
	String s = "abas12721703AXVASD!@(*!(GH@(D)IS)AKCSA";

	String s_copy = s;
	std::cout << "Original " << s << ' ' << s.size() << ' ' << s.capacity() << '\n';
	std::cout << "Copy " << s_copy << ' ' << s.size() << ' ' << s.capacity() << '\n';

	s.sort();
	std::cout << "Original sorted " << s << ' ' << s.size() << ' ' << s.capacity() << '\n';
	std::cout << "Copy " << s_copy << ' ' << s.size() << ' ' << s.capacity() << '\n';
  }*/

  String s("123");

for(auto i : s) {
  std::cout << i << ' ';
}

}
