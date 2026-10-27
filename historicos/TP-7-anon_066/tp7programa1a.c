
#include <stdio.h>
#include <string.h>
#define CANTIDAD_TAMANIO 11
int cantidad_de_minas_a_cargar(int fila,int columna)
{
    int tamanio;
    int cantidad_minas;
    cantidad_minas=0;
    tamanio = fila*columna;
    if(tamanio%2==0)
    {
        cantidad_minas=(tamanio/2)-8;     
    }else{
        cantidad_minas=((tamanio+1)/2)-8;
    }
    if(cantidad_minas<=0)
    {
        cantidad_minas=1;
    }
    return cantidad_minas;
}
int cargar_minas(int grilla[][CANTIDAD_TAMANIO],int i, int j,int fila,int columna)
{
    if(i>=0 && j>=0 && i<fila && j<columna)
    {
        if(grilla[i][j]!=-1)
        {
            grilla[i][j]=-1; //va a ser una mina
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}
int incrementar_celda(int grilla[][CANTIDAD_TAMANIO],int i,int j,int fila,int columna)
{
    if(i>=0 && j>=0 && i<fila && j<columna)
    {
        if(grilla[i][j]!=-1)
        {
            grilla[i][j]++;
        }
    } 
    grilla=&*grilla;
    return 0;
}
int cargar_grilla(int grilla[][CANTIDAD_TAMANIO],int fila,int columna)
{
    int i,j;
    int columna_a_modificar;
    int fila_a_modificar;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            if(grilla[i][j]==-1)
            {
                incrementar_celda(grilla,i-1,j-1,fila,columna); 
                incrementar_celda(grilla,i-1,j,fila,columna);
                incrementar_celda(grilla,i-1,j+1,fila,columna);
                incrementar_celda(grilla,i,j-1,fila,columna);
                incrementar_celda(grilla,i,j+1,fila,columna);
                incrementar_celda(grilla,i+1,j-1,fila,columna); 
                incrementar_celda(grilla,i+1,j,fila,columna);
                incrementar_celda(grilla,i+1,j+1,fila,columna);   
            }
        }
    }
    grilla=&*grilla;
    return 0;
}
int dibujar_grilla(int grilla[][CANTIDAD_TAMANIO],int fila,int columna)
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
                //printf("%c",186);
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
            if(grilla[i][j]==-1)
            {
                printf(" M "); 
                printf("%c",186);
            }else if(grilla[i][j]==-2)
            {
                printf(" D "); 
                printf("%c",186);
            }else{
                printf(" %d ",grilla[i][j]);
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
int guardar_tablero(int grilla[][CANTIDAD_TAMANIO],int fila,int columna)
{
    FILE * fp;
    int i,j;
    char *nombrearchivo;
    fp = fopen ("tablero.txt", "w+");
    fprintf(fp, "%d,%d\n",fila,columna);
    for(i=0;i<fila;i++)
    {      
       for(j=0;j<columna;j++)
        {
            fprintf(fp, "%d,", grilla[i][j]);
           
        }
        fprintf(fp, "\n", grilla[i][j]);
    }
   fclose(fp);
   return 0;
}
int main(int argc, char *argv[])
{
    int grilla[CANTIDAD_TAMANIO][CANTIDAD_TAMANIO];
    memset (grilla,0,sizeof(int)*CANTIDAD_TAMANIO*CANTIDAD_TAMANIO);
    int i,j,cargar,fila,columna,fila_ingresada,columna_ingresada,cantidad_de_minas,cantidad_de_minas_ingresadas,cargar_minas_en_grilla;
    int coordenada_fila,coordenada_columna,cargar_fila,cargar_columna,agregar_mina;
    fila=0;
    columna=2;
    fila_ingresada=0;
    columna_ingresada=0;
    cargar_minas_en_grilla=1;
    coordenada_fila=0;
    coordenada_columna=0;
    cargar_fila=1;
    cargar_columna=0;
    agregar_mina=0;
    while(1)
    {
        printf("Ingrese un numero mayor a 2 y menor a %d para la cantidad de filas: ",CANTIDAD_TAMANIO);
        scanf("%d",&fila);
        if(fila>CANTIDAD_TAMANIO || fila<=2)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }  
    }
    while(1)
    {
        printf("Ingrese un numero mayor a 2 y menor a %d para la cantidad de columnas: ",CANTIDAD_TAMANIO);
        scanf("%d",&columna);
        if(columna>CANTIDAD_TAMANIO || columna<=2)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }  
    }
    cantidad_de_minas= cantidad_de_minas_a_cargar(fila,columna);
    cantidad_de_minas_ingresadas=0;
    printf("Ingrese las coordenadas para las minas:\n");
    while(cargar_minas_en_grilla)
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
                    if(cargar_minas(grilla,coordenada_fila,coordenada_columna,fila,columna))
                    {
                        cantidad_de_minas_ingresadas=cantidad_de_minas_ingresadas+1;
                    }else{
                        printf("Las coordenadas para la mina ya existe\n");
                    }                 
                }
        }else{
            printf("Desea agregar mas minas? Puede agregar hasta %d minas, ingrese 1 para si o 0 para no: ",cantidad_de_minas);
            scanf("%d",&agregar_mina);
            if(agregar_mina)
            {
                if(cantidad_de_minas_ingresadas==cantidad_de_minas)
                {
                    printf("Ya ingreso todas las minas disponibles!!!");
                    break;
                }
                cargar_fila=1;
            }else{
                break;
            }           
        }  
    }
    cargar_grilla(grilla,fila,columna);
    printf("\n");
    printf("Tablero realizado!!!\n");
    dibujar_grilla(grilla,fila,columna);
    printf("\n");
    guardar_tablero(grilla,fila,columna);
	return 0;
}
