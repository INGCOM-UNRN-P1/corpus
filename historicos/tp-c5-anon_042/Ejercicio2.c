
#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 10

void ordenar_asc(char arreglo[], int capacidad){
	int contador = 0;
	while(contador < capacidad){
		for (int i=0; i<capacidad-1; ++i){
			int guardar;
			if (arreglo[i] > arreglo[i+1]){
				guardar = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = guardar;
			}
		}
		contador = contador +1;
	}
}
void ordenar_des(char arreglo[], int capacidad){
	int contador = 0;
	while(contador < capacidad){
		for (int i=0; i<capacidad-1; ++i){
			int guardar;
			if (arreglo[i] < arreglo[i+1]){
				guardar = arreglo[i];
				arreglo[i] = arreglo[i+1];
				arreglo[i+1] = guardar;
			}
		}
		contador = contador +1;
	}
}

int main(int argc, char * argv[])
{
	FILE *destino = fopen(argv[3], "w");
	if(argc != 4){
		printf( "Argumentos insuficientes\n");
	}
	else{
		FILE *file = fopen(argv[1], "r");
		char i;
		char numeros[MAXIMO];
		int j=0;
		int capacidad=0;
        while((i=fgetc(file))!=EOF)
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


		if(argv[2][0]=='a'){
			ordenar_asc(numeros,capacidad);
		}
		else if(argv[2][0]=='d'){
			ordenar_des(numeros,capacidad);
		}
		fprintf(destino,"%s",numeros);
		fclose(destino);
	}
	

	
	return 0;	
}