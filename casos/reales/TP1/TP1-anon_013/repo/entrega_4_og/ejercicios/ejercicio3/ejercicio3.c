

long long factorial(int numero)
{
    long long resultado_iterativo = 1;

    if (numero < 0)
    {
        resultado_iterativo = -1;
    }
    else
    {
        for(int i = numero; i > 0; i--)
        {
            resultado_iterativo = resultado_iterativo * i;
        }
    }
    return resultado_iterativo;
}

long long combinatorio(int cantidad_elementos, int elementos_por_grupo)
{
    long long combinaciones = 0;
    
    if(elementos_por_grupo < 0 || cantidad_elementos < 0 || elementos_por_grupo > cantidad_elementos)
    {
        combinaciones = -1;
    }
    else
    {
        combinaciones = factorial(cantidad_elementos) /
                        (factorial(elementos_por_grupo) *
                        factorial(cantidad_elementos - elementos_por_grupo));
    }
    return combinaciones;
}