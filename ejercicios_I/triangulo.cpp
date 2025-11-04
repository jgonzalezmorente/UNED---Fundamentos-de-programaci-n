#include <stdio.h>

int main() {
  float a, b, c;
  printf("Longitud del lado a? ");
  if((scanf("%f", &a) != 1)){
    a=0;
  }
  printf("Longitud del lado b? ");
  if(scanf("%f", &b) != 1){
    b=0;
  };
  printf("Longitud del lado c? ");
  if(scanf("%f", &c) != 1){
    c=0;
  }
  if (
    (a>0 && b>0 && c>0) &&
    (a < b + c) &&
    (b < a + c) &&
    (c < a + b)
  ) {
    if ((a==b) && (b==c)) {
      printf("Triangulo equilatero");
    } else if (
      (a*a + b*b == c*c) ||
      (a*a + c*c == b*b) ||
      (b*b + c*c == a*a)
    ) {
      printf("Triangulo rectangulo");
    } else if ((a==b) || (a==c) || (b==c)) {
      printf("Triangulo isoceles");
    } else {
      printf("Triangulo escaleno");
    }
  } else {
    printf("No forman triangulo");
  }
}
