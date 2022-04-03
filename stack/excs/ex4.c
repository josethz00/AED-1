#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../stack_char.h"

bool is_expr_balanced(char * expr) {
  unsigned int i = 0;
  Stack * s = stack(strlen(expr));

  while (expr[i]) {
    if (expr[i] == '{' || expr[i] == '[' || expr[i] == '(') {
      push_S(expr[i], s);
    } 
    else if (expr[i] == '}' || expr[i] == ']' || expr[i] == ')') {
      if (is_empty_S(*s)) {
        return false;
      } 
      else {
        Itemp top = pop_S(s);
        if (expr[i] == '}' && top != '{') {
          return false;
        } 
        else if (expr[i] == ']' && top != '[') {
          return false;
        } 
        else if (expr[i] == ')' && top != '(') {
          return false;
        }
      }
    }
    i++;
  }

  // if there is something left in the stack, it means that there is an
  // unclosed bracket, so the expression is not balanced
  return is_empty_S(*s);
}

int main(void) {
  char expr[100];
  printf("Type an expression: ");
  fgets(expr, 100, stdin);

  if (is_expr_balanced(expr)) {
    puts("Expression is balanced");
  } 
  else {
    puts("Expression is not balanced");
  }

  return 0;
}
