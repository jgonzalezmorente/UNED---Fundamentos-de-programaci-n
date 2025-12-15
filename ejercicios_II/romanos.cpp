/*************************************************************************
* Programa: Números romanos
*
* Descripción:
*   Realizar un procedimiento que lea una letra, compruebe que es una de
*   las utilizadas para escribir los números romanos y devuelva su valor,
*   según la siguiente tabla:
*       I - 1   C - 100
*       V - 5   D - 500
*       X - 10  M - 1000
*       L - 50  Resto - 0
*   Utilizando el procedimiento anterior, realizar otro procedimiento que
*   lea un número romano y devuelva su valor entero correspondiente. Este
*   procedimiento tendrá en cuenta las reglas de escritura de los números
*   romanos. Finalmente, utilizando este último procedimiento realizar un
*   programa que lea dos números romanos e indique cuál de ellos es mayor.
**************************************************************************/
#include <stdio.h>
#include <string.h>

typedef char CifraRomana[10];
const int ERROR_CODE = 1;

void LeerSimbolo(char & simbolo, int & valorSimbolo) {
  do {
    scanf("%c", &simbolo);
  } while(simbolo == ' ');

  switch(simbolo) {
    case 'I':
      valorSimbolo = 1;
      break;
    case 'V':
      valorSimbolo = 5;
      break;
    case 'X':
      valorSimbolo = 10;
      break;
    case 'L':
      valorSimbolo = 50;
      break;
    case 'C':
      valorSimbolo = 100;
      break;
    case 'D':
      valorSimbolo = 500;
      break;
    case 'M':
      valorSimbolo = 1000;
      break;
    case '\n':
      simbolo = ' ';
      valorSimbolo = 0;
      break;
    default:
      simbolo = ' ';
      valorSimbolo = 0;
      throw ERROR_CODE;
  }
}

void LeerRomano(CifraRomana & cifra, int & valor) {
  char simboloActual, simboloSiguiente;
  int valorActual, valorSiguiente;
  bool haySiguiente = false;
  int idx = 0;
  valor = 0;
  strcpy(cifra, "");
  do {
      if (!haySiguiente) {
        LeerSimbolo(simboloActual, valorActual);
      } else {
        simboloActual = simboloSiguiente;
        valorActual = valorSiguiente;
      }
      LeerSimbolo(simboloSiguiente, valorSiguiente);
      haySiguiente = true;
      if ((simboloSiguiente != ' ') && (valorActual < valorSiguiente)) {
        valorActual = -valorActual;
      }
      valor = valor + valorActual;
      cifra[idx] = simboloActual;
      idx++;
  } while(simboloSiguiente != ' ');
  if (idx > 9) {
    throw ERROR_CODE;
  }
  cifra[idx] = '\0';
}

void EnteroARomano(int valor, CifraRomana & cifra) {
  typedef int VectorInt4[4];
  typedef CifraRomana CifrasRomanas[9];
  typedef CifrasRomanas OrdenesMagnitud[4];

  const OrdenesMagnitud ordenes = {
    {"M", "MM", "MMM"},
    {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
  };
  const VectorInt4 divisores = {1000, 100, 10, 1};
  int cociente, resto;
  int idx = 0;

  cociente = valor;
  strcpy(cifra, "");
  for (int i = 0; i < 4; i++) {
    resto = cociente % divisores[i];
    cociente = cociente / divisores[i];
    if (cociente > 0) {
      strcat(cifra, ordenes[i][cociente-1]);
    }
    cociente = resto;
  }
}

int main() {
  int valor1, valor2;
  CifraRomana cifra1In, cifra1Out, cifra2In, cifra2Out;
  try {
    printf("Numero romano 1: ");
    LeerRomano(cifra1In, valor1);
    EnteroARomano(valor1, cifra1Out);
    if (strcmp(cifra1In, cifra1Out) != 0) {
      throw ERROR_CODE;
    }
    printf("%s -> %d\n", cifra1In, valor1);

    printf("\nNumero romano 2: ");
    LeerRomano(cifra2In, valor2);
    EnteroARomano(valor2, cifra2Out);
    if (strcmp(cifra2In, cifra2Out) != 0) {
      throw ERROR_CODE;
    }
    printf("%s -> %d\n", cifra2In, valor2);

    if (valor1 >= valor2) {
      printf("\nEl mayor es: %s\n", cifra1In);
    } else {
      printf("\nEl mayor es: %s\n", cifra2In);
    }
  } catch(int ErrorCode) {
    printf("\n**Error: El valor introducido no representa un numero romano\n");
  }
}


