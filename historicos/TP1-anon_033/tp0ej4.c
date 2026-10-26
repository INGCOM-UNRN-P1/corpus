/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numeroA,cont;
    cont = 2;
    while(numeroA < 100)
    {
        printf("Ingrese un numero entero mayor a 100: ");
        scanf("%d",&numeroA);
	}
	while(cont <= 6){
		if(numeroA % cont != 0){
			printf("No es multiplo por %d.\n",cont);
			}
			else
            {
                printf("Es multiplo por %d.\n",cont);
				}
	cont = cont + 1;
	}
	return 0;
}
