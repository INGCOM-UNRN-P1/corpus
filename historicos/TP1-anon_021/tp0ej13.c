/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
 
int es_primo(int numero);
 
int main(int argc, char *argv[])
{

int numero,primo;

printf("\n Ingrese un numero entero : ");

scanf("%d",&numero);

primo = es_primo(numero);

if (primo == 1)
{
	
	printf("\n El numero |%d| es primo \n",numero);
	
}
else
{
	
	printf("\n El numero |%d| NO es primo \n",numero);
	
}

return 0;
}

int es_primo(int numero)
{

int clon, resta, restos,primo;

if (numero < 0)
{
	
	numero = numero * -1;
	
}

resta = 1;

clon = numero;

restos = 0;

while (resta <= numero)
{
	
	while (clon > 0)
	{
		
		clon = clon - resta;
		
	}
	
	if (clon == 0)
	{
		
		restos = restos + 1;
		
	}
	clon = numero;
	resta = resta + 1;

}

if (restos == 2)
{
	
	primo = 1;

	
}
else if (restos > 2)
{
	
	primo = 0;
	
}

return primo;
}
