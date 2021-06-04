#include <String.h>
#include <test.h>
#include <string>

int main() {
  {
    String s = "abas12721703AXVASD!@(*!(GH@(D)IS)AKCSA";

    String s_copy = s;
    std::cout << "Original " << s << ' ' << s.size() << ' ' << s.capacity() << '\n';
    std::cout << "Copy " << s_copy << ' ' << s.size() << ' ' << s.capacity() << '\n';

    s.sort();
    std::cout << "Original sorted " << s << ' ' << s.size() << ' ' << s.capacity() << '\n';
    std::cout << "Copy " << s_copy << ' ' << s.size() << ' ' << s.capacity() << '\n';
  }

  String* sp = new String[15];
  sp[3] = "abc";
  std::cout << sp[3];
}
