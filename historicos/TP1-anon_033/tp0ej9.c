/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    printf("Ingrese un numero n: ");
    scanf("%d",&n);
    while(n<100)
    {
        printf("El numero es menor a 100.\n");
        printf("\nIngrese un numero n: ");
        scanf("%d",&n);
	}
	return 0;
}
