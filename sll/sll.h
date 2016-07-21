#ifndef __SLL_H__
#     define __SLL_H__
#include <stddef.h>
#include <stdbool.h>

typedef struct _Node {
  int data;
  struct _Node* next;
}sNode;

typedef struct _List {
  size_t size;
  sNode* head;
  sNode* tail;
  sNode* curr;
}sList;

void init(sList**);
/////////////////////////////

bool push_back(sList*, int);
int pop_back(sList*);
void print(sList*);
sNode* at(sList*, size_t);
sNode* search(sList*, int);
void create(sList* list, int*, size_t);
void reverse(sList* list);
void purge(sList*);
#endif /* __SLL_H__ */
