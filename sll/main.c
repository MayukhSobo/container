#include "./sll.h"
#include <stdio.h>

int main(){
  sList* list;
  init(&list);
  int data[] = {1};
  create(list, data, 1);
  /** push_back(list, 10); */
  /** push_back(list, 20); */
  /** push_back(list, 30); */
  print(list);
  /** printf("%d\n", at(list, 1)->data); */
  /** printf("%d\n", search(list, 30)->data); */
  printf("%d\n", pop_back(list));  
  print(list);
  return 0;
}
