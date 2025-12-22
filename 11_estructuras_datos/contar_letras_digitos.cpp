/*************************************************************************
* Programa: ContarLetrasyDigitos
*
* Descripción:
*   Programaque analiza fragmentos de texto y cuenta las letras y dígitos
*   que los componen
**************************************************************************/

#include <stdio.h>
#include <ctype.h>

/** Analizar el texto */
void AnalizarTexto(const char texto[]) {
  int letras = 0;
  int digitos = 0;
  int blancos = 0;
  int posi = 0;

  while(texto[posi] != '\0') {
    if (isalpha(texto[posi])) {
      letras++;
    } else if (isdigit(texto[posi])) {
      digitos++;
    } else if (isspace(texto[posi])) {
      blancos++;
    }
    posi++;
  }

  printf("Texto: %s\n", texto);
  printf(
    "Longitud: %2d Letras: %2d Digitos: %2d Blancos: %2d\n\n",
    posi, letras, digitos, blancos
  );
}
/** Programa principal */
int main() {
  AnalizarTexto("12 de Octubre de 1492");
  AnalizarTexto("2001, una odisea del espacio");
  AnalizarTexto("");
}
