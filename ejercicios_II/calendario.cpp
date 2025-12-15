/*************************************************************************
* Programa: Calendario
*
* Descripción:
*   Realizar una función que devuelva el día de la semana cuando se le
*   pasan como argumentos el día, el mes y el año de una fecha cualquiera.
*   Utilizando la función anterior escribir un programa al que se le
*   introduzcan como datos el mes y el año y devuelve como resultado la
*   hoja del calendario de dicho mes. Por ejemplo:
*
*   Mes? 1
*   Año? 2018
*
*             ENERO 2018
*   LU   MA    MI   JU   VI   SA   DO
*    1    2     3    4    5    6    7
*    8    9    10   11   12   13   14
*   15   16    17   18   19   20   21
*   22   23    24   25   26   27   28
*   29   30    31
**************************************************************************/
#include <stdio.h>
#include <string.h>

int TABcolumna, TABultima, TABancho;

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
  int anyo;
};

typedef char TipoCadena2[3];
typedef TipoCadena2 DiasCalendario[7];

const DiasCalendario diasCalendario = {"LU", "MA", "MI", "JU", "VI", "SA", "DO"};

TipoDia SumarDias(TipoDia dia, int n) {
  const int DiasSemana = 7;
  return TipoDia((int(dia) + n) %  DiasSemana);
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

bool EsBisiesto(int anyo) {
  return (anyo % 4 == 0) && ((anyo % 100 != 0) || (anyo % 400 == 0));
}

TipoDia DiaDeLaSemana(TipoFecha fecha) {
  const TipoDia FinAnyo2025 = Miercoles;
  const int AnyoInicial = 2026;
  int IncreDias;
  TipoMes M = fecha.mes;
  IncreDias = fecha.dia;
  for (int m = 0; m < M; m++) {
    IncreDias = IncreDias + DiasMes(TipoMes(m));
  }
  for (int a = AnyoInicial+1; a <= fecha.anyo; a++) {
    IncreDias++;
    if (EsBisiesto(a) && (
      (a < fecha.anyo) ||
      (a == fecha.anyo && (fecha.mes > Febrero || (fecha.mes == Febrero && fecha.dia == 29)))
    )) {
      IncreDias++;
    }
  }
  for (int a = AnyoInicial-1; a >= fecha.anyo; a--) {
    IncreDias--;
    if (EsBisiesto(a) && (
      (a > fecha.anyo) ||
      (a == fecha.anyo && (fecha.mes < Febrero || (fecha.mes == Febrero && fecha.dia < 29)))
    )) {
      IncreDias--;
    }
  }
  return SumarDias(FinAnyo2025, IncreDias);
}

void IniciarTabulacion(int columnas, int ancho) {
  TABultima  = columnas;
  TABancho   = ancho;
  TABcolumna = 1;
}

void ImprimirCadena2Tabulando(const TipoCadena2 str) {
  if (TABcolumna > TABultima) {
    printf("\n");
    TABcolumna = 1;
  }
  printf("%*s", TABancho, str);
  TABcolumna++;
}

void ImprimirTabulando(int k) {
  if (TABcolumna > TABultima) {
    printf("\n");
    TABcolumna = 1;
  }
  printf("%*d", TABancho, k);
  TABcolumna++;
}

void EscribirMesAnyo(TipoMes mes, int anyo) {
  switch (mes) {
    case Enero:
      printf("ENERO %d", anyo);
      break;
    case Febrero:
      printf("FEBRERO %d", anyo);
      break;
    case Marzo:
      printf("MARZO %d", anyo);
      break;
    case Abril:
      printf("ABRIL %d", anyo);
      break;
    case Mayo:
      printf("MAYO %d", anyo);
      break;
    case Junio:
      printf("JUNIO %d", anyo);
      break;
    case Julio:
      printf("JULIO %d", anyo);
      break;
    case Agosto:
      printf("AGOSTO %d", anyo);
      break;
    case Septiembre:
      printf("SEPTIEMBRE %d", anyo);
      break;
    case Octubre:
      printf("OCTUBRE %d", anyo);
      break;
    case Noviembre:
      printf("NOVIEMBRE %d", anyo);
      break;
    case Diciembre:
      printf("DICIEMBRE %d", anyo);
      break;
  }
}

int main() {
  int mes;
  int diasMes;
  TipoFecha primeroMes;
  primeroMes.dia = 1;
  printf("Mes? ");
  scanf("%d", &mes);
  primeroMes.mes = TipoMes(mes - 1);
  printf("Anyo? ");
  scanf("%d", &primeroMes.anyo);
  printf("\n             ");
  EscribirMesAnyo(primeroMes.mes, primeroMes.anyo);
  printf("\n");

  IniciarTabulacion(7, 5);
  for(int k=0; k<7; k++) {
    ImprimirCadena2Tabulando(diasCalendario[k]);
  }
  for(int k=1; k<int(DiaDeLaSemana(primeroMes)) + 1; k++) {
    ImprimirCadena2Tabulando(" ");
  }

  diasMes = DiasMes(primeroMes.mes);
  if (primeroMes.mes == Febrero && EsBisiesto(primeroMes.anyo)) {
    diasMes++;
  }
  for(int k=1; k<=diasMes; k++) {
    ImprimirTabulando(k);
  }
  printf("\n");
}
