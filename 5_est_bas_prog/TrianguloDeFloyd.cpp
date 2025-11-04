
#include <stdio.h>

int main() {
  int N;
  int inf=1;
  int delta=1;

  printf("¿Cantidad de numeros? ");
  scanf("%d", &N);

  while(inf<=N) {
    if (inf+delta-1>N) {
      delta=N-inf+1;
    }
    for(int n=0; n<=delta-1; n++) {
      printf("%3d ", inf+n);
    }
    inf=inf+delta;
    delta++;
    printf("\n");
  }
}
