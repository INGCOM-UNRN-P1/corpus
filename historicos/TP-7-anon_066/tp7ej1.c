/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CARACTERES_MAXIMOS_CADENA 12000
#define CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR 10000
#define CANTIDAD_ENTEROS 4096
struct operacion
{
 char *tipo;
 int numeros[CANTIDAD_ENTEROS];
 int numeros_guardados;
 double resultado;
 int operacioncerrada;
};struct operacion operaciones[CANTIDAD_ENTEROS][CANTIDAD_ENTEROS];
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i=0;
    int largo=0;
    for (i=0;i<capacidad_cadena;i++){
        if(cadena[largo]!='\n' && cadena[largo]!='\0')
        {
            largo=largo+1;
        }else{
            break;
        }
    }
	return largo;
}
int sumar(int E[CANTIDAD_ENTEROS], int final)
{
    int i;
    int suma;
    suma=0;
    for (i=0;i<final;i++){
        suma =suma + E[i];
    }
    return suma;
}
int restar(int E[CANTIDAD_ENTEROS], int final, int inicio)
{
    int i;
    int resta;
    if(inicio==0)
    {
        resta=E[final-1];
        for (i=0;i<final-1;i++){
            resta =resta - E[i];
        }
    }else{
        resta=E[0];
        for (i=1;i<final;i++){
            resta =resta - E[i];
        }
    }
    return resta;
}
int multiplicar(int E[CANTIDAD_ENTEROS], int final)
{
    int i;
    int multiplicar;
    multiplicar=1;
    for (i=0;i<final;i++){
        multiplicar =multiplicar*E[i];
    }
    return multiplicar;
}
double promedio(int E[CANTIDAD_ENTEROS], int final)
{
    int i;
    double sumas,promedio;
    sumas = sumar(E,final);
    promedio=0;
    if(final>0)
    {
        promedio=sumas/final;  
    }
    return promedio;
}
int esnumero_valido(char *cadena)
{
    //65.536
    int i,esnegativo;
    int tamanio_linea;
    int salida;
    salida=0;
    tamanio_linea=largo_cadena(cadena,CARACTERES_MAXIMOS_CADENA);
    if(tamanio_linea>0)
    {
        if(cadena[0]==45 && tamanio_linea>1)
        {
            esnegativo=1;
        }else{
            esnegativo=0;
        }
    }else{
        return salida;
    }
    for(i=esnegativo;i<tamanio_linea;i++)
    {
        if(cadena[i]<48 || cadena[i]>57 )
        {               
            return salida;
        }
    }
    salida=1;
    return salida;
    
}
int essuma(char *cadena)
{
    int tamanio_linea;
    int i;
    int salida;
    salida=0;
    tamanio_linea=largo_cadena(cadena,CARACTERES_MAXIMOS_CADENA);
    for(i=0;i<tamanio_linea;i++)
    {
        if(cadena[i]!=43)
        {
            return salida;
        }        
    }
    salida=1;
    return salida;
}
int esresta(char *cadena)
{
    int tamanio_linea;
    int i,salida;
    salida=0;
    tamanio_linea=largo_cadena(cadena,CARACTERES_MAXIMOS_CADENA);
    for(i=0;i<tamanio_linea;i++)
    {
        if(cadena[i]!=45)
        {
            return salida;
        }        
    }
    salida=1;
    return salida;
}
int esmultiplicacion(char *cadena)
{
    int tamanio_linea;
    int i,salida;
    salida=0;
    tamanio_linea=largo_cadena(cadena,CARACTERES_MAXIMOS_CADENA);
    for(i=0;i<tamanio_linea;i++)
    {
        if(cadena[i]!=42)
        {
            return salida;
        }        
    }
    salida=1;
    return salida;   
}
int espromedio(char *cadena)
{
    int tamanio_linea;
    int i,salida;
    salida=0;
    tamanio_linea=largo_cadena(cadena,CARACTERES_MAXIMOS_CADENA);
    for(i=0;i<tamanio_linea;i++)
    {
        if(cadena[0]!=97)
        {
            return salida;
        }        
    }
    salida=1;
    return salida;
}
int essignoigual(char *cadena)
{
    int tamanio_linea;
    int i;
    int salida;
    salida=0;
    tamanio_linea=largo_cadena(cadena,CARACTERES_MAXIMOS_CADENA);
    for(i=0;i<tamanio_linea;i++)
    {
        if(cadena[i]!=61)
        {
            return salida;
        }
    }
    salida=1;
    return salida;
}
int quetipoes(char *cadena)
{
    int tipo;
    tipo =0;
    if(esnumero_valido(cadena)==1){
        tipo =1;
    }else if(essuma(cadena)==1)
    {
        tipo =2;
    }else if(esresta(cadena)==1)
    {
        tipo =3;
    }else if(essignoigual(cadena)==1)
    {
        tipo =4;
    }else if(esmultiplicacion(cadena)==1)
    {
        tipo =5;
    }else if(espromedio(cadena)==1)
    {
        tipo =6;
    }
    return tipo;
}
int main(int argc, char *argv[])
{
    FILE *archivo;;
    char *nombre_archivo;
    int numeros_a_guardar[CANTIDAD_ENTEROS];
    char *cadena;
    char *valor;
    char *txt_operacion;
    int i,j,k,numerovalido,operacion_cerrada,operaciones_cerradas,numero,resta,multiplicacion,resultado, cant_operaciones;
    int cantidad_numeros,es_promedio;
    int inicio,posicion_inicial,operacion_anterior,tipo,suma;
    double total,total_salida,salida_promedio;
    nombre_archivo =argv[1];
    archivo = fopen(nombre_archivo,"r");
    cantidad_numeros=0;
    posicion_inicial=0;
    cant_operaciones=0;
    operacion_cerrada=0;
    operaciones_cerradas=0;
    numerovalido=0;
    total=0;
    total_salida=0;
    es_promedio=0;
    salida_promedio=0;
    operacion_anterior =1;
    if(argc >= 2)
    {       
        if (archivo == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }
        else
        {
            cadena = (char *)malloc(CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
            while(fgets(cadena, CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR, archivo))
            {
                tipo =quetipoes(cadena);
                switch(tipo)
                {
                    case 1:
                        numero = (int) strtol(cadena, NULL, 10);
                        if (numero<65536 && numero>(-65536))
                        {
                            numeros_a_guardar[cantidad_numeros]=numero;
                            operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=numero;
                            operaciones[operaciones_cerradas][cant_operaciones].numeros_guardados=cantidad_numeros;
                            cantidad_numeros=cantidad_numeros+1;   
                        }else{
                            printf("El numero no esta dentro del rango aceptado\n");                      
                        } 
                        operacion_anterior=1;   
                    break;
                    case 2:
                        if(cantidad_numeros==0 && operacion_anterior==1)
                        {
                            printf("No se puede realizar la operacion suma\n");
                        }else if(operacion_anterior!=2)
                        {
                            if(operacion_anterior==1)
                            {
                                operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=total;
                                cantidad_numeros=cantidad_numeros+1;
                            }
                            suma =sumar(operaciones[operaciones_cerradas][cant_operaciones].numeros,cantidad_numeros);
                            operaciones[operaciones_cerradas][cant_operaciones].tipo="+";
                            operaciones[operaciones_cerradas][cant_operaciones].resultado=suma;
                            total = suma;
                            cantidad_numeros=0;
                            cant_operaciones=cant_operaciones+1; 
                            operacion_anterior=2;                             
                        }  
                    break;
                    case 3:
                        if(cantidad_numeros==0 && operacion_anterior==1)
                        {
                            printf("No se puede realizar la operacion resta\n");
                        }else if(operacion_anterior!=3)
                        {   
                            if(operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="=" && cant_operaciones!=0)
                            {
                                inicio=1;
                                resta =restar(operaciones[operaciones_cerradas][cant_operaciones].numeros,cantidad_numeros,inicio);
                            }else if(cant_operaciones!=0 && (operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="+" ||  operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="-" ||  operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="a"))
                            {  
                                inicio=0;
                                total = operaciones[operaciones_cerradas][cant_operaciones-1].resultado;
                                operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=total;
                                cantidad_numeros=cantidad_numeros+1;  
                                resta =restar(operaciones[operaciones_cerradas][cant_operaciones].numeros,cantidad_numeros,inicio);
                            }else{
                                inicio=1;
                                resta =restar(operaciones[operaciones_cerradas][cant_operaciones].numeros,cantidad_numeros,inicio);    
                            }
                            operaciones[operaciones_cerradas][cant_operaciones].tipo="-";
                            operaciones[operaciones_cerradas][cant_operaciones].resultado=resta;
                            total = resta;
                            cantidad_numeros=0;
                            cant_operaciones=cant_operaciones+1;
                            operacion_anterior=3;   
                        }    
                    break;
                    case 4:
                        if(operacion_anterior!=4 && operacion_anterior!=1)
                        {
                            operaciones[operaciones_cerradas][cant_operaciones].tipo="=";
                            operaciones[operaciones_cerradas][cant_operaciones].resultado=total;
                            cantidad_numeros=0;
                            cant_operaciones=cant_operaciones+1;
                            operacion_cerrada=1;
                            operaciones[operaciones_cerradas][cant_operaciones].operacioncerrada=operacion_cerrada;
                            operaciones_cerradas=operaciones_cerradas+1;
                            operacion_cerrada=0;  
                            total=0;
                            operacion_anterior=4;
                        }else if(operacion_anterior==1)
                        {
                            printf("Necesita ingresar una operacion\n");
                        }
                    break;
                    case 5:
                        if(cantidad_numeros==0 && operacion_anterior==1)
                        {       
                            printf("No se puede realizar la operacion multiplicacion\n");
                        }else if(operacion_anterior!=5)
                           
                        {    
                            if(cant_operaciones>1 && operacion_anterior!=1 && operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="=")
                            {                            
                                total = 1;
                                operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=total;
                                cantidad_numeros=cantidad_numeros+1;  
                            }else if(cant_operaciones>1 && operacion_anterior==1 && (operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="+" ||  operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="-" ||  operaciones[operaciones_cerradas][cant_operaciones-1].tipo=="a"))
                            {
                                total = operaciones[operaciones_cerradas][cant_operaciones-1].resultado;
                                operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=total;
                                cantidad_numeros=cantidad_numeros+1; 
                            }else if(operacion_anterior==1)
                            {
                                total = 1;
                                operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=total;
                                cantidad_numeros=cantidad_numeros+1; 
                            }
                            multiplicacion =multiplicar(operaciones[operaciones_cerradas][cant_operaciones].numeros,cantidad_numeros);
                            operaciones[operaciones_cerradas][cant_operaciones].tipo="*";
                            operaciones[operaciones_cerradas][cant_operaciones].resultado=multiplicacion;
                            total = multiplicacion;
                            cantidad_numeros=0;
                            cant_operaciones=cant_operaciones+1;   
                            operacion_anterior=5;   
                        }   
                    break;
                    case 6:
                        if(cantidad_numeros==0 && operacion_anterior==1)
                        {
                            printf("No se puede realizar la operacion promedio\n");
                        }else if(operacion_anterior!=6)
                        {      
                            if(cant_operaciones>1)
                            {                            
                                total = operaciones[operaciones_cerradas][cant_operaciones-1].resultado;
                                operaciones[operaciones_cerradas][cant_operaciones].numeros[cantidad_numeros]=total;
                                cantidad_numeros=cantidad_numeros+1;  
                            }
                            salida_promedio =promedio(operaciones[operaciones_cerradas][cant_operaciones].numeros,cantidad_numeros);
                            operaciones[operaciones_cerradas][cant_operaciones].tipo="a";
                            operaciones[operaciones_cerradas][cant_operaciones].resultado=salida_promedio;
                            total = salida_promedio;
                            cantidad_numeros=0;
                            cant_operaciones=cant_operaciones+1;  
                            operacion_anterior=6;   
                        }    
                    break;
                    case 0:
                        printf("Entrada no valida\n");
                    break;
                }                        
            }
            free(cadena);
        }
        fclose(archivo);
    }else
    {
        printf("No se envio el nombre del archivo");
    }
    for(k=0;k<operaciones_cerradas;k++)
    {        
        for(i=0;i<cant_operaciones;i++)
        { 
            if(operaciones[k][i].tipo=="=")
            {
                total_salida=operaciones[k][i].resultado;
                if(es_promedio==1){
                    printf("%s%.2f\n",operaciones[k][i].tipo,total_salida);
                }else{
                    printf("%s%.0f\n",operaciones[k][i].tipo,total_salida);
                }
                
            }else{
                if(operaciones[k][i].tipo=="a")
                {
                    es_promedio=1;
                }
                for(j=0;j<=operaciones[k][i].numeros_guardados;j++)
                {
                    if(operaciones[k][i].numeros[j])
                    {   
                        if(numerovalido==0)
                        {
                            txt_operacion="";
                        }else{
                            txt_operacion=operaciones[k][i].tipo;
                        }
                        numerovalido=numerovalido+1;
                        printf("%s%d",txt_operacion,operaciones[k][i].numeros[j]);
                    }
                    
                }
                
            }
        }
        es_promedio=0;
        numerovalido=0;
    }
	return 0;
}
