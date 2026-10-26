
#include <stdio.h>


int es_multiplo(int numero, int multiplo);

//pre:Se necesitan 2 numeros enteros.
//post:Se retornara 1 o 0, dependiendo de lo que resuelva la funcion (si es multiplo o no);

int main()
{
    int numero = 0;
    int multiplo = 0;
    int respuesta = 0;
    
    printf("\n");
    printf("----------------------------------------------------\n");
    printf("                      Multiplo                      \n");
    printf("----------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero: ");
    scanf("%d",&numero);//Guardo el numero
    
    printf("Ingrese otro numero para saber si es multiplo de %d :",numero);
    scanf("%d",&multiplo);//Guardo el multiplo
    
    respuesta = es_multiplo(numero, multiplo);//llama a la funcion
    
    printf("%d",respuesta);//Imprime el retorno
    
    
}

//pre:Se necesitan 2 numeros enteros
//post:se restara el segundo numero por el primero hasta que el segundo sea menor al primero.


int es_multiplo(int numero, int multiplo)
{
    
    while (multiplo >= numero)//si todavia se le puede restar, se puede dividir
    {
        
        multiplo = multiplo - numero;//aca resta para ver si puede quedar en 0
        
    }
    
    if (multiplo == 0)//Si "multiplo", que seria el resto queda en 0, entonces es multiplo del numero
    {
        return 1;
    }    
    else//En caso contario, no es multiplo
    {
        return 0;
    }
    
    
}




