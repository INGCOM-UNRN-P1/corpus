

 #include <stdio.h>

int producto(int entero, int otroentero)
{
    int i = 0;

    if(entero > 0)
    {
        while(entero > 0)
        {
            i = i + otroentero;
            entero = entero - 1;
        }
    }
    else if(entero < 0)
    {
        while(entero < 0)
        {
            i = i - otroentero;
            entero = entero + 1;
        }
    }
    else 
    {
        return 0;
    }

    return i;
}

int potencia(int entero, int otroentero)
{
    int i = 1;

    if(entero > 0)
    {
        while(entero > 0)
        {
            i = producto(i, otroentero);
            entero = entero - 1;
        }
    }
    else if(entero < 0)
    {
        while(entero < 0)
        {
            i = producto(i, otroentero);
            entero = entero + 1;
        }
    }
    else
    {
        return 0;
    }
    return i;
}

 int main()
 {
    int ingreso_a, ingreso_b, base, exponente, resultado_a, resultado_b;

    printf("\nIngrese un entero para multiplicarlo: ");
    scanf("%d", &ingreso_a);
    printf("\nIngrese un entero para multiplicar al anterior: ");
    scanf("%d", &ingreso_b);

    resultado_a = producto(ingreso_a, ingreso_b);
    printf("\nEl resultado de la multiplicacion es: %d", resultado_a);

    printf("\nIngrese un entero para exponenciarlo: ");
    scanf("%d", &base);
    printf("\nIngrese un entero para exponenciar al anterior: ");
    scanf("%d", &exponente);

    resultado_b = potencia(exponente, base);
    printf("\nEl resultado de la operacion es: %d", resultado_b);

    return 0;
 }