/*************************************************************************
* Programa: Aparcamiento
*
* Descripción:
*   Realizar un programa para controlar las plazas de un aparcamiento. El
*   aparcamiento dispone de 25 plazas de dos tamaños diferentes: 15
*   pequeñas y 10 grandes con la disposición que se muestra a
*   contitypenuación:
*   G  G  G  G  G  G  G  G  G  G
*   1  2  3  4  5  6  7  8  9  10
*
*   P  P  P  P  P  P  P  P  P  P   P   P   P   P   P
*   1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
*
*   La asignación se realizará automáticamente según el tamaño del
*   vehículo que se quiere aparcar con el siguiente algoritmo:
*    - Cada vehículo solamente ocupará una plaza.
*    - Un vehículo pequeño siempre ocupará una plaza pequeña, salvo que
*      estén todas ocupadas y exista alguna grande libre.
*    - Un vehículo grando sólo puede aparcar en una plaza grande. Si todas
*      están ocupadas no podrá aparcar aunque estén todas las pequeñas
*      libres.
*    - De todas las plazas libres, siempre se ocupará primer la de número
*      menor.
*   El programa tendrá 3 opciones básicas
*    - Entrada: es necesario indicar el tamaño de coche (P/G).
*    - Salida: es necesario indicar la plaza que se deja libre.
*      Por ejemplo: P 5
*    - Situación del aparcamiento: indicando las plazas libres y
*      las ocupadas.
**************************************************************************/
#include <stdio.h>
#include <ctype.h>

typedef enum TipoMenu {
  Entrada, Salida, Estado, Terminar
};

typedef enum TipoCoche {
  P, G
};

typedef struct TipoPlaza {
  TipoCoche coche;
  int numero;
};

const int MAXIMO_G = 10;
const int MAXIMO_P = 15;

typedef bool TipoDispoG[MAXIMO_G];
typedef bool TipoDispoP[MAXIMO_P];

TipoDispoG grandes;
TipoDispoP pequenas;

TipoMenu Menu() {
  char opcion;
  printf("Elige una opcion:\n - Entrada (E)\n - Salida (S)\n - Ver estado (V)\n - Terminar (T)\n>> ");
  do {
    scanf(" %c", &opcion);
    opcion = toupper(opcion);
  } while(opcion != 'E' && opcion != 'S' && opcion != 'V' && opcion != 'T');
  switch (opcion) {
    case 'E':
      return Entrada;
      break;
    case 'S':
      return Salida;
      break;
    case 'V':
      return Estado;
      break;
    case 'T':
      return Terminar;
      break;
    default:
      return Terminar;
    }
}

void InicializarPlazas() {
  for (int i=0; i < MAXIMO_P; i++) {
    pequenas[i] = false;
  }
  for (int i=0; i < MAXIMO_G; i++) {
    grandes[i] = false;
  }
}

TipoPlaza AsignarPlaza(TipoCoche coche) {
  TipoPlaza plaza;
  plaza.coche = coche;
  if (coche == P) {
    for(int i=0; i<MAXIMO_P; i++) {
      if (!pequenas[i]) {
        plaza.numero = i+1;
        pequenas[i] = true;
        return plaza;
      }
    }
  }
  for(int i=0; i<MAXIMO_G; i++) {
    if (!grandes[i]) {
      plaza.numero = i+1;
      grandes[i] = true;
      return plaza;
    }
  }
  throw -1;
}

void DesasignarPlaza(TipoPlaza plaza) {
  int indice = plaza.numero - 1;
  switch(plaza.coche) {
    case P:
      if (plaza.numero > MAXIMO_P) {
        throw -1;
      }
      if (!pequenas[indice]) {
        throw -2;
      }
      pequenas[indice] = false;
      break;
    case G:
      if (plaza.numero > MAXIMO_G) {
        throw -1;
      }
      if (!grandes[indice]) {
        throw -2;
      }
      grandes[indice] = false;
      break;
  }
}

void RegistrarEntrada() {
  char tipo;
  TipoCoche tipoCoche;
  TipoPlaza plazaAsignada;
  printf("Tipo de coche (P/G)? ");
  do {
    scanf(" %c", &tipo);
    tipo = toupper(tipo);
  } while(tipo != 'P' && tipo != 'G');
  if (tipo == 'P') {
    tipoCoche = P;
  } else {
    tipoCoche = G;
  }
  try {
    plazaAsignada = AsignarPlaza(tipoCoche);
    printf("\nPlaza asignada:\n - Parking: %c\n - Plaza: %d\n", tipo, plazaAsignada.numero);
  } catch(int ErrorCode) {
    switch(ErrorCode) {
      case (-1):
        printf("\n**Error: No hay plazas disponibles para el tipo de coche introducido\n\n");
        break;
      default:
        printf("\n**Error: Error desconocido");
    }
  }
}

void RegistrarSalida() {
  char tipo;
  TipoPlaza plaza;
  printf("Tipo de coche (P/G)? ");
  do {
    scanf(" %c", &tipo);
    tipo = toupper(tipo);
  } while(tipo != 'P' && tipo != 'G');
  if (tipo == 'P') {
    plaza.coche = P;
  } else {
    plaza.coche = G;
  }
  printf("Numero de plaza? ");
  scanf("%d", &plaza.numero);
  try {
    DesasignarPlaza(plaza);
    printf("\nPlaza liberada:\n - Parking: %c\n - Plaza: %d\n", tipo, plaza.numero);
  } catch(int ErrorCode) {
     switch(ErrorCode) {
      case (-1):
        printf("\n**Error: Numero de plaza incorrecta\n\n");
        break;
      case (-2):
        printf("\n**Error: La plaza ya estaba libre\n\n");
        break;
      default:
        printf("\n**Error: Error desconocido");
    }
  }
}

void Pausar() {
  char continuar = ' ';
  getchar();
  printf("\nPulsa ENTER para continuar...\n");
  while(continuar != '\n') {
    scanf("%c", &continuar);
  }
}

void VerEstado() {
  int libresPequenas = 0;
  int ocupadasPequenas = 0;
  int libresGrandes = 0;
  int ocupadasGrandes = 0;

  for (int i=0; i<MAXIMO_P; i++) {
    ocupadasPequenas = ocupadasPequenas + int(pequenas[i]);
  }
  libresPequenas = MAXIMO_P - ocupadasPequenas;

  for (int i=0; i<MAXIMO_G; i++) {
    ocupadasGrandes = ocupadasGrandes + int(grandes[i]);
  }
  libresGrandes = MAXIMO_G - ocupadasGrandes;

  printf(" - Plazas ocupadas pequenas: %d", ocupadasPequenas);
  printf("\n - Plazas libres pequenas: %d", libresPequenas);
  printf("\n - Plazas ocupadas grandes: %d", ocupadasGrandes);
  printf("\n - Plazas libres grandes: %d\n", libresGrandes);
}

int main() {
  TipoMenu opcion;
  InicializarPlazas();
  do {
    opcion = Menu();
    switch (opcion) {
      case Entrada:
        RegistrarEntrada();
        break;
      case Salida:
        RegistrarSalida();
        break;
      case Estado:
        VerEstado();
        break;
      default:
        ;
    }
    Pausar();
  } while(opcion != Terminar);
}
