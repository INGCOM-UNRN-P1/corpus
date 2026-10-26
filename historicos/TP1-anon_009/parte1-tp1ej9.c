/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int n;
        
    printf("Ingrese el numero n: ");
    scanf("%d", &n);

    while (n < 100)
    {   
        printf("El numero es menor a 100\n\n");
        printf("Ingrese el numero n: ");
        scanf("%d", &n);    
    }
    
    
        printf("El numero es mayor a 100\n\n");
    
    


}