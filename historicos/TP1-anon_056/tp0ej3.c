#include <stdio.h>

int main(){
    int numeroA;
    int numeroB;

    printf("Ingrese numero A: ");
    scanf("%d",&numeroA);
    printf("Ingrese numero B: ");
    scanf("%d",&numeroB);

    printf("primer numero: A = %d\n",numeroA);
    printf("segundo numero: B = %d\n",numeroB);

    printf("Operador multiplicacion: A*B = %d\n",(numeroA*numeroB));
    printf("Operador division: A/B = %d\n", (numeroA/numeroB));
    printf("Operador resto: A%%B = %d\n",(numeroA%numeroB));

    return 0;
}