/*
Ejercicio 1 - Enter the matrix
Juan Bautista Mangold Moro - Usuario Github BautiMM
Comision 1 - 2023
Programacion 1 - Ingenieria en computacion
*/
#include <stdio.h>

void introduce_filas_columnas (int *filas, int *columnas);
void introduce_matriz(int filas, int columnas, int matriz[filas][columnas]);
void muestra_matriz(int filas, int columnas, int matriz[filas][columnas]);
int producto_escalar(int filas, int columnas, int matriz[filas][columnas], int escalar);
void suma_matriz(int filas_1, int columnas_1, int matriz_1[filas_1][columnas_1],
								int filas_2, int columnas_2, int matriz_2[filas_2][columnas_2],
								int filas_r, int columnas_r, int resultado[filas_r][columnas_r]);
int main(){
	int filas;
	int columnas;
	int escalar;
	
	introduce_filas_columnas (&filas,&columnas);
	
	int matriz[filas][columnas];
	

	introduce_matriz(filas,columnas,matriz);
	muestra_matriz (filas, columnas, matriz);
	

    producto_escalar(filas,columnas,matriz,escalar);
    muestra_matriz (filas,columnas,matriz);
    
    //Valores pre cargados para mostrar el uso de la funcion suma_matriz
    int filas_1 = 2;
    int filas_2 = 2;
    int filas_r = 2;
    int columnas_1 = 2;
    int columnas_2 = 2;
    int columnas_r = 2;
    int matriz_1[2][2] = {{1, 2}, {3, 4}};
    int matriz_2[2][2] = {{5, 6}, {7, 8}};
    int resultado[filas_r][columnas_r];
    
    printf("\nEl resultado de la suma de matriz_1 con matriz_2 es:\n");
	suma_matriz(filas_1, columnas_1, matriz_1, filas_2, columnas_2, matriz_2, filas_r, columnas_r, resultado);
	muestra_matriz(filas_r, columnas_r, resultado);
	

	return 0;
}



void introduce_filas_columnas (int *filas, int *columnas){
	printf("Introduzca cuantas filas desea: ");
	scanf("%d",filas);
	printf("Introduzca cuantas columnas desea: ");
	scanf("%d",columnas);
}
void introduce_matriz(int filas, int columnas, int matriz[filas][columnas]){
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			printf("Que valor quieres poner en el casillero [%i] [%i]:  ", i+1, j+1);
			scanf("%d", &matriz[i][j]);
		}
	}
}
void muestra_matriz(int filas, int columnas, int matriz[filas][columnas]){
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			printf("|%d|", matriz[i][j]);
		}
		printf ("\n");
	}
}
int producto_escalar(int filas, int columnas, int matriz[filas][columnas], int escalar){
	printf("Introduzca el escalar para la multiplicacion: ");
    scanf("%d", &escalar);
	for (int i = 0; i <  filas; i++){
		for (int j = 0; j < columnas; j++){
			matriz[i][j] = escalar * matriz[i][j];
			
		}
	}
	return matriz;
}
void suma_matriz(int filas_1, int columnas_1, int matriz_1[filas_1][columnas_1],
								int filas_2, int columnas_2, int matriz_2[filas_2][columnas_2],
								int filas_r, int columnas_r, int resultado[filas_r][columnas_r])
{
    if (filas_1 != filas_2 || columnas_1 != columnas_2 || filas_1 != filas_r || columnas_1 != columnas_r) {
        printf("Las dimensiones de las matrices no son compatibles para la suma.\n");
        return 1; 
    }

    
    for (int i = 0; i < filas_1; ++i) {
        for (int j = 0; j < columnas_1; ++j) {
            resultado[i][j] = matriz_1[i][j] + matriz_2[i][j];
        }
    }

    return resultado; 
}

//Precondiciones:
//Se espera que el usuario introduzca la cantidad de filas y columnas para la matriz principal.
//El usuario debe proporcionar valores para llenar la matriz con números enteros.
//Para el producto escalar, el usuario debe introducir un valor entero.
//Para la función suma_matriz, los tamaños de las matrices de entrada (matriz_1 y matriz_2) deben ser iguales tanto en filas como en columnas.

//Postcondiciones:
//Después de la ejecución, se mostrará la matriz original, la matriz después de la multiplicación por escalar y la matriz resultante de la suma de matrices.
//La matriz original se llenará con los valores proporcionados por el usuario multiplicados por el escalar ingresado.
//Se imprimirá un mensaje si las dimensiones de las matrices de entrada para la suma no son compatibles.
//La función suma_matriz modificará la matriz de resultado para contener la suma de matriz_1 y matriz_2.
//La función producto_escalar modificará la matriz original para contener el resultado de la multiplicación por el escalar ingresado.

