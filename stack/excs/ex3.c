#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"
#include "../../utils/random.h"

int main(void) {
  int n = 10;
  Stack A = stack(n * sizeof(int)); 
  Stack B = stack(n * sizeof(int));
  
  for (int i = 0; i < n; i++) {
    push_S(random_int(0, 100), &A);
  }

  while (!is_empty_S(A)) {
    int stack_a_top = pop_S(&A);
    while (!is_empty_S(B) && top(B) < stack_a_top) {
      pop_S(&B);
    }
  }

  while (!is_empty_S(A)) {
    printf("%d ", A.item[A.top]);
    pop_S(&A);
  }

  return 0;
}