
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1 //codigo de error
#define MAXIMO 10
#define CAPACIDAD_MAX 20 

void reemplaza(char *caracter);
int busca_vocales(char cadena[], int capacidad);
int largo_seguro(char *str, int capacidad);

//pre: se necesita una cadena valida
//post: se espera que se imprima la cadena sin vocales

int main()
{
    char cadena[CAPACIDAD_MAX];
    int capacidad = MAXIMO;
    
    
    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, MAXIMO, stdin);
    
    busca_vocales(cadena, capacidad);
    
    printf("%s",cadena);
    
    
    
}





int largo_seguro(char *str, int capacidad)
{
	int contador = 0;
	
	while ((contador < capacidad) && (*str != '\0'))
	{
		contador++;
		str = str + 1;
	
	}
	
	if (contador == CAPACIDAD_MAX)
	{
		contador = CADENA_SIN_TERMINADOR;
	}
	
	return contador;
	
	
}




int busca_vocales(char cadena[], int capacidad)
{
    
    char cadena_vocales[11] = "AEIOUaeiou"; //son 10 caracteres
    int contador = 0;
    int largo = 0;
    int retorno = 0;
    
    largo = largo_seguro(cadena, capacidad);
    
    if (largo == CADENA_SIN_TERMINADOR)
    {
        retorno = CADENA_SIN_TERMINADOR;
    }
    else
    {
        while(contador < largo)//esto toma un caracter de la cadena
        {
            for(int i = contador + 1; i < capacidad ; i++)//Esto compara el caracter de "contador" con la cadena de las vocales.
            {
                if(cadena[contador] == cadena_vocales[i])//Si encuentra una vocal
                {
                    reemplaza(&cadena[contador]);//LLama a que reemplace
                }
            }
            contador++;
            
        }
    }
    
    return retorno;
    
  
}




void reemplaza(char *caracter)
{
    char reemplazo = 'a';
    
    printf("\n");
    printf("Ingrese un caracter para reemplazar la vocal (%c): ",*caracter);
    scanf("\n%c",&reemplazo);//guarda el nuevo caracter, el \n es por que si no toma el enter del anterior caracter.
    
    
    *caracter = reemplazo; //Guarda el nuevo caracter en el puntero.
}

