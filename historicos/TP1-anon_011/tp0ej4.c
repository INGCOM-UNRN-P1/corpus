/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_011
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[]){
	int multiplo;
	
	do
	{
		printf("ingrese un numero mayor a 100: ");
		scanf("%d", &multiplo);
		printf("\n");
		if (multiplo <= 100)
		{
			printf("recuerde que tiene que ser mayor a 100 \n");
		}
	}
	while(multiplo <= 100);
	
	if(multiplo % 2 == 0)
	{
		printf("es multiplo de 2: SI \n");
	}
	else
		printf("es multiplo de 2: NO \n");
	if(multiplo % 3 == 0)
	{
		printf("es multiplo de 3: SI \n");
	}
	else
		printf("es multiplo de 3: NO \n");
	if(multiplo % 4 == 0)
	{
		printf("es multiplo de 4: SI \n");
	}
	else
		printf("es multiplo de 4: NO \n");
	if(multiplo % 5 == 0)
	{
		printf("es multiplo de 5: SI \n");
	}
	else
		printf("es multiplo de 5: NO \n");
	if(multiplo % 6 == 0)
	{
		printf("es multiplo de 6: SI");
	}
	else
		printf("es multiplo de 6: NO");
	
	return 0;
}
