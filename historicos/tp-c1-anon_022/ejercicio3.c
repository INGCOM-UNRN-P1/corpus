

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int signo(int numero){
   if (numero>0){
      return 1;
   }else if(numero<0){
      return 0;
   }else{
      printf("Cero");
   }

}

int main(){
	int numero;
   int resultado; 
  	printf("Introduce un número:\n");
	scanf("%i", &numero);
   resultado = signo(numero);
}