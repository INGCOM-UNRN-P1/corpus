

#include <stdio.h>


int digitos(unsigned int numero)
{
    int contador = 0;
    while (numero != 0)
    {
        numero = numero / 10;
        contador++;
    }
    return contador;
}

int main()
{
    unsigned int num;
    printf("Escriba el número a revisar: \n");
    scanf("%u", &num);
    
    printf("La cantidad de dígitos es: %u", digitos(num));
   
    //COMPLETAR
    // No quiero
    return 0;
}
