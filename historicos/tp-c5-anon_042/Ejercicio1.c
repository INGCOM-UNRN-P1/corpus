
#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 10

int ordenado(char numeros[], int capacidad){
	int i=1;
	int resultado;
	if(numeros[i]<numeros[i+1])
	{
		while(i<capacidad-1){
			if(numeros[i]<numeros[i+1]){
				resultado=1;
			}
			else{
				return 0;
			}
			i++;
		}
	}
	else if(numeros[i]>numeros[i+1])
	{
		while(i<capacidad-1){
			if(numeros[i]>numeros[i+1]){
				resultado=-1;
			}
			else{
				return 0;
			}
			i++;
		}
	}
	else{
		return 0;
	}
	return resultado;
}

int main(int argc, char * argv[])
{
	if(argc != 2){
		printf( "Nombre de archivo no introducido\n");
	}
	else{
		FILE *file = fopen(argv[1], "r");
		char i;
		char numeros [MAXIMO];
		int j=0;
		int capacidad=0;
        while  ((i=fgetc(file))!=EOF)
        {
			if (i>=48 && i<=57){
				numeros[j]=i;
				j++;
				capacidad++;
			}
        }
		numeros[j]= '\0';
		fclose( file );
		printf("%s \n", numeros);

		int resultado=ordenado(numeros,capacidad);
		printf("Resultado: %d\n", resultado);
	}
	return 0;	
}