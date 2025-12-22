/**************************************************************************
* Programa: Mostrador2
*
* Descripción:
*   Este programa confecciona tarjetas de embarque y asigna plazas en la
*   misma fila si es posible
**************************************************************************/
#include <stdio.h>
#include <ctype.h>

const int NumFilas = 10;    /* número de filas */
const int AsientosFila = 6; /* asientos por fila */
const int Pasillo = AsientosFila / 2;

typedef enum TipoEstado {vacio, ocupado, reservado};
typedef TipoEstado TipoOcupa[AsientosFila];
typedef struct TipoFila {
  TipoOcupa asientosOcupados;
  int juntas;   /* plazas seguidas al mismo lado */
  int desde;    /* desde ésta */
  int juntasP;  /* plazas seguidas con pasillo en medio */
  int desdeP;   /* desde ésta */
};

typedef TipoFila TipoPlazas[NumFilas];

/** Mostrar ocupación del avión */
void PintarPlazas(const TipoPlazas P) {
  const char DibujoAsiento[3] = { ' ', '*', 'R' };

  printf("\n     A    B     C       D    E    F\n\n");
  for (int i = 0; i < NumFilas; i++) {
    printf("%3d", i+1);
    for (int j = 0; j < AsientosFila; j++) {
      if (j == Pasillo) {
        printf("   ");
      }
      printf("  (%c)", DibujoAsiento[P[i].asientosOcupados[j]]);
    }
    printf("\n");
  }
  printf("\n");
}

/** Imprimir una "tarjeta de embarque" */
void ImprimirTarjeta(int fila, char asiento) {
  printf(".-----------------------------.\n");
  printf("|     TARJETA DE EMBARQUE     |\n");
  printf("|    Fila: %3d", fila);
  printf("  Asiento: %3c  |\n", asiento);
  printf("-------------------------------\n");
}

/** Calcular número y posición de plazas contiguas */
void CalcularPlazasJuntas(TipoFila & fila) {
  int juntas = 0;
  int juntasP = 0;

  fila.juntas = 0;
  fila.juntasP = 0;
  for(int j=0; j < AsientosFila; j++) {
    if (j == Pasillo) {
      juntas = 0;
    }
    if (fila.asientosOcupados[j] == vacio) {
      juntas++;
      juntasP++;
      if (juntas > fila.juntas) {
        fila.juntas = juntas;
        fila.desde = j - juntas + 1;
      }
      if (juntasP > fila.juntasP) {
        fila.juntasP = juntasP;
        fila.desdeP = j - juntasP + 1;
      }
    } else {
      juntas = 0;
      juntasP = 0;
    }
  }
}

/** Reservar plazas contiguas al mismo lado de la fila */
bool MarcarPlazasJuntas(int numero, TipoFila & fila) {
  if (fila.juntas < numero) {
    return false;
  }
  for (int j = 1; j <= numero; j++) {
    fila.asientosOcupados[fila.desde + j - 1] = reservado;
  }
  return true;
}

/** Reservar plazas contiguas a uno u otro lado de la fila */
bool MarcarPlazasJuntasConPasillo(int numero, TipoFila & fila) {
  if (fila.juntasP < numero) {
    return false;
  }
  for (int j =1 ; j <= numero; j++) {
    fila.asientosOcupados[fila.desdeP + j - 1] = reservado;
  }
  return true;
}

/** Reservar plazas contiguas o no en la fila */
void MarcarPlazas(int & numero, TipoFila & fila) {
  int j = 0;
  while (numero > 0 && j < AsientosFila) {
    fila.asientosOcupados[j] = reservado;
    numero--;
  }
}

/** Buscar plazas contiguas o próximas */
bool BuscarPlazas(int nuevas, int libres, TipoPlazas plazas) {
  int fila;
  if (nuevas > libres) {
    printf("No hay plazas suficientes\n");
    return false;
  }
  /*-- Buscar plazas juntas en la misma fila --*/
  fila = 0;
  while (fila < NumFilas) {
    if (MarcarPlazasJuntas(nuevas, plazas[fila])) {
      return true;
    }
    fila++;
  }
  /*-- Buscar plazas seguidas en la misma fila --*/
  fila = 0;
  while (fila < NumFilas) {
    if (MarcarPlazasJuntasConPasillo(nuevas, plazas[fila])) {
      return true;
    }
    fila++;
  }
  /*-- Ocupar plazas de una en una desde la primera fila --*/
  fila = 0;
  while (nuevas > 0 && fila < NumFilas) {
    MarcarPlazas(nuevas, plazas[fila]);
    fila++;
  }
  return nuevas == 0;
}

/** Confirmar o liberar plazas reservadas */
void ConfirmarPlazas(bool ok, TipoPlazas plazas) {
  bool cambio;
  for (int i = 0; i < NumFilas; i++) {
    cambio = false;
    for (int j = 0; j < AsientosFila; j++) {
      if (plazas[i].asientosOcupados[j] == reservado) {
        if (ok) {
          plazas[i].asientosOcupados[j] = ocupado;
          ImprimirTarjeta(i + 1, char(int('A') +  j));
          cambio = true;
        } else {
          plazas[i].asientosOcupados[j] = vacio;
        }
      }
    }
    if (cambio) {
      CalcularPlazasJuntas(plazas[i]);
    }
  }
}

/** Programa principal */
int main() {
  TipoPlazas pasaje;
  int sitiosLibres;
  char car;
  int aux, fil, col;
  bool seguir;

  /*-- Iniciar con todo vacío --*/
  sitiosLibres = NumFilas * AsientosFila;
  for(int i = 0; i < NumFilas; i++) {
    for(int j = 0; j < AsientosFila; j++) {
      pasaje[i].asientosOcupados[j] = vacio;
    }
    CalcularPlazasJuntas(pasaje[i]);
  }

  /*-- Bucle de operaciones --*/
  seguir = true;
  while (seguir) {
    printf("Opcion (Plaza, Grupo, Estado, Fin)? ");
    scanf(" %c", &car);
    car = toupper(car);
    switch (car) {
      /*-- Asignar una plaza determinada --*/
      case 'P':
        do {
          printf("Fila (1 a 10)? ");
          scanf("%d", &aux);
        } while (aux < 1 || aux > 10);
        do {
          printf("Asiento (A a F)? ");
          scanf(" %c", &car);
          car = toupper(car);
        } while(car < 'A' || car > 'F');
        fil = aux - 1;
        col = int(car - 'A');
        if (pasaje[fil].asientosOcupados[col] == vacio) {
          pasaje[fil].asientosOcupados[col] = ocupado;
          sitiosLibres--;
          CalcularPlazasJuntas(pasaje[fil]);
          ImprimirTarjeta(fil + 1, char(int('A') + col));
        } else {
          printf("** Plaza OCUPADA\n");
        }
        break;

      /*-- Asignar automáticamente plazas contiguas --*/
      case 'G':
        do {
          printf("Numero de plazas (2 a 6)? ");
          scanf("%d", &aux);
        } while (aux < 2 || aux > 6);
        if (BuscarPlazas(aux, sitiosLibres, pasaje)) {
          PintarPlazas(pasaje);
          printf("Confirmar (S/N)? ");
          scanf(" %c", &car);
          if (toupper(car) == 'S') {
            ConfirmarPlazas(true, pasaje);
            sitiosLibres = sitiosLibres - aux;
          } else {
            ConfirmarPlazas(false, pasaje);
          }
        }
        break;
        /*-- Dibujar estado de ocupación --*/
        case 'E':
          PintarPlazas(pasaje);
          break;
        /*-- Fin del programa --*/
        case 'F':
          seguir = false;
          break;
    }
  }
}




