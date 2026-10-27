
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumNatural();
void limpiar_pantalla();
int es_primo(int numero);


//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	printf("***¿Es un número Primo?*** \n");
	printf("Escribir una función que indique con 1 si un numero indicado es Primo y con un 0 si no lo es.\n");
	int numero = ingresoNumNatural();
  int resultado = es_primo(numero);
  if (resultado == 1) {
    printf("El numero %d es primo\n",numero);
  }else{
    printf("El numero %d no es primo\n",numero);
  };
}

//Funciones
int ingresoNumNatural(){
	int num=0;
	while (num < 1){
		printf("\nIngrese un numero natural: ");
		fflush(stdout);
		scanf("%d", &num);
	}
  return num;
}

void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}

int es_primo(int numero){
    int cantDeDivisores = 0;
    int numAnterior = numero;
    do {
      if (numero%numAnterior==0) {
        cantDeDivisores = cantDeDivisores + 1;
      };
      numAnterior = numAnterior - 1;
    } while(cantDeDivisores < 2 || numAnterior != 0);
    if (cantDeDivisores == 2) {
      return 1;
    }else{
      return 0;
    };
}
