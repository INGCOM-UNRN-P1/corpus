
#include <stdio.h>

int comparador (int numero1, int numero2, int numero3);

//pre: Se necesitan 3 numeros enteros
//post: se devolvera el mayor de los 3 numeros

int main()
{
    int numero1 = 0;//Guardo el primer numero
    int numero2 = 0;//Guardo el segundo numero
    int numero3 = 0;//Guardo el tercer numero
    int respuesta = 0;//Este es el valor del retorno de la funcion
    
    
    printf("\n");
    printf("--------------------------------------------------------------\n");
    printf("                      Mayor de 3 numeros                      \n");
    printf("--------------------------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese el primer numero : ");
    scanf("%d",&numero1);//Guardo el primer numero
    
    printf("Ingrese el segundo numero : ");
    scanf("%d",&numero2);//Guardo el segundo numero
    
    printf("Ingrese el tercer numero : ");
    scanf("%d",&numero3);//Guardo el tercer numero
    
    respuesta = comparador ( numero1, numero2, numero3);//Llamo a la funcion y guardo el retorno
    printf("El numero mayor es el %d.",respuesta);
    
    
    
}



int comparador (int numero1, int numero2, int numero3)
{
    int retorno = 0;
    
    if ((numero1 >= numero2) && (numero1>= numero3)) //Si el primero es mayor al segundo y al tercer numero, retorno vale el numero 1, que es el mas grande
    {
        retorno = numero1;
    }
    else if(numero2 > numero3)//Si el segundo numero es mas grande al tercero, entonces es el mas grande
    {
        retorno = numero2;
    }
    else //En otro caso el tercer numero es mas grande, o hay igualdad
    {
        retorno = numero3;
    }
    
    return retorno;
    
}
