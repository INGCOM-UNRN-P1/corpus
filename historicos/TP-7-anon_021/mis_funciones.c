
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE 50
#include "mis_funciones.h"

void prepara_juego(int lineas, int columnas, int largo_arch_salida){
 
    int **tablero, **matriz_minas_a, tipo_de_mapeado;
    
    char fila, columna; 
    
    tablero = (int**) malloc(sizeof(int)*(lineas*columnas));
    
    matriz_minas_a = (int**) malloc(sizeof(int)*(lineas*columnas));
    
    for (int i; i < lineas; i++){
        
        tablero[i] = (int*)malloc(sizeof(int)*columnas);

        matriz_minas_a[i] = (int*)malloc(sizeof(int)*columnas);
    }
    
    do {
    
        printf("\n como desea mapear las bombas \n\n\t 1 = aleatorio\n\n\t 0 = manual\n\n\t ingrese: ");    
            
        scanf("%d",&tipo_de_mapeado);
        
        getchar();
        
    }
    while (tipo_de_mapeado < 0 || tipo_de_mapeado > 1);

    crea_tablero(tablero, lineas, columnas, tipo_de_mapeado);
  
    minas_adyacentes(tablero, matriz_minas_a, lineas, columnas);
    
    crea_archivo_minas(tablero, matriz_minas_a, lineas , columnas, largo_arch_salida);
 
    printf("\n\n Archivo con mapa de minas creado\n\n");
    
    imprime_mapa(tablero, lineas, columnas);
 
    for (int i; i < lineas; i++){
        
        free(tablero[i]);
        
        free(matriz_minas_a[i]);
        
    }
    
    free(tablero);
    
    free(matriz_minas_a);
 
}

void crea_tablero(int **tablero, int lineas, int columnas ,int como){
    
    int cuantas, donde_l, donde_c, pone_o_no;
    
    do{ 
        printf("\n ingrese cantidad de bombas a ingresar (min 0 | max %d): ", lineas * columnas);
        
        scanf("%d",&cuantas);
            
        getchar();
    }
    while(cuantas < 0 || cuantas > (lineas * columnas));
    
    if (como == 1){
    
        for (int i = 0; i < lineas; i++){
            
            for(int j = 0; j < columnas; j++){
                
                pone_o_no = rand() / (RAND_MAX / 2);
                
                if (pone_o_no == 1 && cuantas > 0){
                    
                    tablero[rand() / (RAND_MAX / lineas)][rand() / (RAND_MAX / columnas)] = 1;
                    
                    cuantas --;
                    
                }
                
                if (tablero[i][j] != 1){
                 
                    tablero[i][j] = 0;
                 
                }
                
            }
            
        }
        
    }
    
    else if(como == 0){
        
        for(int i = 0; i<lineas; i++){
            
            for(int j = 0; j<columnas; j++){
                
                tablero[i][j] = 0;
     
            }
       
        }        
        
        for (int i = 0; i < cuantas; i++){
        
            imprime_mapa(tablero, lineas, columnas);
        
            do{
        
            printf("\n BombaNro %d  linea (min = 0 y max = %d): ",i, lineas -1);
        
            scanf("%d", &donde_l);
        
            getchar();
            
            }
            while(donde_l < 0 || donde_l > lineas - 1);
            
            do{
                printf("\n BombaNro %d  columna (min = 0 y max = %d): ", i, columnas - 1);
            
                scanf("%d", &donde_c);
            
                getchar();
            }
            while (donde_c < 0 || donde_c > columnas - 1);
            
            tablero[donde_l][donde_c] = 1;
        
        }        
               
    }
 
}

void crea_archivo_minas(int **linea_de_tablero, int **minas_adyacent, int lineas, int columnas, int tamanio_salida){
    
    FILE *minas;
    
    int minas_adyacentes; 
    
    char *salida;
    
    salida = (char*) malloc(sizeof(char)*tamanio_salida);
     
    printf("\n\t Que nombre desea darle al mapa\n\t ingresar: "); 
     
    fgets(salida,tamanio_salida,stdin);
        
    for(int i = 0; i < tamanio_salida; i++){

        if (salida[i] == '\n'){
                
            salida[i + 1] = salida[i + 2];
                
            salida[i] = '\0';
                
        }

    } 
    
    strcat(salida,".txt");
     
    minas = fopen(salida, "w");
        
    for (int i = 0; i<lineas; i++){
            
        for (int j = 0; j < columnas; j++){
            
            if(linea_de_tablero[i][j] == 1){
            
                fprintf(minas, "B");
                
                linea_de_tablero[i][j] = 9;
                
            }
            else if (linea_de_tablero[i][j] == 0){
                             
                fprintf(minas,"%d", minas_adyacent[i][j]);
                
                linea_de_tablero[i][j] = minas_adyacent[i][j];
                
            }
        }
        
        fprintf(minas,"\n");
        
    }
            
    fclose(minas);
                    
    free(salida);           
    
}

void imprime_mapa(int **tablero , int lineas, int columnas){
    
    int lin, col, h = 0, k = 0;
    
    lin = lineas + lineas + 1;
    
    col = columnas + columnas + 1;
    
    printf("\n    ");
    
    for (int i = 0; i < lin; i++){
        
        for(int j = 0; j < col; j++){
            
            if( i % 2 == 0){
                
                printf("|");
                
            }
            else if (j % 2 == 0){
                
                printf("|");
                
            }
            else{
                
                printf("%d",tablero[k][h]);
                
                h++;
                
            }
        }
        
        if (i % 2 != 0){
            
            k ++;
            
            h = 0;
            
        }
        
        printf("\n    ");
        
    }
    
}

void minas_adyacentes(int **tablero_minas, int **tablero_adyacent, int lineas, int columnas){

    int cuenta = 0;
    
    for(int i = 0; i < lineas; i++){
            
        for(int j = 0; j< columnas; j++){
                
            if(tablero_minas[i][j] == 0){ 
                
                if( i < lineas - 1 ){
                    
                    if(1 == tablero_minas[i+1][j]){
                        cuenta ++;
                    }
                }
                
                if( i > 0){
                
                    if(1 == tablero_minas[i-1][j]){
                        cuenta ++;
                    }
                }
                
                if( j < columnas - 1 ){
                
                    if(1 == tablero_minas[i][j+1]){
                        cuenta ++;
                    }
                }
                
                if( j > 0 ){
                
                    if(1 == tablero_minas[i][j-1]){
                        cuenta ++;
                    }
                }
                
                if( i < lineas - 1 && j < columnas - 1){
            
                    if(1 == tablero_minas[i+1][j+1]){
                        cuenta ++;
                    }
                }
                
                if( i > 0 && j < columnas - 1){
                
                    if(1 == tablero_minas[i-1][j+1]){
                        cuenta ++;
                    }
                }
                
                if( i < lineas -1 && j > 0){
                
                    if(1 == tablero_minas[i+1][j-1]){
                        cuenta ++;
                    }
                }
                
                if (i > 0 && j > 0){
                
                    if(1 == tablero_minas[i-1][j-1]){
                        cuenta ++;
                    }
                }
                
                tablero_adyacent[i][j] = cuenta;
            }
            else{
            
                tablero_adyacent[i][j] = -1;
            
            }
            
            cuenta = 0;
            
        }
        
    }
 
}


