

#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int a = 0;
    int b = 0;
    int multiplicacion = 0;
    int division = 0;
    int resto = 0;

    printf("Ingrese primer numero: \n");
    do {
        scanf("%d", &a);

        if (a < 0)
        {
            printf("Valor ingresado negativo, intente de nuevo. \n");
        }
    }while(a < 0);

    
    printf("Ingrese segundo numero: \n");
    do {
        
        scanf("%d", &b);
        
        if (b < 0)
        {
            printf("Valor ingresado negativo, intente de nuevo. \n");
        }
        
    }while(b < 0);
    

    multiplicacion = a * b;
    division = a / b;
    resto = a%b;

    printf("Operador multiplicacion: A*B = %d \n", multiplicacion);
    printf("Operador division: A/B = %d \n", division);
    printf("Operador resto: A%B = %d \n", resto);

    return 0;
}