


int suma_lenta(int numero, int otro_numero);

int suma_lenta(int numero, int otro_numero)
{
    int contador = 1;
    int resultado = 0; //En resultado guardo el valor del numero mas pequeño.
    int compara = 0; //en compara guardo el valor del numero mas grande
    
    if(numero < otro_numero)//si numero es mas pequeño guardo "numero" en resultado.
    {
        resultado = numero;
        compara = otro_numero;
    }
    else//si no guardo el otro numero en resultado;
    {
        resultado = otro_numero;
        compara = numero;
    }
    
    while (contador <= compara)
    {
        resultado++; //Se va sumando de a 1
        
        contador++;//Incremento contador en 1
    }
    return resultado;
}


    
