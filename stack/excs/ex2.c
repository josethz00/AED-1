#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stack_char.h"
#define STACK_LENGTH 513

char ** split(char * str, char delim) {
  char ** result = (char**)malloc(sizeof(char*) * (strlen(str) + 1));
  char * token = strtok(str, &delim);
  while (token != NULL) {
    result = realloc(result, sizeof(char*) * (strlen(token) + 1));
    result[strlen(token)-1] = token;
    token = strtok(NULL, &delim);
  }
  return result;
}

int main(void) {
  char c[STACK_LENGTH];
  Stack s = stack(STACK_LENGTH);

  printf("Type a chain of characters: ");
  fgets(c, STACK_LENGTH, stdin);

  char ** words = split(c, ' ');
  
  for (int i = 0; words[i]; i++) {
    push_S(c[i], &s);
  }

  printf("Reversed chain: ");

  while (!is_empty_S(s)) {
    printf("%c", pop_S(&s));
  }
  puts("\n");

  destroy_S(&s);

  return 0;
}