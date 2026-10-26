
#include <stdio.h>

int calculador(int numero, int multiplica);
void tabla_multiplicar(int numero);

//pre: se necesita un numero entero
//post se retornara el numero multiplicado por el contador (de 1 a 10)


int main()
{
    int numero = 0;//guardo el numero del que se quiera hacer la tabla.

    printf("\n");
    printf("--------------------------------------------------------------\n");
    printf("                     Tabla de multiplicar                     \n");
    printf("--------------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese el numero para saber su tabla (hasta el 10): ");
    scanf("%d",&numero);
    
    tabla_multiplicar(numero);//Llamo a "tabla_multiplicar".      
    
}



void tabla_multiplicar(int numero)
{
    int contador = 1;
    int tabla = 0;
    
    while(contador <= 10)//10 para que multiplique hasta 10.
    {
        tabla = calculador (numero, contador);//LLamo a que se multiplique el numero ingresado por el valor del contador
        printf("%d x %d = %d\n",numero, contador, tabla);//Aca imprimo el resultado
        contador++;//Sumo para pasar a la proxima multiplicacion.
    }
}
  



int calculador(int numero, int multiplica)
{
    int respuesta = 0;
    
    respuesta = numero * multiplica;
    
    return respuesta;
    
}