/**************************************************************************************************
* Programa: Arbol
*
* Descripción:
*   Este programa imprime la silueta de un árbol de navidad, hecha con asteriscos.
**************************************************************************************************/

#include <stdio.h>

int main() {
  /*-- Imprimir copa --*/  {
    /*-- Imprimir primeras ramas --*/ {
      printf("    *\n");
      printf("   ***\n");
      printf("  *****\n");
    }
    /*-- Imprimir segundas ramas --*/ {
      printf("   ***\n");
      printf("  *****\n");
      printf(" *******\n");
    }
    /*-- Imprimir terceras ramas --*/ {
      printf("  *****\n");
      printf(" *******\n");
      printf("*********\n");
    }
  }
  /*-- Imprimir tronco --*/ {
    printf("    *\n");
    printf("    *\n");
    printf("    *\n");
  }
  /* Imprimir base --*/ {
    printf("  *****\n");
  }
}
