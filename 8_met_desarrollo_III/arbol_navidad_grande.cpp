/**********************************************************************
* Programa: Arbol de Navidad grande
*
* Descripción:
*   Usa las mismas definiciones de procedimientos que el programa
*   anterior
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
  for (int k=1; k<=5; k++) {
    ImprimirRama(rama);
    rama = rama + 2;
  }

  ImprimirRectangulo(3, 5);
  ImprimirRectangulo(9, 2);
}
