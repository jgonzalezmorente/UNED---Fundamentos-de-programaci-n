#include <stdio.h>

int main() {
  float error = 0.1;
  int fact, fact_n, n;
  const float cota = 3;
  float e;
  while(error>0) {
    printf("Error? ");
    if(scanf("%f", &error) != 1){
      error=0;
    };
    if (error>0) {
      fact = 1;
      n = 1;
      e = 1.0;
      while(error * fact <= cota) {
        e = e + 1/float(fact);
        n = n+1;
        fact = fact * n;
      }
      printf("%1.16f\n\n",e);
    }
  }
}
