
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero, i;

    //Pido un numero hasta que el ingresado sea mayor a 10
    do {
        printf("Ingrese un numero entero mayor a 10: ");
        scanf("%d", &numero);
    } while(numero < 10);

    int fibonacci[numero]; //En base al numero ingresado creo el array

    for(i = 0; i < numero; i++)//lleno el array con los items de la secuencia fibonacci
    {
        if(i < 2)
           fibonacci[i] = i;// los dos primeros items, son 0 y 1 siempre
        else
           fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];// el resto de los items son la suma de los dos anteriores
    }

    printf("La secuencia fibonacci (%d) = %d\n", numero, fibonacci[i]);

    return 1;
}
