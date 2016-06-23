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
}dList;

void init(dList**);
/////////////////////////////

bool push_back(dList*, int);
Node* pop_back(dList*);
void print(dList*, bool);
Node* at(dList*, size_t);
Node* search(dList*, int);

#endif /* __DLL_H__ */
