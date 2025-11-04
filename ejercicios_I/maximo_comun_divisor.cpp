#include <stdio.h>

int main() {
  int a;
  int b;
  int r = 1;
  printf("Primer Numero? ");
  if (scanf("%d", &a) != 1) {
    return 0;
  }
  printf("Segundo Numero? ");
  if (scanf("%d", &b) != 1) {
    return 0;
  }
  if (a<0) {
    a = (-1)*a;
  }
  if (b<0) {
    b = (-1)*b;
  }
  while (r != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  printf("El maximo comun divisior es:%5d", a);
}
