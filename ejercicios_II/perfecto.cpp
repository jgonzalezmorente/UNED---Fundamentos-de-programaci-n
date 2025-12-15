/**********************************************************************
* Programa: Ejercicio números perfectos
*
* Descripción:
*   Realizar una función que devuelva un valor booleano cierto o falso
*   si el número que se le pasa como argumento es "perfecto". Para que
*   un número sea "perfecto" es necesario que su valor sea igual a la
*   suma de todos sus divisores incluyendo al 1 y sin incluir a él
*   mismo. Por ejemplo, los divisores de 6 son el 1, el 2 y el 3; su
*   suma es igual a 6, luego el número 6 es "perfecto". Utilizando la
*   función anterior realizar un programa que escriba la lista de
*   números "perfectos" hasta uno dado, introducido como dato al
*   programa.
***********************************************************************/
#include <stdio.h>
#include <math.h>

int TABcolumna;
int TABultima;
int TABancho;

void IniciarTabulacion(int columnas, int ancho) {
  TABultima  = columnas;
  TABancho   = ancho;
  TABcolumna = 1;
}

void ImprimirTabulando(int k) {
  if (TABcolumna > TABultima) {
    TABcolumna = 1;
    printf("\n");
  }
  printf("%*d", TABancho, k);
  TABcolumna++;
}

bool EsPerfecto(int numero) {
  int suma = 0;
  int otro;
  if (numero < 0) {
    numero = -numero;
  }
  for (int k=1; k<=int(sqrt(numero)); k++) {
    if (numero % k == 0) {
      suma = suma + k;
      otro = numero/k;
      if (otro != k && otro != numero) {
        suma = suma + otro;
      }
    }
  }
  return numero == suma;
}


int main() {
  int hasta, result;
  printf("Hasta que numero? ");
  do {
    result = scanf("%d", &hasta);
    if (result == 0) {
      while(getchar() != '\n'){};
    }
  } while(result == 0 || hasta <= 0);

  IniciarTabulacion(7, 11);

  printf("\nNumeros perfectos hasta el %d:\n", hasta);

  for (int k=1; k<=hasta; k++) {
    if (EsPerfecto(k)) {
      ImprimirTabulando(k);
    }
  }
}
