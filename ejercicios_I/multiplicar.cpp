#include <stdio.h>

int main() {
  bool exit = false;
  int N=0;
  while(!exit) {
    printf("Numero? ");
    if (scanf("%d", &N) == 1) {
      printf("\n");
      printf("Tabla de multiplicar por %d\n", N);
      printf("==============================\n");
      for(int i=1; i<=10; i++) {
        printf("\t%2d x %2d = %2d\n",N, i, N*i);
      }
      printf("\n");
    } else {
      exit=true;
    }
  }
}
