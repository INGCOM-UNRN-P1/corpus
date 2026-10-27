
#include <stdio.h>
 
int main(int argc, char *argv[])

{
    int A, B; 
    int C; 

    printf("Ingrese un numero entero:\n");
    scanf("%d", &A); 
    printf("Ingrese otro numero entero:\n");
    scanf("%d", &B); 
    
    C = A * B;
    printf("El producto de %d y %d es: %d\n", A, B, C);
    C = A / B;
    printf("El resultado entre %d y %d es: %d\n", A, B, C);
    C = A % B;
    printf("El resto de %d y %d es: %d\n", A, B, C);
    
    
    return 0;
}
