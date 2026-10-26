
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char * argv[])
{
	if(argc != 5){
		printf( "Argumentos insuficientes\n");
	}
	else{
		FILE *file = fopen(argv[1], "w+");
		int contador = atoi(argv[2]);
		int valor_i= atoi(argv[3]);
		int sumador= atoi(argv[4]);
		if(valor_i >=0){
				for(int i=0; i<= contador; i++){
					fprintf(file,"%d",valor_i);
					valor_i=valor_i + sumador;
				}
			}
		if(valor_i <0){
			for(int i=0; i<= contador; i++){
				fprintf(file,"%d",valor_i);
				valor_i=valor_i - sumador;
				}
			}
		fclose(file);
       
	}
	

	
	return 0;	
}