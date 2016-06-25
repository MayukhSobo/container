#include "./dll.h"
#include <stdio.h>

int main(){
  
  dList* list = NULL;
  init_d(&list);
  if (!push_back_d(list, 10))
    return -1;
  push_back_d(list, 20);
  push_back_d(list, 30);
  push_back_d(list, 40);
  printd(list, false);
  pop_back_d(list);
  printd(list, false);
  printf("%d\n", at_d(list, 1)->data);
  printf("%d\n", search_d(list, 30)->data);
  /** printf("%d\n", search(list, 70)->data); */
  return 0;
}
