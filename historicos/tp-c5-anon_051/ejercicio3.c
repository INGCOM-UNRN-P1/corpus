
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if(argc != 5)
    {
		printf("Ingrese el archivo, seguido la cantidad de numeros, seguido el numero de inicio y seguido la distancia entre numeros: \n");
	}
    else if((atoi (argv[2])) <= 0)
    {
        printf("Ingrese una cantidad positiva de numeros \n");
    }
	else
    {
		FILE *fichero = fopen(argv[1], "w+");
		int cantidad = atoi(argv[2]);
		int origen = atoi(argv[3]);
		int distancia = atoi(argv[4]);
        int i = 1;
        while(i <= cantidad)
        {
			fprintf(fichero,"%d \n",origen);
            origen = origen + distancia;
            i++;
        }
		fclose(fichero);
	}
	return 0;	
}