
 
#include <stdio.h>
#include <string.h>
#define CADENA_CORTA -1
#define TAMANIO_CADENA 20

int largo_cadena(char *cadena, int capacidad_cadena)
{
   int contador = 0;
   
   while(cadena[contador] != '/0')
   {
       
       contador = contador + 1;
       
    }   
    
    return contador;

}



int inversor(char* origen, char* destino, int capacidad_destino)
{
    int j,i, x;
    char resultado;
    int largo = TAMANIO_CADENA;
    
    
    x = strlen(origen);
    if(x <= capacidad_destino)
    {        
        for(i=0; i< largo; i++)
        {
            for(j=largo; j>0; j--)
            {
               
               destino[i] = origen[j];
               
            }
        }
    }
    else
    {
        return CADENA_CORTA;
    }
    
    return destino;
}




int es_palindromo(char *cadena, int largo)
{
    int j,i;
    char true[] = "VERDADERO";
    char false[] = "FALSO";
    
    for(i=0; i< largo; i++)
    {
        for(j=largo; j>0; j--)
        {
           
           if(cadena[i] == cadena[j])
           {
               
               
           }
           else
           {
               
               return false;  
               
           }
 
        }
    }
      
    return true;
}


int main(int argc, char *argv[])
{
    char palindromo;
    char cadena[] = "Neuquen";
    char origen[TAMANIO_CADENA];
    char destino[TAMANIO_CADENA];
    int capacidad_destino;
    int capacidad_cadena;
    int largo;
    int largocadena;
    char inversorf;
    largo = strlen(cadena);
    


    largocadena = largo_cadena(cadena[TAMANIO_CADENA], capacidad_cadena);
    inversorf = inversor(origen[TAMANIO_CADENA],destino[TAMANIO_CADENA], capacidad_destino);
    palindromo = es_palindromo(cadena[largo], largo);
    printf("%s", palindromo);
    
}








