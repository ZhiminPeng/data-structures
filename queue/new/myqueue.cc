#include <iostream>
#include <cstdlib>

template <typename ElemType>
MyQueue<ElemType>::MyQueue() {
  head = tail = nullptr;
}


template <typename ElemType>
MyQueue<ElemType>::~MyQueue() {
  Node<ElemType>* temp;
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }
  tail = nullptr;
}

template <typename ElemType>
int MyQueue<ElemType>::size() {
  int len = 0;
  Node<ElemType>* curr = head;
  while (curr) {
    curr = curr->next;
    ++len;
  }
  return len;
}


template <typename ElemType>
void MyQueue<ElemType>::print() {
  Node<ElemType>* curr = head;
  while (curr) {
    std::cout << curr->val << " ";
    curr = curr->next;
  }
  std::cout << "\n";
}


template <typename ElemType>
void MyQueue<ElemType>::enqueue(ElemType val) {
  Node<ElemType>* temp = new Node<ElemType>(val);
  if (head == nullptr) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = tail->next;
  }
}

template <typename ElemType>
void MyQueue<ElemType>::dequeue() {
  if (head) {
    Node<ElemType>* temp = head;
    head = head->next;
    delete temp;
  }
}

template <typename ElemType>
ElemType MyQueue<ElemType>::front() {
  if (head) {
    return head->val;
  } else {
    std::cout << "The queue is empty! \n";
    abort();
  }
}
