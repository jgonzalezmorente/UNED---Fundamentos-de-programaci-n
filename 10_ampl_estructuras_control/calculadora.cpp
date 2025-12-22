/**********************************************************************
* Programa: Calculadora
*
* Descripción:
*   Este programa simula una calculadora con las cuatro operaciones
*   básicas (+, -, *, /) y cuatro posiciones de memoria. Analiza
*   y evalúa las expresiones e indica los errores que contengan, si
*   los hay
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef enum TipoSimbolo {
  Numero, Memoria, Operador, Terminador, Desconocido
};

char c = ' ';
bool releer;
TipoSimbolo simbolo;
float numero;
char caracter;
bool primero;

typedef float TipoMemoria[4];
TipoMemoria memoriaABCD;

void LeerCaracter() {
  if (primero) {
    primero = false;
    releer = false;
    c = '\0';
    scanf(" %c", &c);
  } else if (releer) {
    releer = false;
    return;
  } else {
    c = '\0';
    scanf("%c", &c);
  }
  printf("%c", c);
}

void LeerSimbolo() {
  do {
    LeerCaracter();
  } while (c == ' ');
  caracter = c;
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
      simbolo = Operador;
      break;
    case 'A':
    case 'B':
    case 'C':
    case 'D':
      simbolo = Memoria;
      break;
    case ';':
    case '.':
      simbolo = Terminador;
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      simbolo = Numero;
      numero = 0.0;
      do {
        numero = numero * 10 + float(int(c) - int('0'));
        LeerCaracter();
      } while ((c >= '0') && (c <= '9'));
      releer = true;
      break;
    case '\n':
    case '\r':
      simbolo = Terminador;
      printf("\n** Error: expresion incompleta\n");
      break;
    case '\0':
      simbolo = Terminador;
      printf("\n** Error: fin de la entrada\n");
      break;
    default:
      simbolo = Desconocido;
      caracter = '\0';
      printf("\n** Error: simbolo no reconocido\n");
  }
}

void LeerOperando(float & valor, bool & error) {
  error = false;
  LeerSimbolo();
  if (simbolo == Numero) {
    valor = numero;
  } else if (simbolo == Memoria) {
    valor = memoriaABCD[int(caracter) - int('A')];
  } else {
    error = true;
    if (caracter > ' ') {
      printf("\n** Error: se necesita operando\n");
    }
  }
}

int main() {
  float operando, resultado;
  char operador;
  bool seguir, error;

  for (int k = 0; k < 4; k++) {
    memoriaABCD[k] = 0.0;
  }

  do {
    printf("Calculo: ");
    resultado = 0.0;

    primero = true;
    LeerOperando(resultado, error);

    seguir = !error;
    while(seguir) {
      LeerSimbolo();
      switch(simbolo) {
        case Operador:
          operador = caracter;
          LeerOperando(operando, error);
          if (error) {
            seguir = false;
            continue;
          }
          switch (operador) {
            case '+':
              resultado = resultado + operando;
              break;
            case '-':
              resultado = resultado - operando;
              break;
            case '*':
              resultado = resultado * operando;
              break;
            case '/':
              resultado = resultado / operando;
              break;
            default:
              if (simbolo == Memoria) {
                memoriaABCD[int(caracter) - int('A')] = resultado;
              } else {
                printf("\n** Error: Se necesita A, B, C, o D\n");
                error = true;
                seguir = false;
                continue;
              }
          }
          break;
        case Numero:
        case Memoria:
          printf("\n** Error: se necesita operador\n");
          error = true;
          break;
        default:
          seguir = false;
          error = (caracter !=  ';' && caracter != '.');
      }
      seguir = seguir && !error;
    }

    if (!error) {
      printf( "\n>> Resultado: %g\n", resultado);
    } else if (c != '\0') {
      printf("<< ");
      while (c != ';' && c != '.' && c != '\n' && c != '\0') {
        LeerCaracter();
      }
      printf("\n");
    }
    printf("\n");
  } while(c != '.' && c != '\0');
}


























