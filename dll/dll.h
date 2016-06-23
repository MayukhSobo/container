#ifndef __DLL_H__
#     define __DLL_H__
#include <stddef.h>
#include <stdbool.h>

/////////////////////////////
typedef struct _Node {
  struct _Node* prev;
  int data;
  struct _Node* next;
}dNode;


typedef struct _List {
  size_t size;
  dNode* head;
  dNode* tail;
  dNode* curr;
}dList;

void init(dList**);
/////////////////////////////

bool push_back(dList*, int);
dNode* pop_back(dList*);
void print(dList*, bool);
dNode* at(dList*, size_t);
dNode* search(dList*, int);

#endif /* __DLL_H__ */
