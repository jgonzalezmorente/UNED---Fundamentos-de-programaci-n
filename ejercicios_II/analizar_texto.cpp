/*************************************************************************
* Programa: Analizador de textos
*
* Descripción:
*   Realizar un programa que analice un texto terminado con un punto (.)
*   y elabore las siguientes estadísticas:
*    - Número total de palabras del texto
*    - Número de palabras que utilizan N o más vocales diferentes
*    - Número de palabras que utilizan M o más consonantes diferentes
*   Los valores de N y M se leerán como datos del programa.
**************************************************************************/
#include <stdio.h>
#include <ctype.h>

const char Fin = '.';
const int MaximoMarcador = 22;
typedef char TipoCadena[25];
typedef bool TipoMarcador[MaximoMarcador];

const TipoCadena vocales = "aeiou";
const TipoCadena consonantes = "bcdfghjklmnñpqrstvwxyz";

TipoMarcador marcadorVocales, marcadorConsonantes;
int BuscarIndice(const TipoCadena cadena, char caracter) {
  int indice = -1;
  int i = 0;
  while((cadena[i] != caracter) && (cadena[i] != '\0')) {
    i++;
  }
  if (cadena[i] == caracter) {
    indice = i;
  }
  return indice;
}

char LimpiarCaracter(char caracter) {
  char caracterLower;
  if (caracter == Fin) {
    return caracter;
  }
  caracterLower = tolower(caracter);
  if (BuscarIndice(consonantes, caracterLower) >= 0) {
    return caracterLower;
  }
  switch(caracter) {
    case 'A':
    case 'Á':
    case 'á':
      return 'a';
      break;
    case 'E':
    case 'É':
    case 'é':
      return 'e';
      break;
    case 'I':
    case 'Í':
    case 'í':
      return 'i';
      break;
    case 'O':
    case 'Ó':
    case 'ó':
      return 'o';
      break;
    case 'U':
    case 'Ú':
    case 'Ü':
    case 'ú':
    case 'ü':
      return 'u';
      break;
  }
  return caracterLower;
}

bool EsCaracterPalabra(char caracter) {
  return ((caracter == 'ñ') || (caracter == 'Ñ') || isalpha(caracter) || isdigit(caracter));
}

void inicializarMarcadores() {
  for (int i = 0; i < MaximoMarcador; i++) {
    marcadorVocales[i] = false;
    marcadorConsonantes[i] = false;
  }
}

void informarMarcador(char caracter, TipoMarcador marcador, const TipoCadena cadena) {
  int indice;
  indice = BuscarIndice(cadena, caracter);
  if (indice >= 0) {
    marcador[indice] = 1;
  }
}

int SumarMarcador(const TipoMarcador marcador) {
  int suma = 0;
  for (int i = 0; i < MaximoMarcador; i++) {
    suma = suma + int(marcador[i]);
  }
  return suma;
}

int N = 0;
int M = 0;
int palabras = 0;
int palabrasNVoc = 0;
int palabrasMCon = 0;
int contador = 0;
char c = ' ';
char cPrevio = ' ';

void AnalizarTexto() {
  int indice;
  bool esCaracterPalabra;
  char caracter = ' ';
  palabras = 0;
  palabrasNVoc = 0;
  palabrasMCon = 0;
  printf("Texto? ");
  inicializarMarcadores();
  while(caracter != Fin) {
    scanf("%c", &caracter);
    c = LimpiarCaracter(caracter);
    esCaracterPalabra = EsCaracterPalabra(c);
    if (esCaracterPalabra) {
      informarMarcador(c, marcadorVocales, vocales);
      informarMarcador(c, marcadorConsonantes, consonantes);
    }
    if (!esCaracterPalabra && EsCaracterPalabra(cPrevio)) {
      palabras++;
      if (SumarMarcador(marcadorVocales) >= N) {
        palabrasNVoc++;
      }
      if (SumarMarcador(marcadorConsonantes) >= M) {
        palabrasMCon++;
      }
      inicializarMarcadores();
    }
    cPrevio = c;
  }
}

int main() {
  printf("N o mas vocales diferentes? ");
  scanf("%d", &N);
  printf("M o mas consonantes diferentes? ");
  scanf("%d", &M);
  getchar();
  AnalizarTexto();
  printf("\nPalabras: %d", palabras);
  printf("\nPalabras con %d o mas vocales diferentes: %d", N, palabrasNVoc);
  printf("\nPalabras con %d o mas consonantes diferentes: %d", M, palabrasMCon);
}
