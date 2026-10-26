

#include <stdio.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

int es_multiplo(int numero, int multiplo);

int main()
{
    int numero, multiplo;
    printf("Ingrese un número: \n");
    scanf("%d",&numero);
    
    printf("Ingrese el número a analizar: \n");
    scanf("%d",&multiplo);
   
    if(es_multiplo(numero,multiplo)){
        return true;}   
   else{
        return false;
    }
 
    //return 0;
}

int es_multiplo(int numero, int multiplo)
{
    int resta;
    int i;
    resta = multiplo;
        for(i=numero;i>multiplo && resta >=0;){
        resta=resta-1;
    }
    return 0;
}
