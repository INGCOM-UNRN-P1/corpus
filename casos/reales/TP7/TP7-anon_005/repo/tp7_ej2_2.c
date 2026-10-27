

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESCUBRIR 1
#define MARCAR 2
#define GAME_OVER -1
#define CONTINUA 3
#define VICTORIA 5


FILE* abrir_archivo(FILE* p_file, char* archivo);
int leer_datos(FILE* p_file);
char** reservar_memoria(char** tablero, int filas, int columnas);
char** guardar_datos(FILE* p_file, char** tablero, int filas, int columnas);
void linea_encabezado(int columnas);
void encabezado(int columnas);
void linea_fila(int filas);
void mostrar_tablero(char** tablero, int fila, int columnas);
FILE* cerrar_archivo(FILE* p_file);
char** llenar_t_x(char** t_x, int filas, int columnas);
int contar_vacias(char** t_datos, int filas, int columnas);
void inicio();
int elegir_opcion();
char** adyascencias(char** t_datos, char** t_x, int d_fila, int d_columna, int filas, int columnas);
int descubrir_celda(char** t_datos, char** t_x, int filas, int columnas, int cant_minas);
int marcar_mina(char** t_datos, char** t_x, int filas, int columnas);
FILE* abrir_archivo_final(FILE* p_file_dos, char* archivo_dos);
FILE* guardar_partida(FILE* p_file_dos, char** t_x, int filas, int columnas);
void liberar_memoria(char** tablero, int filas, int columnas);


int main(int argc, char *argv[])
{
    int i, j, filas, columnas, cant_minas, opcion, res_a, res_b, cant_celdas, cant_vacias,vacias, marcadores;

    char** t_datos;
    char** t_x;
    
    char* archivo = "datos_tablero.txt";
    FILE* p_file;
    
    char* archivo_dos = "final_partida.txt";
    FILE* p_file_dos;
    
    
    p_file = abrir_archivo(p_file, archivo);
    
    filas = leer_datos(p_file);
    columnas = leer_datos(p_file);
    cant_minas = leer_datos(p_file); 
    marcadores = cant_minas;
    cant_celdas = (filas * columnas) - cant_minas - cant_vacias;
    
    t_datos = reservar_memoria(t_datos, filas, columnas+1);
    t_x = reservar_memoria(t_x, filas, columnas);
        
    t_datos = guardar_datos(p_file, t_datos, filas, columnas);
    
    p_file = cerrar_archivo(p_file);
    
    t_x = llenar_t_x(t_x, filas, columnas);
    
    cant_vacias = contar_vacias(t_datos, filas, columnas);
    
    // INICIO DE JUEGO
    
    inicio();
    mostrar_tablero(t_x, filas, columnas);
    printf("\n");
    
    do{
        opcion = elegir_opcion();
        
        if(opcion == DESCUBRIR)
        {
            res_a = descubrir_celda(t_datos, t_x, filas, columnas, cant_minas);
            
            if(res_a == GAME_OVER)
            {
                printf("\n\n---------------------------------------------------------\n\n");
                printf(" GAME OVER! La celda descubierta tenia una mina.Has perdido.");
                printf("\n\n---------------------------------------------------------\n\n\n");
                mostrar_tablero(t_datos, filas, columnas);
                printf("\n\n");
                cant_celdas = 0;
                break;
            }
            else
            {
                printf("Celda sin mina. Continuar...\n\n");
                
                mostrar_tablero(t_x, filas, columnas);
                printf("\n\n");
                
                for(i = 0; i < filas; i++)
                {
                    for(j = 0; j < columnas; j++)
                    {
                        if((t_x[i][j])!= '+')
                        {
                            vacias++;
                        }
                    }
                }
                cant_celdas += vacias;
            }    
        }
        else
        {
           res_b = marcar_mina(t_datos, t_x, filas, columnas);
           
           if(res_b == GAME_OVER)
            {
                printf("\n\n---------------------------------------------------------\n\n");
                printf(" GAME OVER! La celda marcada no tenia una mina.Has perdido.");
                printf("\n\n---------------------------------------------------------\n\n\n");
                mostrar_tablero(t_x, filas, columnas);
                cant_celdas = 0;
                break;
            }
            else
            {
                marcadores--;
                if(marcadores == 0)
                {
                    printf("\n\n---------------------------------------------------------\n\n");
                    printf(" VICTORIA! Has marcado todas las minas por lo que has ganado!.\n");
                    printf("\n\n---------------------------------------------------------\n\n\n");
                    mostrar_tablero(t_datos, filas, columnas);
                    printf("\n\n");
                    cant_celdas = 0;
                    break;
                }
                else
                {
                    printf("\n Correcto! Mina marcada.  Te quedan %d marcadores. Continuar...\n\n", marcadores);
                    mostrar_tablero(t_x, filas, columnas);
                    printf("\n\n");
                    cant_celdas--;
                }
            }
        }
    }while(cant_celdas > 0);

    if((cant_celdas == 0)&&(res_a != GAME_OVER)&&(res_b != GAME_OVER)&&(marcadores >0))
    {
        printf(" VICTORIA! Has destapado todas las celdas que no son minas, por lo que has ganado!.\n");
        mostrar_tablero(t_datos, filas, columnas);
        printf("\n\n");
    }
    
    p_file_dos = abrir_archivo_final(p_file_dos, archivo_dos);
   
    p_file_dos = guardar_partida( p_file_dos, t_x, filas, columnas);

    p_file_dos = cerrar_archivo(p_file_dos);
    
    liberar_memoria(t_x, filas, columnas);
    liberar_memoria(t_datos, filas, columnas);
    
    return 0;
}

FILE* abrir_archivo(FILE* p_file, char* archivo)
{
    p_file = fopen(archivo, "r");
    if(p_file == NULL)
    {
        printf("No se pudo abrir el archivo. \n");
    }

    return p_file;
}

 int leer_datos(FILE* p_file)
 {
    int numero;

    fscanf(p_file,"%d \n",&numero);
    
    return numero;
 }

char** reservar_memoria(char** tablero, int filas, int columnas)
{
    int i;
    
    tablero = (char**)calloc(filas, sizeof(char*));
    
    for(i=0; i< filas; i++)
    {
        tablero[i] = (char*) calloc(columnas, sizeof(char));
    }
    
    if(tablero == NULL)
    {
        printf("Error. No se pudo reservar la memoria. \n");
    }
    
    return tablero;
}

char** guardar_datos(FILE* p_file, char** tablero, int filas, int columnas)
{
    int i, j;
    char caracter, residuo;
    
    for(i = 0; i< filas; i++)
    {
        for(j = 0; j< columnas+1; j++)
        {
            caracter =fgetc(p_file);
            if(caracter == '9')
            {
               tablero[i][j] = '*'; 
            }
            else
            {
               tablero[i][j] = caracter; 
            }   
        }
    }
    return tablero;
}

void linea_encabezado(int columnas)
 {
    int i;
    for (i = 0; i <= columnas+3; i++)
    {
        printf("----");
        if (i + 2 == columnas+1)
        {
            printf("-");
        }
    }
    printf("\n");
}

void encabezado(int columnas)
{
    linea_encabezado(columnas);
    int i;
    printf("      ");
    
    for (i = 0; i < columnas; i++)
    {
        printf("| %d  ", i);
        if (i == columnas)
        {
            printf("|");
        }
    }
    printf("|");
    printf("\n");
}

void linea_fila(int filas)
 {
    int i;
    for (i = 0; i <= filas+3; i++)
    {
        printf("+---");
        if (i == filas)
        {
            printf("+");
        }
    }
    printf("\n");
}

void mostrar_tablero(char** tablero, int filas, int columnas)
{
    int i, j;
    
    encabezado(columnas);
    linea_encabezado(columnas);
    
    for(i=0;i< filas;i++)
    {
        printf("| %d | ", i);
        
        for(j=0;j< columnas;j++)
        {
            printf("| %c |", tablero[i][j]);
        }
        printf("\n"); 
        linea_fila(filas);        
    }
}

FILE* cerrar_archivo(FILE* p_file)
{
    fclose(p_file);        
     
    return p_file;
}

char** llenar_t_x(char** t_x, int filas, int columnas)
{
    int i, j;
    
    for(i=0;i< filas;i++)
    {
        for(j=0;j< columnas;j++)
        {
            t_x[i][j] = '+';
        }    
    }
    return t_x;
}

int contar_vacias(char** t_datos, int filas, int columnas)
{
    int i, j, cantidad;
    cantidad = 0;
    
    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            if(t_datos[i][j] == '0')
            {
                cantidad++;
            }
        }
    }
    return cantidad;  
}

void inicio()
{
    printf("\n\n**************************************************************************\n");
    printf("                             BUSCAMINAS                                       ");
    printf("\n**************************************************************************\n");
    printf("\n");
    printf("PASO 1.DEFINICION DEL TABLERO DE JUEGO.\n");    
    printf("\n");    
    printf("PASO 2.DEFINICION DE COORDENADAS DE LAS MINAS.\n");
    printf("\n");
    printf("PASO 3.MOMENTO DE JUGAR!!!.\n");
    printf("\n");
    printf("\n");
}

int elegir_opcion()
{
    int opcion;
    
    printf("OPCIONES DE JUEGO: \n\n");
    printf("1: Descubrir una celda.\n");
    printf("2: Marcar una mina.\n");
    
    do{
        printf("Ingresar opcion:\n");
        scanf("%d", &opcion);
        printf("\n Opcion elegida: %d. -> ", opcion);
        
        if(opcion == DESCUBRIR)
        {
            return DESCUBRIR;
        }
        else if(opcion == MARCAR)
        {
            return MARCAR;
        }
        else
        {
            printf("ingreso no valido \n");   
        }
    }while((opcion != DESCUBRIR)&&(opcion != MARCAR));
        
    return opcion;
}

char** adyascencias(char** t_datos, char** t_x, int d_fila, int d_columna, int filas, int columnas)
{
    int f, c;
    
    for(f = d_fila; f < filas; f++)
    {
        for(c = d_columna; c < columnas; c++)
        {
            if(t_datos[f][c] == '0')
            {
                t_x[f][c]= t_datos[f][c];
            }
            else
            {
                break;
            }
        }
    }
    
    for(f = d_fila; f > 0; f--)
    {
        for(c = d_columna; c > 0; c--)
        {
            if(t_datos[f][c] == '0')
            {
                t_x[f][c]= t_datos[f][c];
            }
            else
            {
                break;
            }
        }
    }
      
    return t_x;
}

int descubrir_celda(char** t_datos, char** t_x, int filas, int columnas, int cant_minas)
{
    int d_fila, d_columna;
    
    printf(" Ha seleccionado la opcion descubrir celda\n\n");
    printf("\n Ingrese la fila de la celda a descubrir:\n");
    scanf("%d",&d_fila);
    printf("\n Ingrese la columna de la celda a descubrir:\n");
    scanf("%d",&d_columna);
    printf("\n Ha ingreado la posicion: %d - %d.\n\n", d_fila, d_columna);
    
    if((t_datos[d_fila][d_columna]) == '*')
    {        
        t_x[d_fila][d_columna] == '*';
        
        return GAME_OVER;
    }
    else
    {
        t_x[d_fila][d_columna]=t_datos[d_fila][d_columna];
        t_x = adyascencias(t_datos, t_x, d_fila, d_columna, filas, columnas);
        
        return CONTINUA;
    }
}
     
int marcar_mina(char** t_datos, char** t_x, int filas, int columnas)
{
    int d_fila, d_columna;
    
    printf("Ha seleccionado la opcion marcar mina.\n\n");
    printf("Ingrese la fila de la celda a marcar:\n");
    scanf("%d", &d_fila);
    printf("Ingrese la columna de la celda a marcar:\n");
    scanf("%d", &d_columna);
    printf("Ha ingreado la posicion: %d - %d.\n", d_fila, d_columna);
    
    if(t_datos[d_fila][d_columna] == '*')
    {
        t_x[d_fila][d_columna] = 'M'; 
        
        return CONTINUA;
    }
    else
    {
        t_x[d_fila][d_columna] = t_datos[d_fila][d_columna]; 
        
        return GAME_OVER;
    }
}

FILE* abrir_archivo_final(FILE* p_file_dos, char* archivo_dos)
{
    p_file_dos = fopen(archivo_dos, "w");
    
    if(p_file_dos == NULL)
    {
        printf("No se pudo abrir el archivo. \n");
    }

    return p_file_dos;
}

FILE* guardar_partida(FILE* p_file_dos, char** t_x, int filas, int columnas)
{
    int i, j;
    
    for(i=0; i< filas; i++)
    {
        for(j = 0; j<columnas; j++)
        {
            fprintf(p_file_dos,"%c", t_x[i][j]);
        }
        fprintf(p_file_dos, "\n");
    }
    return p_file_dos;
}

void liberar_memoria(char** tablero, int filas, int columnas)
{
    int i;
    
    for(i= 0; i< filas; i++)
    {
        free(tablero[i]);
    }
    free(tablero);
}