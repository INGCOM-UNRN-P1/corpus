

#include <stdio.h>


int suma_lenta(int numero, int otronumero){
    int suma = numero;

    for (int i = 0; i < otronumero; i++)
    {
        suma++;
    }
    
    return suma;
}

int main(int argc, char const *argv[])
{
    int numA;
    int numB;
    int resultado;


    printf("Ingrese numero A: ");
    scanf("%d", &numA);
    printf("Ingrese numero B: ");
    scanf("%d", &numB);


    resultado = suma_lenta(numA, numB);

    printf("%d\n", resultado);



    return 0;
}
