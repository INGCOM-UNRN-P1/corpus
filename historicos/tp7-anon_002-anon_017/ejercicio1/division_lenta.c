


int division_lenta(int dividendo, int divisor);

int cociente_lento(int dividendo, int divisor);


int division_lenta(int dividendo, int divisor)
{
    int resto = dividendo;//El resto es lo que sobra de la division
    
    
    while (resto >= divisor)//si todavia se le puede restar, se puede dividir
    {
        //0             5          -5  
        resto = resto - divisor;//aca resta
        
    }
     
    return resto;//devuelve el resto.  
    
}

int cociente_lento(int dividendo, int divisor)
{
    int resultado = dividendo; //Es lo que va quedando
    int contador = 0;//contador es el cociente
    
    while (resultado >= divisor)//ve si es posible dividir
    {
///      4          4          3                                
        resultado = resultado - divisor; //"Divide"
        contador++; //1+1+1
    }
     
    return contador;  
    
}




