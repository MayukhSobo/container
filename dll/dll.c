#include "./dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool d_initialized = false;
/////////////////////////////////////////////
void init_d(dList** list) {
  (*list) = (dList*)malloc(sizeof(dList));
  (*list)->size = 0;
  (*list)->head = (*list)->tail = (*list)->curr = NULL;
  d_initialized = true;
}
////////////////////////////////////////////
bool push_back_d(dList* list, int ele) {
  if (d_initialized) {
    if (list->head == NULL && list->size == 0){
     list->head = (dNode*)malloc(sizeof(dNode));
     list->curr = list->tail = list->head;
     list->curr->data = ele;
     list->size++;
     list->curr->prev = list->curr->next = NULL;
    }else{
      dNode* temp = list->curr;
      list->curr->next = (dNode*)malloc(sizeof(dNode));
      list->curr = list->curr->next;
      list->curr->data = ele;
      list->tail = list->curr;
      list->size++;
      list->curr->next = NULL;
      list->curr->prev = temp;
    }
    return true;
  }else{
    printf("List is not properly d_initialized");
    return false;
  }
}
///////////////////////////////////////////////
void printd(dList* list, bool reverse) {
  if(!reverse){
    dNode* loop = list->head;
    while(loop != NULL) {
      printf("%d ", loop->data);
      loop = loop->next;
    }
  }else{
  dNode* loop = list->tail;
   while(loop != NULL){
     printf("%d ", loop->data);
     loop = loop->prev;
   } 
  }
  printf("\n");
}
/////////////////////////////////////////////////
dNode* pop_back_d(dList* list) {
  if (list->size == 0){
    return NULL;
  }

  dNode* temp = list->tail;
  dNode* ret = (dNode*)malloc(sizeof(dNode));
  ret->data = temp->data;
  ret->next = ret->prev = NULL;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  free(temp);
  list->size--;
  return ret;
}
/////////////////////////////////////////////////
dNode* at_d(dList* list, size_t ele){
  if (ele >= list->size){
    return NULL;   
  }
  dNode* loop = list->head;
  size_t index = 0;
  while(index != ele){
    loop = loop->next;
    index++;
  }
  return loop;
}
////////////////////////////////////////////////
dNode* search_d(dList* list, int ele){
 dNode* loop = list->head;
 while(loop){
   if (loop->data == ele)
     break;
   loop = loop->next;
 }
  return loop;
}
///////////////////////////////////////////////

