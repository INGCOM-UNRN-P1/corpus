
int* ordena_arreglo(int* arreglo, int tamano);


//MENOR

int* ordena_arreglo(int* arreglo, int tamano)
{
    int contador = 0 ;//recorre el arreglo, empieza en 1 para no contar el primer termino
    int posicion_min = 0;//Aca voy a guardar la posicon del valor minimo
    int recorre= 0;//recorre el arreglo para comparar
    int valor_parcial = 0;//Aca guardo el valor que va a ser reemplazado, para despues devolverlo al arreglo.
    
    while(contador < tamano)//recorre el arreglo
    {
        posicion_min = arreglo[contador];//Guardo el primer elemento como posicion minima
        
        for(recorre = contador + 1; recorre < tamano; recorre++)//Esto va recorriendo el resto del arreglo sin contar la posicion actual del valor minimo
        {
            if(posicion_min > arreglo[recorre])//Si encuentra un valor menor a la posicion minima, los intercambia
            {
                posicion_min = arreglo[recorre];//Guardo el nuevo valor como posicion minima
                valor_parcial = arreglo[contador];//Guardo el valor por el que se va a intercambiar
                arreglo[contador] = posicion_min;//Guardo la posicion minima en donde se reemplaza
                arreglo[recorre] = valor_parcial;//Guardo el valor reemplazado en donde saco el minimo.
                
                
            }
        }
	contador++;       
    }
    
    return arreglo;
    
}



