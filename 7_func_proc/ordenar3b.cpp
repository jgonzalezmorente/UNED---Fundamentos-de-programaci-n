/**********************************************************************
* Programa: Ordenar3b
*
* Descripción:
*   Este programa ordena 3 valores
***********************************************************************/
#include <stdio.h>
#include <math.h>

/** Procedimiento para ordenar dos datos */
void OrdenarDos( float & y, float & z ) {
  float aux;
  if (y > z) {
    aux = y;
    y = z;
    z = aux;
  }
}

/** Procedimiento para leer un dato */
void LeerDato(int indice, float & dato) {
  printf( "¿Dato %1d? ", indice );
  scanf( "%f", &dato );
}

/** Programa principal */
int main() {
  float valorUno, valorDos, valorTres;    /* valores a ordenar */
  char tecla;                             /* tecla de opción */

  tecla = 'S';
  while (tecla != 'N') {
    /*-- Leer los datos --*/
    LeerDato( 1, valorUno );
    LeerDato( 2, valorDos );
    LeerDato( 3, valorTres );

    /*-- Ordenar los datos --*/
    OrdenarDos( valorUno, valorDos );
    OrdenarDos( valorUno, valorTres );
    OrdenarDos( valorDos, valorTres );

    /*-- Escribir resultados --*/ {
      printf( "\nDatos Ordenados = \n" );
      printf( "%7.2f %7.2f %7.2f\n", valorUno, valorDos, valorTres );
    }

    /*-- Comprobar si se continúa --*/
    tecla = ' ';
    printf( "\n¿Desea continuar (S/N)? ");
    while ((tecla != 'S') && (tecla != 'N')) {
      scanf( "%c", &tecla );
    }
  }
}
