/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
#include <math.h>
int divide_lento(int dividendo, int divisor);

int resto_lento(int dividendo, int divisor);
 
int main(int argc, char *argv[])
{

int dividendo,divisor, divicion, resto;

printf("\n Ingrese el dividendo : ");

scanf("%d",&dividendo);

printf("\n Ingrese el divisor : ");

scanf("%d",&divisor);

divicion = divide_lento(dividendo,divisor);

resto = resto_lento(dividendo,divisor);

printf("\n\n Entre %d y %d : \n  division = %d \n  resto = %d",dividendo,divisor,divicion,resto);

return 0;
}

int divide_lento(int dividendo, int divisor)
{
	
if (divisor == 0)
{
	
	printf("\n#error al dividir por 0");
	
	return 0;
	
}

int contador, negativo;

negativo = 0;

if (dividendo < 0 && divisor < 0)
{
	
	dividendo = dividendo * -1;
	
	divisor = divisor * -1;
	
}
else if (dividendo < 0 || divisor < 0)
{
	
	dividendo = abs(dividendo);
	
	divisor = abs(divisor);
	
	negativo = 1;
	
}


contador = 0;

while (dividendo > 0)
{
	
	dividendo = dividendo - divisor;
	
	contador = contador + 1;
	
}
if (dividendo != 0)
	
{
	
	contador = contador -1;
	
}

if (negativo == 1)
{
	
	contador = contador * -1;
	
}

return contador;
}

int resto_lento(int dividendo, int divisor)
{

if (divisor == 0)
{
	
	printf("\n#error al dividir por 0");
	
	return 0;
	
}

int resto, negativo;

negativo = 0;

resto = 0;

if (dividendo < 0 && divisor < 0)
{
	
	dividendo = dividendo * -1;
	
	divisor = divisor * -1;
	
}
else if (dividendo < 0 || divisor < 0)
{
	
	dividendo = abs(dividendo);
	
	divisor = abs(divisor);
	
	negativo = 1;
	
}
while (dividendo >= divisor)
{
	
	dividendo = dividendo - divisor;
	
}

if (dividendo != 0)
{

	resto = dividendo;
	
}


if (negativo == 1)
{
	
	resto = abs(resto);
	
}

return resto;

}