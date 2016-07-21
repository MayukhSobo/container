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

int pop_back(sList* list){
  int ret;
  sNode* p = NULL;
  list->curr = list->head;
  while(list->curr->next){
    p = list->curr;
    list->curr = list->curr->next;
  }
  ret = list->curr->data;
  free(list->curr);
  list->size--;
  list->tail = list->curr = p;
  if (list->size == 0)
    list->head = NULL;
  return ret;
}

sNode* at(sList* list, size_t index){
  if (index <= (size_t)list->size){
    size_t c = 0;
    list->curr = list->head;    
    while(c != index){
      list->curr = list->curr->next;
      c++;
    }
  return list->curr;
  }
  return NULL; 
}

sNode* search(sList* list, int ele){
  list->curr = list->head;
  while(list->curr){
    if (list->curr->data == ele)
      return list->curr;
    list->curr = list->curr->next;
  }
  return NULL;
}

void print(sList* list){
  sNode* loop = list->head;
  while(loop){
    printf("%d ", loop->data);
    loop = loop->next;
  }
  printf("\n");
}

void create(sList* list, int* elems, size_t len){
  int i;
  for(i = 0; i < (int)len; i++){
   if (i == 0){
    // This is the first element 
    list->head = (sNode*)malloc(sizeof(sNode));
    list->head->data = elems[i];
    list->head->next = NULL;
    list->curr = list->tail = list->head;
    list->size++;
   }else{
     // Already entered
    list->curr->next = (sNode*)malloc(sizeof(sNode)); 
    list->curr = list->curr->next;
    list->curr->data = elems[i];
    list->curr->next = NULL;
    list->tail = list->curr;
    list->size++;
   }
  }
}

void reverse(sList* list){
 sNode* p = NULL; 
 list->curr = list->head;
 sNode* n;
 while(list->curr){
  n = list->curr->next;
  list->curr->next = p;
  p = list->curr;
  list->curr = n;
 }
 list->head = p;
}

static void _remove(sNode* node){
 if (node->next == NULL){
   free(node);
 }else{
   _remove(node->next);
   free(node);
 }
}

void purge(sList* list){
  _remove(list->head);
  list->head = NULL;
}

