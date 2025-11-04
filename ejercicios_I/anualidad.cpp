#include <stdio.h>

int main() {
  float C, i, a, factor, B, interes, amortiz;
  int A;
  printf("Capital? ");
  scanf("%f", &C);
  printf("Interes? ");
  scanf("%f", &i);
  printf("Anyos? ");
  scanf("%d", &A);
  i = i/100;
  factor = i+1;
  for (int k=1; k<A; k++) {
    factor = factor * (i+1);
  }
  a = (i*C*factor)/(factor - 1);
  printf("\nAnualidad: %1.2f\n\n", a);
  printf("Anyo\tIntereses\tAmortizacion\n");
  for (int k=1; k<=A; k++) {
    printf(" %d\t", k);
    factor = 1;
    for (int j=1; j<k; j++) {
      factor = factor * (i+1);
    }
    B=C*factor - a*(factor - 1)/i;
    interes = i*B;
    amortiz = a - interes;
    printf("%1.2f\t", interes);
    printf("%1.2f\n", amortiz);
  }
}
