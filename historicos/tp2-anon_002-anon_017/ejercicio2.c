
#include <stdio.h>

int sumador(int numero);

//Pre: se necesita que se ingrese un numero entero.
//post: Se sumara el resto de cada division por 10 que se le pueda hacer al numero ingresado.

int main()
{
    int numero_ingresado = 0;//Aca guardo el numero ingresado
    int resultado = 0; //Aca guardo el resultado de la suma de los digitos
    
    printf("\n");
    printf("---------------------------------------------------------\n");
    printf("                     Suma de digitos                     \n");
    printf("---------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero para sumar sus digitos: ");
    scanf("%d",&numero_ingresado);
    
    resultado = sumador(numero_ingresado);
    
    printf("La suma de todos los digitos es: %d",resultado);
    
    
}

    



int sumador (int numero)
{
    
    int suma = 0;//Aca guardo la suma de los restos.

    while (numero > 0)//Mientras sea divisible.
    {
        suma = suma + (numero % 10); //Aca guardo el resto de dividir por 10, que seria el ultimo numero.
        numero = numero / 10; //Aca me quedo con la parte entera de la division (el cociente);
    }
    
    return suma;
}





