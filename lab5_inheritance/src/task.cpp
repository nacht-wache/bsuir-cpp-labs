#include <task.h>

std::ostream& operator<<(std::ostream& os, const Animal& value) {
  os << value.private_animal << ' ' << value.protected_animal << '\n';
  return os;
}
std::ostream& operator<<(std::ostream& os, const Mammal& value) {
  os << value.protected_animal << '\n'
	 << value.private_mammal << ' ' << value.protected_mammal << '\n';
  return os;
}
std::ostream& operator<<(std::ostream& os, const Lion& value) {
  os << value.protected_animal << ' ' << value.protected_mammal << '\n'
	 << value.private_lion << ' ' << value.protected_lion << '\n';
  return os;
}
std::ostream& operator<<(std::ostream& os, const Bird& value) {
  os << value.protected_animal << '\n'
	 << value.private_bird << ' ' << value.protected_bird << '\n';
  return os;
}
std::ostream& operator<<(std::ostream& os, const Eagle& value) {
  os << value.protected_animal << ' ' << value.protected_bird << '\n'
	 << value.private_eagle << ' ' << value.protected_eagle << '\n';
  return os;
}
std::ostream& operator<<(std::ostream& os, const Gryphon& value) {
  os << value.protected_animal << '\n'
	 << value.protected_mammal << ' ' << value.protected_bird << '\n'
	 << value.protected_lion << ' ' << value.protected_eagle << '\n'
	 << value.private_gryphon << ' ' << value.protected_gryphon << '\n';
  return os;
}
