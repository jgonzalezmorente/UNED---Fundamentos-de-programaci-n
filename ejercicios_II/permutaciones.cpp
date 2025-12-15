/*************************************************************************
* Programa: Permutaciones
*
* Descripción:
*   Realizar un programa que escriba todas las permutaciones posibles
*   que se pueden obtener a partir de las 4 letras: A, B,C y D
**************************************************************************/
#include <stdio.h>
#include <string.h>

const int N = 4;
typedef char Permutacion[N+1];
typedef bool Flags[N];

const Permutacion elementos = "ABCD";
Permutacion p = "";
Flags elegidos;
int total = 0;

void append_char(Permutacion p, char c) {
  int l = strlen(p);
  if (l>= N) {
    return;
  }
  p[l] = c;
  p[l+1] = '\0';
}

void remove_last_char(Permutacion p) {
  int l = strlen(p);
  if (l == 0) {
    return;
  }
  p[l-1]='\0';
}

void search() {
  if (strlen(p) == N) {
    printf("%s\n", p);
    total++;
    return;
  }
  for (int k=0; k<N; k++) {
    if (elegidos[k]) {
      continue;
    }
    append_char(p, elementos[k]);
    elegidos[k] = true;
    search();
    remove_last_char(p);
    elegidos[k] = false;
  }
}

int main() {
  for (int k=0; k<N; k++) {
    elegidos[k] = false;
  }
  search();
  printf("\nTotal: %d", total);
}
