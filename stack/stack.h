#include <stdlib.h>
#include <stdio.h>

typedef int Itemp;

typedef struct stack {
  int max;
  int top;
  Itemp * item;
} Stack;

Stack stack(int m);
int is_empty_S(Stack S);
int is_full_S(Stack S);
void push_S(Itemp x, Stack * S);
Itemp pop_S(Stack * S);
Itemp top_S(Stack S);
void destroy_S(Stack * Q);