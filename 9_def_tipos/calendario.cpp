/**********************************************************************
* Programa: Calendario
*
* Descripción:
*   Programa para el cálculo del día de la semana
*   que corresponde a una fecha comprendida entre:
*   01/01/1989 y 31/12/2088
***********************************************************************/
#include <stdio.h>

typedef enum TipoDia {
  Lunes, Martes, Miercoles, Jueves,
  Viernes, Sabado, Domingo
};

typedef enum TipoMes {
  Enero, Febrero, Marzo, Abril, Mayo,
  Junio, Julio, Agosto, Septiembre,
  Octubre, Noviembre, Diciembre
};

typedef struct TipoFecha {
  int dia;
  TipoMes mes;
  int anno;
};

TipoDia SumarDias(TipoDia dia, int n) {
  const int DiasSemana = 7;
  int aux;
  aux = (int(dia) + n) % DiasSemana;
  return TipoDia(aux);
}

int DiasMes(TipoMes mes) {
  if (mes == Febrero) {
    return 28;
  }
  if ((int(mes) % 2 == 0 && mes <= Julio) ||
      (int(mes) % 2 == 1 && mes > Julio)) {
    return 31;
  }
  return 30;
}

TipoDia DiaDeLaSemana(TipoFecha fecha) {
  const int OrigenA = 89;
  TipoDia TreintaUnoDiciembre88 = Sabado;
  int IncreBisis, IncreAnnos, IncreDias;
  bool bisiesto;
  TipoMes M = fecha.mes;
  int A = fecha.anno;

  IncreDias = fecha.dia;
  for (int m = 0; m < M; m++) {
    IncreDias = IncreDias + DiasMes(TipoMes(m));
  }
  bisiesto = (A % 4) == 0;
  if (A < OrigenA) {
    A = A + 100;
  }
  IncreAnnos = A - OrigenA;
  IncreBisis = IncreAnnos/4;
  IncreDias = IncreDias + IncreAnnos + IncreBisis;
  if (bisiesto && (M > Febrero)) {
    IncreDias++;
  }
  return SumarDias(TreintaUnoDiciembre88, IncreDias);
}

void EscribirDia(TipoDia S) {
  if (S == Lunes) {
    printf("Lunes");
  } else if (S == Martes) {
    printf("Martes");
  } else if (S == Miercoles) {
    printf("Miercoles");
  } else if (S == Jueves) {
    printf("Jueves");
  } else if (S == Viernes) {
    printf("Viernes");
  } else if (S == Sabado) {
    printf("Sabado");
  } else {
    printf("Domingo");
  }
}

void LeerFecha(TipoFecha & fecha) {
  int mes;
  scanf("%d/%d/%d", &fecha.dia, &mes, &fecha.anno);
  fecha.mes = TipoMes(mes - 1);
  if (fecha.anno >= 100) {
    fecha.anno = fecha.anno % 100;
  }
}

void EscribirFecha(TipoFecha fecha) {
  printf("%02d/%02d/%02d", fecha.dia, int(fecha.mes) + 1, fecha.anno);
}

int main() {
  TipoFecha fecha;
  char tecla;
  tecla = 'S';
  while(tecla != 'N') {
    printf("Dia Mes Anyo(DD/MM/AA)? ");
    LeerFecha(fecha);
    printf("Fecha: ");
    EscribirFecha(fecha);
    printf("  Dia de la semana: ");
    EscribirDia(DiaDeLaSemana(fecha));
    tecla = ' ';
    printf("\n\nOtra Fecha(S/N)? ");
    while((tecla != 'S') && (tecla != 'N')) {
      scanf("%c", &tecla);
    }
  }
}

