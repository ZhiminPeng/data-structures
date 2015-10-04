/* 
header file for myvector class 

*/

#ifndef _myvector_h
#define _myvector_h

template <typename ElemType>
class MyVector
{
 public:
  MyVector();
  ~MyVector();

  int size();
  void add(ElemType s);
  ElemType getAt(int index);
  void setAt(int index, ElemType s);
  void insertAt(int index, ElemType e);
  void removeAt(int index);
  void print();
  ElemType operator [] (int index);
 private:
  ElemType *arr_;
  int num_used_, num_allocated_;
  void doubleCapacity();
};

#include "myvector.cc"

#endif
