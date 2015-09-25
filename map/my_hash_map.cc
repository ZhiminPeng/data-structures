#include "my_hash_map.h"

template <typename ValType>
MyHashMap<ValType>::MyHashMap()
{
  for(int i=0;i<knum_buckets_;i++)
    buckets[i] = NULL;
}

template <typename ValType>
MyHashMap<ValType>::~MyHashMap()
{
  // delete all of the cells
}

template <typename ValType>
ValType MyHashMap<ValType>::get_val(string key)
{
  int bucket_id = hash(key, knum_buckets_);
  Cell *match = FindCellForKey(key, buckets[bucket_id]);
  if(match!=NULL) return match->val;
  else return 0;
}

template <typename ValType>
typename  MyHashMap<ValType>::Cell *MyHashMap<ValType>::FindCellForKey(string key, Cell *head)
{
  while(head){
    if(head->key == key ) return head;
    head = head->next;
  }
  return NULL;
}

template <typename ValType>
void MyHashMap<ValType>::add(string key, ValType val)
{
  int bucket_id = hash(key, knum_buckets_);

  Cell* match = FindCellForKey(key, buckets[bucket_id]);
  if(match) match->val = val;
  else{
    Cell *new_cell = new Cell;
    new_cell->key = key;
    new_cell->val = val;
    new_cell->next = buckets[bucket_id];
    buckets[bucket_id] = new_cell;
  }
}

const long kmultiplier = -166411799L;

template<typename ValType>
int MyHashMap<ValType>::hash(string s, int num_buckets)
{
  unsigned long hash_code = 0;
  for(int i=0;i<s.size();i++)
    hash_code = hash_code * kmultiplier + s[i];
  return hash_code % num_buckets;
}


