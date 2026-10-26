/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Eduardo Alfredo Aguilar - @anon_012
*************************/
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnterosPositivos();
void limpiar_pantalla();
int sumaLenta(int num1, int num2);

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	printf("***Suma Lenta de dos numeros naturales*** \n");
	int num1 = ingresoNumEnterosPositivos();
	int num2 = ingresoNumEnterosPositivos();
  int suma = sumaLenta (num1, num2);
	printf("\nEl resultado de la suma lenta entre %d y %d es: %d\n", num1, num2, suma);


}

//Funciones
int ingresoNumEnterosPositivos(){
	int num=0;
	while (num < 1){
		printf("\nIngrese un numero: ");
		fflush(stdout);
		scanf("%d", &num);
	}
}

void limpiar_pantalla(){
	#ifdef _WIN32
		system("cls");
	 #else
		system("clear");
	#endif
}

int sumaLenta(int num1, int num2){
    for (int i =0; i < num2; i++){
			num1 = num1 + 1;
      printf("\n%d + 1 = %d", num1-1, num1);
		};
		return num1;
}

int sumaLentaConNegativos(int num1, int num2){
    if (num2 < 0) {
      for (int i =1; i < (-num2); i++){
        num1 = num1 - 1;
        printf("\n%d + (-1) = %d", num1+1, num1);
      };
    }else{
			for (int i =0; i < num2; i++){
				num1 = num1 + 1;
        printf("\n%d + 1 = %d", num1-1, num1);
			};
		};
		return num1;
}
