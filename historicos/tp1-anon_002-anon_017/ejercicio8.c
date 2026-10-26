
#include <stdio.h>


int suma_rango(int n, int m);

//pre:Se necesitan 2 numeros enteros
//post: Se retornara la suma entre el primer numero y el numero anterior del segundo numero ingresado


int main()
{
    int numero_1 = 0;
    int numero_2 = 0;
    int respuesta = 0;
    
    
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("                 Suma en rango                 \n");
    printf("-----------------------------------------------\n");
    printf("\n");
    
    printf("Ingrese un numero : ");
    scanf("%d",&numero_1);//guardo el primer numero
    
    
    printf("Ingrese un segundo numero : ");
    scanf("%d",&numero_2);//Guardo el segundo numero
    
    respuesta = suma_rango(numero_1, numero_2);//Llamo a la funcion
    
    printf("La suma de rango entre %d y %d es: %d",numero_1, numero_2, respuesta);//Imprimo respuesta.
    
    
}

//pre: se necesitan 2 numeros.
//post: se retornara el total de la suma de numeros entre el primero y el segundo (sin sumar el segundo numero).

int suma_rango(int n, int m)
{
    int total = 0;//aca se guarda el valor parcial de la suma
    
    while (n < m)//si n es = o mayor, deja de sumar, para no sumar a "m".
    {
        total = total + n; //Sumo el total anterior con n
        n++;//Incremento n para sumar n+1;
        
    }
    return total; 
}
