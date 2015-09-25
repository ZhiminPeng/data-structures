/*
header file for my queue implementation
*/

#ifndef _myqueue_h
#define _myqueue_h

template <typename ElemType>
class MyQueue{
 public:
  MyQueue();
  ~MyQueue();
  void enqueue(ElemType val);
  ElemType dequeue();
  bool isEmpty();
  ElemType front();
  void print();
 private:
  struct node{
    ElemType val;
    node* next;
  };
  node* head;
  node* tail;
};


#include "myqueue.cc"

#endif
