#include "./generic.h"
#include <stdio.h>

int main(){
  List* list;
  void* data;
  //////////////////////////////////////////////// 
  /** init(&list, CHAR); */
  /** char value; */
  init(&list, INT);
  int value;
  /** init(&list, FLOAT); */
  /** float value; */
  /** init(&list, DOUBLE); */
  /** double value; */
  ////////////////////////////////////////////////
  
  value = 1;
  data = &value;
  push_back(list, data);

  value = 2;
  data = &value;
  push_back(list, data);
  
  value = 3;
  data = &value;
  push_back(list, data);
  
  value = 4;
  data = &value;
  push_back(list, data);
  
  value = 5;
  data = &value;
  push_back(list, data);

  print(list);
  printf("%d\n", *(int*)pop_back(list)); 
  print(list);
  return 0;
}
