#include "./generic.h"
#include <stdlib.h>
#include <stdio.h>

static bool initialized = false;

void init(List** list, types what){
 (*list) = (List*)malloc(sizeof(List)); 
 (*list)->head = (*list)->tail = (*list)->curr = NULL; 
 (*list)->size = 0;
 (*list)->aType = what;
 initialized = true;
}


bool push_back(List* list, void* ele){
  if (initialized){
   if (list->head == NULL){

     list->head = (Node*)malloc(sizeof(Node));
     list->head->data = ele;
     list->curr = list->tail = list->head;
     list->curr->next = list->curr->prev = NULL;
     list->size++;
   }
   return true;
  }
  return false;
}

void print(List* list){
  list->curr = list->head;
  while(list->curr){
    if (list->aType == CHAR)
      printf("%c ", *(char*)list->curr->data);
    else if (list->aType == INT)
      printf("%d ", *(int*)list->curr->data);
    else if (list->aType == FLOAT)
      printf("%.4f ", *(float*)list->curr->data);
    else if (list->aType == DOUBLE)
      printf("%.8lf ", *(double*)list->curr->data);
    list->curr = list->curr->next; 
  }
  printf("\n");
}
