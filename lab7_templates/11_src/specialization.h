#ifndef BSUIR_CPP_LABS_LAB7_TEMPLATES_11_SRC_SPECIALIZATION_H_
#define BSUIR_CPP_LABS_LAB7_TEMPLATES_11_SRC_SPECIALIZATION_H_

#include <task.h>

template <>
class DoubleLinkedList<char*> {
 private:
  struct Node {
	char* value;
	Node* prev = nullptr;
	Node* next = nullptr;

	Node() = delete;
	explicit Node(char*& value, Node* prev = nullptr, Node* next = nullptr)
		: value(value), prev(prev), next(next) {};
	Node(const Node& node) = default;
	~Node() = default;
  };

  static Node** arr;
  Node* head = nullptr;
  Node* tail = nullptr;
  size_t sz = 0;
  size_t cap = 0;

 public:

  typedef Node node_type;

  // Constructors and destructor
  DoubleLinkedList() = default;
  DoubleLinkedList(const std::initializer_list<char*>& lst) {
	if (std::empty(lst)) { return; }

	arr = static_cast<Node**>(::operator new(lst.size() * sizeof(Node*)));

	for (auto item : lst) {
	  if (empty()) {
		head = new Node(item);
		tail = head;
		arr[sz] = head;
		++sz;
		++cap;
	  } else if (sz == 1) {
		Node* node = new Node(item, tail, tail);
		head->next = node;
		head = node;
		tail->next = head;
		tail->prev = head;
		arr[sz] = head;
		++sz;
		++cap;
	  } else {
		Node* node = new Node(item, head, tail);
		head->next = node;
		head = node;
		tail->prev = head;
		arr[sz] = head;
		++sz;
		++cap;
	  }
	}
  };

  ~DoubleLinkedList() {
	if (empty()) { return; }

	while (head != tail) {
	  Node* temp = head->prev;
	  delete head;
	  head = temp;
	}
	delete head;
	delete[] static_cast<void*>(arr);
  };


  bool empty() { return sz == 0; }
  [[nodiscard]] size_t size() const {
	return sz;
  }

  char*& operator[](size_t count) {
	Node* node = tail;
	for(size_t i = 0; i != count; ++i) {
	  node = node->next;
	}
	return node->value;
  }

  char* const & operator[](size_t count) const {
	Node* node = tail;
	for(size_t i = 0; i != count; ++i) {
	  node = node->next;
	}
	return node->value;
  }
};

typename DoubleLinkedList<char*>::node_type** DoubleLinkedList<char*>::arr = nullptr;

template <>
class ops<char*> : public DoubleLinkedList<char*> {
 public:
  void print(DoubleLinkedList<char*>& lst) {
	for(size_t i = 0; i < lst.size(); ++i) {
	  std::cout << *(lst[i]) << ' ';
	}
	std::cout << '\n';
  }
};

#endif //BSUIR_CPP_LABS_LAB7_TEMPLATES_11_SRC_SPECIALIZATION_H_
