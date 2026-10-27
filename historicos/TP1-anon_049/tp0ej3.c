
#include <stdio.h>
 
int multiplicacion(a,b);
int division(a,b);
int resto(a,b);

int main(){
	int numero1;
	int numero2;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero1);
	printf("\nIngrese otro numero: ");
	scanf("%d", &numero2);
	
	int producto= multiplicacion(numero1, numero2);
	printf("\nEl producto de %d * %d es %d", numero1, numero2, producto);
	
	int cociente = division(numero1, numero2);
	printf("\nEl cociente de %d / %d es %d", numero1, numero2, cociente);
	
	int restos = resto(numero1, numero2);
	printf("\nEl resto de %d / %d es %d", numero1, numero2, restos);
	return 0;

}
int multiplicacion(a,b){
	int multiplicar = a*b;
	
	return multiplicar;
}
int division(a,b){
	int dividir = a/b;
	
	return dividir;
}
int resto(a,b){
	int resto = a % b;
	
	return resto;
}