#include <stdio.h>

int main(){
    int numero;
    int multiplo;

    printf("Ingrese numero mayor a 100: ");
    scanf("%d",&numero);

    if (numero<100){
        printf("Ingreso invalido, numero menor a 100\n");
    }
    else{

        for (int i = 1; i < 6; i++)
        {
            multiplo = (numero%i);
            if (multiplo == 0){
                printf("Es multiplo de %d: SI\n", i);
            } 
            else{
                printf("Es multiplo de %d: NO\n", i);
            }
        }
        
    }
    



    return 0;
}