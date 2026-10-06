

int suma_divisores_propios(int numero)
{
    int suma = 0;
    if (numero <= 0)
    {
        suma = -1;
    }
    else
    {
        for(int i = 1; i < numero; i++)
        {
            if (numero % i == 0)
            {
                suma = suma + i;
            }
        }
    }
    return suma;
}

int clasificar_numero(int numero)
{
    int clase = 0;
    if (numero <= 0)
    {
        clase = -1;
    }
    else
    {
        if(suma_divisores_propios(numero) == numero)
        {
            clase = 1;
        }
        else if (suma_divisores_propios(numero) > numero)
        {
            clase = 2;
        }
    }
    return clase;
}
