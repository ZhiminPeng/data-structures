/*
  implementations for queue
*/

#include "myqueue.h"
#include <iostream>

template <typename ElemType>
MyQueue<ElemType>::MyQueue()
{
  head = tail = NULL;
}

template <typename ElemType>
MyQueue<ElemType>::~MyQueue()
{
  while(head){
    node* old_nd = head;
    head = head->next;
    delete old_nd;
  }
}

template <typename ElemType>
bool MyQueue<ElemType>::isEmpty()
{
  return (head==NULL);
}

template <typename ElemType>
void MyQueue<ElemType>::enqueue(ElemType val)
{
  
  node* nd = new node;
  nd->val = val;
  nd->next = NULL;
  if(isEmpty()) head = tail = nd;
  else{
    tail->next = nd;
    tail = nd;
  }
}

template <typename ElemType>
ElemType MyQueue<ElemType>::dequeue()
{
  if(isEmpty()){
    std::cout<<"The queue is empty."<<std::endl;
    return 0;
  }
  node* old_head = head;
  head = head->next;
  ElemType val = old_head->val;
  delete old_head;
  return val;
}

template <typename ElemType>
void MyQueue<ElemType>::print()
{
  node* curr = head;
  while(curr){
    std::cout<<curr->val<<" ";
    curr = curr->next;
  }
  std::cout<<std::endl;
}
