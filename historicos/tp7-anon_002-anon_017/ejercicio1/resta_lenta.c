


int resta_lenta(int numero, int otro_numero);

int resta_lenta(int numero, int otro_numero)
{
    int contador = 1;
    int resultado = 0; //En resultado guardo el valor del numero mas pequeño.
    int compara = 0; //en compara guardo el valor del numero mas grande
    
    resultado = numero; //esto es por que hay que sacarle al primer numero.
    
    while (contador <= otro_numero)
    {
        resultado--; //Se va restando de a 1
        
        contador++;//Incremento contador en 1 para que salga
    }
    return resultado;
}


    
