

#include <stdio.h>
#include <string.h>
#define CADENA_SIN_TERMINADOR -1
#define NO_ARGUMENTOS -2
#define UNA_CADENA -3
#define MAXIMO 1000
void vaciar(char cadena[], int capacidad)
{
    /**
    *  La funcion vacia las cadenas ( generalmente auxiliares) para no generar errores en las otras funciones.
    *  @param cadena es la direccion de la cadena en la que se eliminaran los caracteres
    *  @pre cadena es un puntero no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @pre es un valor numerico entero positivo mayor a uno
    *  @post La cadena se vacia y se devuelve vacia
    */
    int i = 0;
    while (cadena[i] != '\0' && i <= capacidad)
    {
        cadena[i] = '\0';
        i++;
    }
}
void mostrar(char cadena[], int capacidad)
{
    /**
    *  La funcion muestra las cadenas al final de cada funcion siguiente.
    *  @param cadena es la direccion de la cadena que se muestra.
    *  @pre cadena es un puntero no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post La cadena se printea para mostrarle al usuario.
    */
    printf("La cadena quedo : %s \n", cadena); 
}
int largo_seguro(char cadena[], int capacidad)
{
    /**
    *  La funcion cuenta la cantidad de caracteres en la cadena siempre y cuando respete el largo seguro '\0'
    *  @param cadena es la direccion de la cadena que se usa para contar caracteres.
    *  @pre cadena es un puntero no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post se devuelve caracteres que es la cantidad de caracteres existentes en la cadena con largo seguro.
    */
    int caracteres = 0;
    while(cadena[caracteres] != '\0' && caracteres <= capacidad)
    {
        caracteres++;
    }
    if(caracteres == 0)
    {
        caracteres = CADENA_SIN_TERMINADOR;
    }
    return caracteres;
}
int insercion(char cadena[], int posicion, char cadena2[], char cadenaux[], int largo1, int largo2, int capacidad)
{
    /**
    *  La funcion inserta la primer cadena dentro de la segunda.
    *  @param cadena es la direccion de la cadena que se usa para traer la primer cadena ingresada por ./a.exe.
    *  @param cadena2 es la direccion de la segunda cadena para la insercion ./a.exe.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se inserta la cadena en la posicion elegida por el usuario, se devuelve usando la funcion mostrar.
    */
    int caracter1 = 0;
    int caracter2 = 0;
    int caracter3 = 0;
    int largo = 0;
    if(posicion < largo2)
    {
        while(caracter1 <= largo2)
        {
            cadenaux[caracter1] = cadena2[caracter1];
            caracter1++;
        }
        caracter1 = 0;
        caracter2 = posicion + 1;
        caracter3 = posicion + 1;
        while(caracter1 < largo1)
        {
            cadenaux[caracter2] = cadena[caracter1];
            caracter1++;
            caracter2++;
        }
        while(caracter2 <= (largo1 + largo2))
        {
            cadenaux[caracter2] = cadena2[caracter3];
            caracter2++;
            caracter3++;
        }
        largo = largo_seguro(cadenaux, capacidad);
    }
    else
    {
        largo = CADENA_SIN_TERMINADOR;
    }
    mostrar(cadenaux, capacidad);
    return largo;
}
int copia(char cadena[], char cadenaux[], int largo1, int capacidad)
{
    /**
    *  La funcion copia una cadena en otra.
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux es la direccion de la segunda cadena para copia ./a.exe.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se copia la cadena en otra y se devuelve con un return, ademas de ser mostrada con la funcion mostrar.
    */
    int largocopia = 0;
    int contador = 0;
    while(contador < largo1)
    {
        cadenaux[contador] = cadena[contador];
        contador++;
    }
    if (cadena[contador] == '\0')
    {
        cadenaux[contador] = '\0';
    }
    largocopia = largo_seguro(cadenaux, capacidad);
    mostrar(cadenaux, capacidad);
    return largocopia;
    
}
int limpieza(char cadena[], char cadenaux2[], char cadenaux3[], int largo, int capacidad)
{
    /**
    *  La funcion limpia los caracteres no alfanumericos.
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se va a guardar la cadena con caracteres unicamente alfanumericos ./a.exe.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se limpia la cadena elegida por el usuario y se devuelve la cantidad de caracteres alfanumericos.
    */
	int i = 0;
	int j = 0;
    vaciar(cadenaux2, capacidad);
    vaciar(cadenaux3, capacidad);
    while (i < largo && cadena[i] != '\0')
    {
        cadenaux3[i] = cadena[i];
        i++;
    }
    i = 0;
	while (i < largo && cadena[i] != '\0')
	{
		if (cadenaux3[i] <= 57 && cadenaux3[i] >= 48)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
		}
		else if (cadenaux3[i] <= 90 && cadenaux3[i] >= 65)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
           
		}
		else if (cadenaux3[i] <= 122 && cadenaux3[i] >= 97)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
		}
		else
		{
            cadenaux3[i] = cadenaux3[i + 1];
        }
        i++;
	}
	largo = largo_seguro(cadenaux2, capacidad);
    mostrar(cadenaux2, capacidad);
	return largo;
}
int limpiezanumeros(char cadena[], char cadenaux2[], char cadenaux3[], int largo, int capacidad)
{
    /**
    *  La funcion limpia los caracteres que no sean letras.
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se va a guardar la cadena con caracteres unicamente alfanumericos ./a.exe.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se limpia la cadena elegida por el usuario y se devuelve la cantidad de caracteres sin numeros.
    */
	int i = 0;
	int j = 0;
    while (i < largo && cadena[i] != '\0')
    {
        cadenaux3[i] = cadena[i];
        i++;
    }
    i = 0;
	while (i < largo && cadena[i] != '\0')
	{
		if (cadenaux3[i] <= 90 && cadenaux3[i] >= 65)
		{
			cadenaux2[j] = cadenaux3[i] + 32;;
            j++;
           
		}
		else if (cadenaux3[i] <= 122 && cadenaux3[i] >= 97)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
		}
		else
		{
            cadenaux3[i] = cadenaux3[i + 1];
        }
        i++;
	}
	largo = largo_seguro(cadenaux2, capacidad);
    mostrar(cadenaux2, capacidad);
	return largo;
}
int inversor(char cadena[], char cadenaux2[], char cadenaux3[], int largo1, int capacidad, int variable)
{
    /**
    *  La funcion invierte la cadena proveniente de ./a.exe
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se va a guardar la cadena con caracteres unicamente alfanumericos ./a.exe.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se invierte la cadena y se muestra con la funcion mostrar.
    */
    int i = 0;
    int j = 0;
    int k = 0;
    copia(cadena, cadenaux2, largo1, capacidad);
    copia(cadena, cadenaux3, largo1, capacidad);
    k = largo_seguro(cadenaux2,capacidad);
    j = k - 1;
    while (i <= k - 1)
    {
        cadenaux3[j] = cadenaux2[i];
        i++;
        j--;
    }
    largo1 = largo_seguro(cadenaux3, MAXIMO);
    mostrar(cadenaux3, capacidad);
    return largo1;
    
}
int comparacion(char cadena[], char cadenaux[], char cadenaux2[], char cadenaux3[], char cadenaux4[], int largo, int capacidad)
{
    /**
    *  Se compara que cadena va antes en orden alfabetico
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param resultadocomparacion es un entero donde se guarda el valor para saber cual va antes o despues.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se devuelve mediante valor 0, -1 o 1 que cadena va antes, despues o si son iguales y por ende van el en mismo orden.
    */
    int i = 0;
    int j = 0;
    int resultadocomparacion = 0;
    vaciar(cadenaux2, capacidad);
    vaciar(cadenaux3, capacidad);
    limpiezanumeros(cadena, cadenaux2, cadenaux3, largo, capacidad);
    vaciar(cadenaux3, capacidad);
    limpiezanumeros(cadenaux, cadenaux3, cadenaux4, largo, capacidad);
    if(cadenaux2[i] == cadenaux3[i])
    {
        while(cadenaux2[i] == cadenaux3[i] && cadenaux2[i] != '\0')
        {
            i++;
        }
        if (cadenaux2[i] < cadenaux3[i])
        {
           resultadocomparacion = -1;
        }
        if (cadenaux3[i] < cadenaux2[i])
        {
            resultadocomparacion = 1;
        }
        if (cadenaux2[i] == cadenaux3[i])
        {
            resultadocomparacion = 0;
        }
    }
    else if(cadenaux2[i] < cadenaux3[i])
    {
        resultadocomparacion = -1;
    }
    else
    {
        resultadocomparacion = 1;
    }
    return resultadocomparacion;
}
int contador(char cadena[], char cadenaux2[],char cadenaux3[], int capacidad, int largo)
{
    /**
    *  Se cuenta la cantidad de caracteres alfanumericos en una cadena
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se va a guardar la cadena con caracteres unicamente alfanumericos ./a.exe.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se devuelve mediante valor 0, -1 o 1 que cadena va antes, despues o si son iguales y por ende van el en mismo orden.
    */
    int contador = 0;
    int i = 0;
    int j = 0;
    vaciar(cadenaux2, capacidad);
    vaciar(cadenaux3, capacidad);
    limpieza(cadena, cadenaux2, cadenaux3, largo, capacidad);
    while (i < largo && cadenaux2[i] != '\0')
    {
        contador++;
        i++;
    }
    return contador;
}
int contadorsimbolos(char cadena[], char cadenaux2[],char cadenaux3[], int capacidad, int largo)
{
    /**
    *  Se cuenta la cantidad simbolos en una cadena
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se guardan los simbolos de la cadena
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post se devuelve la cuenta de los simbolos y la funcion mostrada con mostrar
    */
    int i = 0;
	int j = 0;
    vaciar(cadenaux2, capacidad);
    vaciar(cadenaux3, capacidad);
    while (i < largo && cadena[i] != '\0')
    {
        cadenaux3[i] = cadena[i];
        i++;
    }
    i = 0;
	while (i < largo && cadena[i] != '\0')
	{
		if (cadenaux3[i] <= 47 && cadenaux3[i] >= 32)
		{
			cadenaux2[j] = cadenaux3[i];;
            j++;
           
		}
		else if (cadenaux3[i] <= 64 && cadenaux3[i] >= 58)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
		}
        else if (cadenaux3[i] <= 96 && cadenaux3[i] >= 91)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
		}
        else if (cadenaux3[i] <= 126 && cadenaux3[i] >= 123)
		{
			cadenaux2[j] = cadenaux3[i];
            j++;
		}
		else
		{
            cadenaux3[i] = cadenaux3[i + 1];
        }
        i++;
	}
	largo = largo_seguro(cadenaux2, capacidad);
    mostrar(cadenaux2, capacidad);
	return largo;
}
void mayuscminusc(char cadena[], char cadenaux2[],char cadenaux3[], int capacidad, int largo, int posicion)
{
    /**
    *  Se transforma de mayusculas a minusculas o de minusculas a mayusculas elegido por el usuario
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se devuelve la cadena en mayuscula o minuscula.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post No se devuelve nada pero se muestra con mostrar
    */
    vaciar(cadenaux2, capacidad);
    vaciar(cadenaux3, capacidad);
    int i = 0;
	int j = 0;
    while (i < largo && cadena[i] != '\0')
    {
        cadenaux3[i] = cadena[i];
        i++;
    }
    i = 0;
    if (posicion == 1)
    {
        while (i < largo && cadena[i] != '\0')
        {
            if (cadenaux3[i] <= 122 && cadenaux3[i] >= 97)
            {
                cadenaux2[j] = cadenaux3[i] - 32;;
                j++;
               
            }
            else if (cadenaux3[i] <= 90 && cadenaux3[i] >= 65)
            {
                cadenaux2[j] = cadenaux3[i];
                j++;
            }
            else
            {
                cadenaux3[i] = cadenaux3[i + 1];
            }
            i++;
        }
    }
    else 
    {
        while (i < largo && cadena[i] != '\0')
        {
            if (cadenaux3[i] <= 90 && cadenaux3[i] >= 65)
            {
                cadenaux2[j] = cadenaux3[i] + 32;;
                j++;
               
            }
            else if (cadenaux3[i] <= 122 && cadenaux3[i] >= 97)
            {
                cadenaux2[j] = cadenaux3[i];
                j++;
            }
            else
            {
                cadenaux3[i] = cadenaux3[i + 1];
            }
            i++;
        }
    }
    mostrar(cadenaux2, capacidad);
    
}
int palindromo(char cadena[], char cadenaux2[],char cadenaux3[], int capacidad, int largo)
{
    /**
    *  Se verifica si una cadena es palindromo o no
    *  @param cadena es la direccion de la cadena que se usa para traer la cadena ingresada por ./a.exe.
    *  @param cadenaux2 es la direccion donde se devuelve la cadena.
    *  @pre cadena y cadena 2 son punteros no nulo
    *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
    *  @post Se devuelve 1 si es palindromo y 0 si no lo es, se muestra con mostrar.
    */
    int i = 0;
    int j = 0;
    int k = 0;
    int contador = 0;
    vaciar(cadenaux2, capacidad);
    vaciar(cadenaux3, capacidad);
    limpiezanumeros(cadena, cadenaux2, cadenaux3, largo, capacidad);
    k = largo_seguro(cadenaux2,capacidad);
    j = k - 1;
    while (i <= k - 1)
    {
        if (cadenaux2[j] == cadenaux2[i])
        {
            contador++;
        }
        i++;
        j--;
    }
    if (k == contador)
    {
        k = 1;
    }
    else
    {
        k = 0;
    }
    mostrar(cadenaux2, capacidad);
    return k;
}
int main(int argc, char *argv[])
{
    int i = 1;
    int posicion = -1;
    int resultado = 0;
    int capacidad = MAXIMO;
    int variable = 0;
    char cadenaux[MAXIMO];
    char cadenaux2[MAXIMO];
    char cadenaux3[MAXIMO];
    char cadenaux4[MAXIMO];
    int largo = 0;
    int largo1 = 0;
    int largo2 = 0;
    if (argc > 2)
    {
        while(i < argc)
        {
            resultado = largo_seguro(argv[i], MAXIMO);
            if(resultado != -1)
            {
                printf("Palabra posicion [%d] Cantidad : %d\n", i-1, resultado);
                i++;
            }
            else
            {
                printf("%d", CADENA_SIN_TERMINADOR);
            }
        }
        largo1 = largo_seguro(argv[1], MAXIMO);
        largo2 = largo_seguro(argv[2], MAXIMO);
        while(posicion < 0)
        {
            printf("Ingrese la posicion (en un natural positivo o 0) donde insertar la nueva cadena en la anterior: \n");
            scanf("%i", &posicion);
        }
        largo = insercion(argv[1], posicion, argv[2], cadenaux, largo1, largo2, capacidad);
        if(largo == CADENA_SIN_TERMINADOR)
        {
            printf("%i", CADENA_SIN_TERMINADOR);
        }
        else
        {
            printf("El largo de las 2 cadenas es de %d\n", largo);      
        }
        resultado = copia(argv[1], cadenaux, largo1, capacidad);
        printf("El largo de la copia da como resultado: %d\n", resultado);
       
        while(variable < 1 || variable >= argc)
        {
            printf("Que cadena desea limpiar (numero > 1)? : \n");
            scanf("%i", &variable);
        }
        resultado = limpieza(argv[variable], cadenaux2, cadenaux3, largo, capacidad);
        if (largo != CADENA_SIN_TERMINADOR)
        {
            printf("El largo de la cadena es de %d : \n", resultado);
        }
        else
        {
        printf("El largo de la cadena limpia es de %d : \n", CADENA_SIN_TERMINADOR);   
            
        }
        variable = 0;
        while(variable < 1 || variable >= argc)
        {
            printf("Que cadena desea invertir (numero > 1)? : \n");
            scanf("%i", &variable);
        }
        resultado = inversor(argv[variable], cadenaux2, cadenaux3, largo1, capacidad, variable);
        printf("El resultado de la inversion da como resultado %d: \n", resultado); 
        resultado = comparacion(argv[1], argv[2], cadenaux2, cadenaux3, cadenaux4, largo, capacidad);
        printf("El resultado de la comparacion entre las primeras 2 cadenas es %d: \n", resultado);
        variable = 0;
        while(variable < 1 || variable >= argc)
        {
            printf("En que cadena desea contar alfanumericos? (numero > 1)? : \n");
            scanf("%i", &variable);
        }
        resultado = contador(argv[variable], cadenaux2, cadenaux3, capacidad, largo);
        printf("La cantidad de caracteres alfanumericos es de %d: \n", resultado);
        variable = 0;    
        while(variable < 1 || variable >= argc)
        {
            printf("En que cadena desea contar simbolos? (numero > 1)? : \n");
            scanf("%i", &variable);
        }
        resultado = contadorsimbolos(argv[variable], cadenaux2, cadenaux3, capacidad, largo);
        printf("La cantidad de simbolos es de %d\n", resultado);
        variable = 0;
        posicion = -1;
        while(variable < 1 || variable >= argc)
        {
            printf("En que cadena desea transformar a minusc o mayusc? (numero > 1)? : \n");
            scanf("%i", &variable);
        }
        while(posicion < 1 || posicion >= argc)
        {
            printf("Para transformar de mayusc a minusc ingrese 2, para transformar de minusc a mayusc ingrese 1\n: ");
            scanf("%i", &posicion);
        }
        mayuscminusc(argv[variable], cadenaux2, cadenaux3, capacidad, largo, posicion);
        variable = 0;
        while(variable < 1 || variable >= argc)
        {
            printf("En que cadena desea verificar si es palindromo? (numero > 1)? : \n");
            scanf("%i", &variable);
        }
        resultado = palindromo(argv[variable], cadenaux2, cadenaux3, capacidad, largo);
        if (resultado == 1)
        {
            printf("TRUE");
        }
        else
        {
            printf("FALSE");
        }
        
    }
    else if(argc == 2)
    {
        printf("%d", UNA_CADENA);
    }
    else
    {
        printf("%d\n", NO_ARGUMENTOS);
    }
    return 0;
}