/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#include <stdio.h>
 
int esPrimo(int numero);
int main(int argc, char *argv[]){
  int numero;
  printf("Ingrese un numero: ");
  scanf("%d", &numero);
  if (esPrimo(numero)) {
    printf("1");
  } else {
    printf("0");
  }
  return 0;
}

int esPrimo(int numero){
  if (numero == 0 || numero == 1) return 0;
  if (numero == 4) return 0;
  for (int x = 2; x < numero / 2; x++){
    if (numero % x == 0) return 0;
  }
  return 1;
}