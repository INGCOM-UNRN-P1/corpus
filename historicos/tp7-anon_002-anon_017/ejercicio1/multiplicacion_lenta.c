

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

        while (contador < numero2) 
        {
            resultado = resultado + numero;
            contador++;
        }

    }
    return resultado;
}