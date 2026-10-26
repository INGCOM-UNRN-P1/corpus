

#include <stdio.h>

void litros_galones(){
	int seleccionador;
	float litro;
	float galon;
	
	printf("Escriba 1 si desea usar el convertidor de litros a galones\n");
	printf("Escriba 2 si desea usar el convertidor de galones a litros\n");
	scanf("%d",&seleccionador);
	
	if(seleccionador == 1){
		printf("Ingrese la cantidad de litros a convertir: ");
		scanf("%f",&litro);
		galon = litro / 3.785411784;
		printf("\n%f litros es igual a %f galones ", litro, galon);
	}else if (seleccionador == 2){
		printf("Ingrese la cantidad de galones a convertir: ");
		scanf("%f",&galon);
		litro = galon * 3.785411784;
		printf("\n%f galones es igual a %f litros ", galon, litro);
	}else{
		printf("Ese valor no es aceptable.");
	}
}

void millas_kilometros(){
	int seleccionador;
	float millas;
	float kilometros;
	
	printf("Escriba 1 si desea usar el convertidor de millas a kilometros\n");
	printf("Escriba 2 si desea usar el convertidor de kilometros a millas\n");
	scanf("%d",&seleccionador);
	
	if(seleccionador == 1){
		printf("Ingrese la cantidad de millas a convertir: ");
		scanf("%f",&millas);
		kilometros = millas * 1.609;
		printf("\n%f millas es igual a %f kilometros ", millas, kilometros);
	}else if (seleccionador == 2){
		printf("Ingrese la cantidad de kilometros a convertir: ");
		scanf("%f",&kilometros);
		millas = kilometros / 1.609;
		printf("\n%f kilometros es igual a %f millas ", kilometros, millas);
	}else{
		printf("Ese valor no es aceptable.");
	}
}

int main(){
	int seleccionador;
	
	printf("Escriba 1 si desea usar el convertidor de litros a galones y viceversa. \n");
	printf("Escriba 2 si desea usar el convertidor de millas a kilometros y viceversa. \n");
	scanf("%d",&seleccionador);
	
	if(seleccionador == 1){
		litros_galones();
	}else if (seleccionador == 2){
		millas_kilometros();
	}else{
		printf("Ese valor no es aceptable.");
	}
	return 0;
}

//precondicion: El usuario tiene la libertad de elegir que convertidor usar, luego de elegir debe escribir el numero de la medida a convertir.
//poscondicion: El programa convertira el numero escrito por el usuario y mostrara por pantalla el numero convertido a la otra unidad de medida seleccionada.
