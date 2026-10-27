
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int numero;
	int auxiliar_numero; 
	int valorabuscar;
	valorabuscar=100;
	while(1)
	{	printf("Ingrese un numero n : ");
		scanf("%d", &numero);
		auxiliar_numero=numero;
		if(auxiliar_numero>valorabuscar)
		{
			printf("El numero es mayor a %d.\n\n",valorabuscar);
			break;
		}else if(auxiliar_numero==valorabuscar)
		{
			printf("El numero es igual a %d.\n\n",valorabuscar);
			continue;
		}else{
			printf("El numero es menor a %d.\n\n",valorabuscar);
			continue;
		}
	}
	return 0;
}
