


#include <stdio.h>



int main()

{
int a, b, fact=1;

    printf ("Ingrese el valor n: ");
    scanf ("%d",&a);
        for (b=1;b<=a;b++)
        {
            fact=fact*b;
            printf ("El factorial de %d! es: %d\n" ,b,fact);
         }

}

