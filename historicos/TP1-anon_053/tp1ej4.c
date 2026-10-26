/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_053 
*************************/

#include <stdio.h>

int main(int argc, char *argv[])

{
    int valor;
    int multiplo;
    
    
    printf("ingrese numero mayor a 100\n");
    scanf ("%d", &valor);
    
    
    
        for (multiplo = 0; multiplo >= 7; multiplo++)
        {   
            
            if (valor % multiplo == 0)
            printf ("es multiplo de %d: si", multiplo);
                        
            
        
     
            else
        
           
            printf ("multiplo de %d:no\n", multiplo);
         
        
             return 0;
        }
}


