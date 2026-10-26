
#include <stdio.h>
#include "largo_seguro.c"
#define MAXIMO 10
#define MAXIMA_CAPACIDAD (MAXIMO*2)
#define TRUE 1
#define FALSE 0


int es_palindromo(char cadena[], int largo);


int main()
{
    char cadena[MAXIMO];
    int capacidad = MAXIMA_CAPACIDAD;
    int largo = 0;
    int palindromo = 0;
    
    
    printf("Ingrese una cadena de caracteres: ");
    scanf("%s",&cadena);
    
    
    largo = largo_seguro(cadena, capacidad);
    
    if(largo > 1)
    {
        largo = largo - 1;//Esto es por que si no empezaria a contar desde el terminador en el palindromo.
        
        palindromo = es_palindromo(cadena, largo); 
        
        if(palindromo == TRUE)
        {
            printf("%s es palindromo!",cadena);
        }
        else
        {
            printf("%s no es palindromo!",cadena);
        }
    
        
    }
    else
    {
        printf("Error, cadena muy corta o sin terminador.");
    }
    
    

   
    
}

/**
 * La funcion verifica si una cadena de caracteres es palindromo o no de forma recursiva, comparando caracter a caracter.
 *  @param cadena es la cadena que se va a verificar
 *  @pre tiene que ser una cadena valida.
 *  @param largo es el largo de la cadena, sin contar el terminador ya que si no lo compararia con el primer caracter.
 *  @pre tiene que ser un numero entero positivo mayor a 1
 *  @returns retorna 1(TRUE) si es palindromo o 0(FALSE) si no lo es 
 *  @post se espera que verifique si una cadena es palindromo o no.
 */


int es_palindromo(char cadena[], int largo)
{

    int retorno = TRUE;
    
    if(largo < 1)//Si el largo llego hasta lo ultimo, significa que es palindromo.
    {
        retorno = TRUE;//El retorno es true
    }
    else
    {
        if(*cadena == cadena[largo])//Comparo la poscion actual de la cadena con la posicion de donde esta el largo.
        {
            es_palindromo(cadena + 1, largo - 1);//Muevo el puntero de la cadena y resto el largo, para comparar las posciones.
        }
        else//Si en algun momento son diferentes, no es palindromo.
        {
            retorno = FALSE;//El retorno es falso
        }
    }
    
    return retorno;
    
    
}
