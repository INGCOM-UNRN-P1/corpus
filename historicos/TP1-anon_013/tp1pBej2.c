

//Trabajo práctico 1:
//Parte B:
//Ejercicio 2: Suma lenta

#include <stdio.h>
int suma_lenta(int A, int B)
{
    int resultado=A;
    for (int i=1; i<=B; i++)
    {
        ++resultado;
    }
    return resultado;
}
void main()
{
    int num_1, num_2, valor;
    printf("Ingrese dos numeros naturales\n");
    scanf("%d%d", &num_1, &num_2);
    valor=suma_lenta(num_1, num_2);
    printf("\n%d+%d = %d\n", num_1, num_2, valor);
}
