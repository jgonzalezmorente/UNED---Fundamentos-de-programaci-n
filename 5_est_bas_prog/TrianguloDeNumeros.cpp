/**************************************************************************************************
* Programa: Ordenar3
*
* Descripción:
*   Este programa escribe un triángulo de dígitos.
*   La altura se lee como dato y debe ser menor de 10.
**************************************************************************************************/

#include <stdio.h>

int main() {
  const int centro = 35;
  int nivel, altura_inicial, valor_inicial;

  printf("¿Altura del triángulo? ");
  scanf("%d", &nivel);

  printf("¿Altura inicial del triángulo? ");
  scanf("%d", &altura_inicial);

  printf("¿Valor inicial? ");
  scanf("%d", &valor_inicial);

  nivel = nivel % 10;
  altura_inicial = altura_inicial % 10;
  valor_inicial = valor_inicial % 10;

  if (altura_inicial < valor_inicial) {
    valor_inicial = altura_inicial;
  }

  for(int altura = altura_inicial; altura <= nivel; altura++) {

    for(int i=1; i <= (centro - altura + valor_inicial - 1); i++) {
      printf("*");
    }

    for(int i=valor_inicial; i<=altura; i++) {
      printf( "%d", i);
    }

    for(int i=altura-1; i>=valor_inicial; i--) {
      printf( "%d", i);
    }

    printf("\n");
  }
}
