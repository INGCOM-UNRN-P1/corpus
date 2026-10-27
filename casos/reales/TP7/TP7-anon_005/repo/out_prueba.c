
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int i,j; 
    int filas, columnas;
    int num_aleatorio;
    int cantidad_minas;
    
    int tablero[20][20];
    
    FILE *p_file;

    printf("\n Ingrese un numero del 1 al 25 para definir la cantidad de filas del tablero de juego.\n");
    scanf(" %d", &filas);
        
    printf("\n Ingrese un numero del 1 al 25 para definir la cantidad de columnas del tablero de juego.\n");
    scanf(" %d", &columnas);    
    
    printf(" Ingrese un numero del 1 al 17 para definir la cantidad de minas a ubicar \n");
    scanf(" %d", &cantidad_minas);
    
    printf(" filas %d \n", filas);
    printf(" columnas %d \n", columnas);
    printf(" minas %d \n", cantidad_minas);
    

  
    int k;
    int vueltas = 4;
     
    for(i =0; i< filas;i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if(vueltas >0)
            {
                printf("Posicion [%d][%d]. Colocar mina aqui?\n");
                scanf("%d",&tablero[i][j]);
                if(tablero[i][j] != 9)
                {
                    tablero[i][j] = 0;  
                }
                else
                {
                    vueltas--;
                }
            }
        }    
        printf("\n"); 
    }
 
  
   
    p_file = fopen("outprueba.txt", "w");
    
    if(p_file == NULL)
    {
        printf("Error al abrir el archivo <tablero.txt>. \n");
    }    

    fprintf(p_file,"Filas:%d \n", filas);    
    fprintf(p_file, "Columnas:%d \n", columnas);
    fprintf(p_file,"Minas: %d \n", cantidad_minas);
    fprintf(p_file,"\n");
    
    for(i = 0; i < filas;i++)
    {
        for(j= 0; j < columnas; j++)
        {
            fprintf(p_file,"%d", tablero[i][j]);           
        }
        fprintf(p_file,"\n");
    }
    
    fclose(p_file);  
    
    return 0;
}