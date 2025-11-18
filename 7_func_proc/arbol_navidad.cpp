/**********************************************************************
* Programa: ArbolDeNavidad
*
* Descripción:
*   Este programa imprime la silueta de un árbol de Navidad
*   hecha con asteriscos
***********************************************************************/
#include <stdio.h>

const int centro = 20;

void ImprimirN(char c, int N) {
  for (int k=1; k<=N; k++) {
    printf("%c", c);
  }
}

void ImprimirTrapecio(int ancho, int alto, int avance) {
  int anchura;

  anchura = ancho;
  for (int k=1; k<=alto; k++) {
    ImprimirN(' ', centro - anchura/2 - 1);
    ImprimirN('*', anchura);
    printf("\n");
    anchura = anchura + 2*avance;
  }
}

void ImprimirRama(int ancho) {
  ImprimirTrapecio(ancho, 3, 1);
}

void ImprimirRectangulo(int ancho, int alto) {
  ImprimirTrapecio(ancho, alto, 0);
}

int main() {
  int rama;

  rama = 1;
  for (int k=1; k<=3; k++) {
    ImprimirRama(rama);
    rama = rama + 2;
  }

  ImprimirRectangulo(1, 3);
  ImprimirRectangulo(5, 1);
}




