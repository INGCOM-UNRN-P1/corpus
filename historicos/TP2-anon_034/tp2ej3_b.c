

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

 int combinatorio(int n, int k)
 {
    int formula;

    if(k <= n)
    {
        formula = factorial(n)/(factorial(k) * factorial(n - k));
    }
    else
    {
        return -1;
    }

    return formula;
 }

 int main()
 {
    int ingreso_n, ingreso_k, resultado;

    printf("\nIngrese el valor de n: ");
    scanf("%d", &ingreso_n);
    printf("\nIngrese el valor de k: ");
    scanf("%d", &ingreso_k);

    resultado = combinatorio(ingreso_n, ingreso_k);

    printf("\nEl resultado de la formula combinatoria es: %d\n", resultado);

    return 0;
 }