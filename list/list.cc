#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  // list initializer
  ListNode(int x): val(x), next(NULL) {}

};

// pass by reference of pointer to modify the pointer
// otherwise we will need to return a ListNode pointer
void push_front(ListNode*& head, int val){
  ListNode* node = new ListNode(val);
  node->next = head;
  head = node;
}


void insert_after(ListNode*& head, int pos, int val){
  if(pos<0){
    push_front(head, val);
    return;
  }
  ListNode* curr = head;
  ListNode* temp;
  while(pos){
    if(curr->next == NULL) break;
    curr = curr->next;
    --pos;
  }
  temp = curr->next;
  ListNode* node = new ListNode(val);
  curr->next = node;
  node->next = temp;

}


void push_back(ListNode*& head, int val){
  ListNode* temp = head;
  ListNode* node = new ListNode(val);
  if(head==NULL){
    head = node;
  }
  while (temp->next) {
    temp = temp->next;
  }
  temp->next = node;
  return;
}


void delete_at(ListNode*& head, int pos){
  ListNode* new_head = head->next;
  if(pos==0){
    delete[] head;
    head = head->next;
    return;
  }
  ListNode* prev = head;
  while(pos>1){
    if(prev->next == NULL){
      return;
    }else{
      prev = prev->next;
      --pos;
    }
  }

  ListNode* curr = prev->next;
  ListNode* next = curr->next;
  prev->next = next;
  delete[] curr;
  return;
}



void print(ListNode* head){

  if(head == NULL) return;
  while(head->next){
    cout<<head->val <<"->";
    head = head->next;
  }
  cout<<head->val<<endl;
 
}


int main(){
  ListNode *head = new ListNode(1);
  ListNode *second = new ListNode(2);
  ListNode *third = new ListNode(3);
  head->next = second;
  second->next = third;
  print(head);
  push_front(head, 0);
  //insert_after(head, 1, 100);
  push_back(head, 200);
  print(head);
  delete_at(head, 4);
  print(head);
  return 0;

}
