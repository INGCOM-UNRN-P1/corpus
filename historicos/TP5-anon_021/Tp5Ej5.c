
#include <stdio.h>
#include <string.h>
#define MAX_COLUMNAS 100
#define MAX_LINEAS 50

int Strtok_Casero(int columnas, char *mensaje, int lineas, char mi_mensaje[columnas][lineas]);

int main(int argc, char *argv[])
{
    char mensaje[MAX_COLUMNAS], mensaje_procesado[MAX_LINEAS][MAX_COLUMNAS];

    int cantidad_lineas;

    printf("\n Ingrese su mensaje: ");
    
    fgets(mensaje,MAX_COLUMNAS,stdin);    
    
    cantidad_lineas = Strtok_Casero(MAX_COLUMNAS, mensaje, MAX_LINEAS, mensaje_procesado);  
    
    printf("\n|%s", mensaje_procesado[0]);
    printf("\n|%s", mensaje_procesado[1]);
    printf("\n|%s", mensaje_procesado[2]);
    
    
    return 0;
} 

int Strtok_Casero(int columnas, char *mensaje, int lineas, char mi_mensaje[columnas][lineas]){
       
    int j = 0, n = 0, i = 0;   
       
    for(; i<lineas;i++){
     
        for(;j<columnas; j++){
            
            if (mensaje[j] != 92 || mensaje[j+1] != 'n'){
                
                mi_mensaje[i][n] = mensaje[j];

                n++;
                
            }
            else{
                
                break;
                
            }
            
        }
    
    n = 0;
    
    j = j + 2;
    
    }
    
    printf("\n|%s funcion", mi_mensaje[0]);
    printf("\n|%s funcion", mi_mensaje[1]);
    printf("\n|%s funcion", mi_mensaje[2]);
    
    return i;
    
}



