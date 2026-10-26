
#include <stdio.h>
#define MAXIMA_CAPACIDAD 10
#define CAPACIDAD_TOTAL (MAXIMA_CAPACIDAD * 2)


typedef struct struct_arreglo{
    int arreglo[MAXIMA_CAPACIDAD]; //Es el arreglo
    int capacidad;//Es la capacidad del arreglo normal
	int arreglo_grande[MAXIMA_CAPACIDAD];//Este arreglo es para guardar el arreglo fusionado.
}struct_arreglo_t;


struct_arreglo_t cargar_arreglo(struct_arreglo_t arreglo1);
void muestra_arreglo(struct_arreglo_t arreglo1);
struct_arreglo_t fusionador(struct_arreglo_t arreglo1, struct_arreglo_t arreglo2);
struct_arreglo_t ordena_arreglo(struct_arreglo_t arreglo1);

int main()
{
    struct_arreglo_t arreglo1;
    struct_arreglo_t arreglo2;
    struct_arreglo_t arreglo_grande;
    int opcion = 0;
	int suma_capacidad = 0;
	
	printf("Ingrese 1 para fusionar un arreglo\n");
	printf("Ingrese 2 para ordenar un arreglo\n");
	printf("Opcion: ");
	scanf("%d",&opcion);
	
	
    
	if(opcion == 1)
	{
		
		printf("Ingrese la capacidad del arreglo: ");
		scanf("%d",&arreglo1.capacidad);
		
		printf("Ingrese la capacidad del segundo arreglo: ");
		scanf("%d",&arreglo2.capacidad);
		
		suma_capacidad = arreglo1.capacidad + arreglo2.capacidad;//La suma de la capacidad de los 2 es la capacidad del arreglo fusionado. 
		
		printf("Primer arreglo.\n");
		arreglo1 = cargar_arreglo(arreglo1);
		
		printf("Segundo arreglo.\n");
		arreglo2 = cargar_arreglo(arreglo2);
		
		
		arreglo_grande = fusionador(arreglo1, arreglo2);
		

		arreglo_grande.capacidad = suma_capacidad; //Asigno la capacidad sumada, para que imprima lo que se "fusiono".

		printf("Arreglo fusionado\n");
		
		muestra_arreglo(arreglo_grande);
			
	}
	else if(opcion == 2)
	{
		printf("Ingrese la capacidad del arreglo: ");
		scanf("%d",&arreglo1.capacidad);
		
		arreglo1 = cargar_arreglo(arreglo1);
		
		arreglo1 = ordena_arreglo(arreglo1);
		
		printf("\n");
		printf("--El arreglo ordenado--\n");
		
		muestra_arreglo(arreglo1);
		
	}
	else
	{
		printf("No es una opcion!");	
	}
	
    

    
}




struct_arreglo_t cargar_arreglo(struct_arreglo_t arreglo1)
{
    int contador = 0;
    struct_arreglo_t retorno;
    
    if((arreglo1.capacidad > MAXIMA_CAPACIDAD ) || (arreglo1.capacidad < 1))
    {
        retorno = arreglo1;//retorna el arreglo pelado si da error
    }
    else
    {
        while(contador < arreglo1.capacidad)
        {
        printf("Ingrese un numero para la posicion '%d': ",contador);
        scanf("%d",&arreglo1.arreglo[contador]);//Guardo el valor ingresado en la posicion de contador
        contador++;//Incremento la posicion en 1
        } 
    }   
    
    return arreglo1;//retorna el arreglo vacio o el arreglo cargado
}



void muestra_arreglo(struct_arreglo_t arreglo1)
{
    int posicion = 0;
    
    while(posicion < arreglo1.capacidad)
    {
        printf("El numero en la posicion '%d' es: %d\n",posicion,arreglo1.arreglo[posicion]);//Muestro el valor de la "posicion" en el arreglo
        posicion++;//Incremento la posicion en 1
    }
}


struct_arreglo_t fusionador(struct_arreglo_t arreglo1, struct_arreglo_t arreglo2)
{
    struct_arreglo_t arreglo_fusionado;
	
	int contador = 0;
    int posicion = 0;
    
    while (contador < arreglo1.capacidad)
    {
        arreglo_fusionado.arreglo[posicion] = arreglo1.arreglo[contador];
        contador++;
        posicion++;//Esto cuando termine, va a empezar el donde tiene que seguir pegando el arreglo.
    }
    
    contador = 0;
    
    while (contador < arreglo2.capacidad)
    {
        arreglo_fusionado.arreglo[posicion] = arreglo2.arreglo[contador];
        contador++;
        posicion++;
    }    
	
	return arreglo_fusionado;//Retorno el arreglo fusionado.
}





struct_arreglo_t ordena_arreglo(struct_arreglo_t arreglo1)
{
    int contador = 0;//recorre el arreglo 
    int recorre = 0;//recorre el arreglo para comparar
    int valor_min = 0;//Aca voy a guardar el valor minimo
    int posicion = 1;//Aca voy a guardar la posicon del valor minimo
    int valor_parcial= 0;//Aca guardo el valor que va a ser reemplazado, para despues devolverlo al arreglo.
 
    
    while(contador < arreglo1.capacidad)
    {
        valor_min = arreglo1.arreglo[contador];//Pongo como valor minimo el primer elemento
        
        for (recorre = contador + 1; recorre < arreglo1.capacidad; recorre++)//Empieza en + 1 para no contar la misma posicion que el contador.
        {
            
            if(valor_min > arreglo1.arreglo[recorre])//Si es menor al numero anterior encontrado como "minimo"
            {
                posicion = recorre;//Guardo la posicion del numero minimo
                valor_min = arreglo1.arreglo[recorre];//Guardo el valor minimo encontrado.
            }
            
        }
        
        valor_parcial = arreglo1.arreglo[contador];//guardo el valor que va a ser reemplazado
        arreglo1.arreglo[contador] = arreglo1.arreglo[posicion];//Reemplazo el valor de la posicion del numero comparado, con el valor minimo encontrado.
        arreglo1.arreglo[posicion] = valor_parcial;//Guardo el valor que fue anteriormente reemplazado, en la posicion que estaba antes el valor minimo.

        contador++;
    }
    
	
	return arreglo1;
    
}