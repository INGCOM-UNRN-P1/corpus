
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	if(argc != 5){
		printf( "Argumentos insuficientes\n");
	}
	else{
		int numero;
		FILE *file = fopen(argv[1], "w+");
		int contador = atoi(argv[2]);
		int valor_minimo= atoi(argv[3]);
		int valor_maximo= atoi(argv[4]);
		for(int i=0; i< contador; i++){
			numero=valor_minimo+rand()%(valor_maximo+1-valor_minimo);
			fprintf(file,"%d\t",numero);
			}
		fclose(file);
	}
	return 0;	
}