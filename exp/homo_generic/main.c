#include "./generic.h"

int main(){
  List* list;
  
  init(&list, CHAR);
  char value = 'A';

  /** init(&list, INT); */
  /** int value = 10; */
  
  /** init(&list, FLOAT); */
  /** float value = 10.34f; */
  
  /** init(&list, DOUBLE); */
  /** double value = 3.14563425; */
  
  
  void* data = &value;
  push_back(list, data);
  print(list);
  return 0;
}
