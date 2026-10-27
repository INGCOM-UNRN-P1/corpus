
#include <stdio.h>
int inicial, factorial, cuenta;


int main(int argc, char *argv[])
{
    printf("Ingese un numero para saber su factorial: ");
    scanf("%d", &inicial);
    cuenta = inicial;
    factorial = inicial;
    while(cuenta > 1)
    {
        cuenta = cuenta - 1;
        factorial = factorial*cuenta;
    }
    printf("El factorial de %d! es: %d", inicial, factorial);    
}