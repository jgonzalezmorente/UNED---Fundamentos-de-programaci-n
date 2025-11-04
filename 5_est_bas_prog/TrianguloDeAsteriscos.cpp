/**************************************************************************************************
* Programa: TrianguloDeAsteriscos
*
* Descripción:
*   Este programa escribe un triángulo de asteriscos.
*   La altura se lee como dato
**************************************************************************************************/

#include <stdio.h>

int main() {
  int N=1;
  while(N>0) {
    printf("Altura del triangulo? ");
    if(scanf("%d", &N) != 1){
      N=0;
    };
    for(int j=1; j<N; j++) {
      printf(" ");
    }
    if (N>=1) {
      printf("*\n");
    }
    for(int h=2; h<N; h++) {
      for(int j=1; j<=N-h; j++) {
        printf(" ");
      }
      printf("*");
      for(int j=1; j<=2*h-3; j++) {
        printf(" ");
      }
      printf("*\n");
    }
    if (N>1) {
      printf("*");
    }
    for(int j=1; j<=N-1; j++) {
      printf(" *");
    }
    printf("\n");
  }
}
