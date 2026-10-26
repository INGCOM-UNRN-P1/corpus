
#include <stdio.h>
#define FILAS 10
#define COLUMNAS 10
#define ERROR_DE_DIMENSION -1 //Esto significa que las dimensiones son muy pequeñas o que no coinciden.

void muestra_matriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
int carga_matriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void producto_escalar(int filas, int columnas, int matriz[FILAS][COLUMNAS], int escalar);
int suma_matriz(int filas_1, int columnas_1, int matriz_1[FILAS][COLUMNAS], int filas_2, int columnas_2, int matriz_2[FILAS][COLUMNAS], int filas_r, int columnas_r, int resultado[FILAS][COLUMNAS]);

int main()
{
    int matriz[FILAS][COLUMNAS];
    int filas = 0;
    int columnas = 0;
    int matriz_2[FILAS][COLUMNAS];
    int filas_2 = 0;
    int columnas_2 = 0;
    int matriz_resultado[FILAS][COLUMNAS];
    int filas_res = 0;
    int columnas_res = 0;
    
    int retorno = 0;
    int retorno_2 = 0;
    int escalar = 0;
    int opcion = 0;
    
    printf("--Ingrese las dimensiones de la matriz--");
    printf("\nIngrese la cantidad de filas: ");
    scanf("%d",&filas);//guardo la cantidad de filas
    
    printf("\nIngrese la cantidad de columnas: ");
    scanf("%d",&columnas);//guardo la cantidad de columnas
    
    printf("Ingrese 1 para multiplicar la matriz por un escalar.\n");
    printf("Ingrese 2 para sumar con otra matriz.\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    
    retorno = carga_matriz(matriz, filas, columnas);//llamo a que se cargue la matriz
    
    if(retorno == ERROR_DE_DIMENSION)
    {
        printf("Las dimensiones no son correctas!");
    }
    else//si cargo bien, se puede operar con el arreglo
    {
        if(opcion == 1)//es para ver que operacion hacer
        {
            //LLama a multiplicar
            printf("Ingrese el numero escalar: ");
            scanf("%d",&escalar);//guarda el escalar
            producto_escalar( filas,  columnas,  matriz,  escalar);
            
            
            printf("La matriz queda asi");
            muestra_matriz(matriz, filas, columnas);//muestro la matriz
            printf("\n");
            printf("\n");
        }
        else if(opcion == 2)
        {
            printf("--Ingrese las dimensiones de la segunda matriz--");
            printf("\nIngrese la cantidad de filas de la segunda matriz: ");
            scanf("%d",&filas_2);//guardo la cantidad de filas
            
            printf("\nIngrese la cantidad de columnas de la segunda matriz: ");
            scanf("%d",&columnas_2);//guardo la cantidad de columnas
            
            filas_res = filas;
            columnas_res = columnas;
            
            retorno_2 = carga_matriz(matriz_2, filas_2, columnas_2);
            
            if(retorno_2 != ERROR_DE_DIMENSION)//Si no dio error, puede operar
            {
                retorno = suma_matriz(filas, columnas, matriz, filas_2, columnas_2, matriz_2, filas_res, columnas_res, matriz_resultado);
                if(retorno == ERROR_DE_DIMENSION)
                {
                    printf("Las dimensiones no son correctas!!");
                }
                else
                {
                     printf("La suma de matriz queda asi");
                    muestra_matriz(matriz_resultado, filas_res, columnas_res);//muestro la matriz de resultado
                }

                
            }
            else//Si dio error no puede operar.
            {
                printf("No se pudo operar :(");
            }
            
            
        }
        else
        {
            printf("No es una opcion!\n");
        }
        
    }

       
    
}




int carga_matriz(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
    int contador_filas = 0;//recorre las filas
    int contador_columnas = 0;//recorre las columnas
    int retorno = 0;
    
    
    //Carga por filas
    
    if((filas < 1) || (columnas < 1))//si alguna dimension es menor a 1, devuelve error
    {
        retorno = ERROR_DE_DIMENSION;
    }
    else
    {
        while(contador_columnas < columnas)//esto es la columna
        {
            printf("\n");
            contador_filas = 0;//Reinicia el contador de las filas.
            
            while(contador_filas < filas)//esto es la fila
            {
                printf("Ingrese el numero para la posicion [%d][%d]: ", contador_filas, contador_columnas);
                scanf("%d",&matriz[contador_filas][contador_columnas]);
                contador_filas++;//Mueve la fila
            }    
            contador_columnas++;//Baja en la columna
        }
    }
    
    return retorno;
   
}






void muestra_matriz(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
    
    int contador_filas = 0; //recorre las filas
    int contador_columnas = 0;//Recorre las columnas
    
    //Muestra por filas.
    while(contador_columnas < columnas)//Muestra la  fila de la primer columna
    {
        printf("\n");//esto hace que la fila vaya abajo de la anterior.
        contador_filas = 0;//reinicia el contador de las filas.
        
        while(contador_filas < filas)//esto es la fila
        {
            printf("[%d]",matriz[contador_filas][contador_columnas]);
            contador_filas++;//mueve la fila a la derecha
        }
        contador_columnas++;//baja la columna
    }
    
    
}



void producto_escalar(int filas, int columnas, int matriz[FILAS][COLUMNAS], int escalar)
{

    int contador_filas = 0; //recorre las filas
    int contador_columnas = 0;//Recorre las columnas
    
    
    while(contador_columnas < columnas)//Agarra la  fila de la primer columna
    {
        contador_filas = 0;//reinicia el contador de las filas.
        
        while(contador_filas < filas)//esto es la fila
        {
            matriz[contador_filas][contador_columnas] = (escalar * matriz[contador_filas][contador_columnas]);//esto multiplica por el escalar y lo guarda
            contador_filas++;//mueve la fila a la derecha
        }
        contador_columnas++;//baja la columna
    }
    
    
    
}



int suma_matriz(int filas_1, int columnas_1, int matriz_1[FILAS][COLUMNAS], int filas_2, int columnas_2, int matriz_2[FILAS][COLUMNAS], int filas_r, int columnas_r, int resultado[FILAS][COLUMNAS])
{
    int retorno = 0;
    int contador_filas = 0; //recorre las filas
    int contador_columnas = 0;//Recorre las columnas
    
    
    if(filas_1 != filas_2 || columnas_1 != columnas_2)//Si las dimensiones de las matrices son diferentes
    {
        retorno = ERROR_DE_DIMENSION; //No se puede operar
    }
    else//Si las dimensiones son iguales, opera.
    {
        while(contador_columnas < columnas_r)//Agarra la  fila de la primer columna
        {   
            contador_filas = 0;//reinicia el contador de las filas.
            
            while(contador_filas < filas_r)//esto es la fila
            {
                resultado[contador_filas][contador_columnas] = (matriz_1[contador_filas][contador_columnas] + matriz_2[contador_filas][contador_columnas]);//esto suma los valores de las posciones
                contador_filas++;//mueve la fila a la derecha
            }
            contador_columnas++;//baja la columna
        }
    }
    
    return retorno;
}
