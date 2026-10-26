/******************
UNRN- Programacion I
Ing. en Computacion
Prof: Martín Rene Vilugron
florenciadevalucero
******************/
#include<stdio.h>
int potencia(n,m);
int producto(n,m);


int main(){
	int numero1, numero2, multiplicacion, potenciacion;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero1);
	printf("\nIngrese otro numero: ");
	scanf("%d", &numero2);
	
	multiplicacion = producto(numero1, numero2);
	potenciacion = potencia(numero1, numero2);
	
	printf("\nEl producto de %d x %d es = %d", numero1, numero2, multiplicacion);
	printf("\nLa potencia %d de %d es = %d", numero2, numero1, potenciacion);
	
	return 0;
}
int potencia(n,m){
	int sacar_potencia, i;
	
	for(i=0; i<= m; i++){
		sacar_potencia = n *n;
	}
	return sacar_potencia;	
}
int producto(n,m){
	int calcular_producto, i;
	
	for(i=0; i<=m; i++){
		calcular_producto = n + n;
	}
	return calcular_producto; 
}
