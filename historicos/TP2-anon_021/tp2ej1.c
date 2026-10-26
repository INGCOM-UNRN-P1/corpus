/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>

unsigned raiz(unsigned num);

int main(int argc, char *argv[])
{
unsigned numero,numero2, raizresultante, ejercicio, raizresultante2;

ejercicio = 2;

while (ejercicio != 1 && ejercicio != 0){
	printf("\n ingrese 0 para ejecutar la version a y 1 para b : ");

	scanf("%d",&ejercicio);
}
if(ejercicio == 0){
	
	printf("\n ingrese un n entero para calcular su raiz : ");

	scanf("%d",&numero);

	raizresultante = raiz(numero); 

	printf("\n %d es la raiz de %d ", raizresultante, numero);
	
}
else if(ejercicio == 1){
	
	printf("\n ingrese un n entero A para calcular su raiz : ");

	scanf("%d",&numero);
	
	printf("\n ingrese un n entero B para calcular su raiz : ");

	scanf("%d",&numero2);

	raizresultante = raiz(numero); 

	raizresultante2 = raiz(numero2); 
	
	printf("\n |%d| es la raiz de |%d| y |%d| es la raiz de |%d| ", raizresultante, numero,raizresultante2, numero2);
	
}
return 0;
}

unsigned raiz(unsigned num)
{
	
unsigned contador, resultado;

contador = 0;

while (resultado != num)
{
	contador ++;
	
	resultado = contador * contador;
	
	if (resultado > num)
	{
		contador --;
		
		num = contador * contador;
		
		resultado = num;
		
	}
	
}

return contador;
}

