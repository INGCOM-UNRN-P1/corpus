
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1 //codigo de error
#define ERROR_POSICION -2 //La posicion es menor a 1.
#define MAXIMO 10
#define CAPACIDAD_MAX 20 //Es el doble de la capacidad de la cadena normal
#define TRUE 1
#define FALSE 0


int largo_seguro(char cadena[], int capacidad);
int copiadora(char cadena[], char cadena_destino[], int capacidad, int capacidad_destino);
int insercion(char cadena[],char cadena_destino[], int capacidad,  int capacidad_destino, int posicion);
int limpiadora(char cadena[], char cadena_alfanumerica[], int capacidad, int capacidad_alfanumerica);
int comparacion(char cadena[], char cadena_destino[], int capacidad, int capacidad_2);
int a_minusculas(char cadena[], int capacidad);
int a_mayusculas(char cadena[], int capacidad);
int palindromo(char cadena[], int capacidad);


int main()
{
    char cadena[CAPACIDAD_MAX];
    char cadena_destino[CAPACIDAD_MAX];
    char cadena_alfanumerica[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";//Son 62 caracteres, pero pongo 63 para que este el terminador y se pueda comparar.
    int capacidad_alfanumerica = 63;
    int capacidad = MAXIMO;
    int capacidad_2 = MAXIMO;
    int respuesta = 0;
    int opcion = 0;
    int posicion = 0;
    
	
	printf("Ingrese una cadena de caracteres (no mas de 10) : ");
    fgets(cadena,CAPACIDAD_MAX,stdin);
        
    printf("Ingrese una segunda cadena de caracteres: ");
    fgets(cadena_destino,CAPACIDAD_MAX,stdin);
    
    
    printf("Ingrese 1 para ver el largo de una cadena   \n");
    printf("Ingrese 2 para copiar una cadena en otra    \n");
    printf("Ingrese 3 para insertar una cadena en otra  \n");
    printf("Ingrese 4 para limpiar una cadena           \n");
    printf("Ingrese 5 para pasar una cadena a mayusculas\n");
    printf("Ingrese 6 para pasar una cadena a minusculas\n");
    printf("Ingrese 7 para saber si una palabra es palindromo\n");
    printf("Ingrese 8 para saber que cadena va primera, en orden alfabetico\n");
	printf("Opcion: ");
    scanf("%d",&opcion);
	

	
	if (opcion == 1)
    {
         
        respuesta = largo_seguro(cadena, capacidad);
        printf("El largo de la cadena es de: %d caracteres.\n",respuesta);
		
    }
    else if (opcion == 2)
    {

        
        respuesta = largo_seguro(cadena, capacidad);
        
        if (respuesta == CADENA_SIN_TERMINADOR)
        {
            printf("Error\n");
        }
        else
        {
            copiadora(cadena, cadena_destino, respuesta, capacidad_2);
            printf("%s\n",cadena_destino);
        }    
    }
    else if (opcion == 3)
    {
        
        respuesta = insercion(cadena, cadena_destino, capacidad, capacidad_2, posicion);
        
        printf("La cadena insertada es: %s",cadena_destino);
		printf("Error (solo -1): %d\n",respuesta);
		
    }
    else if (opcion == 4)
    {

        respuesta = limpiadora(cadena, cadena_alfanumerica, capacidad, capacidad_alfanumerica);
        printf("El largo de la cadena limpia es: %d",respuesta);
		
    }
    else if(opcion == 5)
    {
        
        respuesta = a_mayusculas(cadena, capacidad);
        printf("%s",cadena);
        printf("Codigo de error (solo -1): %d",respuesta);
		
    }
    else if (opcion == 6)
    {   
       
	   respuesta = a_minusculas(cadena, capacidad);
        printf("%s",cadena);
        printf("Codigo de error (solo -1): %d",respuesta);
		
    }
    else if (opcion == 7)
    {

        
        respuesta = palindromo(cadena, capacidad);
        printf("%d",respuesta);
		
    }
	else if(opcion == 8)
	{	
		respuesta = comparacion(cadena, cadena_destino, capacidad, capacidad_2);
		printf("(-1) primera, (1 segundo) (0 iguales) || SON: %d",respuesta);
		
	}
	else
	{
		
		printf("No es una opcion!\n");
		
	}


}

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post se espera que se devuelva la longitud de la cadena ingresada.
 */
 
int largo_seguro(char cadena[], int capacidad)
{
    int contador = 0;
    int retorno = 0;
    
    while ((cadena [contador] != '\0') && (contador < capacidad)) //mientras no encuentra el terminador, suma la cantidad de caracteres.
    {
        contador++;//cuento los caracteres.
    }
    
    if(contador >= capacidad)
    {
        retorno = CADENA_SIN_TERMINADOR;//retorna sin terminador
    }
    else
    {
        retorno = contador;//retorna el largo de la cadena
    }
    
    return retorno;
        
}


/**
 * La funcion guarda los caracteres de una cadena en otra y devuelve la cantidad de caracteres de la cadena copiada.
 *  @param cadena es la direccion de la cadena de la que se guardaran los caracters
 *  @pre cadena es una cadena valida
 *  @param Es el tamaño maximo de la cadena
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param cadena_destino es la direccion de la cadena donde se guardara la primer cadena
 *  @pre cadena_destino es una cadena con la capacidad maxima
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
 *  @post se espera que otra cadena tenga el contenido de la cadena ingresada.
 */
 
 
int copiadora(char cadena[], char cadena_destino[], int capacidad, int capacidad_destino)
{
    int contador = 0;
     
    while ((contador < capacidad) && (contador < capacidad_destino))
    {
        cadena_destino[contador] = cadena[contador];//copia el caracter de la posicion contador en la cadena de destino.
        contador++;//esto recorre la cadena
    }
    
    return contador;
}

/**
 * La funcion inserta una cadena de caracteres en otra, en la posicion que se diga.
 *  @param cadena es la direccion de la cadena que se va a insertar
 *  @pre cadena es una cadena valida
 *  @param cadena_destino es la direccion de la cadena donde se va a insertar "cadena"
 *  @pre cadena_destino es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param posicion es en la posicion de donde se va a insertar la cadena en cadena_destino
 *  @pre es un numero entero positivo mayor a 1.
 *  @returns el codigo de error correspondiente, siendo -1 que la cadena no tiene terminador y -2 que la posicion no es valida
 *  @post se espera que la cadena se inserte en otra o el codigo de error correspondiente
 */
 
 
int insercion(char cadena[],char cadena_destino[], int capacidad, int capacidad_destino, int posicion)
{
    int contador = 0; //Esto recorre la cadena
    int largo1 = 0;//veo el largo de la cadena 1
    int largo2 = 0;//Veo el largo de la cadena 2
    int retorno = 0;//retorna el codigo de error
    int ultima_posicion = 0;//Guarda en donde quedo el ultimo caracter de la cadena insertada.
    char cadena_aux[CAPACIDAD_MAX]; //Esta cadena es para guardar los caracteres que se van a pegar despues de que se  inserte la cadena
    
    largo1 = largo_seguro(cadena, capacidad);//veo que tenga terminador.
    largo2 = largo_seguro(cadena_destino, capacidad_destino);//veo que tenga terminador.
    

    if (posicion < 1)
	{
		retorno = ERROR_POSICION;
	}
    else if((largo1 == CADENA_SIN_TERMINADOR) || (largo2 == CADENA_SIN_TERMINADOR))//si no tiene terminador, no puede seguir.
    {
        retorno = CADENA_SIN_TERMINADOR;//retorna codigo de error
    }
    else//Si tiene terminador, empieza con la incersion de cadena.
    {
        
        while(contador < largo1)//inserto la cadena en la cadena destino, en la posicion deseada
        {
            cadena_aux[contador] = cadena_destino[posicion];//guardo los caracteres que se van a borrar, para que no se borre
            cadena_destino[posicion] = cadena[contador];//inserto el caracter
            contador++;//esto recorre la cadena
            posicion++;//Aca es donde se va "sobreescirbiendo" la cadena_destino
            ultima_posicion++;//esto es para ver hasta donde llego de la cadena_destino
        }
        
        contador = 0;//Esto es para que recorra la cadena auxiliar
        ultima_posicion++; //Le incremento 1 por que si no sobreescribiria el ultimo digito

        
        while(ultima_posicion < CAPACIDAD_MAX)
        {
   
            
            cadena_destino[ultima_posicion] = cadena_aux[contador];//Guardo en la ultima posicion que se escribio, lo que habia antes en la cadena_destino.
            ultima_posicion++;//recorre la cadena_destino
            contador++;//recorre la cadena_aux
            
        }
        
    }   
	
	return retorno;
    
}


/**
 * La funcion copia los caracteres alfanumericos a una cadena nueva.
 *  @param cadena es la direccion de la cadena que se "limpiara"
 *  @pre cadena es una cadena valida
 *  @param cadena_alfanumerica es la direccion de la cadena con la que se va a comparar la cadena que va a ser limpiada.
 *  @pre cadena_alfanumerica es una cadena valida de todos los caracteres alfanumericos
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns el codigo de error correspondiente, siendo -1 que la cadena no tiene terminador.
 *  @post se espera que se copien los caracteres alfanumericos en otra cadena.
 */
 
 
int limpiadora(char cadena[], char cadena_alfanumerica[], int capacidad, int capacidad_alfanumerica)
{
    int contador = 0; //Recorre la cadena
    int largo = 0;
    int largo_alfanumerico = 0;
    char cadena_limpia[CAPACIDAD_MAX];//Aca voy a guarda la cadena limpia
    int retorno = 0;
    
    largo = largo_seguro(cadena, capacidad);
    largo_alfanumerico = largo_seguro(cadena_alfanumerica, capacidad_alfanumerica);
    
    if ((largo == CADENA_SIN_TERMINADOR) || (largo_alfanumerico == CADENA_SIN_TERMINADOR))
    {
        retorno =  CADENA_SIN_TERMINADOR;//retorna error si no hay terminador
    }
    else
    {
        while(contador < largo)
        {
            for(int i = 0; i < 63; i++)//63 por que es la cantidad de digitos que tiene la cadena con la que se compara para limpiar.
            {
                if(cadena[contador] == cadena_alfanumerica[i])
                {
                    cadena_limpia[contador] = cadena[contador];//Guardo en la cadena vacia, los caracteres limpios.
                }
                
            }
            contador++;
            
        }
        
        largo = largo_seguro(cadena_limpia, capacidad);//veo el largo de la cadena limpia.
        retorno = largo;//El retorno es el largo
        
    }
    
    return retorno;
    

    
}


/**
 * La funcion pasa los caracteres mayusculas a minusculas, comparando con 1 cadena que tiene los caracteres en minusculas y con otra cadena que tiene
 * los caracteres en mayuscula, al encontrar un caracter mayuscula, lo intercambia por el mismo en minusculas.
 *  @param cadena es la direccion de la cadena que se pasara a minuscula
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns el codigo de error correspondiente, siendo -1 que la cadena no tiene terminador.
 *  @post se espera que la cadena ingresada, se modifique quedando todos los caracteres en minuscula
 */
 
 
 
int a_minusculas(char cadena[], int capacidad)
{
    char cadena_minuscula[27] = "abcdefghijklmnopqrstuvwxyz";
    char cadena_mayuscula[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int contador = 0;
    int largo = 0;
    
    largo = largo_seguro(cadena, capacidad);
    
    if (largo == CADENA_SIN_TERMINADOR)
    {
        return CADENA_SIN_TERMINADOR;//retorna error si no hay terminador
    }
    else
    {
        while(contador < largo)
        {
            for (int i = 0; i < 26 ; i++)//Esto recorre la cadena mayuscula y minuscula, son 26 caracteres para que no tome el terminador
            {
                if(cadena[contador] == cadena_mayuscula[i])//cuando encuentra la letra minuscula
                {
                    cadena[contador] = cadena_minuscula[i];//La pasa a mayuscula.
                }
            }
            contador++; //Contador recorre la cadena original
        }
    } 
}


/**
 * La funcion pasa los caracteres mayusculas a minusculas, comparando con 1 cadena que tiene los caracteres en minusculas y con otra cadena que tiene
 * los caracteres en mayuscula, al encontrar un caracter minuscula, lo intercambia por el mismo en mayusculas.
 *  @param cadena es la direccion de la cadena que se pasara a mayuscula
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns el codigo de error correspondiente, siendo -1 que la cadena no tiene terminador.
 *  @post se espera que la cadena ingresada, se modifique quedando todos los caracteres en mayuscula
 */
 
int a_mayusculas(char cadena[], int capacidad)
{
    char cadena_minuscula[27] = "abcdefghijklmnopqrstuvwxyz";
    char cadena_mayuscula[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int contador = 0;
    int largo = 0;
    
    largo = largo_seguro(cadena, capacidad);
    
    if (largo == CADENA_SIN_TERMINADOR)
    {
        return CADENA_SIN_TERMINADOR;//retorna error si no hay terminador
    }
    else
    {
        while(contador < largo)
        {
            for (int i = 0; i < 27 ; i++)//Esto recorre la cadena mayuscula y minuscula, llega hasta 27 por que son 27 caracteres
            {
                if(cadena[contador] == cadena_minuscula[i])//cuando encuentra la letra minuscula
                {
                    cadena[contador] = cadena_mayuscula[i];//La pasa a mayuscula.
                }
            }
            contador++; //Contador recorre la cadena original
        }
    }  

}

/**
 * La funcion invierte la cadena original y la copia en otra, para despues compararla. Tiene un contador que suma la cantidad de coincidencias que hay en las
 * posiciones de las cadenas, en caso de que haya la misma cantidad de coincidencias y del largo de la cadena, la palabra es palindromo
 *  @param cadena es la direccion de la cadena que se pasara a minuscula
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns el codigo de error correspondiente, siendo -1 que la cadena no tiene terminador.
 *  @post se espera que se devuelva si la cadena es palindromo o no.
 */
 
 
int palindromo(char cadena[], int capacidad)
{
    char cadena_aux[CAPACIDAD_MAX];
    int contador = 0;
    int contador_reversa = 0;
    int coincidencias = 0;
    int largo = 0;
	int retorno = 0;
    
    
    largo = largo_seguro(cadena, capacidad);
    
    if (largo != CADENA_SIN_TERMINADOR)
    {
         //este contador empieza desde la ultima posicion.
        contador_reversa = largo - 2;//resto 2 para no contar el terminador
        

        
        while((contador < largo ) && (cadena[contador] != '\0'))//primero copio la cadena original en otra, del reves
        {
            cadena_aux[contador_reversa] = cadena[contador];//Copio la primera posicion, en la ultima de la cadena auxiliar
            contador++;//Esta es la posicion que se copia, desde la primera hasta la ultima
            contador_reversa--;//Esta es la posicion donde se copia, desde el final al principio, para invertir la cadena
        }
        

        contador = 0;
        
        
        while ((contador < largo ) && (cadena[contador] != '\0'))
        {

            if(cadena[contador] == cadena_aux[contador])//si coinciden
            {
                coincidencias++;//Sumo las coincidencias.
            }
            contador++;

        }
        largo--; //Esto es para no contar el terminador
        
        
    }  
    else if(largo == CADENA_SIN_TERMINADOR)//Si dio error, devuelve el error
    {
        retorno = CADENA_SIN_TERMINADOR;
    }
    
    
    if( coincidencias == largo)//si tiene el mismo largo que coincidencias, es palindromo
    {
        retorno = TRUE;
    }
    else//si no , no es palindromo.
    {
        retorno = FALSE;
    }
    
    return retorno;     
    
}

/**
 * La funcion compara las cadenas ingresadas con un orden preestablecido, la primer cadena que tenga un caracter que la otra no tenga de la cadena ordenada,
 * significa que la cadena que no tiene el caracter, va despues de la cadena que si lo tiene. En caso de que sean iguales, se retornara que son iguales.
 *  @param cadena es la direccion de la cadena que se comparara con la segunda cadena
 *  @pre cadena es una cadena valida
 *  @param cadena_destino es la cadena que se va a comparar con la primer cadena.
 *  @pre cadena_destino es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns el codigo de error correspondiente, siendo -1 que la cadena no tiene terminador.
 *  @post se espera que se retorne que cadena va antes o que son iguales.
 */


int comparacion(char cadena[], char cadena_destino[], int capacidad, int capacidad_2)
{
	char cadena_orden[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";//son 62 caracteres + 1 para el terminador
	int retorno = 0;
    int contador = 0;
	int largo = 0;
    int largo_2 = 0;
    
	
	largo = largo_seguro(cadena, capacidad);
    largo_2 = largo_seguro(cadena, capacidad_2);
	
	
	if ((largo == CAPACIDAD_MAX) || (largo_2 == CAPACIDAD_MAX))
	{
		retorno = CAPACIDAD_MAX;//esto es para que no haga nada si tiene error.
	}
	else
	{
		while(contador < largo )
		{
			
			
			for(int i = 0; i < 62; i++)//esto es para recorrer la cadena que da el orden "cadena_orden"//62 para que no tome el '\0'
			{
				if((cadena[contador] == cadena_orden[i]) && (cadena_destino[contador] != cadena_orden[i]))//Si encuentra 1 coincidencia de la primera y no la segunda 
				{																						  //la primera va antes
					retorno = -1;//-1 es que la primer cadena es mas grande que la segunda
					contador = largo;//Si encuentra, que salga
				}
				else if ((cadena[contador] != cadena_orden[i]) && (cadena_destino[contador] == cadena_orden[i]))//si coincide 1 de la segunda y no la primera
				{																							    // La segundo va antes
					retorno = 1;//1 es que la segunda es mas grande que la primera
					contador = largo;//Si encuentra, que salga
				}
				//retorno queda 0 si no encuentra un orden, por lo que las cadenas son iguales.
			}
			
			contador++;
		}
	
	}
	
	return retorno;
	
}