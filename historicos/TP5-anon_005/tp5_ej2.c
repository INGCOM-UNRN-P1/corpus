/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Agostina Biagini - anon_005 en Github
Ejercicio 2 - Strings seguros   
*************************/

#include <stdio.h>
#include <stdlib.h>

#define CADENA_CORTA -1
#define CADENA_LARGA -2
#define CADENA_VACIA -3
#define POSICION 9
#define CAP_CADENA 50
#define MAX_COPIA 17

int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char *cadena_destino, char* cadena_origen, int posicion, int capacidad_cadena);
int copiadora(char *insertar, char *cadena_destino, int capacidad_cadena);
int limpiadora(char *limpiar, char *limpia, int capacidad_cadena);
int inversor(char *invertir, char * en, int capacidad_cadena);
int compara(char * primera, char * segunda);
int es_palindromo(char * palindromo, int largo);

int main(int argc, char *argv[])
{
    int capacidad_cadena = CAP_CADENA;
    int largo_origen, largo_destino, largo_insertado, largo_copia;
    int largo_limpia,inverso,largo_inverso, largo, comp, es_pal;
    int posicion = POSICION;
  
    char cadena_origen[] = "\0";
    char cadena_destino[] = "Probando strings seguros";
    char insertar[] = "insertar";
    char limpiar[]= "019+aYG#Be\0";
    char limpia[]= "aaaaaaaa";
    char en[] = "cadena con contenido que voy a eliminar";
    char invertir[] = "probando";
    char primera[]= "abece";
    char segunda[] ="efege";
    char palindromo[]="neuquen";
    
    //EJERCICIO LARGO DE CADENA SEGURA
    
    largo_origen = largo_cadena(cadena_origen, capacidad_cadena);
    largo_destino = largo_cadena(cadena_destino, capacidad_cadena);
    
    printf("\n Largo cadena origen: %d", largo_origen);
    if(largo_origen == CADENA_VACIA)
    {
        printf(" -> Cadena vacia");
    }
    printf("\n Largo cadena destino: %d", largo_destino);
    if(largo_destino == CADENA_VACIA)
    {
        printf(" -> Cadena vacia \n");
    }
    
    //INSERCION DE CADENAS 
    
    printf("\n \n Cadena a insertar: <%s> \n", insertar);
    printf(" Cadena destino: <%s> \n", cadena_destino);
    printf(" Posicion: %d \n", posicion);
    
    largo_insertado = insercion(cadena_destino, insertar, posicion, capacidad_cadena);

    if(largo_insertado == CADENA_LARGA)
    {
        printf(" -> Error. La cadena a insertar es demasiado larga \n");
    }
    else
    {
        printf("\n Largo destino: %d", largo_destino);
        printf("\n Nuevo largo cadena destino: %d", largo_insertado);
    }
    
    //COPIA DE CADENAS
    
    printf("\n\n Cadena a copiar: <%s> \n", insertar);
    printf(" Cadena destino: <%s> \n", cadena_destino);
    largo_copia = copiadora(insertar, cadena_destino, capacidad_cadena); 
    
    if(largo_copia == CADENA_VACIA)
    {
        printf(" -> Cadena a copiar vacía\n");    
    }
    else if(largo_copia == CADENA_LARGA)
    {
        printf(" -> Error. Cadena a insertar es mas larga que cadena de destino\n"); 
    }
    else
    {
        printf(" Largo de la cadena copiada: %d", largo_copia);
    }
    
    // LIMPIEZA DE CADENA
    
    printf("\n \n Cadena a limpiar: <%s> \n", limpiar);
    largo_limpia = limpiadora(limpiar, limpia,capacidad_cadena);
    printf(" Cadena limpia: <%s> \n", limpia);
    if(largo_limpia == CADENA_VACIA)
    {
        printf(" -> Cadena vacía\n");
    }
    else
    {
        printf(" Largo cadena limpia: %d", largo_limpia);
    }
    
    //INVERSOR DE CADENA
    
    printf("\n\n Cadena a invertir: <%s> \n",invertir);
    
    inverso = inversor(invertir,en,capacidad_cadena);
    printf(" Cadena invertida: <%s> \n",en);
    
    // COMPARACION DE CADENAS
    
    printf("\n Primer cadena a comparar: <%s> \n", primera);
    printf(" Segunda cadena a comparar: <%s> \n", segunda);    
    comp = compara(primera, segunda);
    
    // CADENA PALINDROMO
    
    largo = largo_cadena(palindromo, capacidad_cadena);
    es_pal = es_palindromo(palindromo,largo);
    if(es_pal == 0)
    {
        printf("VERDADERO. ES PALINDROMO \n");
    }
    else
    {
        printf("FALSO. NO ES PALINDROMO \n");
    }
    
    return 0;
}

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i = 0;
    int largo = 0; 
    
    while(i < capacidad_cadena)
    {
        if(cadena[i] == '\0')
        {
            largo = i;
            if(largo == 0)
            {
                return CADENA_VACIA;
            }
            else
            {
                return largo;    
            }
        }
        else
        {
            largo++;
        }
        i++;
    }
    return largo;
}

int insercion(char *cadena_destino, char* insertar, int posicion, int capacidad_cadena)
{
    int i;
    int largo_i = largo_cadena(insertar, capacidad_cadena);
    int largo_d = largo_cadena(cadena_destino, capacidad_cadena);
    int largo = largo_d + largo_i+1;
    int largo_tot;
    char aux[largo];
    
    if(largo_i <= capacidad_cadena - posicion)
    {
        for(i = 0;i < posicion; i++)
        {
            aux[i] = cadena_destino[i];
        }
        for(i = posicion; i< posicion + largo_i+1; i++)
        {
            aux[i] = insertar[i-posicion];
        }
        for(i = posicion + largo_i+1; i < largo; i++)
        {
            aux[i] = cadena_destino[i-largo_i-1];
        }      
        printf(" La cadena resultante es: <");
        for(i = 0; i < largo; i++)
        {
            printf("%c", aux[i]);
        } 
        printf(">");
        largo_tot = largo_cadena(aux,capacidad_cadena);
        return largo;
    }
    else
    {
        return CADENA_LARGA;
    }
}

int copiadora(char *insertar, char *cadena_destino, int capacidad_cadena)
{
    int i;
    int largo_insertar,largo;
    largo_insertar = largo_cadena(insertar, capacidad_cadena);
    
    if(largo_insertar == 0)
    {
        return CADENA_VACIA;
    }
    else if(largo_insertar == capacidad_cadena)
    {
        return CADENA_LARGA;
    }
    else
    {
        for(i = 0; i < largo_insertar +1; i++)
        {
            cadena_destino[i] = insertar[i];

        }
        printf(" La nueva cadena destino es: <%s> \n", cadena_destino);
        insertar = '\0';
        printf(" La nueva cadena a copiar es: <%s> \n", insertar);
    }    
    largo = largo_cadena(cadena_destino, capacidad_cadena);
    
    return largo;
}

int limpiadora(char *limpiar, char *limpia, int capacidad_cadena)
{
    int i,j;
    int salto = 0;
    int largo_d = largo_cadena(limpiar, capacidad_cadena);
    int largo_o;
    
    j=0;
    
    while(limpia[j]!='\0')
    {
        for(i=0; i<largo_d; i++)
        {
            if(((limpiar[i] >= 48)&& (limpiar[i] <= 57))||((limpiar[i] >= 65)&& (limpiar[i] <=90))||((limpiar[i] >= 97)&& (limpiar[i] <=122))||(limpiar[i] =='\0'))
            {
                limpia[j] = limpiar[i]; 
                j++;
            }
        }
    }
    largo_o = largo_cadena(limpia, capacidad_cadena);
    if(largo_o == 0)
    {
        return CADENA_VACIA;
    }
    else
    {
        return(largo_o);
    }        
}

int inversor(char *invertir, char * en, int capacidad_cadena)
{
    int i;
    int largo_o = largo_cadena(invertir, capacidad_cadena);
    int largo_d = largo_cadena(en, capacidad_cadena);
    int largo_t;
    
    if(largo_d < largo_o)
    {
        return CADENA_CORTA;
    }
    else
    {
        en[largo_o]='\0';
        
        for(i=0; i <largo_o;i++)
        {
            en[largo_o-i-1]=invertir[i];
        }
        
        largo_t = largo_cadena(en, capacidad_cadena);
        return largo_t;
    }
}

int compara(char * primera, char * segunda)
{
    int i=0;
    int vueltas=0;
    
    if(primera[i] == '\0')
    {
        printf("\n La primera cadena esta vacia\n\n");
    }
    else if(segunda[i] == '\0')
    {
        printf("\n La segunda cadena esta vacia\n\n");    
    }
    else
    {
        if((primera[i] >= 97 )&&(primera[i] <= 122 )&&(segunda[i] >= 97 )&&(segunda[i] <= 122 ))
        {
            while((primera[i]!='\0')&&(segunda[i]!='\0'))
            {
                printf("\n[%d] -> primera: %c, segunda: %c \n\n", i, primera[i], segunda[i]);
                if(primera[i] > segunda[i])
                {
                    printf("\n 1: la primera cadena va despues que la segunda \n\n");
                    return 1;
                }
                else if (primera[i] < segunda[i])
                {
                    printf("\n -1: la primera cadena va antes que la segunda \n\n");
                    return -1;
                }
                else
                {
                    i++;
                    vueltas++;
                }
                if((primera[vueltas]=='\0')&&(segunda[vueltas]=='\0')&&(primera[vueltas] == segunda[vueltas]))
                {
                    printf("\n 0: Las cadenas son iguales \n\n");
                    return 0;
                }
            }
        }
        else
        {
            printf("\n Error. La cadena no contiene solo minusculas \n\n");
        }
    }
}

int es_palindromo(char * palindromo, int largo)
{
    int i;
    int cantidad = 0;
    int fin = 0;
    
    for(i=0;i<largo;i++)
    {
        printf("[%c] - [%c]\n", palindromo[i], palindromo[largo-i-1]);
        if(palindromo[i] == palindromo[largo-i-1])
        {
            cantidad++;
        }
        if(palindromo[i] == '\0')
        {
            fin++;
        }
    }
    
    if(fin == 0)
    {
        printf("\n Error. No se encuentra caracter de fin de cadena \n");
    }
    
    if(cantidad == largo)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}