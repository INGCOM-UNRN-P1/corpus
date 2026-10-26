/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#define LARGO 6 

int palindromo();
 

int main()
{
    
    char lista[LARGO];
    int respuesta;
  
    printf("ingrese una palabra de  %d letras para determinar si es un palindromo (1) o no (0): \n",LARGO);
    fgets(lista,LARGO,stdin); 
    
    respuesta = palindromo(lista);   
    
    if(respuesta == 1)
    {
        printf("ES PALINDROMO!");
    }
    else
    {
        printf("NO ES PALINDROMO!");
    }
    
}


int palindromo(char lista[])
{
    int inicio = 0;
    int fin = 0 ;
    int es_palindromo = 0;
    int no_palindromo = 0;
    
    while (lista[fin] != '\0') 
    {
        fin = fin + 1; 
    }
    fin = fin - 1;  
    
    while (inicio < fin )
    {
        if(lista[inicio] == lista[fin])
        {
            inicio = inicio + 1 ; 
            fin = fin -1 ;            
        }
        else
        {
            break; 
        }
        
    }
    
    if (inicio >= fin)
    {
        es_palindromo = 1;
        return es_palindromo; 
    }
    else
    {
        return no_palindromo; 
    }
}
