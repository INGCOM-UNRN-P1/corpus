

 #include <stdio.h>

 int division(int n, int m)
 {
    int i, calculo;

    for(i = m; i < n && i > 0; i++)
    {
        calculo = n / m;
    }

    return calculo;
 }

 int main()
 {  
    int ingreso_n, ingreso_m, i, resultado;

    printf("\nIngrese un numero entero: ");
    scanf("%d", &ingreso_n);

    ingreso_m = ingreso_n;

    for(i = 0; i < ingreso_n; i++)
    {
        ingreso_m--;
        resultado = division(ingreso_n, ingreso_m);
        printf("\n%d dividido %d da %d en numeros enteros\n", ingreso_n, ingreso_m, resultado);
    }

    return 0;
 }