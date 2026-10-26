
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
		int minimo = atoi(argv[3]);
		int maximo = atoi(argv[4]);
        int i = 0;
        int aleatorio = 0;
        while (i < cantidad)
        {
			aleatorio = rand() % (maximo - minimo + 1) + minimo;
			fprintf(fichero,"%d \n", aleatorio);
            i++;
        }
		fclose(fichero);
	}
	return 0;	
}