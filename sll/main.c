#include "./sll.h"
#include <stdio.h>

int main(){
  sList* list;
  init(&list);
  push_back(list, 10);
  push_back(list, 20);
  push_back(list, 30);
  /** print(list); */
  printf("%d\n", at(list, 1)->data);
  printf("%d\n", search(list, 30)->data);
  
  return 0;
}
