#include "./generic.h"
#include <stdio.h>

int main(){
  List* list;
  void* data;
  //////////////////////////////////////////////// 
  init(&list, CHAR);
  char value;
  /** init(&list, INT); */
  /** int value; */
  /** init(&list, FLOAT); */
  /** float value; */
  /** init(&list, DOUBLE); */
  /** double value; */
  ////////////////////////////////////////////////
  
  value = 'A';
  data = &value;
  push_back(list, data);

  value = 'B';
  data = &value;
  push_back(list, data);
  
  value = 'C';
  data = &value;
  push_back(list, data);
  
  value = 'D';
  data = &value;
  push_back(list, data);
  
  value = 'E';
  data = &value;
  push_back(list, data);

  print(list);
  printf("%c\n", *(char*)pop_back(list)); 
  print(list);
  return 0;
}
