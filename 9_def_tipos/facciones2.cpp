/**********************************************************************
* Programa: Fracciones2
*
* Descripción:
*   Este programa es una calculadora que suma, resta, multiplica
*   y divide fracciones.
*   Solución utilizando registros y funciones.
***********************************************************************/
#include <stdio.h>

typedef struct TipoFraccion {
  int numerador;
  int denominador;
};

void ReducirFraccion(TipoFraccion & f) {
  int divisor = 2;
  while ((divisor <= f.numerador) &&
         (divisor <= f.denominador)) {
    while((f.numerador % divisor == 0) &&
          (f.denominador % divisor == 0)) {
      f.numerador = f.numerador / divisor;
      f.denominador = f.denominador / divisor;
    }
    divisor++;
  }
}

TipoFraccion SumarFracciones(TipoFraccion f1, TipoFraccion f2) {
  TipoFraccion suma;

  suma.numerador = f1.numerador * f2.denominador +
                   f2.numerador * f1.denominador;
  suma.denominador = f1.denominador * f2.denominador;

  ReducirFraccion(suma);
  return suma;
}

TipoFraccion RestarFracciones(TipoFraccion f1, TipoFraccion f2) {
  f2.numerador = - f2.numerador;
  return SumarFracciones(f1, f2);
}

TipoFraccion MultiplicarFracciones(TipoFraccion f1, TipoFraccion f2) {
  TipoFraccion producto;
  producto.numerador = f1.numerador * f2.numerador;
  producto.denominador = f1.denominador * f2.denominador;
  ReducirFraccion(producto);
  return producto;
}

TipoFraccion DividirFracciones(TipoFraccion f1, TipoFraccion f2) {
  TipoFraccion cociente;
  cociente.numerador = f1.numerador * f2.denominador;
  cociente.denominador = f1.denominador * f2.numerador;
  ReducirFraccion(cociente);
  return cociente;
}

void LeerFraccion(TipoFraccion & f) {
  scanf("%d/%d", &f.numerador, &f.denominador);
  ReducirFraccion(f);
}

void EscribirFraccion(TipoFraccion f) {
  printf("%d/%d\n", f.numerador, f.denominador);
}

int main() {
  TipoFraccion acumulador = { 0, 0 };
  TipoFraccion operando;
  char operacion = ' ';
  while (operacion != 'F') {
    printf(">> ");
    scanf(" %c", &operacion);

    if (operacion == '+') {
      LeerFraccion(operando);
      acumulador = SumarFracciones(acumulador, operando);
    } else if (operacion == '-') {
      LeerFraccion(operando);
      acumulador = RestarFracciones(acumulador, operando);
    } else if (operacion == '*') {
      LeerFraccion(operando);
      acumulador = MultiplicarFracciones(acumulador, operando);
    } else if (operacion == '/') {
      LeerFraccion(operando);
      acumulador = DividirFracciones(acumulador, operando);
    } else if (operacion == 'N') {
      LeerFraccion(acumulador);
    } else if (operacion == '=') {
      printf("          ");
      EscribirFraccion(acumulador);
    } else if (operacion != 'F') {
      printf("Pulse +, -, *, /, N, =, o F\n");
    }
  }
}


