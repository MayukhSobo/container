#ifndef __SLL_H__
#     define __SLL_H__
#include <stddef.h>
#include <stdbool.h>

typedef struct _Node {
  int data;
  struct _Node* next;
}Node;

typedef struct _List {
  size_t size;
  Node* head;
  Node* tail;
  Node* curr;
}sList;

void init(sList**);
/////////////////////////////

bool push_back(sList*, int);
Node* pop_back(sList*);
void print(sList*, bool);
Node* at(sList*, size_t);
Node* search(sList*, int);


#endif /* __SLL_H__ */
