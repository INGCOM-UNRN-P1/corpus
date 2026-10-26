/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_022 de GitHub
*************************/
#include <stdio.h>
 
int es_primo(num);
int main(int argc, char *argv[])
{ 
  int numero;
  printf("Ingrese un numero: ");
  scanf("%d", &numero);
  if (es_primo(numero)){
	  printf("El numero es primo");
  }
  else{
	  printf("Ek numero no es primo");
  }
  return 0;
	
}

int es_primo(int num){
	int i;
	for (i=2; i<num/2; i++){
		if (num%i==0){
			return 0;
		}
	return  1;
	}
}

