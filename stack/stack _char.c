#include "./stack_char.h"

Stack * stack(int m) {
  Stack * S = (Stack*)malloc(sizeof(struct stack));
  S->max  = m;
  S->top = -1;
  S->item = (Itemp*)malloc(m*sizeof(Itemp));
  return S;
}

int is_empty_S(Stack S) {
  return (S.top == -1);
}

int is_full_S(Stack S) {
  return (S.top == S.max-1);
}

void push_S(Itemp x, Stack * S) {
  if(is_full_S(*S)) { puts("Stack full!"); abort(); }
  S->top++;
  S->item[S->top] = x;
}

Itemp pop_S(Stack * S) {
  if(is_empty_S(*S)) { puts("Stack empty!"); abort(); }
  Itemp x = S->item[S->top];
  S->top--;
  return x; 
}

Itemp top_S(Stack S) {
  if(is_empty_S(S)) { puts("Stack empty!"); abort(); }
  return S.item[S.top];
}

void destroy_S(Stack * S) {
  free(S->item);
  free(S);
  S = NULL;
}
