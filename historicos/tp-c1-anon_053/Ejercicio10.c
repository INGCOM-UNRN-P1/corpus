

#include <stdio.h>

int facto(int num);

int main() {
    int num = 0;
    printf("Ingrese un valor entero: ");
    scanf("%d", &num);
    
    if (num < 0){
        printf("Factorial de un numero negativo no existe.\n");
        }
    else{
        printf("Factorial of %d! = %d\n", num, facto(num));
    }
    return 0;
    
}

int facto(int num)
{
    int i;
    int fact = 1;
        for (i = 1; i <= num; i++) {
            fact = (fact * i);
        }
    return fact;
}

