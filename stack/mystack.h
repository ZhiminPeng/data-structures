/*

header file for my stack class

*/

#ifndef _mystack_h
#define _mystack_h

#include "myvector.h"

template <typename ElemType>
class MyStack
{
 public:
  MyStack();
  ~MyStack();
  
  int size();
  ElemType top();
  void pop();
  void push(ElemType val);
  void print();
 private:
  MyVector<ElemType> data_;
};


#include "mystack.cc"

#endif
