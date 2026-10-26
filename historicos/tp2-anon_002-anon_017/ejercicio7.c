
#include <stdio.h>

int potencia_lenta(int numero, int multiplicador);

//pre:se necesitan 2 numeros enteros.
//post:se devuelve el resultado de mutiplicar el primer numero por si mismo la cantidad de veces por el segundo.

int main()
{
    int numero_in = 0;//Guardo el numero ingresado.
    int multiplicador = 0; //Guardo cuantas veces se va a hacer la multiplicacion
    int total = 0;//Guardo el resultado de la multiplicación
    
    printf("\n");
    printf("----------------------------------------------------------\n");
    printf("                      Potencia lenta                      \n");
    printf("----------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero: ");
    scanf("%d",&numero_in);//Guardo el numero que se va a multiplicar
    
    printf("Ingrese cuantas veces se va a multiplicar: ");
    scanf("%d",&multiplicador);//Guardo la cantidad de veces que se tiene que multiplicar
    
    total = potencia_lenta(numero_in, multiplicador);
    
    printf("El restultado de %d a la %d es: %d",numero_in, multiplicador, total);
    
}



int potencia_lenta(int numero, int multiplicador)
{
    int contador = 0;//Cuantas veces se hace la multiplicacion
    int total = 0;//Aca guardo el numero que se va sumando para despues retornarlo.

    
    if(multiplicador == 2)//si es a la 2, solamente se tiene que multiplicar 1 vez, 
    {
        for (int i = 0; i < numero; i++)//Este bucle es la "multiplicacion lenta".
            {
                
                total = total + numero;//Suma numero + numero cantidad de veces

                
            }
        
    }
    else//Si es mas de 2, se tiene que multiplicar 1 vez
    {
        if(numero > 1)//Si el numero es positivo.
        {
            while (contador < multiplicador)//Este lazo hace la "potencia lenta".
            {

                for (int i = 0; i < numero; i++)//Este bucle es la "multiplicacion lenta".
                {
                   
                    total = total + numero;//Suma numero + numero cantidad de veces
                    
                }
                contador++;
            }                              
        }
        else//Si el numero es negativo.
        {
            while (contador < multiplicador)//Este lazo hace la "potencia lenta".
            {
     
                for (int i = 0; i > numero; i--)//Este bucle es la "multiplicacion lenta".
                {

                    total = total + numero;//Suma numero + numero cantidad de veces
                }
                contador++;
            }
        }
    }
    
    return total;
}