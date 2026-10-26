
#include <stdio.h>
#include <stdlib.h>

#define SEGMENTO 3
#define CADENA_FECHA 9


int main()
{
    char cadenauno[CADENA_FECHA];
    char cadenados[CADENA_FECHA];  
    int resultado;
    
    printf("Ingrese la primer fecha en formato DD/MM/YY: ");
    scanf("%s", cadenauno);
    printf("Ingrese la segunda fecha en formato DD/MM/YY: ");
    scanf("%s", cadenados);    
    
    resultado = compara_fecha_year(cadenauno, cadenados);
    
    if(resultado==0)
    {
        resultado = compara_fecha_mes(cadenauno, cadenados);
    }
    if(resultado==0)
    {
        resultado = compara_fecha_dia(cadenauno, cadenados);
    }
    
    printf("\n El resultado es %d\n", resultado);
    
    return 0; 
}





int compara_fecha_year(char* primera, char* segunda)
{
    char segmento1[SEGMENTO];
    char segmento2[SEGMENTO];
    int valor, valor1, valor2;
    
    segmento1[0]=primera[6];
    segmento1[1]=primera[7];
    segmento1[2]='\0';    
    
    segmento2[0]=segunda[6];
    segmento2[1]=segunda[7];
    segmento2[2]='\0';
    
    valor1 = atoi(segmento1);
    valor2 = atoi(segmento2);
    
    if(valor1==valor2)
    {
        valor = 0;
    }
    else if(valor1 < valor2)
    {
         valor = -1;
    }
    else
    {
         valor = 1;
    }   
    
    return valor;
    
}

int compara_fecha_mes(char* primera, char* segunda)
{
    char segmento1[SEGMENTO];
    char segmento2[SEGMENTO];
    int valor, valor1, valor2;
    int resultado = 0;
    
    segmento1[0]=primera[3];
    segmento1[1]=primera[4];
    segmento1[2]='\0';    
    
    segmento2[0]=segunda[3];
    segmento2[1]=segunda[4];
    segmento2[2]='\0';
    
    valor1 = atoi(segmento1);
    valor2 = atoi(segmento2);
    
    if(valor1==valor2)
    {
        valor = 0;
    }
    else if(valor1 < valor2)
    {
         valor = -1;
    }
    else
    {
         valor = 1;
    }   
    
    return valor;
}

int compara_fecha_dia(char* primera, char* segunda)
{
    char segmento1[SEGMENTO];
    char segmento2[SEGMENTO];
    int valor, valor1, valor2;
    int resultado = 0;
    
    segmento1[0]=primera[0];
    segmento1[1]=primera[1];
    segmento1[2]='\0';    
    
    segmento2[0]=segunda[0];
    segmento2[1]=segunda[1];
    segmento2[2]='\0';
    
    valor1 = atoi(segmento1);
    valor2 = atoi(segmento2);
    
    if(valor1==valor2)
    {
        valor = 0;
    }
    else if(valor1 < valor2)
    {
         valor = -1;
    }
    else
    {
         valor = 1;
    }   
    
    return valor;
}












