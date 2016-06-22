#include "./dll.h"
#include <stdio.h>

int main(){
  
  List* list = NULL;
  init(&list);
  if (!push_back(list, 10))
    return -1;
  push_back(list, 20);
  push_back(list, 30);
  push_back(list, 40);
  print(list, false);
  pop_back(list);
  print(list, true);

  return 0;
}
