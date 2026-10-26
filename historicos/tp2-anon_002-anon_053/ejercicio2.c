

#include <stdio.h>
//se declara funcion
int sumaDigito(int numero);

int main()
{
    int numero = 5324;    

    printf("Todos los digitos suman %d.", sumaDigito(numero));

    return 0;

}

//pre: recibe un numero entero
int sumaDigito(int numero)
{//funcion que suma cada digito de un numero 
    int suma = 0;
    while(numero > 0)
    {
        int resto = numero % 10;
        suma = suma + resto;
        //printf("%d\n", suma);
        numero = numero / 10;
    }
    return suma;
}//pos: retorna la suma de digitos del numero entero


