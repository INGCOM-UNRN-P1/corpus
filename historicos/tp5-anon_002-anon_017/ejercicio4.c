
#include <stdio.h>


typedef struct tiempo{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;


void imprime_tiempo(tiempo_t tiempo);
tiempo_t suma_tiempo(tiempo_t tiempo_1, tiempo_t tiempo_2);
int compara_tiempos(tiempo_t tiempo_1, tiempo_t tiempo_2);

int main()
{
    tiempo_t tiempo_1;
    tiempo_t tiempo_2;
    tiempo_t resultado;
    int respuesta = 0;
    
    int opcion = 0;
    
    printf("Ingrese 1 para sumar 2 horas\n");
    printf("Ingrese 2 para comparar horas\n");
    printf("Opcion: ");
    scanf("%d",&opcion);
    
    
    if(opcion == 1)
    {
        printf("Ingrese las horas: ");
        scanf("%d",&tiempo_1.horas);
        
        printf("Ingrese los minutos: ");
        scanf("%d",&tiempo_1.minutos);
        
        printf("Ingrese los segundos: ");
        scanf("%d",&tiempo_1.segundos);
        
        printf("Ingrese las horas a sumar: ");
        scanf("%d",&tiempo_2.horas);
        
        printf("Ingrese los minutos a sumar: ");
        scanf("%d",&tiempo_2.minutos);
        
        printf("Ingrese los segundos a sumar: ");
        scanf("%d",&tiempo_2.segundos);
        
        resultado = suma_tiempo(tiempo_1, tiempo_2);    
        imprime_tiempo(resultado);
    }
    else if(opcion == 2)
    {
        printf("Ingrese las horas: ");
        scanf("%d",&tiempo_1.horas);
        
        printf("Ingrese los minutos: ");
        scanf("%d",&tiempo_1.minutos);
        
        printf("Ingrese los segundos: ");
        scanf("%d",&tiempo_1.segundos);
        
        printf("Ingrese las horas del segundo tiempo: ");
        scanf("%d",&tiempo_2.horas);
        
        printf("Ingrese los minutos del segundo tiempo: ");
        scanf("%d",&tiempo_2.minutos);
        
        printf("Ingrese los segundos del segundo tiempo: ");
        scanf("%d",&tiempo_2.segundos);
        
        respuesta = compara_tiempos(tiempo_1, tiempo_2);    
        printf("%d",respuesta);

    }
    else
    {
        printf("No es una opcion!");
    }
   
    

    

}





//No modifica tiempo, por que van a llegar ya bien armados.
void imprime_tiempo(tiempo_t tiempo)
{ 
    printf("El tiempo es de %d° %d' %d''",tiempo.horas, tiempo.minutos, tiempo.segundos);
}







tiempo_t suma_tiempo(tiempo_t tiempo_1, tiempo_t tiempo_2)
{
    tiempo_t resultado;
    
    int exceso_segundos = 0;
    int exceso_minutos = 0;
    
    resultado.segundos = tiempo_1.segundos + tiempo_2.segundos;
    
    while(resultado.segundos >= 60)//si se paso de 60, tiene que pasar el exceso a minutos
    {
        resultado.segundos = resultado.segundos - 60;//resto el exceso de segundos
        exceso_segundos++;//por cada resta que hizo, se suma 1 minuto.
    }
    
    resultado.minutos = tiempo_1.minutos + tiempo_2.minutos;
    
    resultado.minutos = resultado.minutos + exceso_segundos;//Aca sumo el exceso anterior de segundos con la suma de los minutos
    
    while(resultado.minutos >= 60)//si se paso de 60, tiene que pasar el exceso a minutos
    {
        resultado.minutos = resultado.minutos - 60;//resto el exceso de minutos
        exceso_minutos++;//por cada resta que hizo, se suma 1 hora.
    }
    
    resultado.horas = tiempo_1.horas + tiempo_2.horas;//Esto suma las horas de los tiempos
    
    resultado.horas =  resultado.horas + exceso_minutos;//Esto suma el exceso de minutos anterior + la suma de las horas.
    
    return resultado;
      
    
}



int compara_tiempos(tiempo_t tiempo_1, tiempo_t tiempo_2)
{
    
    int minutos_aux = 0;
    int horas_aux = 0;
    int retorno = 0;
    
    //Primero ordeno las horas del primer tiempo
    while(tiempo_1.segundos >= 60)
    {
        tiempo_1.segundos = tiempo_1.segundos - 60;//resto  60
        minutos_aux++; //Esto suma los minutos, por cuantas veces resto.
    }
    
    tiempo_1.minutos = tiempo_1.minutos + minutos_aux;//le sumo los minutos
    
    while(tiempo_1.minutos >= 60)
    {
        tiempo_1.minutos = tiempo_1.minutos - 60;//resto 60
        horas_aux++; //Esto suma los hpras, por cuantas veces resto.
    }
    
    tiempo_1.horas = tiempo_1.horas + horas_aux;//Suma los minutos que se pasaron a horas
    
    
    //Despues ordeno las horas del segundo tiempo
    while(tiempo_2.segundos >= 60)
    {
        tiempo_2.segundos = tiempo_2.segundos - 60;//resto  60
        minutos_aux++; //Esto suma los minutos, por cuantas veces resto.
    }
    
    tiempo_2.minutos = tiempo_2.minutos + minutos_aux;//le sumo los minutos
    
    while(tiempo_2.minutos >= 60)
    {
        tiempo_2.minutos = tiempo_2.minutos - 60;//resto 60
        horas_aux++; //Esto suma los hpras, por cuantas veces resto.
    }
    
    tiempo_2.horas = tiempo_2.horas + horas_aux;//Suma los minutos que se pasaron a horas
    
    
    //una vez ordenadas, puedo empezar a comparar
    
    if(tiempo_1.horas > tiempo_2.horas)
    {
        retorno = 1;
    }
    else if(tiempo_1.horas < tiempo_2.horas)
    {
        retorno = -1;
    }
    else if (tiempo_1.minutos > tiempo_2.minutos)//si las horas son iguales, compara minutos.
    {
        retorno = 1;
    }
    else if(tiempo_1.minutos < tiempo_2.minutos)
    {
        retorno = - 1;
    }
    else if(tiempo_1.segundos > tiempo_2.segundos)//Si los minutos son iguales, compara segundos.
    {
        retorno = 1;
    }
    else if(tiempo_1.segundos < tiempo_2.segundos)
    {
        retorno = -1;
    }
    else
    {
        retorno = 0;//si no , son iguales
    }
    
    
    return retorno;
    
    
}