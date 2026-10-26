/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_026
*************************/

#include <stdio.h>

int main()
{
int A;
printf("Ingrese un valor entero >100  \n");
scanf("%d", &A);

if(A % 2 ==0)
{
	printf("Es múltiplo de 2: SI \n", A, (A%2));
}
else
	printf("Es múltiplo de 2: NO \n", A, (A%2));

if(A % 3 == 0)
{
	printf("Es múltiplo de 3: SI \n", A, (A%3));
}
else
	printf("Es múltiplo de 3: NO \n", A, (A%3));

	
if(A % 4 == 0)
{
	printf("Es múltiplo de 4: SI \n", A, (A%4));
}
else
	printf("Es múltiplo de 4: NO \n", A, (A%4));


if(A % 5 == 0)
{
	printf("Es múltiplo de 5: SI \n", A, (A%5));
}
else
	printf("Es múltiplo de 5: NO \n", A, (A%5));


if(A % 6 == 0)
{
	printf("Es múltiplo de 6: SI \n", A, (A%6));
}
else
	printf("Es múltiplo de 6: NO \n", A, (A%6));
}