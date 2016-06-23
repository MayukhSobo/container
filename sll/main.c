#include "./sll.h"

int main(){
  sList* list;
  init(&list);
  push_back(list, 10);
  push_back(list, 20);
  push_back(list, 30);
  print(list);
  return 0;
}
