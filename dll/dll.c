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
    fprintf(stderr, "%s\n", "List is not properly initialized!!");
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
int pop_back_d(dList* list) {
  int ret;
  list->curr = list->tail->prev;
  ret = list->tail->data;
  free(list->tail);
  list->tail = list->curr;
  if (list->tail != NULL)
    list->tail->next = NULL;
  else
    list->head = list->tail;
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
bool push_at_d(dList* list, int ele, size_t index){
  if (index > list->size){
    fprintf(stderr, "%s\n", "Can not push at the mentioned index!!");
    return false;
  }
  size_t cIndex = 0;
  list->curr = list->head;
  while(cIndex != index){
   list->curr = list->curr->next;
   cIndex++;
  }
  
  dNode* middle = (dNode*)malloc(sizeof(dNode)); // creating the node to push

  // fixing the previous connection
  if (index < list->size) 
    middle->prev = list->curr->prev;
  else{
      middle->prev = list->tail;
      list->tail = middle;
  }
  
  if (list->curr != list->head) 
    middle->prev->next = middle;
  else
    list->head = middle;
  
  // fixing the next connection
  middle->next = list->curr;
  if (index < list->size) 
    middle->next->prev = middle;

  // some other stuffs
  middle->data = ele;
  list->size++;
  return true;
}
