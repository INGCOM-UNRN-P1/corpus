# include <stdio.h>

int main(int argc, char *argv[])
{
  int numero = 0;
  int factorial = 1;
  int i = 1;

  printf("Ingrese el numero al que desea calcularle el factorial : \n");
  scanf("%d",&numero);
  
  for (i; i <= numero ; i++)
  {
   factorial = factorial * i;
  }

  printf("El factorial de %d!= % d",numero,factorial);
  return 0;
}
