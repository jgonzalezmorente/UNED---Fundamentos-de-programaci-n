/**************************************************************************
* Programa: Contrastar
*
* Descripción:
*   Este programa convierte una imagen digitalizada a niveles de blanco
*   y negro puros
**************************************************************************/
#include <stdio.h>

const int Ancho  = 40;  /* anchura de la imagen */
const int Alto   = 20;  /* altura de la imagen */
const int Blanco = 0;   /* nivel bajo de grises = blanco */
const int Negro  = 5;   /* nivel alto de grises = negro */

typedef int Imagen_t[Alto][Ancho];

/** Leer la imagen */
void LeerImagen(Imagen_t imagen) {
  char c;
  for (int i=0; i<Alto; i++) {
    for (int j=0; j<Ancho; j++) {
      scanf(" %c", &c);
      imagen[i][j] = int(c) - int('0');
    }
  }
}

/** Contrastar la imagen */
void Contrastar(Imagen_t imagen, int nivel) {
  for(int i=0; i<Alto; i++) {
    for(int j=0; j<Ancho; j++) {
      if (imagen[i][j] <= nivel) {
        imagen[i][j] = Blanco;
      } else {
        imagen[i][j] = Negro;
      }
    }
  }
}

/** Imprimir la imagen */
void Imprimir(const Imagen_t imagen) {
  const char Punto[6] = {' ', '.', '+', 'x', '*', '#'};
  for(int i=0; i<Alto; i++) {
    for(int j=0; j<Ancho; j++) {
      printf("%c", Punto[imagen[i][j]]);
    }
    printf("\n");
  }
}

/** Programa principal */
int main() {
  Imagen_t imagen;

  LeerImagen(imagen);
  printf("Imagen inicial: \n");
  Imprimir(imagen);

  Contrastar(imagen, 3);
  printf("\nImagen contrastada: \n");
  Imprimir(imagen);
}
