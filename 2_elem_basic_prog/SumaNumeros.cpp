/** Programa. SumarNumeros */
/* Este programa calcula e imprime la suma
   de los números correlativos desde 4 hasta 45.

   El algoritmo empleado es el utilizado para
   calcular la suma de una progresión aritmética:
   Suma = (Final - Inicial + 1) * (Inicial + Final) / 2

*/

#include <stdio.h>

int main() {
  printf("La suma de los números desde 4 hasta 45\n");
  printf("es igual a: ");
  printf("%5d\n", (45 - 4 + 1) * (45 + 4) / 2);
}


