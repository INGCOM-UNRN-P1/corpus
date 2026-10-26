/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
#include <stdlib.h>
#define ESPACIO_INCORRECTO -1
#define LARGO 100

int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char *destino, int capacidad_destino, char* insertar, int posicion);
int copiadora(char *origen, char *destino, int capacidad_destino);
int limpiadora(char *origen, char *destino, int capacidad_destino);
int inversor(char* origen, char* destino, int capacidad_destino);
int compara(char* primera, char *segunda);
int es_palindromo(char *cadena, int largo);

void prueba_largo_cadena();
void prueba_insercion();
void prueba_copia();
void prueba_limpiadora();
void prueba_inversor();
void prueba_compara();
void prueba_palindromo();

int main(int argc, char *argv[])
{
	
	int eleccion;
	
	printf("\n 1-7 funciones: ");
	
	scanf("%d",&eleccion);
	
	getchar();
	
	switch(eleccion){
	
        case 1:
		
            prueba_largo_cadena();
		
        break;
		
        case 2:
			
            prueba_insercion();
			
        break;
			
        case 3:
        
            prueba_copia();
		
        break;
        
        case 4: 
            
            prueba_limpiadora();
            
        break;
        
        case 5:
        
            prueba_inversor();
            
        break;
        
        case 6:
        
            prueba_compara();
            
        break;
        
        case 7:
        
            prueba_palindromo();
            
        break;
	
	}
		
    return 0;
}

void prueba_largo_cadena(){
    
    char Texto[LARGO];
    
    printf("\n\n ingrese lo que sea: ");
    
    fgets(Texto, LARGO, stdin); 
    
    int cual_sera_el_largo = largo_cadena(Texto, LARGO);
    
    if (cual_sera_el_largo >= 0){
        
        printf("\n %s : su largo es de %d caracteres", Texto, cual_sera_el_largo);
      
    }
    else{
        
        printf("ERROR, CADENA DEMACIADO LARGA");
        
    }
    
}

int largo_cadena(char *cadena, int capacidad_cadena){
    
    
    int tamanio = 0, i=0;
    
    
    
    for(int j = 0; j< capacidad_cadena; j++){
        
        if (cadena[j] == '\n'){
            
            cadena[j] = '\0';
            
        }
        
    }
    
    for (; i <= capacidad_cadena; i++){
        
        if (cadena[i] != '\0' ){
            
            tamanio ++;
            
        }          
        else if (i + 1 >= capacidad_cadena){                             
            
            tamanio = ESPACIO_INCORRECTO;
            
            break;
            
        }
        else{
            
            break;
            
        }
               
    }

    return tamanio;
}

void prueba_insercion(){
    
    
    char tu_texto[LARGO], la_insercion[LARGO];
    
    int la_posicion,largo_ahora;
    
    printf("\n\n ingrese un texto: ");
    
    fgets(tu_texto, LARGO, stdin); 
    
    printf("\n ahora ingrese un texto pa meterle: ");
    
    fgets(la_insercion, LARGO, stdin);
    
    printf("\n por ultimo, DONDE: ");
    
    scanf("%d", &la_posicion);
	
    largo_ahora = insercion(tu_texto, LARGO, la_insercion, la_posicion);
    
    if(largo_ahora == -1){
     
        printf("\n ERROR, NO HAY ESPASIO SUFICIENTE PARA REALIZAR LA OPERACION");
     
    }
    else{
		
        printf("\n el largo de %s ahora es : %d",tu_texto,largo_ahora);
    
    }
    
}

int insercion(char *destino, int capacidad_destino, char *insertar, int posicion){
    
    char copia[LARGO];
    
    int largo_in, largo_des, largo_total, contador_destino, contador_insertar;
    
    contador_destino = 0;

    contador_insertar = 0;
    
    largo_des = largo_cadena(destino, capacidad_destino);
    
    largo_in = largo_cadena(insertar, capacidad_destino);
    
    largo_total = largo_des + largo_in;
    
    if (largo_des != -1 && largo_in != -1 && largo_total <= capacidad_destino){
    
        for (int i = 0; i < capacidad_destino; i++){
        
            if(i < posicion || contador_insertar >= largo_in){
            
                copia[i] = destino[contador_destino];
            
                contador_destino ++;    
            
            
                
            }
            else if(i >= posicion && contador_insertar < largo_in){
            
                copia[i] = insertar[contador_insertar];
            
                contador_insertar ++;
            
            
            }
 
        }
    
        for(int i = 0; i < capacidad_destino; i++){
        
            destino[i] = copia[i];
        
        }
    
        return largo_total;
    }
    else{
        
        return ESPACIO_INCORRECTO;
        
    }
    
}

void prueba_copia(){
    
    char textorigen[LARGO], textino[LARGO];
    
    int quepaso;
    
    printf("\n\n ingrese un texto origen: ");
    
    fgets(textorigen, LARGO, stdin);
    
    printf("\n ingrese un texto al cual copiar: ");
    
    fgets(textino, LARGO, stdin);
    
    quepaso = copiadora(textorigen, textino, LARGO);
    
    if (quepaso > 0){
    
        printf("\n copia realizadam :%s \n tamanio de destino ahora : %d",textino, quepaso);
    
    }
    else{
        
        printf("\n ERROR, TEXTO ORIGEN SUPERA LAS CAPASIDADES DEL DESTINO");
        
    }
    
}

int copiadora(char *origen, char *destino, int capacidad_destino){
    
    int tamaniodeorigen, tamaniofinal;
    
    tamaniodeorigen = largo_cadena(origen, LARGO);
    
    if (tamaniodeorigen < capacidad_destino){
        
        for (int i = 0; i <= tamaniodeorigen; i++){
        
            destino[i] = origen[i];
        
        }
    
        tamaniofinal = largo_cadena(destino, LARGO);
    
        return tamaniofinal;
    }
    else{
        
        return ESPACIO_INCORRECTO;
        
    }
}

void prueba_limpiadora(){
	
	char mitexto[LARGO], mitexto_limpio[LARGO];
	
	int largo_limpio;
	
	printf("\n\n ingrese su texto(te lo vamos a limpiar): ");
	
	fgets(mitexto, LARGO, stdin);
	
	largo_limpio = limpiadora(mitexto, mitexto_limpio, LARGO);
	
	
	if (largo_limpio > 0){
		
		printf("\n tu texto era : %s \n ahora el texto es : %s y su largo es %d", mitexto, mitexto_limpio, largo_limpio);
		
	}
	else{
		
		printf("EROR, ESPACIO EN DESTINO INSUFICIENTE");
		
	}
	
}

int limpiadora(char *origen, char *destino, int capacidad_destino){
	
	int contador_des = 0, espaciorigen, espaciodestino;
	
	for (int i = 0;i<capacidad_destino;i++){
		
		if(origen[i]> 47 && origen[i]< 58 && origen[i] != '\0'){
		
			destino[contador_des] = origen[i];
			
			contador_des ++;
		
		}
		else if (origen[i]> 64 && origen[i]< 91 && origen[i] != '\0'){
			
			destino[contador_des] = origen[i];
			
			contador_des ++;
			
		}
		else if (origen[i]> 93 && origen[i]< 123 && origen[i] != '\0'){
			
			destino[contador_des] = origen[i];
			
			contador_des ++;
			
		}
		else if (origen[i] == '\0'){
			
			if (contador_des > capacidad_destino){
				
				contador_des = ESPACIO_INCORRECTO;
				
			}
			
			break;
		
		}
		
	}
	
	destino[contador_des] = '\0';
	
	return contador_des;
}

void prueba_inversor(){
	
	char eltexto[LARGO], eltexto_inv[LARGO];
	
	printf("\n\n ingrese un texto a invertir: ");
	
	fgets(eltexto, LARGO, stdin);
	
	inversor(eltexto,eltexto_inv,LARGO);
	
	printf("\n %s\n se invirtio en \n\n %s",eltexto,eltexto_inv);
	
}

int inversor(char* origen, char* destino, int capacidad_destino){
	
	int i = 0, i2 = 0;
	
	for (; i< capacidad_destino;i++){
		
		if(origen[i] == '\n'){
		
        
			break;
		
		}
		
	}
	
	i = i-1;
	
	for(;i>=0;i--){
		
		destino[i2] = origen[i];
		i2 ++;
		
	}
	

}

void prueba_compara(){
	
	char eltexto[LARGO], elotrotexto[LARGO];
	
	int orden;
	
	printf("\n\n ingrese un texto : ");
	
	fgets(eltexto, LARGO, stdin);
	
	printf("\n\n ingrese otro texto : ");
	
	fgets(elotrotexto, LARGO, stdin);
	
	orden = compara(eltexto,elotrotexto);
	
	switch(orden){
        
        case -1:
        
            printf("\n %s va antes",eltexto);
            
        break;
        
        case 0:
        
            printf("\n se ingreso lo mismo 2 veces, comparten orden");
            
        break;
        
        case 1:
        
            printf("\n %s va antes",elotrotexto);
        
        break;
        
    }
	
}

int compara(char* primera, char *segunda){
	
	int orden,i = 0,ciclo = 0;
	
	while(ciclo == 0){
        
		if(primera[i]>= 65 && primera[i] <= 90){
			
			primera[i] += 32;
			
		}
		if(segunda[i]>= 65 && segunda[i] <= 90){
			
			segunda[i] += 32;
			
		}
		if(primera[i] >= 97 && primera[i] <= 122 && segunda[i] >= 97 && segunda[i] <= 122){
			
			if(primera[i] > segunda[i]){
			
				orden = 1;
				
				ciclo = 1;
			
			}
			else if(primera[i] < segunda[i]){
			
				orden = -1;
			
				ciclo = 1;
				
			}
			
		}
        else if(primera[i] < 97 || primera[i] > 122){
            
            if(segunda[i] < 97 || segunda[i] > 122){
                
                orden = 0;
			
                ciclo = 1;
                
            }
            else{
                
                orden = -1;
			
                ciclo = 1;
                
            }
            
            
        }   
        else if(segunda[i] < 97 || segunda[i] > 122){
            
            orden = 1;
			
			ciclo = 1;
            
        }
        
		i++;
	}
	
	return orden;
	
}

void prueba_palindromo(){
    
    char Lapalabra[LARGO];
	
	int palindromo;
	
	printf("\n\n ingrese su palabra : ");
	
	fgets(Lapalabra, LARGO, stdin);
    
    palindromo = es_palindromo(Lapalabra,LARGO);
    
    if(palindromo == 0){
        
        printf("\n %s es palindromo", Lapalabra);
        
    }
    else{
        
        printf("\n %s No es palindromo ", Lapalabra);
        
    }
}

int es_palindromo(char *cadena, int largo){
    
    char *cadena_inv;
    
    int validador;
    
	cadena_inv = (char*)malloc(sizeof(char)*largo);
    
    inversor(cadena, cadena_inv, largo);
    
    validador = compara(cadena, cadena_inv);
    
	free(cadena_inv);
    
    return validador;
    
}

