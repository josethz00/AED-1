#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../stack_char.h"

int main(void) {
  Stack * s = stack(5);
  char chain[11];

  for (int i = 0; i < 3; i++) {
    printf("? ");
    fgets(chain, 11, stdin);
    push_S(chain, s);
  }
  while (!is_empty_S(*s)) {
    printf("%c", pop_S(s));
  }

  return 0;
}