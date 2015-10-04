#ifndef _mystack_h
#define _mystack_h

template <typename ElemType>
struct Node {
  ElemType val;
  Node* next;
 Node(ElemType v) : val(v), next(nullptr) {};
};

template <typename ElemType>
class MyStack{

public:
  MyStack();
  MyStack(int val);
  ~MyStack();

  int size();
  ElemType top();
  void pop();
  void push(ElemType val);
  void print();

private:
  Node<ElemType>* head;
};

#include "mystack.cc"

#endif
