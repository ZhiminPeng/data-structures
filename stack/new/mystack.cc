#include <iostream>
#include <cstdlib>
#include "mystack.h"

template <typename ElemType>
MyStack<ElemType>::MyStack(){
  head = NULL;
}

template <typename ElemType>
MyStack<ElemType>::~MyStack(){
  Node<ElemType>* temp;
  while (head) {
    temp = head->next;
    delete head;
    head = temp;
  }
}

template <typename ElemType>
int MyStack<ElemType>::size() {
  int len = 0;
  Node<ElemType>* curr = head;
  while (curr) {
    curr = curr->next;
    ++len;
  }
  return len;
}


template <typename ElemType>
void MyStack<ElemType>::print() {
  Node<ElemType>* curr = head;
  while (curr) {
    std::cout << curr->val << " ";    
    curr = curr->next;
  }
  std::cout << "\n";
}

template <typename ElemType>
void MyStack<ElemType>::push(ElemType val) {

  Node<ElemType>* node  = new Node<ElemType>(val);
  node->next = head;
  head = node;
}

template <typename ElemType>
ElemType MyStack<ElemType>::top() {

  if (head) {
    return head->val;
  } else {
    std::cout << "The stack is empty. \n";
    abort();
  }
}

template <typename ElemType>
void MyStack<ElemType>::pop() {
  if (head) {
    Node<ElemType>* temp = head;
    head = head->next;
    delete temp;
  } else {
    std::cout << "The stack is empty. \n";
    abort();
  }
}
