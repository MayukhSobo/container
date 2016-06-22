#ifndef __DLL_H__
#     define __DLL_H__
#include <stddef.h>
#include <stdbool.h>

/////////////////////////////
typedef struct _Node {
  struct _Node* prev;
  int data;
  struct _Node* next;
}Node;


typedef struct _List {
  size_t size;
  Node* head;
  Node* tail;
  Node* curr;
}List;

void init(List**);
/////////////////////////////

bool push_back(List*, int);
Node* pop_back(List*);
void print(List*, bool);
Node* at(List*, size_t);
Node* search(List*, int);

#endif /* __DLL_H__ */
