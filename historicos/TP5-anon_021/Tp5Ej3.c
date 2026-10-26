/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>

#define TAMANIO 100

char* busqueda(char *cadena, int largo, char *busqueda);
 
int main(int argc, char *argv[])
{
    char mitexto[TAMANIO], palabra[TAMANIO];
    
    char *puntencontrol[TAMANIO];
    
    printf("\n ingrese una oracion: ");

    fgets(mitexto,TAMANIO,stdin);
    
    printf("\n ingrese una palabra: ");
    
    fgets(palabra,TAMANIO,stdin);
    
    *puntencontrol = busqueda(mitexto, TAMANIO, palabra);
    
    printf("\n %s", *puntencontrol);
    

return 0;
}

char* busqueda(char *cadena, int largo, char *busqueda){
    
    int donde_esta, tamanio_busqueda, i_b, coincidencia;
    
    coincidencia = 0;
    
    tamanio_busqueda = 0;
    
    donde_esta = 0;
    
    i_b = 0;
    
    for(int i = 0 ; i<largo ; i++){
        
        if(busqueda[i] != '\n'){
            
            tamanio_busqueda ++;
            
        }
        else{
            
            break;
            
        }
        
    }
    
    for(int i = 0; i<largo ; i++){
        
        if (cadena[i] == busqueda[i_b] ){
            
        coincidencia ++;

        i_b ++;
         
        }
        else if(coincidencia == tamanio_busqueda){
            
            donde_esta = i;
            
            break;
            
        }
        else{
            
            i_b = 0;
            
            coincidencia = 0;
            
        }
       
    }
    
    if(donde_esta > 0){
        
        donde_esta = donde_esta - tamanio_busqueda;
        return cadena + donde_esta;
    }
    else{
        
        return NULL;
        
    }
    
}  