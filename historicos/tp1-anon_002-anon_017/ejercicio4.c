

#include <stdio.h>

int compara(int numero, int otro_numero);

//pre:se necesita que se ingresen 2 numeros enterosz.
//post: se imprimira el "estado" del primer numero en relacion al segundo.


int main()
{
    int numero_1 = 0; //Donde se guarda el primer numero.
    int numero_2 = 0; //Donde se guarda el segundo numero.
    int respuesta = 0; //Donde guardo el retorno de la funcion.
    
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("                Comparación de números                \n");
    printf("------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese el primer entero numero a comparar: ");
    scanf("%d",&numero_1);
    
    printf("Ingrese el segundo entero numero a comparar: ");
    scanf("%d",&numero_2);  
    
    respuesta = compara(numero_1, numero_2); //Guardo el retorno de la funcion "compara" en "respuesta".
    
    printf("\n");
    printf("%d",respuesta);
    printf("\n");
    printf("------------------------------------------------------\n");
       
}

//pre: se necesitan 2 numeros
//post: se retorna un numero que indica la comparacion entre ambos numeros.

int compara(int numero, int otro_numero)
{
    if (numero == otro_numero)//Si ambos numero son iguales se retorna "0".
    {
        return 0;
    }
    else if (numero > otro_numero)//Si el primer numero es mas grande retorna "-1".
    {
        return -1;
    }
    else //El otro caso es si el primer numero es menor al segundo, entonces retorna "1".
    {
        return 1;
    }
    
}
