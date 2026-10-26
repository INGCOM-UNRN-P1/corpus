

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40

void cargar_arreglo(int cantidad, int arreglo[]); 
void muestra_arreglo(int cantidad, int arreglo[]);
int maximo(int cantidad, int arreglo[]);
int minimo(int cantidad, int arreglo[]);
float promedio(int cantidad, int arreglo[]);
void menor_a_mayor(int cantidad, int arreglo[]);
void mayor_a_menor(int cantidad, int arreglo[]);



int main(int argc, char*argv[])
{
    
    int maximizar = 0; 
    int cantidad = 0;
    int minimizar;
    int orden_men_may = 0;
    float promediar;
    int contador  = 0;
    //int orden_men_may;
    //int orden_may_men;


    if (argc == 1)
    {
    
    printf("Ingrese tamaño del arreglo: \n");
   
    scanf("%d", &cantidad);
    
    int arreglo[SIZE];
    cargar_arreglo(cantidad, arreglo);
    muestra_arreglo(cantidad, arreglo);
    
    
    maximizar = maximo(cantidad, arreglo);
    minimizar = minimo(cantidad, arreglo);
    promediar = promedio(cantidad, arreglo);
     
    
    printf("El valor maximo es %d \n",maximizar);   
    printf("El valor minimo es %d \n",minimizar);
    printf("El promedio es %.1f \n",promediar);

    
    printf("Elementos ordenado de menor a mayor es \n");
    menor_a_mayor(cantidad, arreglo);
    
    printf("\nEl arreglo ordenado de mayor a menor es \n");
    mayor_a_menor(cantidad,arreglo);

    }

    else 
    {
    int arreglo[SIZE];
    cantidad = argc -1;

    for(contador = 0; contador< cantidad; contador++)
    {
        arreglo[contador] = atoi(argv[contador +1]);
    }
    muestra_arreglo(cantidad, arreglo);
    maximizar = maximo(cantidad, arreglo);
    minimizar = minimo(cantidad, arreglo);
    promediar = promedio(cantidad, arreglo);
    

    printf("\nEl maximo ingresado es %d \n",maximizar);   
    printf("El minimo ingresado es %d \n",minimizar);
    printf("El promedio es %.1f \n", promediar);
    printf("El arrglo ordenado de menor a mayor es: ");
    menor_a_mayor(cantidad,arreglo);
    printf("\nEl arreglo ordenado de mayor a menor es : ");
    mayor_a_menor(cantidad,arreglo);

    }
        
}




void cargar_arreglo(int cantidad, int arreglo[])
{
    int i;
    
    for (i=0; i< cantidad; i++)
    {
        printf("Ingrese valores: %d\n", i);
        scanf("%d", &arreglo[i]);
                 
    }
    
}


void muestra_arreglo(int cantidad, int arreglo[])
{
    int i;

    for(int i=0;i< cantidad;i++)
    {
        printf("Elemento numero %d = %d\n", i+1, arreglo[i]);
    }
    
}

//FUNCION QUE BUSCA EL MAXIMO ENTRE LOS ELEMENTOS DEL ARREGLO


int maximo(int cantidad, int arreglo[])
{
    int max = arreglo[0];
    int i;
    for(int i=1; i< cantidad; i++){
        if (arreglo[i] > max ){
            max = arreglo[i];
    
        }
    
    }
    
    return max;
    
}
    




int minimo(int cantidad, int arreglo[])
{
    int min = arreglo[0];
    for(int i=1; i< cantidad; i++){
        if (arreglo[i]< min){
            min = arreglo[i];
        }
    }
    return min;
    
}           

// FUNCION QUE HALLA la SUMA DE LOS VALORES DEL ARREGLO

float promedio(int cantidad, int arreglo[])
{
    float suma = 0;
    for (int i=0 ; i< cantidad; i++){
        suma+=arreglo[i];
    }
    float media = suma/cantidad;
    
}




void menor_a_mayor(int cantidad, int arreglo[])
{
    int aux = 0;
    int i = 0;
    int j = 0;

    for(i=0; i < cantidad; i++){    
        for(j=i+1; j < cantidad; j++){

            if(arreglo[i] > arreglo[j]){
                aux= arreglo[i];
                arreglo[i] = arreglo[ j];
                arreglo[j] = aux;
            }
        }
    }

    for(i=0; i < cantidad; i++)
    {
        printf("%d " , arreglo[i]);
    }
        
}



void mayor_a_menor(int cantidad, int arreglo[])
{
    int i = 0;
    int j = 0;
    int aux = 0;

    for(i=0; i<cantidad;i++)
    {
        for(j=i+1; j<cantidad;j++)
        {
            if(arreglo[i]<arreglo[j])
            {
                aux = arreglo[i];
                arreglo[i]=arreglo[j];
                arreglo[j]=aux;
            }
        }
    }
    for (i=0;i<cantidad; i++)
    {
        printf("%d ", arreglo[i]);
    }
}

                 



    

