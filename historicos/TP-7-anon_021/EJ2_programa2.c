/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NOMBRE 50

void tamanio_del_archivo(FILE *mi_archivo, int *lineas, int *columnas);

void buscaminas(FILE *arch_mapa, int lineas, int columnas);

void imprime_matriz(char **tablero, int **mascara , int lineas, int columnas);

void accion(char **tablero, int **mascara, int cordenada_a, int cordenada_b, int lineas, int columnas, int que_hacer, int *tachas);

int que_paso(char **tablero, int **mascara, int lineas, int columnas, int cant_minas);

int main(int argc, char *argv[])
{
    
    FILE *el_mapa;
    
    int lineas,columnas;
    
    char mapita[NOMBRE];
    
    do{
        
        printf("\n\n ingrese el nombre de su mapa: ");
        
        fgets(mapita,NOMBRE,stdin);
        
        for(int i = 0; i < NOMBRE; i++){

            if (mapita[i] == '\n'){
                
                mapita[i + 1] = mapita[i + 2];
                
                mapita[i] = '\0';
                
            }

        }   
        
        el_mapa = fopen(mapita, "r");
        
    }
    while (el_mapa == NULL);
    
    tamanio_del_archivo(el_mapa, &lineas, &columnas);
    
    rewind(el_mapa);
    
    buscaminas(el_mapa, lineas, columnas);
    
    fclose(el_mapa);

return 0;
}

void tamanio_del_archivo(FILE *mi_archivo, int *lineas, int *columnas){
    
    char caracter;
    
    int columnas_a, i, j;
    
    *lineas = 0;
    
    *columnas = 0;
    
    i = 0;
    
    j = 0;
    
    columnas_a = 1;
    
    while (feof(mi_archivo) == 0){
        
        caracter = fgetc(mi_archivo);

        i ++;
        
        if(caracter == '\n'){
            
            if (columnas_a == 1){

                *columnas = i - 1;
                
                columnas_a = 0;
                
            }
            
            j ++;
            
        }
    
    }
    
    *lineas = j - 1;
    
}

void buscaminas(FILE *arch_mapa, int lineas, int columnas){
    
    char **sitio_minado;
    
    int **mascara, estado_juego, cordenada_a, cordenada_b, como;
    
    int minas_en_tablero, tachas;
    
    estado_juego = 0;
    
    sitio_minado = (char**) malloc(sizeof(char*)*(lineas*columnas));
    
    mascara = (int**) malloc(sizeof(int*)*(lineas*columnas));
    
    for(int i = 0; i< lineas; i++){    
        
        sitio_minado[i] = (char*) malloc(sizeof(char)*columnas);
        
        mascara[i] = (int*) malloc(sizeof(int)*columnas);
        
        if(feof(arch_mapa) == 0){
        
            fgets(sitio_minado[i], columnas + 2 , arch_mapa);

        }
        
        for(int j = 0; j < columnas; j++){
            
            mascara[i][j] = 0;
            
        }
        
    }
    
    minas_en_tablero = 0;
    
    for(int i = 0; i< lineas; i++){
        
        for(int j = 0; j< columnas; j++){
            
            if (sitio_minado[i][j] == 'B'){
                
                minas_en_tablero ++;
                
            }
            
        }
        
    }
    
    tachas = minas_en_tablero;

    printf("\n Cuidado un grupo de terroristas a infectado el edificio con bombas \n\n");
    printf("Deberas dar con las cordenadas de las bombas para salvar a los civiles\n\n   contamos contigo\n ");
    
    while(estado_juego == 0){
        
        printf("\n     Minas plantadas:(%d):", minas_en_tablero);
 
        imprime_matriz(sitio_minado, mascara, lineas, columnas);

        do{            
            printf("\n    1 para descubrir casilla\n    0 para marcar/desmarcar casilla: ");
            
            scanf("%d", &como);
            
            getchar();
        }
        while (como < 0 || como > 1);
        
        if(como == 0){
            
            printf("\n   Tachas restantes: (%d)",tachas);
            
        }
        
        do{       
            printf("\n    Nro de piso (min 0 - max %d): ",lineas - 1);
            
            scanf("%d", &cordenada_a);
            
            getchar();
        }
        while (cordenada_a < 0 || cordenada_a >= lineas);
            
        do{
            printf("\n\n    Nro de habitacion (min 0 - max %d): ", columnas - 1);
            
            scanf("%d", &cordenada_b);
            
            getchar();
        }
        while ( cordenada_b < 0 || cordenada_b >= columnas );

        cordenada_a = lineas - 1 - cordenada_a;
        
        accion(sitio_minado, mascara, cordenada_a, cordenada_b, lineas, columnas, como, &tachas);

        estado_juego = que_paso(sitio_minado, mascara, lineas, columnas, minas_en_tablero);
        
    }
    
    if (estado_juego == -1){
        
        for(int i = 0; i < lineas; i++){
            
            for(int j = 0; j < columnas; j++){
                
                mascara[i][j] = 1;
                
            }
            
        }
        
        imprime_matriz(sitio_minado, mascara, lineas, columnas);
        
        printf("\n\n    PERDISTE\n\n   mejor suerte la proxima, murieron %d civiles inocentes por tu error\n", (lineas * columnas) - minas_en_tablero);

    }
    else if (estado_juego == 1){
        
        imprime_matriz(sitio_minado, mascara, lineas, columnas);
        
        printf("\n\n           GANASTEE\n\n            gracias por jugar \n\n");
    }
   
 
    for (int i = 0; i < lineas; i++){
        
        free(sitio_minado[i]);
        
        free(mascara[i]);
        
    }
    
    free(mascara);
    
    free(sitio_minado);
    
}

void imprime_matriz(char **tablero, int **mascara , int lineas, int columnas){
    
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

                if(mascara[k][h] == 0){
                
                    printf("-");
               
                }
                else if (mascara[k][h] == 1){
           
                    printf("%c",tablero[k][h]);

                }
                else if (mascara[k][h] == 2){
                
                    printf("X");
                
                }

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

void accion(char **tablero, int **mascara, int cordenada_a, int cordenada_b, int lineas, int columnas,  int que_hacer, int *tachas){

    if(que_hacer == 1){

        if(tablero[cordenada_a][cordenada_b] == '0' && mascara[cordenada_a][cordenada_b] == 0){
            
            mascara[cordenada_a][cordenada_b] = 1;
            
            if( cordenada_a < lineas - 1 ){
                        
                accion(tablero,mascara,cordenada_a + 1,cordenada_b,lineas,columnas,1, tachas);
                        
            }
                    
            if( cordenada_a > 0){
                    
                accion(tablero,mascara,cordenada_a - 1,cordenada_b,lineas,columnas,1, tachas);
                       
            }
                    
            if( cordenada_b < columnas - 1 ){
                    
                accion(tablero,mascara,cordenada_a,cordenada_b + 1,lineas,columnas,1, tachas);
                       
            }
                    
            if( cordenada_b > 0 ){
                    
                accion(tablero,mascara,cordenada_a ,cordenada_b - 1,lineas,columnas,1, tachas);
                        
            }
                    
            if( cordenada_a < lineas - 1 && cordenada_b < columnas - 1){
                
                accion(tablero,mascara,cordenada_a + 1,cordenada_b + 1,lineas,columnas,1, tachas);
                       
            }
                    
            if( cordenada_a > 0 && cordenada_b < columnas - 1){
                    
                accion(tablero,mascara,cordenada_a - 1,cordenada_b + 1,lineas,columnas,1, tachas);    
                        
            }
                    
            if( cordenada_a < lineas -1 && cordenada_b > 0){
                    
                accion(tablero,mascara,cordenada_a + 1,cordenada_b - 1,lineas,columnas,1, tachas);       
                       
            }
                    
            if (cordenada_a > 0 && cordenada_b > 0){
                    
                accion(tablero,mascara,cordenada_a - 1,cordenada_b - 1,lineas,columnas,1, tachas);      
                      
            }    
            
        }
        else if (tablero[cordenada_a][cordenada_b] > 0 && mascara[cordenada_a][cordenada_b] == 0){
            
            mascara[cordenada_a][cordenada_b] = 1;
            
        }
        
    }
    else if (que_hacer == 0){
      
        if (mascara[cordenada_a][cordenada_b] == 2){

            mascara[cordenada_a][cordenada_b] = 0;
            
            *tachas = *tachas + 1;
            
        }
        else if(mascara[cordenada_a][cordenada_b] == 0 && *tachas > 0){
           
            mascara[cordenada_a][cordenada_b] = 2;
            
            *tachas = *tachas - 1;
 
        }
        else if(mascara[cordenada_a][cordenada_b] == 1){
            
            mascara[cordenada_a][cordenada_b] = 1;
    
        }
   
    }
     
}

int que_paso(char **tablero, int **mascara, int lineas, int columnas, int cant_minas){
    
    int perdiste_ganaste = 0 , aciertos = 0;
    
    for(int i = 0; i < lineas; i++){
        
        for(int j = 0; j < columnas; j++){
            
            if(mascara[i][j] == 1 && tablero[i][j] == 'B'){
                
                perdiste_ganaste = -1;
                
                aciertos = 0;
                
                break;
                
            }
            else if(mascara[i][j] == 2 && tablero[i][j] == 'B'){
                
                aciertos ++;
                
            }
            
        }
        
    }
    
    if (aciertos == cant_minas){
        
        perdiste_ganaste = 1;
        
    }
    
    return perdiste_ganaste;
}

