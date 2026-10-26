
 
 #include <stdio.h>

 int divide_lento(int dividendo, int divisor)
 {
    int cociente, resto;

    if(dividendo > 0 && divisor > 0)
    {
        cociente = 0;
        resto = dividendo;

        while(resto >= divisor)
        {
            resto -= divisor;
            cociente++; 
        }
        return cociente;
    }
    else
    {
        return -1;
    }
 }

 int resto_lento(int dividendo, int divisor)
 {
    int cociente, resto;

    if(dividendo > 0 && divisor > 0)
    {
        cociente = 0;
        resto = dividendo;

        while(resto >= divisor)
        {
            resto -= divisor;
            cociente++;
        }
        return resto;
    }
    else
    {
        return -1;
    }
 }

 int main()
 {
    int divisor, dividendo, resultado_resto, resultado;

    printf("\nIngrese un numero entero para dividirlo: ");
    scanf("%d", &dividendo);
    printf("\nIngrese el entero que divide al anterior: ");
    scanf("%d", &divisor);

    resultado = divide_lento(dividendo, divisor);
    resultado_resto = resto_lento(dividendo, divisor);

    printf("\nEl resultado de la division lenta fue: %d\n", resultado);
    printf("El resto de esta operacion fue: %d\n", resultado_resto);

    return 0;
 }