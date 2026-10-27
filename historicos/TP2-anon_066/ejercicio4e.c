
#include <stdio.h>
void dibujar_linea(int numero_caracter)
{
    int i;
	int j;
    for(i=0;i<numero_caracter;i++){
			for(j=0;j<numero_caracter;j++){
				if(i==0 || i==numero_caracter-1)
				{
					printf("* ");
				}else{
					if(j==0){
						printf("*");
					}else if(j==numero_caracter-1){
						printf(" *");
					}else{
						printf("  ");
					}
					
				}			
			}
	printf("\n");
    }
}

int main(int argc, char *argv[])
{	
	int naturala;
	printf("Ingrese un numero natural: ");
	scanf("%d",&naturala);
	if(naturala>0)
	{
		dibujar_linea(naturala);	
	}else{
		printf("El numero ingresado %d no es un numero natural",naturala);
	}	
	return 0;
}
