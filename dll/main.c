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
  /** printf("%d\n", pop_back_d(list)); */
  /** printd(list, false); */
  /** printf("%d\n", at_d(list, 1)->data); */
  /** printf("%d\n", search_d(list, 30)->data); */
  /** printf("%d\n", search(list, 70)->data); */
  /** printf("%lu", list->size); */
  push_at_d(list, 100, 0);
  printd(list, false);
  pop_from_d(list, 3);
  printd(list, false);
  return 0;
}
