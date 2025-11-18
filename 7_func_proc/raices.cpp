/**********************************************************************
* Programa: Raíces
*
* Descripción:
*   Este programa calcula las raíces de una ecuación
*   de segundo grado: ax^2 + bx + c
*   mismas variables que se leen
***********************************************************************/
#include <stdio.h>
#include <math.h>

/** Función para calcular el discriminante */
float Discriminante( float a, float b, float c ) {
  return b*b - 4.0 * a * c;
}

/** Procedimiento de lectura de un coeficiente */
void LeerValor( int grado, float & valor ) {
  printf( "¿Coeficiente de grado %1d? ", grado );
  scanf( "%f", &valor );
}

/** Programa principal */
int main() {
  float valorA, valorB, valorC;   /* Coeficientes de la ecuación */
  float parteUno, parteDos;       /* Variables intermedias de cálculo */
  float valorD;                   /* Discriminante de la ecuación */

  LeerValor( 2, valorA );
  LeerValor( 1, valorB );
  LeerValor( 0, valorC );
  if (valorA == 0.0) {
    if (valorB == 0.0) {
      if (valorC == 0.0) {
        printf( "Ecuacion no valida\n" );
      } else {
        printf( "Ecuacion no imposible\n" );
      }
    } else {
      printf( "Raiz unica = %10.2f\n", -valorC/valorB );
    }
  } else {
    parteUno = -valorB/(2.0*valorA);
    valorD = Discriminante( valorA, valorB, valorC );
    if (valorD >= 0.0) {
      parteDos = sqrt(valorD)/(2.0*valorA);
      printf( "Raices reales: \n" );
      printf( "%10.2f y \n", parteUno+parteDos );
      printf( "%10.2f\n", parteUno-parteDos );
    } else {
      parteDos = sqrt(-valorD)/(2.0*valorA);
      printf( "Raices complejas: \n" );
      printf( "%10.2f + %10.2fi y \n", parteUno, parteDos );
      printf( "%10.2f - %10.2fi\n", parteUno, parteDos );
    }

  }
}

