#include <stdio.h>

int main() {
  int N=1;
  int suma, producto, cociente, resto;
  while (N!=0) {
    printf("N? ");
    if ((scanf("%d", &N) != 1) || N<0){
      N=0;
    }
    for(int k=1; k<=10000; k++) {
      suma = 0;
      producto = 1;
      cociente = k;
      while (cociente > 0) {
        resto = cociente % 10;
        suma = suma + resto;
        producto = producto * resto;
        cociente = cociente / 10;
      }
      if ((N % suma == 0) && (producto != 0) && (producto % N == 0)) {
        printf("%d\n", k);
      }
    }
  }
}
