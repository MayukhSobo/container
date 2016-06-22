#include "./dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool initialized = false;
/////////////////////////////////////////////////////////
void init(List** list) {
  (*list) = (List*)malloc(sizeof(List));
  (*list)->size = 0;
  (*list)->head = (*list)->tail = (*list)->curr = NULL;
  initialized = true;
}
///////////////////////////////////////////////////////
bool push_back(List* list, int ele) {
  if (initialized) {
    if (list->head == NULL && list->size == 0){
     list->head = (Node*)malloc(sizeof(Node));
     list->curr = list->tail = list->head;
     list->curr->data = ele;
     list->size++;
     list->curr->prev = list->curr->next = NULL;
    }else{
      Node* temp = list->curr;
      list->curr->next = (Node*)malloc(sizeof(Node));
      list->curr = list->curr->next;
      list->curr->data = ele;
      list->tail = list->curr;
      list->size++;
      list->curr->next = NULL;
      list->curr->prev = temp;
    }
    return true;
  }else{
    printf("List is not properly initialized");
    return false;
  }
}
///////////////////////////////////////////////
void print(List* list, bool reverse) {
  if(!reverse){
    Node* loop = list->head;
    while(loop != NULL) {
      printf("%d ", loop->data);
      loop = loop->next;
    }
  }else{
  Node* loop = list->tail;
   while(loop != NULL){
     printf("%d ", loop->data);
     loop = loop->prev;
   } 
  }
  printf("\n");
}
/////////////////////////////////////////////////
Node* pop_back(List* list) {
  if (list->size == 0){
    return NULL;
  }

  Node* temp = list->tail;
  Node* ret = (Node*)malloc(sizeof(Node));
  ret->data = temp->data;
  ret->next = ret->prev = NULL;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  free(temp);
  list->size--;
  return ret;
}
/////////////////////////////////////////////////
Node* at(List* list, size_t ele){
  if (ele >= list->size){
    return NULL;   
  }
  Node* loop = list->head;
  size_t index = 0;
  while(index != ele){
    loop = loop->next;
    index++;
  }
  return loop;
}
////////////////////////////////////////////////
Node* search(List* list, int ele){
 Node* loop = list->head;
 while(loop){
   if (loop->data == ele)
     break;
   loop = loop->next;
 }
  return loop;
}
///////////////////////////////////////////////

