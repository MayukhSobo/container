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

void init_d(dList**);
/////////////////////////////

bool push_back_d(dList*, int);
int pop_back_d(dList*);
void printd(dList*, bool);
dNode* at_d(dList*, size_t);
dNode* search_d(dList*, int);

bool push_at_d(dList*, int, size_t);
int pop_from_d(dList*, size_t);
#endif /* __DLL_H__ */
