#include <stdio.h>
#include <stdlib.h>
#include "./stack_char.h"
#define STACK_LENGTH 513

int main(void) {
  char c[STACK_LENGTH];
  Stack * s = stack(STACK_LENGTH);

  printf("Type a chain of characters: ");
  fgets(c, STACK_LENGTH, stdin);

  for (int i = 0; c[i]; i++) {
    push_S(c[i], s);
  }

  printf("Reversed chain: ");

  while (!is_empty_S(*s)) {
    printf("%c", pop_S(s));
  }
  puts("\n");

  destroy_S(s);

  return 0;
}
