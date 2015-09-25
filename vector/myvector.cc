#include "myvector.h"
#include <iostream>

template <typename ElemType>
MyVector<ElemType>::MyVector()
{
  arr_ = new ElemType[2];
  num_used_ = 0;
  num_allocated_ = 2;
}

template <typename ElemType>
MyVector<ElemType>::~MyVector()
{
  // delete memory
  delete[] arr_;
}

template <typename ElemType>
int MyVector<ElemType>::size()
{
  return num_used_;
}

template <typename ElemType>
void MyVector<ElemType>::add(ElemType s)
{
  if(num_used_==num_allocated_) doubleCapacity();
  arr_[num_used_] = s;
  ++num_used_;
}

template <typename ElemType>
ElemType MyVector<ElemType>::getAt(int index)
{
  if(index>=size()) return 0;
  else return arr_[index];
}

template <typename ElemType>
void MyVector<ElemType>::setAt(int index, ElemType val)
{
  if(index >= num_allocated_) doubleCapacity();
  arr_[index] = val;
}
 
template <typename ElemType>
void MyVector<ElemType>::insertAt(int index, ElemType val)
{
  if(num_used_==num_allocated_) doubleCapacity();
  for(int i=num_used_;i>index;--i)
    arr_[i] = arr_[i-1];
  arr_[index] = val;
  ++num_used_;
}

template <typename ElemType>
void MyVector<ElemType>::removeAt(int index)
{
  if(index>=num_used_) std::cout<<"Error: index out of bound."<<std::endl;
  for(int i = index; i<num_used_;i++)
    arr_[i]= arr_[i+1];
  --num_used_;
}


template <typename ElemType>
void MyVector<ElemType>::doubleCapacity()
{
  ElemType *bigger = new ElemType[num_allocated_*2];
  for(int i=0;i<num_used_;i++)
    bigger[i] = arr_[i];

  delete[] arr_;
  arr_ = bigger;
  num_allocated_*=2;
}

template <typename ElemType>
void MyVector<ElemType>::print()
{
  for(int i=0;i<size();i++)
    std::cout<<arr_[i]<<" ";
  std::cout<<std::endl;
}
