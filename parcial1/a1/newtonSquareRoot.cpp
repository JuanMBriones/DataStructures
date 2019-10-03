#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main (){
  float error = 0.0001;
  int i=0;  float ea=100,x=0,temp, xi=3;
  printf("#       X             XI               |Ea| \n\n\n");
  do {
    //printf("%d",i);
    //printf("%.8f",x);
    xi = x - (exp(-x) - x) / (-exp(-x) - 1);
    //printf("%.10f",xi);
    if (i==0)
      printf("------");
    else {
      ea = fabs(((xi-temp)/xi)*100);
      printf("%.7f",ea);
    }
    temp=x;
    x=xi;
    i++;
    printf("\n");
  }while(ea > error);
  printf("La raiz de la funcion es: %.10f",temp);
  return 0;
}
