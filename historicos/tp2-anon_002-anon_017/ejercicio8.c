
#include <stdio.h>
#define TRUE 1
#define FALSE 0


int es_defectivo(int numero);

//pre: Se necesita un numero entero 
//post: se imprimira si el numero ingresado en defectivo o no

int main()
{
    int numero_ingresado = 0;//Guardo el numero ingresado
    int respuesta = 0;
    
    
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("                      Número defectivo                      \n");
    printf("------------------------------------------------------------\n");
    printf("\n");
    
    
    printf("Ingrese un numero para ver si es defectivo: ");
    scanf("%d",&numero_ingresado);
    
    respuesta = es_defectivo(numero_ingresado);

    if (respuesta == TRUE)
    {
        printf("El numero %d es defectivo!",numero_ingresado);
    }
    else
    {
        printf("El numero %d no es defectivo",numero_ingresado);
    }
    
}



int es_defectivo(int numero)
{
    int contador = 1;//Esto es por lo que se divide.
    int suma = 0;//Acumulo la suma de los divisores.   
    int retorno = 0;
    
    while(contador < numero)
    {
        if ((numero % contador) == 0)
        {
            suma = suma + contador;//Aca sumo los divisores.
        }
        contador++;
    }
    
    if(suma < numero)
    {
        retorno = TRUE;
    }
    else
    {
        retorno = FALSE;
    }
    return retorno;   
}