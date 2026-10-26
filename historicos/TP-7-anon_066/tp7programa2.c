/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CANTIDAD_TAMANIO 11
#define CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR 500
#define LIMITE_MAXIMO_STRING 20
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i=0;
    int largo=0;
    for (i=0;i<capacidad_cadena;i++){
        if(cadena[largo]!='\n' && cadena[largo]!='\0')
        {
            largo=largo+1;
        }else{
            break;
        }
    }
	return largo;
}
int destapar_celda(double grilla[][CANTIDAD_TAMANIO],int i,int j,int fila,int columna)
{
    int cantidad_de_veces;
    if(i>=0 && j>=0 && i<fila && j<columna)
    {
        if(grilla[i][j]==0)
        {
            cantidad_de_veces= cantidad_de_veces+1;
            grilla[i][j]=-2;//celda destapada
            destapar_celda(grilla,i-1,j,fila,columna);
            destapar_celda(grilla,i+1,j,fila,columna);
            destapar_celda(grilla,i,j-1,fila,columna);
            destapar_celda(grilla,i,j+1,fila,columna);
        }else
        {
      
            return 0;

        }  
    }
    return 0;
}
int verificar_ingreso(double grilla[][CANTIDAD_TAMANIO],double grilla_aux[][CANTIDAD_TAMANIO],int i,int j,int fila,int columna,int numerosalrededor_mina, int numerosalrededor_mina_descubiertos_a, int *numerosalrededor_mina_descubiertos)
{
    int i_aux, j_aux;
    if(grilla[i][j]==-1)
    {
        printf("Has perdido\n");
        return 0;
    }else if(grilla[i][j]==0)
    {    destapar_celda(grilla,i_aux,j,fila,columna); 
        for(i_aux=i;i_aux>=0;i_aux--)
        {   
            destapar_celda(grilla,i-1,j-1,fila,columna); 
            destapar_celda(grilla,i-1,j,fila,columna);
            destapar_celda(grilla,i-1,j+1,fila,columna);
            destapar_celda(grilla,i,j-1,fila,columna);
            destapar_celda(grilla,i,j+1,fila,columna);
            destapar_celda(grilla,i+1,j-1,fila,columna); 
            destapar_celda(grilla,i+1,j,fila,columna);
            destapar_celda(grilla,i+1,j+1,fila,columna);  
           
        }
        if(i<fila)
        {
            for(i_aux=i;i_aux<fila;i_aux++)
            {   
                destapar_celda(grilla,i-1,j-1,fila,columna); 
                destapar_celda(grilla,i-1,j,fila,columna);
                destapar_celda(grilla,i-1,j+1,fila,columna);
                destapar_celda(grilla,i,j-1,fila,columna);
                destapar_celda(grilla,i,j+1,fila,columna);
                destapar_celda(grilla,i+1,j-1,fila,columna); 
                destapar_celda(grilla,i+1,j,fila,columna);
                destapar_celda(grilla,i+1,j+1,fila,columna); 
                destapar_celda(grilla,i_aux,j,fila,columna); 
            }
            
        } 
    }else if(grilla[i][j]>0)
    {
        if(grilla_aux[i][j]!=grilla[i][j])
        {
            grilla_aux[i][j]=grilla[i][j];
            numerosalrededor_mina_descubiertos_a= numerosalrededor_mina_descubiertos_a+1;
        }   
    }
    grilla=&*grilla;
    grilla_aux=&*grilla_aux;
    *numerosalrededor_mina_descubiertos=numerosalrededor_mina_descubiertos_a;
    return 1;
        
}

int dibujar_grilla_para_jugar(double grilla[][CANTIDAD_TAMANIO],double grilla_aux[][CANTIDAD_TAMANIO],int fila,int columna,int fila_ingresada,int columna_ingresada)
{
    int i,j,k;
    for(i=0;i<=columna*4;i++)
    {
        if(i==0)
        {
            printf("%c%c%c%c%c",201,205,205,205,203);
        }else if(i==columna*4)
        {
            printf("%c\n",187);
        }else{
            if(i%4==0)
            {
                printf("%c",203);
            }else{
                printf("%c",205);
            }
        }
    }
    for(i=0;i<1;i++)
    {    
        for(j=0;j<columna;j++)
        {
            if(j==0)
            {
                printf("%c %c %c C%d",186,196,186,j);
            }else if(j==columna-1){
                printf("%c C%d%c",186,j,186);
            }else{
                printf("%c C%d",186,j);
            }
        }
        printf("\n");
        for(k=0;k<=columna*4;k++)
        {
            if(i<fila-1)
            {
                if(k==0)
                {
                    printf("%c%c%c%c%c",204,205,205,205,206);
                }else if(k==columna*4)
                {
                    printf("%c\n",185);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",206);

                    }else{
                        printf("%c",205);
                    }
                } 
            }else{
                if(k==0)
                {
                    printf("%c%c%c%c%c",200,205,205,205,202);
                }else if(k==columna*4)
                {
                    printf("%c\n",188);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",202);
                    }else{
                        printf("%c",205);
                    }                   
                }
            }     
        }
    }
    for(i=0;i<fila;i++)
    {      
        for(j=0;j<columna;j++)
        {
            if(j==0)
            {
                printf("%cF%d ",186,i);
                printf("%c",186);
            }
            if(grilla[i][j]==-1)//mina
            {
                printf(" * "); 
                printf("%c",186);
            }else if(grilla[i][j]==-2)//destapada
            {
                printf("   "); 
                printf("%c",186);
            }else{
                if(grilla[i][j] == grilla_aux[i][j] && grilla[i][j]>0){//numero que rodea la mina
                    printf(" %.0f ",grilla[i][j]);
                    printf("%c",186);
                }else{
                    printf(" * ");
                    printf("%c",186);
                }           
            }              
        }
        printf("\n");
        for(k=0;k<=columna*4;k++)
        {
            if(i<fila-1)
            {
                if(k==0)
                {
                    printf("%c%c%c%c%c",204,205,205,205,206);
                }else if(k==columna*4)
                {
                    printf("%c\n",185);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",206);
                    }else{
                        printf("%c",205);
                    }
                } 
            }else{
                if(k==0)
                {
                    printf("%c%c%c%c%c",200,205,205,205,202);
                }else if(k==columna*4)
                {
                    printf("%c\n",188);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",202);
                    }else{
                        printf("%c",205);
                    }          
                }
            }     
        }
    }
    return 0;
}
int dibujar_grilla(double grilla[][CANTIDAD_TAMANIO],int fila,int columna)
{
    int i,j,k;
    for(i=0;i<=columna*4;i++)
    {
        if(i==0)
        {
            printf("%c%c%c%c%c",201,205,205,205,203);
        }else if(i==columna*4)
        {
            printf("%c\n",187);
        }else{
            if(i%4==0)
            {
                printf("%c",203);
            }else{
                printf("%c",205);
            }
        }
    }
    for(i=0;i<1;i++)
    {    
        for(j=0;j<columna;j++)
        {
            if(j==0)
            {
                printf("%c %c %c C%d",186,196,186,j);
            }else if(j==columna-1){
                printf("%c C%d%c",186,j,186);
            }else{
                printf("%c C%d",186,j);
            }
        }
        printf("\n");
        for(k=0;k<=columna*4;k++)
        {
            if(i<fila-1)
            {
                if(k==0)
                {
                    printf("%c%c%c%c%c",204,205,205,205,206);
                }else if(k==columna*4)
                {
                    printf("%c\n",185);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",206);
                    }else{
                        printf("%c",205);
                    }
                } 
            }else{
                if(k==0)
                {
                    printf("%c%c%c%c%c",200,205,205,205,202);
                }else if(k==columna*4)
                {
                    printf("%c\n",188);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",202);
                    }else{
                        printf("%c",205);
                    }                   
                }
            }     
        }
    }
    for(i=0;i<fila;i++)
    {      
        for(j=0;j<columna;j++)
        {
            if(j==0)
            {
                printf("%cF%d ",186,i);
                printf("%c",186);
            }
            if(grilla[i][j]==-1)//mina
            {
                printf(" M "); 
                printf("%c",186);
            }else if(grilla[i][j]==-2)//destapada
            {
                printf(" D "); 
                printf("%c",186);
            }else{
                printf(" %.0f ",grilla[i][j]);//numero que rodea la mina
                printf("%c",186);
            }              
        }
        printf("\n");
        for(k=0;k<=columna*4;k++)
        {
            if(i<fila-1)
            {
                if(k==0)
                {
                    printf("%c%c%c%c%c",204,205,205,205,206);
                }else if(k==columna*4)
                {
                    printf("%c\n",185);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",206);
                    }else{
                        printf("%c",205);
                    }
                } 
            }else{
                if(k==0)
                {
                    printf("%c%c%c%c%c",200,205,205,205,202);
                }else if(k==columna*4)
                {
                    printf("%c\n",188);
                }else{
                    if(k%4==0)
                    {
                        printf("%c",202);
                    }else{
                        printf("%c",205);
                    }     
                }
            }     
        }
    }
    return 0;
}
void asignar_valor(char arreglo_string[][LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING],char *cadena,int indice)
{
    int i,tamanio_cadena;
    int columna;
    columna=0;
    tamanio_cadena = largo_cadena(cadena,LIMITE_MAXIMO_STRING);
    for(i=0;i<tamanio_cadena;i++)
    {
        arreglo_string[indice][columna][i]=cadena[i]; 
    }
    arreglo_string[indice][columna][tamanio_cadena]='\0';
}
int guardar_strings(char arreglo_string[][LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING],char *cadena,int indice)
{
    int tamanio_cadena,i,columna,caracter;
    char aux;
    tamanio_cadena=largo_cadena(cadena,CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
    columna=0;
    caracter=0;
    for(i=0;i<tamanio_cadena;i++)
    {
        if(cadena[i]==44)
        {
            arreglo_string[indice][columna][caracter]='\0'; 
            caracter=0;
            columna=columna+1;                 
        }else{          
            arreglo_string[indice][columna][caracter]=cadena[i]; 
            caracter= caracter+1;
        }
    }
    arreglo_string[indice][columna][tamanio_cadena]='\0';
    arreglo_string=&*arreglo_string;
}
int convertir_a_entero(char *arr)
{
    int value;
    value=0;
    char str[LIMITE_MAXIMO_STRING];
    strcpy(str,arr);
    value = atoi(str);
    return value;
}
int convertir_a_double(char *arr)
{
    double value;
    char *eptr;
    value=0;
    char str[LIMITE_MAXIMO_STRING];
    strcpy(str,arr);
    value = strtod(str, &eptr);
    return value;
}
int numeros_alrededor_mina(double grilla[][CANTIDAD_TAMANIO], int numerosalrededor_mina,int fila,int columna)
{
    int i,j,cantidad;
    cantidad =0;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            if(grilla[i][j]>0)
            {
                cantidad=cantidad+1;
            }
        }
    }
    return cantidad;
}
int cantidad_destapadas(double grilla[][CANTIDAD_TAMANIO], int numerosalrededor_mina,int fila,int columna)
{
    int i,j,cantidad;
    cantidad =0;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            if(grilla[i][j]==-2)
            {
                cantidad=cantidad+1;
            }
        }
    }
    return cantidad;
}
int cantidad_minas(double grilla[][CANTIDAD_TAMANIO],int numerosalrededor_mina,int fila,int columna)
{
    int i,j,cantidad;
    cantidad =0;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            if(grilla[i][j]==-1)
            {
                cantidad=cantidad+1;
            }
        }
    }
    return cantidad;
}
int cargar_grilla(char arreglo_string[][LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING],double grilla[][CANTIDAD_TAMANIO],int fila,int columna)
{
    int i,j;
    double numero;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            numero = convertir_a_double(arreglo_string[i+1][j]);
            grilla[i][j]=numero;
        }
    }
    grilla=&*grilla;
    return 0;
}
int cargar_tablero(char arreglo_string[][LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING],double grilla[][CANTIDAD_TAMANIO], int *fila, int *columna)
{
    FILE * archivo;
    int i,j,linea;
    char *cadena;
    double numero;
    linea=0;
    archivo = fopen ("tablero.txt", "r+");
    cadena = (char *)malloc(CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
    while(fgets(cadena, CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR, archivo))
    {
        guardar_strings(arreglo_string,cadena,linea);  
        linea=linea+1;
    }
    *fila = convertir_a_entero(arreglo_string[0][0]);
    *columna = convertir_a_entero(arreglo_string[0][1]);
    free(cadena);
    fclose(archivo);
    return 0;
}
int main(int argc, char *argv[])
{
    double grilla[CANTIDAD_TAMANIO][CANTIDAD_TAMANIO];
    double grilla_aux[CANTIDAD_TAMANIO][CANTIDAD_TAMANIO];
    char arreglo_string[LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING][LIMITE_MAXIMO_STRING];
    int i,j,cargar,fila,columna,fila_ingresada,columna_ingresada,cantidad_de_minas,cargar_coordenada_en_grilla,destapadas,tamanio,cantidad;
    int coordenada_fila,coordenada_columna,cargar_fila,cargar_columna,seguir_jugando,numerosalrededor_mina,numerosalrededor_mina_descubiertos;
    int jugadatotal;
    double numero;
    destapadas=0;
    fila=0;
    columna=2;
    fila_ingresada=0;
    columna_ingresada=0;
    cargar_coordenada_en_grilla=1;
    coordenada_fila=0;
    coordenada_columna=0;
    cargar_fila=1;
    cargar_columna=0;
    seguir_jugando=0;
    numerosalrededor_mina=0;
    cantidad_de_minas=0;
    numerosalrededor_mina_descubiertos=0;
    cargar_tablero(arreglo_string,grilla, &fila, &columna);
    tamanio = fila*columna;
    cargar_grilla(arreglo_string,grilla,fila,columna);
    numerosalrededor_mina=numeros_alrededor_mina(grilla,numerosalrededor_mina,fila,columna);
    cantidad_de_minas=cantidad_minas(grilla,numerosalrededor_mina,fila,columna);
    printf("\n");
    dibujar_grilla(grilla,fila,columna);//Esta funcion la invoco para poder verificar que esta bien el juego, es para depurar
    printf("Comienza el juego\n");
    while(cargar_coordenada_en_grilla)
    {
        if(cargar_fila)
        {
            printf("Ingrese un numero mayor o igual a 0 y menor a %d para las filas: ",fila);
            scanf("%d",&coordenada_fila);
            if(coordenada_fila>=fila || coordenada_fila<0)
            {
                printf("\nIntentelo nuevamente\n");
            }else{
                cargar_columna=1;
                cargar_fila=0;
            }
        }else if(cargar_columna){
            printf("Ingrese un numero mayor o igual a 0 y menor a %d para las columnas: ",columna);
                scanf("%d",&coordenada_columna);
                if(coordenada_columna>=columna || coordenada_columna<0)
                {
                    printf("\nIntentelo nuevamente\n");
                }else{
                    cargar_columna=0;
                    if(verificar_ingreso(grilla,grilla_aux,coordenada_fila,coordenada_columna,fila,columna,numerosalrededor_mina,numerosalrededor_mina_descubiertos,&numerosalrededor_mina_descubiertos))
                    {
                        dibujar_grilla_para_jugar(grilla,grilla_aux,fila,columna,coordenada_fila,coordenada_columna);
                        destapadas= cantidad_destapadas(grilla,numerosalrededor_mina,fila,columna);
                        jugadatotal = tamanio-cantidad_de_minas-(numerosalrededor_mina_descubiertos+destapadas);
                        if(jugadatotal==0)
                        {
                            printf("Has Ganado!!!");
                            break;
                        }
                    }else{
                        cargar_tablero(arreglo_string,grilla, &fila, &columna);
                        cargar_grilla(arreglo_string,grilla,fila,columna);
                    }
                }
        }else{
            printf("Desea seguir jugando? 1 para seguir, 0 para salir: ");
            scanf("%d",&seguir_jugando);
            if(seguir_jugando)
            {
                cargar_fila=1;
            }else{
                break;
            }           
        }  
    }   
    printf("\n");
	return 0;
}
