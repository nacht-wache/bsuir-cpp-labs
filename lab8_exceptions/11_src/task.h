#ifndef BSUIR_CPP_LABS_LAB7_TEMPLATES_SRC_TASK_H_
#define BSUIR_CPP_LABS_LAB7_TEMPLATES_SRC_TASK_H_

#include <functional>
#include <iostream>

template <typename T>
class DoubleLinkedList {
 private:
  struct Node {
	T value;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node() = delete;
	explicit Node(const T& value, Node* next = nullptr, Node* prev = nullptr)
		: value(value), next(next), prev(prev) {};
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
  DoubleLinkedList(const std::initializer_list<T>& lst);
  ~DoubleLinkedList();

  void push_back(const T& value);
  void pop_back();

  void reserve(size_t count);
  bool empty();
  [[nodiscard]] size_t size() const {
	return sz;
  }

  T& operator[](size_t count) {
	Node* node = tail;
	for (size_t i = 0; i != count; ++i) {
	  node = node->next;
	}
	return node->value;
  }

  const T& operator[](size_t count) const {
	Node* node = head;
	for (size_t i = 0; i != count; ++i) {
	  node = node->next;
	}
	return node->value;
  }
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const std::initializer_list<T>& lst) {
  if (std::empty(lst)) { return; }
  reserve(lst.size() * 2);

  for (auto item : lst) {
	if (empty()) {
	  head = new Node(item, tail, head);
	  tail = head;
	  arr[sz] = head;
	  ++sz;
	} else if (sz == 1) {
	  Node* node = new Node(item, tail, head);
	  head->next = node;
	  tail->next = node;
	  tail->prev = node;
	  head = node;
	  arr[sz] = head;
	  ++sz;
	} else {
	  Node* node = new Node(item, tail, head);
	  head->next = node;
	  tail->prev = node;
	  head = node;
	  arr[sz] = head;
	  ++sz;
	}
  }
}

template <typename T>
void DoubleLinkedList<T>::reserve(size_t count) {
  if (count <= cap) { return; }

  auto newarr = static_cast<Node**>(::operator new[](count * sizeof(Node*)));
  try {
	std::uninitialized_copy(arr, arr + sz, newarr);
  } catch (...) {
	::operator delete(static_cast<void*>(newarr));
	throw;
  }

  for (size_t i = sz; i != 0; --i) {
	(*(arr + i - 1))->~Node();
  }
  ::operator delete[](static_cast<void*>(arr));
  arr = newarr;

  cap = count;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  if (empty()) {
    if (cap == 0) {
	  return;
	}
    ::operator delete[](static_cast<void*>(arr));
	return;
  }

  while (head != tail) {
	Node* temp = head->prev;
	delete head;
	head = temp;
  }
  delete head;
  ::operator delete[](static_cast<void*>(arr));
}

template <typename T>
bool DoubleLinkedList<T>::empty() {
  return sz == 0;
}

template <typename T>
void DoubleLinkedList<T>::push_back(const T& value) {
  if (sz == cap) { reserve( 2 * cap); }


  if (head == nullptr) {
    Node* node = new Node(value, nullptr, nullptr);
    head = node;
    tail = node;
    arr[sz] = node;
    ++sz;
	return;
  } else if (head->next == nullptr && tail->next == nullptr) {
	Node* node = new Node(value, tail, head);
	head = node;
	tail->prev = head;
	tail->next = head;
	arr[sz] = node;
	++sz;
	return;
  }
  Node* node = new Node(value, tail, head);
  head->next = node;
  tail->prev = node;
  head = node;
  arr[sz] = node;
  ++sz;
}

template <typename T>
void DoubleLinkedList<T>::pop_back() {
  Node* node = head;
  head = head->prev;
  head->next = tail;
  tail->prev = head;
  delete node;
  arr[0] = nullptr;
  --sz;
}

template <typename T>
typename DoubleLinkedList<T>::node_type** DoubleLinkedList<T>::arr = nullptr;

template <typename T>
class ops : public DoubleLinkedList<T> {
 public:
  void print(DoubleLinkedList<T>& lst) {
	for (size_t i = 0; i < lst.size(); ++i) {
	  std::cout << lst[i] << ' ';
	}
	std::cout << '\n';
  }
};

#endif //BSUIR_CPP_LABS_LAB7_TEMPLATES_SRC_TASK_H_
