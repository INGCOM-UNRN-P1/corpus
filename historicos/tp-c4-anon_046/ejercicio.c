

#include <stdio.h>
#include "mis_funciones.h"
#include "mis_cadenas.h"


#include <string.h>
//#include <strings.h>

#define MAX_CARACTERES 100
#define MAX_CARACTERES_CADENA 100
#define POSICION_INSERCION 4

int main() {
    char entrada[2][MAX_CARACTERES + 1] = {"\0"};
    char     cadena[MAX_CARACTERES + 1] = {"\0"};
    int resultado;
    int i; 

    
    for (i = 0; i < 2; i++) {
        printf("* Ingrese la entrada[%d] de texto de hasta %d caracteres:\n", i + 1, MAX_CARACTERES);
        if (ingreso_sin_newline(entrada[i], sizeof(entrada[i]), stdin)) {
            printf("\n*** Error en ingreso de datos\n");
            return ERROR;
        }
    }
    printf("\n\n");

    
    printf("* Prueba de largo_seguro():\n");
    for (i = 0; i < 2; i++) {
        resultado = largo_seguro(entrada[i], MAX_CARACTERES);
        printf("\tCaracteres de entrada[%d]: %d\n", i + 1, resultado);
        
        memset(cadena, '1', MAX_CARACTERES_CADENA + 1);
        if (strlen(entrada[i]) > 0) {
            strncpy(cadena, entrada[i], strlen(entrada[i]) - 1);
        }
        resultado = largo_seguro(cadena, MAX_CARACTERES_CADENA);
        printf("\tCaracteres de entrada[%d] modificada sin fin de linea (CADENA_SIN_TERMINADOR %d): %d\n",
               i + 1, CADENA_SIN_TERMINADOR, resultado);
    }
    printf("\n");

    
    printf("* Prueba de cadena_insertar():\n");
    memset(cadena, '\0', MAX_CARACTERES_CADENA + 1);
    strcpy(cadena, entrada[1]);
    resultado = cadena_insertar(entrada[0], MAX_CARACTERES, POSICION_INSERCION, cadena, MAX_CARACTERES_CADENA);
    switch(resultado) {
    case CADENA_NO_ENTRA:
        printf("\tLas entradas [1] y [2] no entran en el espacio de entrada[2]\n");
        break;
    case CADENA_A_INSERTAR_POSTERIOR:
        printf("\tPosicion de insercion: %d\n", POSICION_INSERCION + 1);
        printf("\tLa entrada[1] se insertaría posterior al \\0 (fin) de entrada[2] en el espacio de entrada[2], no se mostraria\n");
        break;
    default:
        printf("\tLa insercion de entrada[1] en entrada[2] [posicion: %d] genera %d caracteres con: %s\n",
               POSICION_INSERCION + 1, resultado, cadena);
        break;
    }
    printf("\n");

    
    printf("* Prueba de cadena_copiar():\n");
    for (i = 0; i < 2; i++) {
        memset(cadena, '\0', MAX_CARACTERES_CADENA + 1);
        resultado = cadena_copiar(entrada[i], MAX_CARACTERES, cadena, MAX_CARACTERES_CADENA);
        if (resultado == CADENA_NO_ENTRA) {
            printf("\tLa entrada[%d] no entra en %d caracteres\n", i + 1, MAX_CARACTERES_CADENA);
        } else {
            printf("\tEl largo es %d de la copia de entrada[%d]: %s\n", resultado, i + 1, cadena);
        }
    }
    printf("\n");

    
    printf("* Prueba de cadena_limpiar():\n");
    for (i = 0; i < 2; i++) {
        memset(cadena, '\0', MAX_CARACTERES_CADENA + 1);
        resultado = cadena_limpiar(entrada[i], cadena, MAX_CARACTERES_CADENA);
        if (resultado == CADENA_NO_ENTRA) {
            printf("\tLa entrada[%d] no entra en %d caracteres\n", i + 1, MAX_CARACTERES_CADENA);
        } else {
            printf("\tEl largo es %d de la limpieza de entrada[%d]: %s\n", resultado, i + 1, cadena);
        }
    }
    printf("\n");

    
    printf("* Prueba de cadena_invertir():\n");
    for (i = 0; i < 2; i++) {
        memset(cadena, '\0', MAX_CARACTERES_CADENA + 1);
        resultado = cadena_invertir(entrada[i], MAX_CARACTERES, cadena, MAX_CARACTERES_CADENA);
        if (resultado == CADENA_NO_ENTRA) {
            printf("\tLa entrada[%d] no entra en %d caracteres\n", i + 1, MAX_CARACTERES_CADENA);
        } else {
            printf("\tEl largo es %d de la inversion de entrada[%d]: %s\n", resultado, i + 1, cadena);
        }
    }
    printf("\n");

    
    printf("* Prueba de cadena_comparar():\n");
    resultado = cadena_comparar(entrada[0], entrada[1], MAX_CARACTERES);
    switch (resultado) {
    case CADENA1_MENOR_A_CADENA2:
        printf("\tLa entrada[1] va antes alfabeticamente que la entrada[2]\n");
        break;
    case CADENA1_IGUAL_A_CADENA2:
        printf("\tLa entrada[1] es igual que la entrada[2]\n");
        break;
    case CADENA1_MAYOR_A_CADENA2:
        printf("\tLa entrada[1] va despues alfabeticamente que la entrada[2]\n");
        break;
    default:
        printf("\tResultado de la comparacion desconocido %d\n", resultado);
        break;
    }
    printf("\n");

    
    printf("* Prueba de cadena_contar_caracteres_alfa():\n");
    for (i = 0; i < 2; i++) {
        resultado = cadena_contar_caracteres_alfa(entrada[i]);
        printf("\tLa entrada[%d] tiene %d caracteres alfanumericos\n", i + 1, resultado);
    }
    printf("\n");

    
    printf("* Prueba de cadena_contar_simbolos():\n");
    for (i = 0; i < 2; i++) {
        resultado = cadena_contar_simbolos(entrada[i]);
        printf("\tLa entrada[%d] tiene %d caracteres que son simbolos\n", i + 1, resultado);
    }
    printf("\n");

    
    printf("* Prueba de cadena_a_minusculas():\n");
    for (i = 0; i < 2; i++) {
        memset(cadena, '\0', MAX_CARACTERES_CADENA + 1);
        strncpy(cadena, entrada[i], MAX_CARACTERES_CADENA);
        if (cadena[MAX_CARACTERES_CADENA - 1] != '\0') {
            printf("\tLa entrada[%d] no pudo copiarse en cadena\n", i + 1);
        } else {
            resultado = cadena_a_minusculas(cadena);
            printf("\tLa entrada[%d] en minusculas es: %s\n", i + 1, cadena);
        }
    }
    printf("\n");

    
    printf("* Prueba de cadena_a_mayusculas():\n");
    for (i = 0; i < 2; i++) {
        memset(cadena, '\0', MAX_CARACTERES_CADENA + 1);
        strncpy(cadena, entrada[i], MAX_CARACTERES_CADENA);
        if (cadena[MAX_CARACTERES_CADENA - 1] != '\0') {
            printf("\tLa entrada[%d] no pudo copiarse en cadena\n", i + 1);
        } else {
            resultado = cadena_a_mayusculas(cadena);
            printf("\tLa entrada[%d] en mayusculas es: %s\n", i + 1, cadena);
        }
    }
    printf("\n");

    
    printf("* Prueba de palindromo_seguro():\n");
    for (i = 0; i < 2; i++) {
        resultado = palindromo_seguro(entrada[i], MAX_CARACTERES);
        switch (resultado) {
        case FALSE:
            printf("\tLa entrada[%d] no es un palindromo\n", i + 1);
            break;
        case TRUE:
            printf("\tLa entrada[%d] es un palindromo (ignorando Mayusculas/minusculas)\n", i + 1);
            break;
        default:
            printf("\tResultado de test de palindromo desconocido %d\n", resultado);
            break;
        }
    }
    printf("\n");

    
    printf("* Prueba de palindromo_seguro_con_memoria_dinamica():\n");
    for (i = 0; i < 2; i++) {
        resultado = palindromo_seguro_con_memoria_dinamica(entrada[i], MAX_CARACTERES);
        switch (resultado) {
        case NOT_ENOUGH_MEMORY:
            printf("\tNo hay suficiente memoria en el sistema para copiar la entrada\n");
            break;
        case FALSE:
            printf("\tLa entrada[%d] no es un palindromo\n", i + 1);
            break;
        case TRUE:
            printf("\tLa entrada[%d] es un palindromo (ignorando Mayusculas/minusculas)\n", i + 1);
            break;
        default:
            printf("\tResultado de test de palindromo desconocido %d\n", resultado);
            break;
        }
    }
    printf("\n");

    return OK;
}
