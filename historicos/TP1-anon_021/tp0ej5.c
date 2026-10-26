/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{

int numero1,numero2,numerochico,numerogrande;

printf("ingrese un n entero:\n");

scanf("%d",&numero1);

printf("\n\ningrese un segundo numero");

scanf("%d",&numero2);

if (numero1 > numero2)
{
	
	numerogrande = numero1;
	
	numerochico = numero2;
	
}
else if (numero1 == numero2)
{
	
	numerochico = numero1;
	
	numerogrande = numero2;
	
}
else 
{
	
	numerochico = numero1;
	
	numerogrande = numero2;
	
}

while (numerochico <= numerogrande)
{
	
	printf("\n  |%d|",numerochico);
	
	numerochico = numerochico + 1;
	
}

return 0;
}
