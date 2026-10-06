

int fibonacci(int posicion)
{
    int termino_0 = 0;
    int termino_1 = 1;
    int termino_posicion = 0;

    if(posicion < 0)
    {
        termino_posicion = -1;
    }
    for (int i=0; i<=posicion; i++)
    {
        if (i == 0)
        {
            termino_posicion = 0;
        }
        else if (i == 1)
        {
            termino_posicion = 1;
        }
        else
        {
            termino_posicion = termino_0 + termino_1;
            termino_0 = termino_1;
            termino_1 = termino_posicion;
        }
    }
    return termino_posicion;
}

int suma_fibonacci(int hasta_posicion)
{
    int suma = 0;
    if (hasta_posicion < 0)
    {
        suma = -1;
    }
    else
    {
        for(int i = 0; i <= hasta_posicion; i++)
        {
            suma = suma + fibonacci(i);
        }
    }
    return suma;
}