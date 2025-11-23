#include <stdio.h>
#include <string.h>

typedef char TipoCadena[20];

int main() {
  TipoCadena nombre, apellido;
  typedef char TipoTexto[100];
  TipoTexto texto;
  int resul;

  printf("Nombre y Apellido? ");
  scanf("%s%s", nombre, apellido);
  printf("Datos: %s - %s \n", nombre, apellido);
  printf("Longitudes: %4d%4d\n", strlen(nombre), strlen(apellido));
  strcpy(texto, nombre);
  printf("Texto copiado: %s\n", texto);
  strcat(texto, apellido);
  printf("Texto concatenado: %s\n", texto);
  resul = strcmp(apellido, nombre);
  if (resul == 0) {
    printf("Nombre y Apellido iguales\n");
  } else if (resul > 0) {
    printf("%s es anterior a %s\n", nombre, apellido);
  }
}
