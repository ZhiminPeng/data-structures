/*
  This is my implementation of hash map.
  where the key has type string
  and value can be any type
*/
#ifndef my_hash_map_h
#define my_hash_map_h
#include <vector>
#include <string>
using namespace std;

template <typename ValType>
class MyHashMap
{
public:
  MyHashMap();
  ~MyHashMap();
  void add(string key, ValType val); // add a key val pair to the hash map
  ValType get_val(string key);

private:
  static const int knum_buckets_ = 100; // the total number of buckets

  // cell for holding the key and values, it is basically a linked list
  struct Cell{
    string key;
    ValType val;
    Cell *next;
  };

  Cell *buckets[knum_buckets_]; 

  int hash(string key, int num_buckets);
  Cell *FindCellForKey(string key, Cell* head); //find the cell within the linked list
  
};

#include "my_hash_map.cc"

#endif
