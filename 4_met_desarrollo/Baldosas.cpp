/**************************************************************************************************
* Programa: Baldosas
*
* Descripción:
*   Este programa calcula el costo total de las baldosas necesarias para cubrir una habitación
*   rectangular.
**************************************************************************************************/

#include <stdio.h>
int main() {
  int largo, ancho; /* Dimensiones de la habitación en m */
  int lado;         /* Lado de la baldosa en cm */
  int nLargo;       /* Número de baldosas a lo largo */
  int nAncho;       /* Número de baldosas a lo ancho */
  int baldosas;     /* Número total de baldosas */
  float precio;     /* Precio de cada baldosa ^*/
  float coste;      /* Coste total */

  /*-- Leer los datos --*/ {
    printf("Dar el tamaño de la habitación, en m\n");
    printf("¿Largo, ancho? ");
    scanf("%d, %d", &largo, &ancho);

    printf("¿Lado de la baldosa, en cm? ");
    scanf("%d", &lado);

    printf("¿Precio de cada baldosa, en euros? ");
    scanf("%f", &precio);
  }

  /*-- Calcular el número de baldosas --*/ {
    /*-- Calcular el número de baldosas a lo largo, por exceso --*/ {
      nLargo = (largo * 100 + lado - 1) / lado;
    }
    /*-- Calcular el número de baldosas a lo ancho, por exceso --*/ {
      nAncho = (ancho * 100 + lado - 1) / lado;
    }
    /*-- Calcular el número de baldosas --*/ {
      baldosas = nLargo * nAncho;
    }
  }
  /*-- Calcular el coste baldosas --*/ {
    coste = baldosas * precio;
  }
  /*-- Imprimir el resultado --*/ {
    printf("Total %5d baldosas\n", baldosas);
    printf("Coste %8.2f euros\n", coste);
  }
}



