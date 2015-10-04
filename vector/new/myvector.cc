#include <iostream>
#include <cstdlib>
#include "myvector.h"

template <typename ElemType>
MyVector<ElemType>::MyVector(){
  
  arr_ = new ElemType[2];
  num_used_ = 0;
  num_allocated_ = 2;
}

template <typename ElemType>
MyVector<ElemType>::~MyVector(){
  delete[] arr_;
  num_used_ = 0;
  num_allocated_ = 0;
}


template <typename ElemType>
int MyVector<ElemType>::size(){
  
  return num_used_;

}

template <typename ElemType>
void MyVector<ElemType>::add(ElemType s) {
  if (num_used_ < num_allocated_) {
    arr_[num_used_++] = s;
  } else {
    doubleCapacity();
    arr_[num_used_++] = s;    
  }
}

template <typename ElemType>
void MyVector<ElemType>::print(){
  for (int i = 0; i < num_used_; i++) {
    std::cout << arr_[i] << " ";
  }
  std::cout << std::endl;
}


template <typename ElemType>
void MyVector<ElemType>::doubleCapacity() {
  ElemType* temp = new ElemType[2 * num_allocated_];
  for (int i = 0; i < num_used_; i++) {
    temp[i] = arr_[i];
  }
  num_allocated_ *= 2;
  delete[] arr_;
  arr_ = temp;
}

template <typename ElemType>
void MyVector<ElemType>::setAt(int index, ElemType s) {
  if (index >= num_used_) {
    while (index >= num_allocated_) {
      doubleCapacity();
    }
    num_used_ = index + 1;
  }
  arr_[index] = s;
}

template <typename ElemType>
ElemType MyVector<ElemType>::getAt(int index) {
  if (index >= num_used_) {
    std::cout << "Out of range!" << std::endl;
    abort();
  }
  return arr_[index];
}

template <typename ElemType>
void MyVector<ElemType>::insertAt(int index, ElemType e) {

  if (index >= num_used_) {
    setAt(index, e);
  } else {
    if (num_used_ == num_allocated_) {
      doubleCapacity();
    }
    for (int j = num_used_ - 1; j >= index; j--) {
      arr_[j + 1] = arr_[j];
    }
    arr_[index] = e;
    ++num_used_;
  }
  return;
}

template <typename ElemType>
void MyVector<ElemType>::removeAt(int index) {
  if (index < num_used_) {
    for (int i = index; i < num_used_ - 1; i++) {
      arr_[i] = arr_[i + 1];
    }
    --num_used_;
  }
}

template <typename ElemType>
ElemType MyVector<ElemType>::operator[](int index) {
  return getAt(index);
}
