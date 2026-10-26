

#include <stdio.h>
//se declara funcion
int contadorDigito(int numero);

int main()
{
    int numero;

    printf("Ingrese numero a contar: ");
    scanf("%d", &numero);

    printf("El numero tiene %d digitos", contadorDigito(numero));
    
    return 0;

}
//pre: recibe un numero entero
int contadorDigito(int numero)
{//funcion que cuenta lso digitos de un numero
    int contador = 0;
    while (numero > 0)
    {
        numero = numero / 10;
        contador ++;
    }
    return contador;
}//pos: retorna la cantidad de digitos de un numero

