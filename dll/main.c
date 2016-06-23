#include "./dll.h"
#include <stdio.h>

int main(){
  
  dList* list = NULL;
  init(&list);
  if (!push_back(list, 10))
    return -1;
  push_back(list, 20);
  push_back(list, 30);
  push_back(list, 40);
  print(list, false);
  pop_back(list);
  printf("%d\n", at(list, 1)->data);
  printf("%d\n", search(list, 30)->data);
  /** printf("%d\n", search(list, 70)->data); */
  return 0;
}
