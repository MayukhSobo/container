#include "./sll.h"
#include <stdlib.h>
#include <stdio.h>

bool s_initialized = false;

void init(sList** list) {
  (*list) = (sList*)malloc(sizeof(sList));
  (*list)->size = 0;
  (*list)->head = (*list)->tail = (*list)->curr = NULL;
  s_initialized = true;
}


bool push_back(sList* list, int ele){
  
  if (s_initialized){
    if (list->size == 0 && list->head == NULL){
      // This is the first element
      list->head = (sNode*)malloc(sizeof(sNode));
      list->tail = list->curr = list->head;
      list->curr->data = ele;
      list->curr->next = NULL;
      list->size++;
    }else{
      // The list was already populated
      list->curr->next = (sNode*)malloc(sizeof(sNode));
      list->curr = list->curr->next;
      list->curr->data = ele;
      list->tail = list->curr;
      list->curr->next = NULL;
      list->size++;
    }
  }else{
    printf("The list is not properly initialized\n");
    return false;
  }
  return true;
}

void print(sList* list){
  sNode* loop = list->head;
  while(loop){
    printf("%d ", loop->data);
    loop = loop->next;
  }
  printf("\n");
}

