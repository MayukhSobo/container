#ifndef __GENERIC_H__
#     define __GENERIC_H__
#include <stddef.h>
#include <stdbool.h>

typedef enum {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  EXPLICIT,
}types;


typedef struct _Node {
  struct _Node* prev;
  void* data;
  struct _Node* next;
}Node;

typedef struct _List {
  size_t size;
  Node* head;
  Node* tail;
  Node* curr;
  types aType;
}List;

//////////////////////////

void init(List**, types what);
bool push_back(List*, void*);
void* pop_back(List*);
void print(List*);
//////////////////////////

void init(List**, types what);
#endif /* __GENERIC_H__ */
