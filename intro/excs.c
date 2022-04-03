#include <stdio.h>

typedef struct {char valor[10];} Str;

int main(void) {
  Str x = { "um" };
  Str y = { "dois" };

  puts(x.valor);
  x = y;
  puts(x.valor);
  printf("%p %p", &x, &y);

  return 0;
}
