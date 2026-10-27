
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE 50
#include "mis_funciones.h"
 
int main(int argc, char *argv[]){

    int lineas, columnas;
    
    printf("\n\n Bienvenido a 'buscaminas_0.02' \n\n  ingresar cantidad de lineas del tablero: ");

    scanf("%d",&lineas);
    
    getchar();
    
    printf("\n\n  ingresar cantidad de columnas del tablero: ");

    scanf("%d",&columnas);
    
    getchar();

    prepara_juego(lineas,columnas,NOMBRE);

    return 0;
    
}

// void prepara_juego(int lineas, int columnas){
 
    // int **tablero, **matriz_minas_a, tipo_de_mapeado;
    
    // char fila, columna; 
    
    // tablero = (int**) malloc(sizeof(int)*(lineas*columnas));
    
    // matriz_minas_a = (int**) malloc(sizeof(int)*(lineas*columnas));
    
    // for (int i; i < lineas; i++){
        
        // tablero[i] = (int*)malloc(sizeof(int)*columnas);

        // matriz_minas_a[i] = (int*)malloc(sizeof(int)*columnas);
    // }
        
    // printf("\n como desea mapear las bombas \n\n 1 = aleatorio\n\n 0 = manual\n\n ingrese: ");    
        
    // scanf("%d",&tipo_de_mapeado);
        
    // crea_tablero(tablero, lineas, columnas, tipo_de_mapeado);
  
    // minas_adyacentes(tablero, matriz_minas_a, lineas, columnas);
    
    // crea_archivo_minas(tablero, matriz_minas_a, lineas , columnas);
 
    // printf("\n\n Archivo con mapa de minas creado\n\n");
    
    // imprime_mapa(tablero, lineas, columnas);
 
    // for (int i; i < lineas; i++){
        
        // free(tablero[i]);
        
        // free(matriz_minas_a[i]);
        
    // }
    
    // free(tablero);
    
    // free(matriz_minas_a);
 
// }

// void crea_tablero(int **tablero, int lineas, int columnas ,int como){
    
    // int cuantas, donde_l, donde_c, pone_o_no;
    
    // if (como == 1){
    
        // printf("\n ingrese cantidad de bombas a ingresar aleatorias: ");
    
        // scanf("%d",&cuantas);
        
        // getchar();
    
        // for (int i = 0; i < lineas; i++){
            
            // for(int j = 0; j < columnas; j++){
                
                // pone_o_no = rand() / (RAND_MAX / 2);
                
                // if (pone_o_no == 1 && cuantas > 0){
                    
                    // tablero[rand() / (RAND_MAX / lineas)][rand() / (RAND_MAX / columnas)] = 1;
                    
                    // cuantas --;
                    
                // }
                
                // if (tablero[i][j] != 1){
                 
                    // tablero[i][j] = 0;
                 
                // }
                
            // }
            
        // }
        
    // }
    
    // else if(como == 0){
        
        // printf("\n ingrese la cantidad de bombas a ingresar: ");
        
        // scanf("%d", &cuantas);
        
        // getchar();
        
        // for(int i = 0; i<lineas; i++){
            
            // for(int j = 0; j<columnas; j++){
                
                // tablero[i][j] = 0;
     
            // }
       
        // }        
        
        // for (int i = 0; i < cuantas; i++){
        
            // imprime_mapa(tablero, lineas, columnas);
        
            // printf("\n BN %d  linea: ",i);
        
            // scanf("%d", &donde_l);
        
            // getchar();
            
            // printf("\n BN %d  columna: ",i);
        
            // scanf("%d", &donde_c);
        
            // getchar();
            
            // tablero[donde_l][donde_c] = 1;
        
        // }        
               
    // }
 
// }

// void crea_archivo_minas(int **linea_de_tablero, int **minas_adyacent, int lineas, int columnas){
    
    // FILE *minas;
    
    // int minas_adyacentes; 
     
    // minas = fopen("tablero_minas.txt", "w");
        
    // for (int i = 0; i<lineas; i++){
            
        // for (int j = 0; j < columnas; j++){
            
            // if(linea_de_tablero[i][j] == 1){
            
                // fprintf(minas, "B");
                
                // linea_de_tablero[i][j] = 9;
                
            // }
            // else if (linea_de_tablero[i][j] == 0){
                             
                // fprintf(minas, "%d", minas_adyacent[i][j]);
                
                // linea_de_tablero[i][j] = minas_adyacent[i][j];
                
            // }
        // }
        
        // fprintf(minas, "\n");
        
    // }
        
    // fprintf(minas, "\n");
            
    // fclose(minas);
                    
               
    
// }

// void imprime_mapa(int **tablero , int lineas, int columnas){
    
    // int lin, col, h = 0, k = 0;
    
    // lin = lineas + lineas + 1;
    
    // col = columnas + columnas + 1;
    
    // printf("\n    ");
    
    // for (int i = 0; i < lin; i++){
        
        // for(int j = 0; j < col; j++){
            
            // if( i % 2 == 0){
                
                // printf("|");
                
            // }
            // else if (j % 2 == 0){
                
                // printf("|");
                
            // }
            // else{
                
                // printf("%d",tablero[k][h]);
                
                // h++;
                
            // }
        // }
        
        // if (i % 2 != 0){
            
            // k ++;
            
            // h = 0;
            
        // }
        
        // printf("\n    ");
        
    // }
    
// }

// void minas_adyacentes(int **tablero_minas, int **tablero_adyacent, int lineas, int columnas){

    // int cuenta = 0;
    
    // for(int i = 0; i < lineas; i++){
            
        // for(int j = 0; j< columnas; j++){
                
            // if(tablero_minas[i][j] == 0){ 
                
                // if( i < lineas - 1 ){
                    
                    // if(1 == tablero_minas[i+1][j]){
                        // cuenta ++;
                    // }
                // }
                
                // if( i > 0){
                
                    // if(1 == tablero_minas[i-1][j]){
                        // cuenta ++;
                    // }
                // }
                
                // if( j < columnas - 1 ){
                
                    // if(1 == tablero_minas[i][j+1]){
                        // cuenta ++;
                    // }
                // }
                
                // if( j > 0 ){
                
                    // if(1 == tablero_minas[i][j-1]){
                        // cuenta ++;
                    // }
                // }
                
                // if( i < lineas - 1 && j < columnas - 1){
            
                    // if(1 == tablero_minas[i+1][j+1]){
                        // cuenta ++;
                    // }
                // }
                
                // if( i > 0 && j < columnas - 1){
                
                    // if(1 == tablero_minas[i-1][j+1]){
                        // cuenta ++;
                    // }
                // }
                
                // if( i < lineas -1 && j > 0){
                
                    // if(1 == tablero_minas[i+1][j-1]){
                        // cuenta ++;
                    // }
                // }
                
                // if (i > 0 && j > 0){
                
                    // if(1 == tablero_minas[i-1][j-1]){
                        // cuenta ++;
                    // }
                // }
                
                // tablero_adyacent[i][j] = cuenta;
            // }
            // else{
            
                // tablero_adyacent[i][j] = -1;
            
            // }
            
            // cuenta = 0;
            
        // }
        
    // }
 
// }


