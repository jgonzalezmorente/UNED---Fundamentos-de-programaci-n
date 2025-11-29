/**********************************************************************
* Programa: Mostrador
*
* Descripción:
*   Este programa confecciona tarjetas de embarque
*   y asigna plazas en la misma fila si es posible
***********************************************************************/
#include <stdio.h>

const int Aforo = 60;
const int AsientosFila = 6;

const int Filas = Aforo / AsientosFila;
const int Pasillo = AsientosFila / 2;

typedef int Plazas[Filas];

/** Mostrar ocupación del avión */
void PintarPlazas(const Plazas P) {
  for (int i = 0; i < Filas; i++) {
    for (int j = AsientosFila; j >= 1; j--) {
      if (j == Pasillo) {
        printf("  ");
      }
      if (j > P[i]) {
        printf(" (*)");
      } else {
        printf(" ( )");
      }
    }
    printf("\n");
  }
}

/** Imprimir una "tarjeta de embarque" */
void ImprimirTarjeta(int fila, int asiento) {
  printf(".-----------------------------.\n");
  printf("|     TARJETA DE EMBARQUE     |\n");
  printf("|    Fila: %3d", fila);
  printf("  Asiento: %3d  |\n", asiento);
  printf("-------------------------------\n");
}

/** Buscar plazas libres contiguas */
void BuscarPlazas(int nuevas, int & libres, Plazas sitios) {
  int ind, nue, dispo, aux;

  if (nuevas <= libres) {
    ind = 0;
    nue = nuevas;
    while ((ind < Filas) && (nue > 0)) {
      dispo = sitios[ind];
      if (nue <= dispo) {
        aux = AsientosFila - dispo;
        for (int i = 1; i <= nue; i++) {
          ImprimirTarjeta(ind+1, aux+i);
        }
        sitios[ind] = sitios[ind] - nue;
        libres = libres - nue;
        nue = 0;
      }
      ind++;
    }
    ind = 0;
    while (nue > 0) {
      dispo = sitios[ind];
      if (dispo > 0) {
        aux = AsientosFila - dispo;
        for (int i = 1; i <= dispo; i++) {
          ImprimirTarjeta(ind+1, aux+i);
        }
        sitios[ind] = sitios[ind] - dispo;
        nue = nue - dispo;
        libres = libres - dispo;
      }
      ind++;
    }
  } else {
    printf("No hay plazas suficientes\n");
  }
}

/** Programa principal */
int main() {
  Plazas pasaje;
  int sitiosLibres = Aforo;
  char tecla;
  int aux;

  for (int i = 0; i < Filas; i++) {
    pasaje[i] = AsientosFila;
  }

  do {
    printf("\nOpcion (Tarjetas, Pasaje, Fin)? ");
    scanf(" %c", &tecla);
    switch (tecla) {
      case 'T':
        do {
          printf("Numero de plazas (1 a 6)? ");
          scanf("%d", &aux);
        } while(aux < 1 || aux > 6);
        BuscarPlazas(aux, sitiosLibres, pasaje);
        break;
      case 'P':
        PintarPlazas(pasaje);
        break;
      default:
        ;
    }
  }
  while (tecla != 'F');
}









