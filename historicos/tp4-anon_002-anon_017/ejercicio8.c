

#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1 //codigo de error
#define ERROR_POSICION -2
#define MAXIMO 20
#define CAPACIDAD_MAX 40 

char* busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda);//Esto retorna un puntero a char?
int largo_seguro(char cadena[], int capacidad);


int main()
{
    char cadena[CAPACIDAD_MAX];//cadena en la que se busca
    char cadena_busqueda[CAPACIDAD_MAX];//Cadena que se va a buscar.
    int capacidad_cadena = MAXIMO;
    int capacidad_busqueda = MAXIMO;
    int errores = 0;
    char *retorno = NULL;
    
    printf("Ingrese una cadena: ");
    fgets(cadena, MAXIMO, stdin);
    
    printf("Ingrese lo que se va a buscar de la cadena: ");
    fgets(cadena_busqueda, MAXIMO, stdin);
    
    retorno = busqueda( cadena, capacidad_cadena, cadena_busqueda, capacidad_busqueda);
    
    printf("%s", retorno);
      
}




int largo_seguro(char cadena[], int capacidad)
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



 

char* busqueda(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda)
{
    int error_1 = 0; //Esto es para ver que las cadenas tengan terminadores.
    int error_2 = 0; //
    char *retorno = NULL;
    int contador = 0;
    
    char *ptr_cadena = cadena;//Puntero que tiene la primera posicion de la cadena.
    char *ptr_busqueda = busqueda; //Puntero que tiene la primera posicion de busqueda.
    
    error_1 = largo_seguro(cadena, capacidad_cadena);
    error_2 = largo_seguro(busqueda, capacidad_busqueda);
    
    if((error_1 != CADENA_SIN_TERMINADOR) || (error_2 != CADENA_SIN_TERMINADOR))//Si no tiene terminador, no sigue
    {
        while(*ptr_cadena != capacidad_cadena) //Esto recorre la cadena 
       {
            //Si la encuentra, la cadena de busqueda, va a llegar al final 
            
            if(*ptr_cadena == *ptr_busqueda) //Compara los valores de las cadenas
            {
                *ptr_busqueda = *ptr_busqueda + 1;//Esto aumenta para ver hasta donde esta de la cadena. 
            }
            else
            {
                //si no lo encuentra, tiene que volver a comparar, entonces tengo que reiniciar el valor del puntero de busqueda.
                //Esto lo hago por que si hay una coincidencia, pero no toda, ya no vale y hay que volver a comparar desde 0.
                ptr_busqueda = busqueda;//Empieza en la posicion de inicio de la cadena.
            }
            
           *ptr_cadena = *ptr_cadena + 1; //Esto aumenta por que es lo que recorre la cadena.
           
       }
    }
    
    if(*ptr_busqueda == '\0')
    {
        retorno = cadena;//Si recorrio la cadena completa, la cadena esta dentro de la otra.
    }

    return retorno;
    
}
