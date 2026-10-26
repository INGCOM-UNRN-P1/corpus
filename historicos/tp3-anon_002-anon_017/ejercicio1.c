
#include <stdio.h>
#define MAXIMO 15
#define DOBLE_MAXIMO (MAXIMO * 2)
#define ERROR -1
 

int cargar_arreglo(int capacidad, int arreglo[]);
void muestra_arreglo(int capacidad, int arreglo[]);
void fusionador(int capacidad, int capacidad_2, int capacidad_mix, int arreglo_1[], int arreglo_2[], int arreglo_mix[]);
float promedio(int capacidad, int arreglo[]);
int minimo(int capacidad, int arreglo[]);
int maxima_posicion(int capacidad, int arreglo[]);
void menor_a_mayor(int capacidad, int arreglo[]);

//pre: Se necesita un numero entero.
//post:Se opera con el arreglo

int main()
{
    int arreglo_1[MAXIMO];//El primer arreglo
    int arreglo_2[MAXIMO];//El segundo arreglo
    int capacidad = 1;//capacidad del arreglo
    int capacidad_2 = 1;
    int capacidad_mix = 1;
    int error = 0;
    int error_2 = 0;
    int arreglo_mix[DOBLE_MAXIMO];
    int opcion = 0;
    float res_promedio = 0;
    int resultado = 0;
    
    printf("Ingrese 1 para fusionar arreglos\n");
    printf("Ingrese 2 para calcular el promedio de un arreglo\n");
    printf("Ingrese 3 para obtener el minimo de un arreglo\n");
    printf("Ingrese 4 para obtener la posicion del valor maximo de arreglo\n");
    printf("Ingrese 5 para ordenar un arreglo de menor a mayor\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    printf("Ingrese la capacidad del arrelgo (no mas de 15): ");
    scanf("%d",&capacidad);
    
    if (capacidad < 1)
    {
        printf("Matyor a 1!");
    }
    else
    {
        if(opcion == 1)
        {
            printf("Ingrese el primer arreglo\n");
            printf("------------------\n");
            error = cargar_arreglo(capacidad, arreglo_1);
            
            printf("Ingrese la capacidad del segundo arreglo (no mas de 15): ");
            scanf("%d",&capacidad_2);
            
            capacidad_mix = capacidad + capacidad_2; //Esto crea la capacidad necesaria para fusionar los arreglos.
            
            printf("------------------\n");
            printf("Ingrese el segundo arreglo\n");
            error_2 = cargar_arreglo(capacidad_2, arreglo_2);
            printf("------------------\n");
            
            
            
            if((error == ERROR) || (error_2 == ERROR))
            {
                printf("Error!");
            }
            else
            {
                fusionador(capacidad, capacidad_2, capacidad_mix, arreglo_1, arreglo_2, arreglo_mix);
                printf("MUESTRA:\n\n");
                printf("Primer arreglo\n");
                printf("------------------\n");
                muestra_arreglo(capacidad, arreglo_1);
                printf("------------------\n");
                printf("Segundo arreglo\n");
                muestra_arreglo(capacidad, arreglo_2);
                printf("------------------\n");
                printf("MIX\n\n");
                capacidad = capacidad * 2;//Esto es para que muestre el largo total de la fusion de los arreglos.
                muestra_arreglo(capacidad, arreglo_mix);
            }
        }
        else if(opcion == 2)
        {
            printf("Ingrese un arreglo\n");
            printf("------------------\n");
            error = cargar_arreglo(capacidad, arreglo_1);
            
            if(error == ERROR)
            {
                printf("Error!");
            }
            else
            {
                res_promedio = promedio(capacidad, arreglo_1);
                printf("El promedio del arreglo es: %.2f",res_promedio);
            }
        }
        else if(opcion == 3)
        {
            printf("Ingrese un arreglo\n");
            printf("------------------\n");
            error = cargar_arreglo(capacidad, arreglo_1);
            
            if(error == ERROR)
            {
                printf("Error!");
            }
            else
            {
                resultado = minimo(capacidad, arreglo_1);
                printf("El minimo del arreglo es: %d",resultado);
            }
        }
        else if(opcion == 4)
        {
            printf("Ingrese un arreglo\n");
            printf("------------------\n");
            error = cargar_arreglo(capacidad, arreglo_1);
            
            if(error == ERROR)
            {
                printf("Error!");
            }
            else
            {
                resultado = maxima_posicion(capacidad, arreglo_1);
                printf("La posicion del numero maximo del arreglo es la: [%d]",resultado);
            }
        }
        else if(opcion == 5)
        {
            printf("Ingrese un arreglo\n");
            printf("------------------\n");
            error = cargar_arreglo(capacidad, arreglo_1);
            
            if(error == ERROR)
            {
                printf("Error!");
            }
            else
            {
                menor_a_mayor(capacidad, arreglo_1);
                printf("El arreglo ordenado es\n");
                printf("----------------------\n");
                muestra_arreglo(capacidad, arreglo_1);
            }
        }
        else
        {
            printf("No es una opcion valida!!\n");
        }
    }
     
}


//post:Se carga un numero en cada posicion del arreglo desde 0 hasta.

int cargar_arreglo(int capacidad, int arreglo[])
{
    int contador = 0;
    int retorno = 0;
    
    if((capacidad > DOBLE_MAXIMO ) || (capacidad < 1))
    {
        retorno = -1;
    }
    else
    {
        while(contador < capacidad)
        {
        printf("Ingrese un numero para la posicion '%d': ",contador);
        scanf("%d",&arreglo[contador]);//Guardo el valor ingresado en la posicion de contador
        contador++;//Incremento la posicion en 1
        } 
    }   
    
    return retorno;
}


//post:Se imprime el valor de posicion en la posicion del arreglo.

void muestra_arreglo(int capacidad, int arreglo[])
{
    int posicion = 0;
    
    while(posicion < capacidad)
    {
        printf("El numero en la posicion '%d' es: %d\n",posicion,arreglo[posicion]);//Muestro el valor de la "posicion" en el arreglo
        posicion++;//Incremento la posicion en 1
    }
}


//post:Se guarda el arreglo 1 y 2 en uno solo.

void fusionador(int capacidad_1, int capacidad_2, int capacidad_mix, int arreglo_1[], int arreglo_2[], int arreglo_mix[])
{
    int contador = 0;
    int posicion = 0;
    
    while (contador < capacidad_1)
    {
        arreglo_mix[posicion] = arreglo_1[contador];
        contador++;
        posicion++;
    }
    
    contador = 0;
    
    while (contador < capacidad_2)
    {
        arreglo_mix[posicion] = arreglo_2[contador];
        contador++;
        posicion++;
    }    

}




float promedio(int capacidad, int arreglo[])
{
    int contador = 0;
    int suma = 0;
    float total = 0;
    
    
    while(contador < capacidad)//Mientras este dentro de la cadena
    {
        suma = suma + arreglo[contador];//sumo el valor de la posicion anterior con el de la posicion actual

        contador++;//Incremento la posicion.
    }
    

    total = suma / capacidad;//Diviso la suma total por la cantidad de numeros de la cadena.

    return total;
}





int minimo(int capacidad, int arreglo[])
{
    int contador = 0;
    int min = arreglo[0];//guardo el valor de la primera posicion
    
    while(contador < capacidad)//Esto recorre el arreglo
    {
        if(arreglo[contador] < min)//Compara si el valor anterior es menor al de ahora
        {
            min = arreglo[contador];//si es menor lo guarda
        }
        contador++;//Muevo la posicion en +1
    }
    
    return min;//retorno el valor minimo
}



int maxima_posicion(int capacidad, int arreglo[])
{
    int recorre = 0;
    int max = arreglo[0];//guardo el valor de la primera posicion
    int posicion = 0;
    
    while(recorre < capacidad)//recorro el arreglo
    {
        if(arreglo[recorre] > max)//si el numero en la posicion actual es mas grande que el de la posicion anterior
        {
            posicion = recorre;//Guarda la posicion del numero mas grande
        }
        recorre++;//Muevo la posicion. 
    }
    
    return posicion;//retorno la posicion del valor maxima
}



void menor_a_mayor(int capacidad, int arreglo[])
{
    int contador = 0;//recorre el arreglo 
    int recorre = 0;//recorre el arreglo para comparar
    int valor_min = 0;//Aca voy a guardar el valor minimo
    int posicion = 1;//Aca voy a guardar la posicon del valor minimo
    int valor_parcial= 0;//Aca guardo el valor que va a ser reemplazado, para despues devolverlo al arreglo.
 
    
    while(contador < capacidad)
    {
        valor_min = arreglo[contador];//Pongo como valor minimo el primer elemento
        
        for (recorre = contador + 1; recorre < capacidad; recorre++)//Empieza en + 1 para no contar la misma posicion que el contador.
        {
            
            if(valor_min > arreglo[recorre])//Si es menor al numero anterior encontrado como "minimo"
            {
                posicion = recorre;//Guardo la posicion del numero minimo
                valor_min = arreglo[recorre];//Guardo el valor minimo encontrado.
            }
            
        }
        
        valor_parcial = arreglo[contador];//guardo el valor que va a ser reemplazado
        arreglo[contador] = arreglo[posicion];//Reemplazo el valor de la posicion del numero comparado, con el valor minimo encontrado.
        arreglo[posicion] = valor_parcial;//Guardo el valor que fue anteriormente reemplazado, en la posicion que estaba antes el valor minimo.

        contador++;
    }
    
    
}
