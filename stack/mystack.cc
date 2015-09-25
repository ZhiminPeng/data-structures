/*
Implementation for stack member functions
*/


#include "mystack.h"
#include <iostream>

template <typename ElemType>
MyStack<ElemType>::MyStack()
{

}

template <typename ElemType>
MyStack<ElemType>::~MyStack()
{
  
}


template <typename ElemType>
int MyStack<ElemType>::size()
{
  return data_.size();
}

template <typename ElemType>
ElemType MyStack<ElemType>::top()
{
  if(data_.size()==0) std::cout<<"The stack is empty."<<std::endl;
  else return data_.getAt(data_.size()-1);
  return 0;
}

template <typename ElemType>
void MyStack<ElemType>::pop()
{
  if(data_.size()==0) std::cout<<"The stack is empty."<<std::endl;  
  data_.removeAt(data_.size()-1);
}

template <typename ElemType>
void MyStack<ElemType>::push(ElemType val)
{
  data_.add(val);
}

template <typename ElemType>
void MyStack<ElemType>::print()
{
  if(data_.size()==0) std::cout<<"The stack is empty."<<std::endl;
  for(int i=0; i<data_.size();i++)
    std::cout<<data_.getAt(i)<<" ";
  std::cout<<std::endl;
}

