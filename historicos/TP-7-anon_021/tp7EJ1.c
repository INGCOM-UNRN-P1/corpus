
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NOMBRE 20

int tamanio_del_archivo(FILE *mi_archivo);

void procesador_de_archivo(FILE *mi_archivo, int tamanio);

int suma(int *numeros, int resul, int cantidad_num);

int resta(int *numeros, int resul, int cantidad_num);

int promedio(int *numeros, int resul, int cantidad_num);

int multiplicacion(int *numeros, int resul, int cantidad_num);

int main(int argc, char *argv[])
{

    FILE *el_archivo;   
    
    char name[NOMBRE];
    
    printf("\n ------------------------------------------------------");
    
    printf("\n |Ingrese el nombre del archivo con las instrucciones |");
    
    printf("\n |                                                    |\n |archivo por defecto 'ej1.txt'                       |");
    
    printf("\n |                                                    |\n | nombre archivo: ");
   
    fgets(name, NOMBRE, stdin);
    
    int tamano;
    
    for(int i = 0; i < NOMBRE; i++){

        if (name[i] == '\n'){
            
            name[i + 1] = name[i + 2];
            
            name[i] = '\0';
            
        }

    }   
    
    el_archivo = fopen(name,"r");
    
    if (el_archivo == NULL){
        
        printf("ERROR 115: archivo no encontrado");
        
    }
    else{
        
        tamano = tamanio_del_archivo(el_archivo);
        
        rewind(el_archivo);
        
        procesador_de_archivo(el_archivo, tamano);    

        fclose(el_archivo);
        
        printf(" |                                                    |\n");
        
        printf(" |archivo con las respuestas exitosamente generado    |\n");
        
        printf(" ------------------------------------------------------");
        
    }
    
    return 0;
    
}

int tamanio_del_archivo(FILE *mi_archivo){
   
    int i = 0;
   
    while (feof(mi_archivo) == 0){
        
        fgetc(mi_archivo);   
        
        i ++;
    
    }   
    
    return i;
    
}

void procesador_de_archivo(FILE *mi_archivo, int tamanio){
        
    FILE *archi_result;    
        
    int *lista_numerica, numero, i, resultado, cant_n_usados, operaciones;
    
    int ultimo_r,archivo_creado = 0;
    
    char numero_char[7];
    
    operaciones = 1;
    
    cant_n_usados = 0;
    
    resultado = 0;
    
    ultimo_r = 0;
    
    i = 0;
    
    lista_numerica = (int*)malloc(sizeof(int)*tamanio);
    
    while (feof(mi_archivo) == 0){

        if (tamanio >= 7){

            fgets(numero_char, 7,mi_archivo); 
            
            tamanio = tamanio - 7;
            
        }    
        else{
            
            fgets(numero_char, tamanio,mi_archivo);
            
        }
    
        if (numero_char[0] != '+' && numero_char[0] != '-' && numero_char[0] != 'a' && numero_char[0] != '*' && numero_char[0] != '='){
        
            numero = atoi(numero_char);               
            
            lista_numerica[i] = numero;
            
        }   
        else if (isdigit(numero_char[1]) || strlen(numero_char) <= 2 || (strlen(numero_char) >= 2 && numero_char[0] == numero_char[1])){
            
            if (numero_char[0] != '-' && numero_char[0] != 'a' && numero_char[0] != '*' && numero_char[0] != '='){ 
                
                resultado = suma(lista_numerica + cant_n_usados,resultado , i - cant_n_usados);
                
                cant_n_usados = i + 1;
                
                ultimo_r = 0;

            }  
            else if (numero_char[0] != 'a' && numero_char[0] != '*' && numero_char[0] != '='){  
                
                if(numero_char[0] == '-' && isdigit(numero_char[1])){
                    
                    numero = atoi(numero_char);
                
                    lista_numerica[i] = numero;
                    
                }
                else{
                    
                    resultado = resta(lista_numerica + cant_n_usados, resultado, i - cant_n_usados);
                    
                    cant_n_usados = i + 1;
                    
                    ultimo_r = 0;

                }
                
            }
            else if (numero_char[0] != '*' && numero_char[0] != '='){ 
                
                resultado = promedio(lista_numerica + cant_n_usados,resultado , i - cant_n_usados);
                
                cant_n_usados = i + 1;
                
                ultimo_r = 0;

            }
            else if (numero_char[0] != '='){ 
                
                resultado = multiplicacion(lista_numerica + cant_n_usados,resultado , i - cant_n_usados);
                
                cant_n_usados = i + 1;
                
                ultimo_r = 0;
                
            }
            else if (numero_char[0] == '=' && ultimo_r == 0){ 
                
                if (archivo_creado == 0){
                
                    archi_result = fopen("Resultados.txt", "w");
                    
                    fprintf(archi_result, "\n Resultado de la operacion n%d = %d", operaciones, resultado);
                    
                    fclose(archi_result);
                    
                    archivo_creado = 1;
                    
                    resultado = 0;
                    
                    operaciones ++;
                    
                }               
                else if (archivo_creado == 1){
                    
                    archi_result = fopen("Resultados.txt", "a");
                    
                    fprintf(archi_result, "\n Resultado de la operacion n%d = %d", operaciones, resultado);
                    
                    fclose(archi_result);
                    
                    resultado = 0;
                    
                    operaciones ++;
                    
                }
                
                ultimo_r = 1;
                
            }
           
        }
        else{
            
            printf("\n ERROR 302: problema con las instrucciones ");
          
            exit(1);
            
        }
        
        
        i++;
    
    }   
    
    free(lista_numerica);
    
}

int suma(int *numeros,int resul, int cantidad_num){
    
    int resultado_f = resul;
    
    for(int i = 0; i < cantidad_num; i++){
        
        if ( -65536 < numeros[i] && numeros[i] < 65536){
        
            resultado_f = resultado_f + numeros[i];
        
        }
    }
    
    return resultado_f;

}

int resta(int *numeros,int resul, int cantidad_num){
    
    int resultado_f = resul;
    
    for(int i = 0; i < cantidad_num; i++){
        
        if ( -65536 < numeros[i] && numeros[i] < 65536){  
            
            resultado_f = resultado_f - numeros[i];
            
        }        
    }
    
    return resultado_f;
  
}

int promedio(int *numeros, int resul, int cantidad_num){
    
    int cuantos_n, resultado_f = resul;
    
    cuantos_n = 0;
    
    for(int i = 0; i < cantidad_num; i++){

        if ( -65536 < numeros[i] && numeros[i] < 65536){
        
            resultado_f = resultado_f + numeros[i];
            
            cuantos_n ++;
                
        }   
        
    }
    
    resultado_f = resultado_f / cuantos_n;
    
    return resultado_f;

    
}

int multiplicacion(int *numeros, int resul, int cantidad_num){
   
    int resultado_f;
    
    if (resul == 0){
    
        resultado_f = 1;
    
    }
    else{
        
        resultado_f = resul;
        
    }
    
    for(int i = 0; i < cantidad_num; i++){
        
        if ( -65536 < numeros[i] && numeros[i] < 65536){
        
            resultado_f = resultado_f * numeros[i];
        }
        
    }
    
    return resultado_f;
    
}

