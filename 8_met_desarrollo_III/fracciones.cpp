#include <stdio.h>

int MaximoComunDivisor(int a, int b) {
  int a_pos = a;
  int b_pos = b;
  int resto;
  if (a < 0) {
    a_pos = -a;
  }
  if (b < 0) {
    b_pos = -b;
  }
  resto = a_pos % b_pos;
  while (resto != 0) {
    a_pos = b_pos;
    b_pos = resto;
    resto = a_pos % b_pos;
  }
  return b_pos;
}

int MinimoComunMultiplo(int a, int b) {
  return (a*b) / MaximoComunDivisor(a, b);
}

void ReducirFraccion(int & n, int & d) {
  int mcd = MaximoComunDivisor(n, d);
  n = n / mcd;
  d = d / mcd;
}

void SumarFracciones(int n1, int d1, int n2, int d2,
                     int & n3, int & d3) {
  n3 = d2*n1 + d1*n2;
  d3 = d1*d2;
  ReducirFraccion(n3, d3);
}

void RestarFracciones(int n1, int d1, int n2, int d2,
                     int & n3, int & d3) {
  SumarFracciones(n1, d1, -n2, d2, n3, d3);
}

void MultiplicarFracciones(int n1, int d1, int n2, int d2,
                           int & n3, int & d3) {
  n3 = n1*n2;
  d3 = d1*d2;
  ReducirFraccion(n3, d3);
}

void DividirFracciones(int n1, int d1, int n2, int d2,
                       int & n3, int & d3) {
  n3 = n1*d2;
  d3 = d1*n2;
  ReducirFraccion(n3, d3);
}

void LeerFraccion(int & n, int & d) {
  scanf("%d/%d", &n, &d);
  ReducirFraccion(n, d);
}

void EscribirFraccion(int n, int d) {
  printf("%d/%d\n", n, d);
}

int main() {
  int num = 0;
  int den = 0;
  int nn, dd;
  char operacion = ' ';

  while (operacion != 'F') {
    printf(">> ");
    scanf(" %c", &operacion);

    if (operacion == '+') {
      LeerFraccion(nn, dd);
      SumarFracciones(num, den, nn, dd, num, den);
      if (num == 0 && den == 0) {
        num = nn;
        den = dd;
      } else {
        SumarFracciones(num, den, nn, dd, num, den);
      }
    } else if (operacion == '-') {
      LeerFraccion(nn, dd);
      if (num == 0 && den == 0) {
        num = nn;
        den = dd;
      } else {
        RestarFracciones(num, den, nn, dd, num, den);
      }
    } else if (operacion == '-') {
      LeerFraccion(nn, dd);
      if (num == 0 && den == 0) {
        num = nn;
        den = dd;
      } else {
        RestarFracciones(num, den, nn, dd, num, den);
      }
    } else if (operacion == '*') {
      LeerFraccion(nn, dd);
      if (num == 0 && den == 0) {
        num = nn;
        den = dd;
      } else {
        MultiplicarFracciones(num, den, nn, dd, num, den);
      }
    } else if (operacion == '/') {
      LeerFraccion(nn, dd);
      if (num == 0 && den == 0) {
        num = nn;
        den = dd;
      } else {
        DividirFracciones(num, den, nn, dd, num, den);
      }
    } else if (operacion == 'N') {
      LeerFraccion(num, den);
    } else if (operacion == '=') {
      printf("          ");
      EscribirFraccion(num, den);
    } else if (operacion != 'F') {
      printf("Pulse +, -, *, /, N, =, o F\n");
    }
  }
}









