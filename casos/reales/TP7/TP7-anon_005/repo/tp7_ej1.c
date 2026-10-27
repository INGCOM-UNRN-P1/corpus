
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PALABRAS 100

#define MAX_RANGO 65535
#define MIN_RANGO -65536
#define MAX_CAR 5
#define LARGO_MIN 2
#define ERROR -1

FILE* abrir_archivo(char* archivo);
int largo_archivo(FILE* p_file);
char** memoria_matriz(int largo);
void comprobacion_cadena(char* cadena);
char** memoria_cadena(FILE* p_file, char** matriz, char* cadena,int largo, int caracteres);
void cerrar_archivo(FILE* p_file);
int buscar_operacion(char** matriz,int limite_inf, int largo, int posicion);
int sumar(int num_uno, int num_dos);
int restar(int num_uno, int num_dos);
int multiplicar(int num_uno, int num_dos);
int promediar(int num_uno, int num_dos);
int cuenta(char** matriz, int posicion, int limite_inf, char operador, int acumulado);
void resultado(char** matriz, char operador, int limite_inf, int posicion, int acumulado, int largo);

int main(int argc, char *argv[])
{
    char* archivo = "cinta.txt";
    FILE* p_file;
    
    int i;
    int limite_inf = 0;
    int posicion = 0;
    int acumulado = 0;
    int largo;
    int caracteres;
    char operador;
    char cadena[MAX_CAR];
    char** matriz;
    
    p_file = abrir_archivo(archivo);
    largo = largo_archivo(p_file);
    caracteres = MAX_CAR;
    
    rewind(p_file);
    matriz = memoria_matriz(largo);
    
    matriz = memoria_cadena(p_file, matriz,cadena, largo, caracteres);
    
    printf("\n Los datos leidos son: \n\n");
    
    for(i=0; i<largo; i++)
    {
        printf("\n %s \n", matriz[i]);
    }
    printf("\n");
    
    cerrar_archivo(p_file);
    
    printf("\n Resultados: \n");
    
    resultado(matriz, operador, limite_inf, posicion, acumulado, largo);
    
    printf("\n Fin de operaciones.\n ");
    
    for(i=0; i< largo; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}

FILE* abrir_archivo(char* archivo)
{
    FILE *p_file;
    p_file = fopen(archivo, "r");
    if(p_file == NULL)
    {
        printf("No se pudo abrir el archivo \n");
    }
    
    return p_file;    
}

int largo_archivo(FILE* p_file)
{
    int n = 0;    
    char palabra[MAX_PALABRAS];
    
    while(!feof(p_file))
    {      
        fscanf(p_file, "%s",palabra);
        n++;
    }              
    return n-1;
}

char** memoria_matriz(int largo)
{
    char** matriz= malloc(largo*sizeof(char*));
    
    if(matriz == NULL)
    {
        printf("Error. No se pudo reservar la memoria. \n");
    }
    return matriz;  
}

void comprobacion_cadena(char* cadena)
{
    int i;
    int largo;
    char op_inicial;
    int coincidencias;

    coincidencias = 0;
    largo = strlen(cadena);
    
    if((largo >LARGO_MIN)&&(atoi(cadena)== 0))
    {
        op_inicial = cadena[0];
        for(i=1; i<largo; i++)
        {
            if(cadena[i] == op_inicial)
            {
                coincidencias++;                
            }
        }
        if(coincidencias!= (largo-1))
        {
            printf("\n Error!. El operador leido <%s> posee multiples operadores diferentes. \n",cadena);
        }
    }
    
    if((atoi(cadena) > MAX_RANGO)||(atoi(cadena) < MIN_RANGO))
    {
        printf("\n Error!. El numero leido <%d> esta fuera de rango. \n",atoi(cadena));
    }
}

char** memoria_cadena(FILE* p_file, char** matriz, char* cadena,int largo, int caracteres)
{
    int i;
    rewind(p_file);
    
    for(i=0; i<largo;i++)
    {
        fscanf(p_file,"%s",cadena);                                             
        matriz[i]= calloc((strlen( cadena )+1),sizeof(char));
        
        if(matriz[i]== NULL)
        {
            printf("Error. No se pudo reservar la memoria para la cadena %d. \n", i);
        }
        
        comprobacion_cadena(cadena);
        strcpy(matriz[i],cadena);
    }
    return matriz;  
}

void cerrar_archivo(FILE* p_file)
{
    fclose(p_file); 
}
          
int buscar_operacion(char** matriz,int limite_inf, int largo, int posicion)
{    
    int i;
    
    for(i =limite_inf; i<largo;i++)
    { 
        if((*matriz[i]=='+')||(*matriz[i]=='-')||(*matriz[i]=='*')||(*matriz[i]=='=')||(*matriz[i]=='a'))
        {
            posicion =i;
            break;
        }
    }
    return posicion;
}

int sumar(int num_uno, int num_dos)
{
    int suma;
    
    suma = num_uno + num_dos;
    printf("\n %d + %d = %d \n ",num_uno, num_dos, suma);
    
    return suma;
}

int restar(int num_uno, int num_dos)
{
    int resta;
    
    resta = num_uno - num_dos;
    printf("\n %d - %d = %d \n ",num_uno, num_dos, resta);
    
    return resta;
}

int multiplicar(int num_uno, int num_dos)
{
    int producto;
    
    if(num_uno == 0)
    {
        num_uno = 1;
    }
    
    producto = num_uno*num_dos;
    printf("\n %d * %d = %d \n",num_uno, num_dos, producto);
    
    return producto;
}

int promediar(int num_uno, int num_dos)
{  
    int suma;
    int media;
    
    suma = num_uno + num_dos;
    media = suma/2;
    
    printf("\n %d a %d = %d \n",num_uno, num_dos, media);
    
    return media;
}

int cuenta(char** matriz, int posicion, int limite_inf, char operador, int acumulado)
{
    int i;
    int num = 0;
    
    if(operador!= '=')
    {
        for(i = limite_inf; i <posicion; i++)
        {
            num = atoi(matriz[i]);
            
            if((num >= MIN_RANGO) && (num <= MAX_RANGO))
            {                
                switch(operador)
                {
                    case'+':
                        acumulado = sumar(acumulado, num);
                        break;        
                    case '-':
                        acumulado = restar(acumulado, num);
                        break;
                    case '*':
                        acumulado = multiplicar(acumulado, num);
                        break;
                    case 'a':
                        acumulado = promediar(acumulado, num);
                        break;
                }
            }
        }
    }
    else
    {
        acumulado = 0;
    }
    return acumulado;
}

void resultado(char** matriz, char operador, int limite_inf, int posicion, int acumulado, int largo)
{
    while(limite_inf < largo)
    {
        posicion = buscar_operacion(matriz,limite_inf,largo,posicion);
        
        operador = *matriz[posicion];

        acumulado = cuenta(matriz, posicion, limite_inf, operador,acumulado);
        
        limite_inf= posicion+1;    
    }
}