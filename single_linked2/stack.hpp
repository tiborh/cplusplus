#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cassert>
#include <iostream>
#include <ostream>
#include <exception>
#include "node.hpp"

struct nomoreitems: public std::exception {
  virtual const char* what() const throw() {
    return "No items in the list.";
  }
};

template<typename T> class stack;
template<typename T> std::ostream& operator<<(std::ostream&, const stack<T>&);

template<typename T>
class stack {
public:
  struct iterator;
  stack():first(nullptr),last(nullptr),n(0) {}
  //stack(const stack& other):first(other.first),n(other.n) {}
  ~stack() {}
  void push(const T);
  //void push(const node<T>);
  T pop();
  T view() const;
  //void erase();
  int size() const { return n; }
  bool is_empty() const { return first == nullptr; }
  iterator begin() { return iterator(first); }
  iterator end() { return iterator(); }
  friend std::ostream& operator<< <> (std::ostream&, const stack<T>&);
protected:
  node<T> *first,*last;
  int n;
private:
};

template<typename T>
struct stack<T>::iterator {
  node<T>* current;
  iterator():current(nullptr) {}
  iterator(node<T>* other):current(other) {}
  node<T>& operator*() { return *current; }
  bool operator==(const iterator& other) {
    if (current == nullptr && other.current == nullptr)
      return true;
    if (current == nullptr || other.current == nullptr)
      return false;
    return (current->item == other.current->item &&
	    current->next_node == other.current->next_node);
  }
  bool operator!=(const iterator& other) {
    return !(*this==other);
  }
  iterator& operator++() {
    if (current == nullptr) {
      std::cerr << "Iterator points at nullptr.\n";
      throw nomoreitems();
    }
    current = current->next_node;
    return *this;
  }
};

template<typename T>
T stack<T>::view() const {
  if (n == 0 || first == nullptr )
    throw nomoreitems();
  
  return first->item;
}

template<typename T>
void stack<T>::push(const T payload) {
  node<T>* a_node = new node<T>(payload);
  a_node->next_node = first;
  first = a_node;
  if (last == nullptr)
    last = a_node;
  assert(first->item == payload);
  assert(first == a_node);
  assert(last != nullptr);
  ++n;
}

template<typename T>
T stack<T>::pop() {
  if (n == 0 || first == nullptr )
    throw nomoreitems();
  assert(last != nullptr);

  T to_return = first->item;
  node<T>* old_node = first;
  first = first->next_node;
  if (first == nullptr)
    last = nullptr;
  delete(old_node);
  --n;
  return to_return;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const stack<T>& st) {
  node<T>* ptr = st.first;
  //int n = st.size();
  //for(int i = 0; i < n; ++i) {
  while (ptr != nullptr) {
    os << '\t' << *ptr << '\n';
    ptr = ptr->next_node;
  }
  return os;
}

// template<typename T>
// void stack<T>::push(const node<T> new_node) {
//   node<T>* a_node = new node<T>(new_node);
//   a_node -> next_node = first;
//   first = a_node;
//   assert(first->item == new_node.item);
//   assert(first == a_node);
//   ++n;
// }

// template<typename T>
// void stack<T>::erase() {
//   while(first != nullptr)
//     pop();
//   assert(n == 0);
//   assert(first == nullptr);
// }

#endif //STACK_H_INCLUDED

// Local Variables:
// mode: c++
// End:
