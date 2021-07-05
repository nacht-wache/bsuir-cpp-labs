#ifndef BSUIR_CPP_LABS_LAB7_TEMPLATES_SRC_TASK_H_
#define BSUIR_CPP_LABS_LAB7_TEMPLATES_SRC_TASK_H_

#include <functional>
#include <iostream>

template <typename T>
class DoubleLinkedList {
 private:
  struct Node {
	T value;
	Node* prev = nullptr;
	Node* next = nullptr;

	Node() = delete;
	explicit Node(const T& value, Node* prev = nullptr, Node* next = nullptr)
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
  DoubleLinkedList(const std::initializer_list<T>& lst);
  ~DoubleLinkedList();

  void push_back(const T& value);
  void pop_back();


  bool empty();
  [[nodiscard]] size_t size() const {
	return sz;
  }

  T& operator[](size_t count) {
    Node* node = tail;
    for(size_t i = 0; i != count; ++i) {
      node = node->next;
    }
	return node->value;
  }

  const T& operator[](size_t count) const {
	Node* node = head;
	for(size_t i = 0; i != count; ++i) {
	  node = node->next;
	}
	return node->value;
  }
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const std::initializer_list<T>& lst) {
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
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
  if (empty()) { return; }

  while (head != tail) {
	Node* temp = head->prev;
	delete head;
	head = temp;
  }
  delete head;
  delete[] static_cast<void*>(arr);
}

template <typename T>
bool DoubleLinkedList<T>::empty() {
  return sz == 0;
}

template <typename T>
void DoubleLinkedList<T>::push_back(const T& value) {
  if(sz == cap) {
    auto newarr = static_cast<Node**>(::operator new(2 * cap * sizeof(Node*)));
    try {
      std::uninitialized_copy(arr, arr+sz, newarr);
    } catch (...) {
	  ::operator delete(static_cast<void*>(newarr));
	  throw;
	}

    delete[] static_cast<void*>(arr);
    arr = newarr;
    cap *= 2;
  }
  Node* node = new Node(value, head, tail);
  head->next = node;
  head = node;
  tail->prev = head;
  arr[sz] = head;
  ++sz;
  ++cap;
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
    for(size_t i = 0; i < lst.size(); ++i) {
      std::cout << lst[i] << ' ';
    }
    std::cout << '\n';
  }
};

#endif //BSUIR_CPP_LABS_LAB7_TEMPLATES_SRC_TASK_H_
