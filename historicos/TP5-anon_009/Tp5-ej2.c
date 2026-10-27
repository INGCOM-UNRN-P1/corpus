
#include <stdio.h>
#define CADENA_LARGA -1
#define MAX_LENGTH 20



int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion); 
int copiadora(char *origen, char *destino, int capacidad_destino);

int main()
{
    //printf("El largo de la cadena es: %d\n\n", largo_cadena("Holaasd", 8));
    //printf("El largo de la cadena es: %d\n", insercion("hola", 7, "MUNDO", 3));
    char destino[MAX_LENGTH] = "Hola";
    char origen[] = "chau";
    int largo = MAX_LENGTH;
    printf("El largo de la cadena es: %d\n\n", copiadora(origen, destino, largo));
}





int largo_cadena(char *cadena, int capacidad_cadena)
{
    int contador = 0;

    for (int i = 0; i < capacidad_cadena; i++) //cuenta la cantidad de caracteres
    {
        if (cadena[i] == '\0')//chequea si termina el string, si lo hace retorna el contador
        {
            return contador;
        }
        contador = contador + 1;
    }

    return CADENA_LARGA; //Si el string no termina dentro de la capacidad de caracteres permitida, se retorno el -1 señalando el error.
    
    
}





int insercion(char *destino, int capacidad_destino, char* insertar, int posicion)
{

    int contador = 0;
    int i = 0;
    int j = 0;

    while (i <= posicion || destino[i] != '\0') //Imprime los valores de la variable destino hasta llegar al lugar de la variable posición.
    {                                           //Además, va sumando 1 al contador por cada caractér que imprime.
        printf("%c", destino[i]);
        contador = contador + 1;
        i = i + 1;
    }
    
    while (insertar[j] != '\0') //Imprime los valores de la variable insertar hasta llegar al fin y suma 1 al contador por cada caractér que imprime
    {
        printf("%c", insertar[j]);
        contador = contador + 1;
        j = j + 1;
    }

    while (destino[i] != '\0' ) //Imprime los valores de destino que falten (puede ser que no falte imprimir ninguno) y suma 1 al contador por       
    {                           // cada caractér impreso.
        printf("%c", destino[i]);
        contador = contador + 1;
        i = i + 1;
    }
    

    printf("\n");

    if(contador > capacidad_destino)// compara el contador con la capacidad de destino. Si el contador es mayor devuelve error, sino la longitud del
    {                               //string.
        return CADENA_LARGA;
    }
    else
    {
    return contador;
    }
}



int copiadora(char *origen, char *destino, int capacidad_destino) 
{
    int j;
    int i;
 
    for ( j = 0; destino[j] != '\0'; j++)
    {
        
    }
    

    for (i = 0; origen[i] != '\0'; i++)
    {
        destino[j + i] = origen[i];
    }
    
    for (int k = 0; origen[k] != '\0'; k++)
    {
        origen[k] = 0;
    }
    
    int contador = j + i;


    printf("destino ahora es: %s\n", destino);

    return contador;

    
}

