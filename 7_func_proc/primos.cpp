/**********************************************************************
* Programa: Primos
*
* Descripción:
*   Este programa imprime una tabla de números primos
*   tabulando a cuatro columnas
***********************************************************************/
#include <stdio.h>
#include <math.h>

const int N = 100;

int columna;

bool EsPrimo(int k) {
  if (k<=1) {
    return false;
  }
  for (int d=2; d<=int(sqrt(k)); d++) {
    if ((k % d) == 0) {
      return false;
    }
  }
  return true;
}

void ImprimirTabulando(int k) {
  if (columna > 4) {
    columna = 1;
    printf("\n");
  }
  printf("%15d", k);
  columna++;
}

int main() {
  columna = 1;
  for (int k=1; k<=N; k++) {
    if (EsPrimo(k)) {
      ImprimirTabulando(k);
    }
  }
  printf("\n");
}



