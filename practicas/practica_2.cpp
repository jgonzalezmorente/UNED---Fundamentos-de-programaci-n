/**************************************
* NOMBRE: #Jose Antonio#
* PRIMER APELLIDO: #Gonzalez#
* SEGUNDO APELLIDO: #Morente#
* DNI: #74916323X#
* EMAIL: #jgonzalez2090@alumno.uned.es#
***************************************/

#include <stdio.h>

int lado;

void ImprimirCaracter(int k) {
  switch(k % 4) {
    case 0:
      printf("@");
      break;
    case 1:
      printf(".");
      break;
    case 2:
      printf("o");
      break;
    case 3:
      printf(".");
      break;
  }
}

void ImprimirLinea(int h) {
  for(int k=1; k<=(lado-h); k++) {
    printf(" ");
  }
  for(int k=0; k<=(h-1); k++) {
    ImprimirCaracter(k);
  }
  for(int k=1; k<=(h-1); k++) {
    ImprimirCaracter(h-1-k);
  }
  printf("\n");
}

int main() {
  printf("Lado del Rombo?");
  if((scanf("%d", &lado) != 1) || (lado <= 0) || (lado > 20)) {
    return 1;
  }
  printf("\n");
  for(int h=1; h<=lado; h++) {
    ImprimirLinea(h);
  }
  for(int h=1; h<=(lado-1); h++) {
    ImprimirLinea(lado-h);
  }
}
