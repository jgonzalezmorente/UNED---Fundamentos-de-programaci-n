#include <stdio.h>
#include <ctype.h>

int main() {
  char letra;
  int caracteres = 0;
  int vocales = 0;
  int a = 0; int hay_a = 0;
  int e = 0; int hay_e = 0;
  int i = 0; int hay_i = 0;
  int o = 0; int hay_o = 0;
  int u = 0; int hay_u = 0;
  int letras = 0; int digitos = 0;
  printf("Introduce el texto a analizar: ");
  while(letra != '.'){
    scanf("%c", &letra);
    letra = tolower(letra);
    if (!isblank(letra)) {
      caracteres = caracteres + 1;
    }
    if (isalpha(letra)) {
      letras = letras + 1;
    }
    if (isdigit(letra)) {
      digitos = digitos + 1;
    }
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
      if (letra == 'a') {
        hay_a = 1;
        a = a + 1;
      }
      if (letra == 'e') {
        hay_e = 1;
        e = e + 1;
      }
      if (letra == 'i') {
        hay_i = 1;
        i = i + 1;
      }
      if (letra == 'o') {
        hay_o = 1;
        o = o + 1;
      }
      if (letra == 'u') {
        hay_u = 1;
        u = u + 1;
      }
    }
  }
  vocales = hay_a + hay_e + hay_i + hay_o + hay_u;
  printf("Numero total de caracteres: %d\n", caracteres);
  printf("Numero total de letras: %d\n", letras);
  printf("Numero total de vocales: %d\n", vocales);
  printf("Numero total de digitos: %d\n", digitos);
  printf("Numero total de 'a': %d\n", a);
  printf("Numero total de 'e': %d\n", e);
  printf("Numero total de 'i': %d\n", i);
  printf("Numero total de 'o': %d\n", o);
  printf("Numero total de 'u': %d\n", u);
}
