

#include <stdio.h>



int main()
{
  int a, b, fact = 1;

  printf("Ingrese el valor n: \n");
  scanf("%d", &a);

  for (b = a; b > 1; b--){
    fact = fact * b;
}
  printf("El factorial de %d! = %d\n", a, fact);

  return 0;
}