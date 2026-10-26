

 #include <stdio.h>

 int raiz(int entero)
{
    float i = 0;
    int resto;

    if(entero >= 0)
    {
        do
        {
            i = i + 0.1;
            resto = i * i;
        }
        while(entero >= resto);
    }
    else
    {
        return -1;
    }

    return i;
}

int main()
{
    int entero, otroentero, resultado_a, resultado_b;

    printf("\nIngrese un numero entero para calcular su raiz cuadrada: ");
    scanf("%d", &entero);
    printf("\nIngrese un segundo numero enteropara calcular su raiz cuadrada: ");
    scanf("%d", &otroentero);

    resultado_a = raiz(entero);
    resultado_b = raiz(otroentero);
    printf("\nEl resultado de la operacion 1 fue: %d", resultado_a);
    printf("\nEl resultado de la operacion 2 fue: %d", resultado_b);

    return 0;
}