

#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 100
#define CAPACIDAD_MAXIMA (MAXIMO*2)
#define CADENA_SIN_TERMINADOR -1


char* concatenaCadenas(char* cadena1, char* cadena2, int largo1, int largo2);
char* carga_cadena(char* cadena);
void pasa_cadenas(char cadena1_estatica[], char cadena2_estatica[], char *cadena_dinamica1, char *cadena_dinamica2, int largo1, int largo2);
int largo_seguro(char* cadena, int capacidad);
char* elimina_duplicados(char* arreglo, int* tamano);
int cuenta_duplicados(char* arreglo, int largo);


int main()
{
    char cadena_estatica1[MAXIMO];
    char cadena_estatica2[MAXIMO];
    
    char *cadena_dinamica1 = NULL;
    char *cadena_dinamica2 = NULL;
    char *cadena_respuesta = NULL;
    
    int capacidad = MAXIMO;
    int largo1 = 0;
    int largo2 = 0;
    int opcion = 0;
    
    
    //Uso scanf porque no toma el \n del fgets.
    printf("Ingrese la primer cadena: ");
    scanf("%s",&cadena_estatica1);
        
    printf("Ingrese la segunda cadena: ");
    scanf("%s",&cadena_estatica2);
    
    
    printf("Ingrese 1 para concatenar cadenas\n");
    printf("Ingrese 2 para eliminar caracteres duplicados de una cadena\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    
    //Veo el largo de las cadenas para saber cuanta memoria pedir.
    largo1 = largo_seguro(cadena_estatica1, capacidad);
    largo2 = largo_seguro(cadena_estatica2, capacidad);
    
    
    //Pido memoria para las cadenas.
    cadena_dinamica1 = (char*) malloc(largo1 * sizeof(char));//Asigno memoria segun la longitud de la cadena.
    cadena_dinamica2 = (char*) malloc(largo2 * sizeof(char));//Asigno memoria segun la longitud de la cadena.
    
    if(cadena_dinamica1 == NULL || cadena_dinamica2 == NULL)
    {
        perror("Error al reservar memoria!");
    }
    else
    {
        
        //Esto pasa las cadenas a memoria dinamica
        pasa_cadenas( cadena_estatica1,  cadena_estatica2, cadena_dinamica1, cadena_dinamica2, largo1, largo2);
        
        if(opcion == 1)
        {
            cadena_respuesta = concatenaCadenas(cadena_dinamica1, cadena_dinamica2, largo1, largo2);
            
            printf("La cadena concatenada es: %s",cadena_respuesta);
            
            free(cadena_respuesta);//Libero la cadena creda en concatenaCadenas.
        }
        else if(opcion == 2)
        {
            cadena_respuesta = elimina_duplicados(cadena_dinamica1, &largo1);
            printf("La cadena sin duplicados es: %s",cadena_respuesta);
            
            free(cadena_respuesta);//Libero la memoria asignada el elimina_duplicados.
        }
 
    }
    
  
    free(cadena_dinamica1);//Libero el espacio
    free(cadena_dinamica2);
      
    
}


/**
 * La funcion concatena 2 cadenas dinamica en 1 sola.
 *  @param cadena1 es la primera cadena dinamica.
 *  @pre tiene que ser un puntero valido.
 *  @param cadena2 es la segunda cadena dinamica.
 *  @pre tiene que ser un puntero valido.
 *  @param largo1 es el largo de la primera cadena
 *  @pre es un numero entero mayor a uno
 *  @param largo2 es el largo de la segunda cadena
 *  @pre es un numero entero mayor a uno
 *  @returns retorna la cadena concatenada en memoria dinamica o NULL en caso de error.
 *  @post se espera que se copien 2 cadenas en 1 sola.
 */
 

char* concatenaCadenas(char* cadena1, char* cadena2, int largo1, int largo2)
{
    char *cadena_concatenada = NULL;
    int contador = 0;//Este contador recorre la primera cadena y la cadena concatenada
    int contador_cadena2 = 0;//Este contador recorre la cadena2

    
    int largo_concatenado = largo1 + largo2;//El largo que tiene que tener la cadena concatenada
    
    cadena_concatenada = (char*) malloc(largo_concatenado * sizeof(char));
    
    if(cadena_concatenada == NULL)
    {
        perror("Error al reservar memoria!");
    }
    else
    {
        while(contador < largo_concatenado)
        {
            
            if(contador < largo1)
            {
                cadena_concatenada[contador] = cadena1[contador];

            }
            else
            {           
                cadena_concatenada[contador] = cadena2[contador_cadena2];
                contador_cadena2++;
            }
            
            contador++;

        }
        
    }
    
    
    cadena_concatenada[contador] = '\0'; // Agregar el terminador .
    
    return cadena_concatenada;
      
}

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post se espera que se devuelva la longitud de la cadena ingresada.
 */
 
int largo_seguro(char* cadena, int capacidad)
{
    int contador = 0;
    int retorno = 0;
    
    while ((cadena [contador] != '\0') && (contador < capacidad)) //mientras no encuentra el terminador, suma la cantidad de caracteres.
    {
        contador++;//cuento los caracteres.
    }
    
    if(contador >= capacidad)
    {
        retorno = CADENA_SIN_TERMINADOR;//retorna sin terminador
    }
    else
    {
        retorno = contador;//retorna el largo de la cadena
    }
    
    return retorno;
        
}


/**
 * La funcion copia una cadena estatica a una cadena dinamica
 *  @param cadena1_estatica es la direccion de la primer cadena estatica
 *  @pre es una cadena valida
 *  @param cadena2_estatica es la direccion de la segunda cadena estatica
 *  @pre es una cadena valida
 *  @param cadena_dinamica1 es la direccion de la primer cadena dinamica
 *  @pre es un puntero valido
 *  @param cadena_dinamica2 es la direccion de la segunda cadena dinamica
 *  @pre es un puntero valido 
 *  @param largo1 es el largo de la primera cadena
 *  @pre es un numero entero mayor a uno
 *  @param largo2 es el largo de la segunda cadena
 *  @pre es un numero entero mayor a uno
 *  @post se espera que se carguen 2 cadenas estaticas a la memoria como cadenas dinamicas.
 */
 
 
void pasa_cadenas(char cadena1_estatica[], char cadena2_estatica[], char *cadena_dinamica1, char *cadena_dinamica2, int largo1, int largo2)
{
    int contador = 0;
    
    while(contador < largo1)
    {
        cadena_dinamica1[contador] = cadena1_estatica[contador];
        contador++;
    }
    
    contador = 0;
    
    while(contador < largo2)
    {
        cadena_dinamica2[contador] = cadena2_estatica[contador];
        contador++;
    }
    
    
}


/**
 * La funcion cuenta cuantas coincidencias tiene una cadena
 *  @param arreglo es la direccion de la cadena
 *  @pre es una cadena valida
 *  @param largo1 es el largo de la cadena
 *  @pre es un numero entero mayor a uno
 *  @returns retorna la cantidad de caracteres iguales que tiene la cadena.
 *  @post se espera que se cuenten la cantidad de caracteres iguales que tiene la cadena
 */
 
int cuenta_duplicados(char* arreglo, int largo)
{
    int contador = 0;
    int coincidencias = 0;
    
    while(contador < largo)
    {
        for(int i = contador + 1 ; i < largo; i++)
        {
            if(arreglo[contador] == arreglo[i])
            {
                coincidencias++;
            }
        }
        contador++;
        
    }
    
    return coincidencias;
    
    
}
 
 

/**
 * La funcion elimina los caracteres duplicados de una cadena
 *  @param cadena1 es la cadena dinamica.
 *  @pre tiene que ser un puntero valido.
 *  @param tamano es el largo de la cadena
 *  @pre es un puntero valido
 *  @returns retorna la cadena sin que se repitan caracteres.
 *  @post se espera que se devuelva una cadena sin que se repitan sus caracteres.
 */
 
 
char* elimina_duplicados(char* arreglo, int* tamano)
{
    char *cadena_limpia = NULL;
    int contador = 0;
    int contador_limpio = 0;
    int coincide = 0;
    
    int largo_limpio = (*tamano - cuenta_duplicados(arreglo, *tamano));//Veo cuantas coincidencias tiene la cadena, para saber de cuanto tiene que ser la cadena limpia
    
    cadena_limpia = (char*) malloc((largo_limpio + 1) * sizeof(char));//Le da la memoria necesaria para copiar la cadena sin los duplicados, + 1 para el terminador
    
    if(cadena_limpia == NULL)
    {
        perror("Error al reservar memoria!");
    }
    else
    {
        //Anda pero en los caracteres duplicados pone caracter desconocidos, no los borra..
        while(contador < *tamano)
        {
            coincide = 0;//Reinicio las coincidencias para contar con otra letra.
            
            for(int i = contador + 1; i < *tamano; i++)//recorre el resto de las posiciones sin contar donde esta contador
            {
                
                if(arreglo[contador] == arreglo[i])
                {
                    coincide++;//Esto cuenta si la letra coincidio con alguna otra
                    
                }
                
            }
            
            if(coincide == 0)//En caso de que no haya coincidido con otra letra, lo copia ala cadena limpia.
            {
                cadena_limpia[contador_limpio] = arreglo[contador]; 
                contador_limpio++;//El contador limpio, es el que recorre la cadena limpia
            }
            
            contador++;//paso con la segunda posicion.
        }
    }
    
    cadena_limpia[contador_limpio] = '\0';//Agrego el terminador  a la cadena limpia.
    
    return cadena_limpia;
 
}

