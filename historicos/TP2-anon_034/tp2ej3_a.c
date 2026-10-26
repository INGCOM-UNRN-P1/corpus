

 #include <stdio.h>

 int factorial(int n)
 {
    int calculo_fact = 1, i;

    for(i = 1; i <= n; i++)
    {
        calculo_fact  = calculo_fact * i;
    }

    return calculo_fact;
 }

 int main()
 {
    int ingreso, resultado;
    printf("\nIngrese un entero para calcular su factorial: ");
    scanf("%d", &ingreso);

    resultado = factorial(ingreso);

    printf("\nEl factorial de %d! es: %d\n", ingreso, resultado);

    return 0;
 }