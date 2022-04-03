#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

int main(void) {
  Stack s = stack(100);
  push_S(8, &s);

  while (top_S(s) > 0) {
    push_S(top_S(s)/2, &s); // 4, 2, 1, 0
  }

  while (!is_empty_S(s)) {
    printf("%d ", pop_S(&s)); // 0, 1, 2, 4, 8
  }
  
  return 0;
}