#ifndef _myqueue_h
#define _myqueue_h

template <typename ElemType>
struct Node {
  ElemType val;
  Node* next;
  Node (ElemType v) : val(v), next(nullptr) {}
};

template <typename ElemType>
class MyQueue {

public:
  MyQueue();
  ~MyQueue();
  int size();
  void enqueue(ElemType val);
  void dequeue();
  void print();
  ElemType front();
  
private:

  Node<ElemType>* head;
  Node<ElemType>* tail;
};

#include "myqueue.cc"

#endif
