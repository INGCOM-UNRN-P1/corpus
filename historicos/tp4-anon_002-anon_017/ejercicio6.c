
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1 //codigo de error
#define MAXIMO 10
#define CAPACIDAD_MAX 20 

int intercambia(char cadena[], int capacidad_cadena, int origen, int destino);
int largo_seguro(char cadena[], int capacidad);



int main()
{
	char cadena[CAPACIDAD_MAX];
	int capacidad = MAXIMO;
	int origen = 0;
	int destino = 0;
    
    
	printf("Ingrese una cadena de caracteres: ");
	fgets(cadena, MAXIMO, stdin);
	
	printf("Ingrese que posicion se va  a intercambiar: ");
	scanf("%d",&origen);
	
	printf("Ingrese con que posicion se va a intercambiar: ");
	scanf("%d",&destino);

	if ((origen > 0) && (destino > 0))
	{
		
		intercambia(cadena, capacidad, origen, destino);
		printf("%s",cadena);
	
	}		
   
	
	
}


/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post se espera que se devuelva la longitud de la cadena ingresada.
 */
 
int largo_seguro(char cadena[], int capacidad)
{
    int contador = 0;
    int retorno = 0;
    
    while ((cadena [contador] != '\0') && (contador < capacidad)) //mientras no encuentra el terminador, suma la cantidad de caracteres.
    {
        contador++;//cuento los caracteres.
    }
    
    if(contador >= capacidad)
    {
        retorno = CADENA_SIN_TERMINADOR;//retorna sin terminador
    }
    else
    {
        retorno = contador;//retorna el largo de la cadena
    }
    
    return retorno;
        
}




int intercambia(char cadena[], int capacidad_cadena, int origen, int destino)
{
	int largo = 0;
	int contador = 0;
	char caracter_parcial = 0;

	largo = largo_seguro(cadena, capacidad_cadena);
	
	if(largo != CADENA_SIN_TERMINADOR)
	{
		while(contador < capacidad_cadena)
		{
			if(contador == origen)
			{
				caracter_parcial = cadena[destino];
				cadena[destino] = cadena[origen];
				cadena[origen] = caracter_parcial;

			}
			contador++;
		}
	}
	
	return largo;

}
