
#include <stdio.h>
#define MAXIMO 10
#define MAXIMO_DOBLE (MAXIMO * 2)
#define ERROR_DE_CARGA -1


void elimina_duplicados(int *capacidad, int arreglo[]);
int cargar_arreglo(int capacidad, int arreglo[]);
void muestra_arreglo(int capacidad, int arreglo[]);


int main()
{
	int arreglo[MAXIMO]= {10, 4, 10, 3};
	int capacidad = 0;
	int largo = 0;
	
	printf("Ingrese la capacidad del arrelgo (no mas de 10): ");
	scanf("%d",&capacidad);
	

	cargar_arreglo(capacidad, arreglo);
    
	elimina_duplicados(&capacidad, arreglo);
    muestra_arreglo(capacidad, arreglo);
	
    printf("El largo del arreglo sin duplicados es: %d",capacidad);
	
}





int cargar_arreglo(int capacidad, int arreglo[])
{
    int contador = 0;
    
    if((capacidad > MAXIMO_DOBLE ) || (capacidad < 1))
    {
        return ERROR_DE_CARGA;
    }
    else
    {
        while(contador < capacidad)
        {
        printf("Ingrese un numero para la posicion '%d': ",contador);
        scanf("%d",&arreglo[contador]);//Guardo el valor ingresado en la posicion de contador
        contador++;//Incremento la posicion en 1
        } 
    }   
}




void muestra_arreglo(int capacidad, int arreglo[])
{
    int posicion = 0;
    
    while(posicion < capacidad)
    {
        printf("El numero en la posicion '%d' es: %d\n",posicion,arreglo[posicion]);//Muestro el valor de la "posicion" en el arreglo
        posicion++;//Incremento la posicion en 1
    }
}





void elimina_duplicados(int *capacidad, int arreglo[])
{
	int contador = 0;
    int recorre = 0;//
    
	
    while(contador < *capacidad)//Esto agarra un elemento del arreglo
    {
        for(int i = contador + 1 ; i < *capacidad; i++)//Esto ve los otros elementos de un arreglo, excepto el que esta en "contador", por eso i = contador + 1
        {
            if(arreglo[contador] == arreglo[i])//Si hay igualdad
            {
                    recorre = i;
                    while(recorre < *capacidad)//Esto es para que vaya moviendo todos los numeros del arreglo hasta donde esta el repetido, para "reemplzarlo" y depues restar el largo.
                    {
                        arreglo[i] = arreglo[i + 1];//Compara con la posicion siguient de i.
                        recorre++;
                        
                    }
                    *capacidad = *capacidad - 1;//esto va borrando las posiciones sobrantes
                    

            }
        }
        contador++;
    
    }
    

}