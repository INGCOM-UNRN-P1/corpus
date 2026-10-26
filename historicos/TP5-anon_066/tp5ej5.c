/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
#include <string.h>
#define CARACTERES_MAXIMOS_CADENA 50
#define CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR 30
#define LIMITE_MAXIMO_STRING 20

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i=0;
    int largo=0;
    for (i=0;i<capacidad_cadena;i++){
        if(cadena[largo]!='\0')
        {
            largo=largo+1;
        }else{
            break;
        }
    }
	return largo;
}
char* limpiar_cadena(char *cadena, int largo_maximo)
{
    int i,tamanio_cadena;
    tamanio_cadena = largo_cadena(cadena,largo_maximo);
    for(i=0;i<largo_maximo;i++){
        cadena[i]='\0';
    }    
    cadena=&*cadena;
}
void asignar_valor(char arreglo_string[][LIMITE_MAXIMO_STRING],char *cadena,int indice)
{
    int i,tamanio_cadena;
    tamanio_cadena = largo_cadena(cadena,LIMITE_MAXIMO_STRING);
    for(i=0;i<tamanio_cadena;i++)
    {
        arreglo_string[indice][i]=cadena[i]; 
    }
    arreglo_string[indice][tamanio_cadena]='\0';
    
}
char* division_de_cadenas_segura(char *cadena, int largo_maximo, char arreglo_string[][LIMITE_MAXIMO_STRING], int limite_maximo_caracteres, int limite_maximo_strings, int *total_caracteres)
{
    char cadena_aux[CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR];
    int i,j,k,l,valor,guardar,tamanio_cadena,tamanio_string,tamanio_maximo_cadena;
    tamanio_cadena = largo_cadena(cadena,largo_maximo);
    j=0;
    k=0;
    if(cadena[0]=='\n')
    {
        cadena_aux[0]=' ';
    }
    for(i=0;i<tamanio_cadena;i++){
        if(cadena[i]=='\n')
        {
            cadena_aux[k]='\0';
            tamanio_maximo_cadena = largo_cadena(cadena_aux,limite_maximo_caracteres);
            if(tamanio_maximo_cadena<=limite_maximo_caracteres)
            {
                if(j<limite_maximo_strings)
                {
                    asignar_valor(arreglo_string,cadena_aux,j);                                     
                    k=0;
                    limpiar_cadena(cadena_aux,CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);                   
                    j++;
                }     
            }
           
        }else{
            cadena_aux[k]=cadena[i];
            k++;
        }
        if(i==tamanio_cadena-1){
            asignar_valor(arreglo_string,cadena_aux,j); 
            valor =j;
            *total_caracteres = valor;
        }
    }
    return *arreglo_string;
}
int main(int argc, char *argv[])
{
    char cadena_solicitada[CARACTERES_MAXIMOS_CADENA];
    char arreglo_string[LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING];
    char *puntero;
    int i,j,tamanio_caracteres_ingresados,total_cadenas; 
    total_cadenas=0;  
    while(1)
    {
        printf("Ingrese una cadena menor a %d caracteres: ",CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
        scanf("%s",&cadena_solicitada);
        tamanio_caracteres_ingresados=largo_cadena(cadena_solicitada,CARACTERES_MAXIMOS_CADENA);
        if(tamanio_caracteres_ingresados>CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }
    }
    puntero = division_de_cadenas_segura(cadena_solicitada,tamanio_caracteres_ingresados,&*arreglo_string,CARACTERES_MAXIMOS_CADENA,LIMITE_MAXIMO_STRING,&total_cadenas);
    printf("total cadenas %d \n",total_cadenas);
    for(i=0;i<=total_cadenas;i++)
    {
        printf("%s\n",arreglo_string[i],i);
    }
}
