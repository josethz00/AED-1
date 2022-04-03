#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void) {
  int n;
  Stack s = stack(8 * sizeof(int));

  printf("Enter a decimal number: ");
  scanf("%d", &n);

  do {
    push_S(n % 2, &s);
    n /= 2;
  } while (n > 0);

  printf("The binary representation of %d is: ", n);

  while (!is_empty_S(s)) {
    printf("%d", pop_S(&s));
  }
  puts("\n");

  destroy_S(&s);

  return 0;
}
