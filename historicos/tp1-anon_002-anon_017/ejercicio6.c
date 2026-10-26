

#include <stdio.h>

int division_lenta(int dividendo, int divisor);

int cociente_lento(int dividendo, int divisor);

//pre: se necesitan 2 numeros enteros, siendo el segundo ingresado, mayor a 1
//post: En caso de que el segundo numero ingresado sea == a 0 se retornara un error, si no se retornara el cociente y el resto entre ambos numeros
//

int main()
{
    int dividendo = 0;//Aca se guarda el dividendo
    int divisor = 0;//Aca de guarda el divisor
    int cociente = 0;//Aca se va a guarda el cociente una vez llamada la funcion "division_lenta".
    int resto = 0;//Aca se va a guarda el resto una vez llamada la funcion "resto_lento".
    
    
    printf("\n");
    printf("----------------------------------------------------------\n");
    printf("                      Division Lenta                      \n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero a dividir: ");
    scanf("%d",&dividendo);//Guardo el dividendo
    
    printf("Ingrese un numero que lo divida (que no sea 0): ");
    scanf("%d",&divisor);//Guardo el divisor
    
    if (divisor ==0 )//si es 0 no puede dividir.
    {
        printf("MATH ERROR!! \nNo se puede dividir por 0!!!");
        return 0;
    }
    
    resto = division_lenta(dividendo, divisor);//llama a funcion
    cociente = cociente_lento(dividendo, divisor);//Llama a funcion
    
    printf("----------------------------------------------------------\n");
    printf("El cociente de dividir %d entre %d es:|| %d resto: %d||",dividendo,divisor,cociente,resto);
    printf("\n");
    
}

//pre: se necesitan 2 numeros enteros
//post: se restara el segundo numero n veces al primero, hasta que este sea menor al segundo numero.


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

//pre: se necesitan 2 numeros enteros
//post: se restara el segundo numero n veces al primero, hasta que este sea menor al segundo numero.

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




