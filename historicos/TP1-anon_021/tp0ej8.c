/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])  
{

unsigned long long numero1, numero2, resultado;

int cantidad;

printf("\n Ingrese un valor mayor a 100: ");

scanf("%d",&cantidad);

while(cantidad < 100)
{
	printf("\n\n %d NO es mayor a 100, reintente :");
	
	scanf("%d",&cantidad);
}

numero1 = 0;

numero2 = 1;

printf("\n\n La sucecion de fibonacci hasta el %d es asi : ",cantidad);

while (numero1 < cantidad)
{
	
	printf("\n  |%llu|",numero1);
	
	resultado = numero1 + numero2;
	
	numero1 = numero2;
	
	numero2 = resultado;
	
}

printf("\n");

return 0;

}
