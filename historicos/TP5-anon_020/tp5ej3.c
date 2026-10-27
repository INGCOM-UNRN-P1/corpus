
#include<stdio.h>
#include<stdlib.h>
#define LIMITE_CADENA 100
#define CADENA_CORTA -1

int largo_cadena(char *cadena, int capacidad_cadena)
{
    capacidad_cadena = 0;
    if (cadena[capacidad_cadena] != 0)
    {
        while (cadena[capacidad_cadena] != 0)
        {
            capacidad_cadena++; 
        }
         return capacidad_cadena;  
    }
    else
    {
        return CADENA_CORTA;
    } 
}
char* busqueda(char *cadena, int largo, char *busqueda)
{
    int i;
    int j;
    int largopalabra = largo_cadena(busqueda, LIMITE_CADENA);
    int coinciden;
  
    for (i = 0; i < largo; i++)
	{
		coinciden = 1;
		
		for (j = 0; j < largopalabra; j++)
		{
			if (cadena[i + j] != busqueda[j])
			{
				coinciden = 0;
				break;
			}
		}
		if (coinciden == 1)
		{
			return &cadena[i];
		}
	}

	return NULL; 
}
               
int main(){
    
    char cadena[20] = "Hola Mundo!";
    char *palabra = "Mundo";
    char *resultado = busqueda(cadena, 20, palabra);
    printf("%s", resultado);
    
    return 0;
   
}
