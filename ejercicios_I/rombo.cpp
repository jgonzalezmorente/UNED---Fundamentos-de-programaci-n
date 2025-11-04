#include <stdio.h>

int main() {
  int h=0;
  int L;
  while(h>=0) {
    printf("Lado? ");
    if(scanf("%d", &L) != 1){
      h=-1;
    };
    h=L-1;
    for(int k=0; k<=h; k++) {
      for (int j=1; j<=h-k; j++) {
        printf(" ");
      }
      if (h>=0) {
        printf("*");
      }
      for (int j=1; j<=k; j++) {
        printf(" *");
      }
      printf("\n");
    }
    for(int k=1; k<=h; k++) {
      for(int j=1; j<=k; j++) {
        printf(" ");
      }
      printf("*");
      for (int j=1; j<=h-k; j++) {
        printf(" *");
      }
      printf("\n");
    }
  }
}
