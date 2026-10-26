/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
void dibujar_triangulo(int altura)
{
    int i;
	int j;
	int base;
	int base2;
    base=0;
    base = 3*altura -(altura-1);
    base2= base/2;
    for(i=0;i<=altura;i++){
        for(j=0;j<base;j++){
            if(j<base2-i || j>base2+i)
            {
                printf("  ");
            }else{
                printf("* ");
            }			
        }
	printf("\n");
    }

}
int main(int argc, char *argv[])
{	
	int altura;
	printf("Ingrese un numero natural: ");
	scanf("%d",&altura);
	
	if(altura>0)
	{
		dibujar_triangulo(altura);
	}else{
		printf("El numero ingresado %d no es un numero natural",altura);
	}	
	return 0;
}
