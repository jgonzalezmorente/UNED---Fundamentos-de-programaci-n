/**********************************************************************
* Programa: Comedor
*
* Descripción:
*   Programa para realizar el ticket de pago de un comedor
***********************************************************************/
#include <stdio.h>
#include <ctype.h>

int main() {
  const float Menu = 8.5;
  const float IVAMenu = 7.0;

  typedef enum TipoMes {
    Enero, Febrero, Marzo, Abril, Mayo,
    Junio, Julio, Agosto, Septiembre,
    Octubre, Noviembre, Diciembre
  };

  TipoMes mes;
  int dias, diasPagar, diasFaltas, aux;
  float total, totalIVA;
  char tecla;

  do {
    printf("Mes? ");
    scanf("%d", &aux);
  } while((aux <1) || (aux > 12));
  mes = TipoMes(aux-1);

  switch (mes) {
    case Agosto:
      dias = 0;
      break;
    case Enero:
    case Abril:
    case Diciembre:
      dias = 17;
      break;
    case Febrero:
    case Septiembre:
      dias = 20;
      break;
    case Junio:
    case Noviembre:
      dias = 21;
      break;
    case Marzo:
    case Julio:
      dias = 22;
      break;
    case Mayo:
    case Octubre:
      dias = 23;
      break;
  }

  do {
    printf("Total de ausencias? " );
    scanf("%d", &diasFaltas);
    printf("-----------------------------------\n");
    diasPagar = dias - diasFaltas;
    total = diasPagar * Menu;
    totalIVA = total * IVAMenu / 100.0;
    printf("     RECIBO de COMEDOR\n");
    printf("Comidas   Precio      Total\n");
    printf("%4d%11.2f%13.2f\n", diasPagar, Menu, total);
    printf("         %3.1f %% IVA   %6.2f\n", IVAMenu, totalIVA);
    printf("      Total Recibo %8.2f Euros\n", total+totalIVA);
    printf("-----------------------------------\n");

    tecla = ' ';
    printf("Otro recibo?(S/N) ");
    while ((tecla != 'S') && (tecla != 'N')) {
      scanf("%c", &tecla);
      tecla = toupper(tecla);
    };
  } while(tecla != 'N');
}
