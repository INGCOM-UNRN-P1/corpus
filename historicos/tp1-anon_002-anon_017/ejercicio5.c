

#include <stdio.h>

int suma_lenta(int numero, int otro_numero);

//pre:se necesitan 2 numeros enteros.
//post: se imprimira la suma de ambos numeros.

int main()
{
    int numero_1 = 0;//Aca guardo el primer numero
    int numero_2 = 0;//Aca guardo las veces que se tiene que repetir el 1 
    int resultado = 0;//Donde se guarda el resultado de la funcion (la suma)
    
    printf("\n");
    printf("------------------------------------------------------\n");
    printf("                      Suma Lenta                      \n");
    printf("------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese el primer numero: ");
    scanf("%d",&numero_1);//Guardo el primer numero.
    
    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero_2);//Guardo el segundo numero.
    
    resultado = suma_lenta(numero_1, numero_2); //Llama a la funcion de suma lenta y guarda el retorno en resultado,
    
    printf("El resultado de la suma lenta es: %d\n",resultado);//Imprime el resultado de suma lenta
    
    return 0;
    
}

//pre: se necesitan 2 numeros enteros.
//post: se sumara de a 1 al numero mas grande,la cantidad de veces correspondientes al segundo numero.

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
        printf("%d\n",resultado);//Para ver como se hacia la suma
        
        contador++;//Incremento contador en 1
    }
    return resultado;
}


    
