
#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones a usar
int ingresoNumEnteros(int num);
void limpiar_pantalla();

//Ejecución
int main(int argc, char *argv[]){
	limpiar_pantalla();
	int numero1 = ingresoNumEnteros(0);
}

//Funciones
int ingresoNumEnteros(int num){
	//num = 0;
	while (num <= 100){
		fflush(stdin);
		printf("\nIngrese un numero n: ");
		fflush(stdout);
		scanf("%d", &num);
		if(num < 100){
			printf("El numero es menor a 100.\n");
		}else if (num > 100){
			printf("El numero es mayor a 100.\n");
		}else if (num = 100){
			printf("El numero es igual a 100.\n");
		}else{
			printf("El valor ingresado no es un numero.\n");
		}
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
