#include "lib.h"


int ** reservar_memoria(int filas, int columnas)
{
    int i;
    int **tablero;
    
    tablero = (int**)malloc(filas*sizeof(int*));
    
    if(tablero == NULL)
    {
        printf("Error. No se pudo reservar la memoria 1. \n");
    }
    
    for(i =0; i< filas; i++)
    {
        tablero[i] = (int*)malloc(columnas*sizeof(int));
        
        if(tablero[i] = NULL)
        {
         printf("Error. No se pudo reservar la memoria 2. \n"); 
        }
    } 
    return tablero;  
}


int ** mostrar_tablero(int **tablero_x, int filas,int columnas)
{
   int i,j;

    for(i =0; i = filas;i++)
    {
        for(j=0; j = columnas; j++)
        {
            tablero_x[i][j] = 0;
            printf("| %d |", tablero_x[i][j]);
        }            
        printf("\n---");
    }
    
    return tablero_x;
}


int ** llenar_matriz(int ** tablero_minas,int filas, int columnas, int cantidad_minas)
{
    int i,j;

    for(i =1; i < filas;i++)
    {
        for(j=1; j < columnas; j++)
        {
            printf("Cantidad_minas: %d \n", cantidad_minas);
            printf("Posicion [%d][%d].Colocar mina? Si:9 No:0 \n", i,j);
            scanf("%d", &tablero_minas[i][j]);
        } 
    }
    return tablero_minas;
}    


void guardar_matriz_cargada(FILE *p_file, int **tablero_minas,int filas, int columnas, int cantidad_minas)
{
    int i,j;
    p_file = fopen("tablero.txt", "w");
        
    if(p_file == NULL)
    {
        printf("Error al abrir el archivo <tablero.txt>. \n");
    }         
    
    fprintf(p_file,"%d", filas);
    
    fprintf(p_file, " %d", columnas);

    fprintf(p_file," %d\n", cantidad_minas);
  
    for(i =0; i = filas;i++)
    {
        for(j=0; j = columnas; j++)
        {
            fprintf(p_file," %d", tablero_minas[i][j]);           
        }
        fprintf(p_file,"\n");
    }
    
    fclose(p_file);     
    
    printf("El contenido fue escrito correctamente");      
}