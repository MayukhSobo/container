#include "./generic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
     
     if (list->aType == CHAR){
       list->head->data = malloc(sizeof(char));
       memcpy(list->head->data, ele, sizeof(char));
     }
     else if (list->aType == INT){
       list->head->data = malloc(sizeof(int));
       memcpy(list->head->data, ele, sizeof(int));
     }
     else if (list->aType == FLOAT){
       list->head->data = malloc(sizeof(float));
       memcpy(list->head->data, ele, sizeof(float));
     }
     else if (list->aType == DOUBLE){
       list->head->data = malloc(sizeof(double));
       memcpy(list->head->data, ele, sizeof(double));
     }
      
     /** list->head->data = ele; */
     list->curr = list->tail = list->head;
     list->curr->next = list->curr->prev = NULL;
     list->size++;
   }else{
     Node* temp = list->curr;
     list->curr->next = (Node*)malloc(sizeof(Node));
     list->curr = list->curr->next;
     
     if (list->aType == CHAR){
       list->curr->data = malloc(sizeof(char));
       memcpy(list->curr->data, ele, sizeof(char));
     }
     else if (list->aType == INT){
       list->curr->data = malloc(sizeof(int));
       memcpy(list->curr->data, ele, sizeof(int));
     }
     else if (list->aType == FLOAT){
       list->curr->data = malloc(sizeof(float));
       memcpy(list->curr->data, ele, sizeof(float));
     }
     else if (list->aType == DOUBLE){
       list->curr->data = malloc(sizeof(double));
       memcpy(list->curr->data, ele, sizeof(double));
     }
     /** list->curr->data = ele; */
     list->curr->next = NULL;
     list->curr->prev = temp;
     list->tail = list->curr;
     list->size++;
   }
   return true;
  }
  return false;
}

void* pop_back(List* list){
  void* ret = NULL;
  if (list->aType == CHAR){
    ret = malloc(sizeof(char));
    memcpy(ret, list->tail->data, sizeof(char));
  }
  else if (list->aType == INT){
    ret = malloc(sizeof(int));
    memcpy(ret, list->tail->data, sizeof(int));
  }
  else if (list->aType == FLOAT){
    ret = malloc(sizeof(float));
    memcpy(ret, list->tail->data, sizeof(float));
  }
  else if (list->aType == DOUBLE){
    ret = malloc(sizeof(double));
    memcpy(ret, list->tail->data, sizeof(double));
  }
  list->curr = list->tail->prev;
  free(list->tail->data);
  free(list->tail);
  list->tail = list->curr;
  list->tail->next = NULL;
  list->size--;
  return ret;
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
