/**********************************************************************
* Programa: Palíndromo
*
* Descripción:
*   Este programa comprueba si una frase es un palíndromo.
***********************************************************************/
#include <stdio.h>
#include <ctype.h>

const char Fin = '.';
const int Maximo = 100;
typedef char TipoCadena[Maximo];

void LeerTexto(TipoCadena texto) {
  int longitud = 0;
  char caracter = ' ';

  printf("Frase acabada en punto(.)?\n");
  while ((caracter != Fin) && (longitud < Maximo)) {
    scanf("%c", &caracter);
    if(((caracter>='a') && (caracter <='z')) ||
       ((caracter>='A') && (caracter <='Z')) ||
       (caracter==Fin) || (caracter=='ñ') ||
       (caracter=='Ñ')) {
      texto[longitud] = toupper(caracter);
      longitud++;
    }
  }
}

bool Simetrico(const TipoCadena Texto) {
  int i, j;
  j = 0;
  while((Texto[j] != Fin) && (j<Maximo)) {
    j++;
  }
  j--;

  i=0;
  while((i < j) && (Texto[i] == Texto[j])) {
    i++;
    j--;
  }
  return i>=j;
}

int main() {
  TipoCadena frase;
  LeerTexto(frase);
  if (Simetrico(frase)) {
    printf(" Es Palindromo\n");
  } else {
    printf(" No es Palindromo\n");
  }
}
