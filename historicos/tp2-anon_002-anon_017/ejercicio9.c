
#include <stdio.h>
int sumador (int numero);
long fibonacci(int tope);

//pre: Se necesita un numero entero
//post:Se retorna la suma de digitos de la serie de fibonacci hasta el numero ingresdo.
int main()
{
    int numero_ing = 0;
    int retorno = 0;
    
    printf("\n");
    printf("----------------------------------------------------------------\n");
    printf("                      Calculo de fibonacci                      \n");
    printf("----------------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero: ");
    scanf("%d",&numero_ing);//Guardo el tope de la serie
    
    if(numero_ing < 1)
    {
        printf("Que sea mayor a 1!!");
    }
    else
    {
        retorno = fibonacci(numero_ing);//Llamo a que se haga la serie y guardo el resultado 
        printf("El valor de la suma de los digitos de la serie es: %d",retorno);
    }
    
}

//Esta funcion guarda la suma de los restos de un numero que se divide por 10.
//pre: Se necesita un numero entero
//Post:se devuelve la suma de los digitos del numero ingresado
int sumador (int numero)
{
    
    int suma = 0;//Aca guardo la suma de los restos.

    while (numero > 0)//Mientras sea divisible.
    {
        suma = suma + (numero % 10); //Aca guardo el resto de dividir por 10, que seria el ultimo numero.
        numero = numero / 10; //Aca me quedo con la parte entera de la division (el cociente);
    }
    
    return suma;
}

//Esta funcion calcula la serie de fibonacci hasta un n numero y llama a la funcion de suma de digitos para sumarlos.
//pre: Se necesita 1 numero entero.
//post: Se devolvera la suma de los digitos de la serie de fibonacci hasta el numero ingresado.

long fibonacci(int tope)
{
    int numero = 1;//Aca se guarda el numero anterior
    int numero_2 = 0;//Aca va el numero sumado
    int total = 0; //esta es el valor parcial de la serie
    int contador = 0;//este es el contador del tope de la serie
    long suma = 0;//aca guardo la suma de los digitos
    
    while(contador < tope)
    { 
        numero_2 = numero;// = 1
        numero = total; //= 0
        total = numero_2 + numero;// 0 = 0 + 1//1 = 1 + 1
        suma = sumador(total) + suma;//Aca llamo a que sume los digitos del nuevo valor y los sume con el del anterior valor.
        contador++;    
    }
    
    return suma;
}

