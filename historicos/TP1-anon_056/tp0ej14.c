

#include <stdio.h>

int divide_lento(int dividendo, int divisor);
int resto_lento(int dividendo, int divisor);


int main(int argc, char const *argv[])
{
    int dividendo;
    int divisor;

    printf("Ingrese dividendo: ");
    scanf("%d", &dividendo);
    printf("Ingrese divisor: ");
    scanf("%d", &divisor);


    return 0;
}

int divide_lento(int dividendo, int divisor){
    int cociente = 0;
    int resto = dividendo;

    while (resto >= divisor)
    {
        resto-=divisor;
        cociente++;
    }

    return cociente;
    
    
}

int resto_lento(int dividendo, int divisor){
    int resto = dividendo;

    while (resto>=divisor)
    {
        resto -= divisor;
    }
    
    return resto;

}