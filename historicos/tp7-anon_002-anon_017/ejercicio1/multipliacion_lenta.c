





int multiplicacion_lenta(int numero,  int numero2);


int multiplicacion_lenta(int numero,  int numero2) 
{
    int resultado = 0;
    int contador = 0;

    if (numero == 0 || numero2 == 0) 
    {
         resultado = 0;
    }
    else
    {

        while (contador < numero2) //Numero 2 es la cantidad de veces que se multiplica
        {
            resultado = resultado + numero;//Sumo el resultado con el numero.
            contador++;
        }

    }
    return resultado;
}