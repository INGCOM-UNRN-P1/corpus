
#include <stdio.h>

int producto(int numeroN, int numeroM);
int potencia(int numeroN, int numeroM);

int main (){

int numeroN, numeroM, resultadoPro, resultadoPot;


printf("ingrese un numero ");
	scanf("%d" ,&numeroN);
printf ("ingrese otro numero ");
	scanf("%d" ,&numeroM);
	
resultadoPro=producto(numeroN, numeroM);
resultadoPot=potencia(numeroN, numeroM);
printf ("El resultado del producto es: %d " ,resultadoPro);
printf ("El resultado de la potencia es: %d " ,resultadoPot);
return 0;
}

int producto(int numeroN, int numeroM){
int resultado1, cont;
cont=0;

while (cont<numeroM){
	resultado1 = resultado1 + numeroN;
	cont++;
}
return resultado1;
}
int potencia(int numeroN, int numeroM){
int resultado2=numeroN, cont = 1;

while (cont<numeroM){
	resultado2 = resultado2*numeroN;
	cont++;
}
return resultado2;
}

	

