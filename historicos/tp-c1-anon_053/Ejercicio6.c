

#include <stdio.h>

int division_lenta(int numero1, int numero2);
int cociente_lento(int numero1, int numero2);

int main()
{
    int numero1;
    int numero2;
    
    printf("Ingrese el dividendo: \n");
    scanf("%d", &numero1);
    
    printf("Ingrese el divisor: \n");
    scanf("%d", &numero2);
    
    printf("El cociente es: %d\n", cociente_lento(numero1,numero2));
    
    printf("El resto es: %d\n", division_lenta(numero1,numero2));
    return 0;
}

int division_lenta(int numero1, int numero2)
{
    int resto;
    resto = numero1;
    while (resto >= numero2){
        resto= resto - numero2;
    }
    return resto;

}

int cociente_lento(int numero1, int numero2)
{
    int cociente;
    while (numero1 > numero2){
        numero1= numero1 - numero2;
        cociente= cociente +1;

    }
    return cociente;

}
