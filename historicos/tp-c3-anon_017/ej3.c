
#include <stdio.h>

typedef struct tiempo{
    int horas;
    int minutos;
    int segundos;
} tiempo_t;


tiempo_t suma_tiempo(tiempo_t el_tiempo1, tiempo_t el_tiempo2);
void mostrar_tiempo(tiempo_t tiempo_final);



int main()
{
    tiempo_t el_tiempo1;
    tiempo_t el_tiempo2;
    tiempo_t tiempo_final;
    int opcion;
    
    printf("ingrese 1 si va a sumar 2 horas, 2 si va a sumar segundos a un tiempo, 3 si va a sumar minutos a un tiempo y 4 si va a sumar horas a un tiempo: \n");
    scanf("%d",&opcion);
    
    
    
    if (opcion == 1)
    {
        printf("ingrese la hora del primer tiempo: \n");
        scanf("%d",&el_tiempo1.horas);
    
        printf("ingrese los minutos del primer tiempo: \n");
        scanf("%d",&el_tiempo1.minutos);
    
        printf("ingrese los segundos del primer tiempo: \n");
        scanf("%d",&el_tiempo1.segundos);
    
        printf("ingrese la hora del segundo tiempo: \n");
        scanf("%d",&el_tiempo2.horas);
    
        printf("ingrese los minutos del segundo tiempo: \n");
        scanf("%d",&el_tiempo2.minutos);
    
        printf("ingrese los segundos del segundo tiempo: \n");
        scanf("%d",&el_tiempo2.segundos);
        
        tiempo_final = suma_tiempo( el_tiempo1, el_tiempo2);
        mostrar_tiempo(tiempo_final);
    }
    else if (opcion == 2)
    {
        printf("ingrese la hora del tiempo: \n");
        scanf("%d",&el_tiempo1.horas);
    
        printf("ingrese los minutos del tiempo: \n");
        scanf("%d",&el_tiempo1.minutos);
    
        printf("ingrese los segundos del tiempo: \n");
        scanf("%d",&el_tiempo1.segundos);
        
        printf("ingrese cuantos segundos va a sumar: \n");
        scanf("%d",&el_tiempo2.segundos);
        
        el_tiempo2.horas = 0;
        el_tiempo2.minutos = 0;
        
        
        tiempo_final = suma_tiempo( el_tiempo1, el_tiempo2);
        mostrar_tiempo(tiempo_final);
    }
    else if (opcion == 3)
    {
        printf("ingrese la hora del tiempo: \n");
        scanf("%d",&el_tiempo1.horas);
    
        printf("ingrese los minutos del tiempo: \n");
        scanf("%d",&el_tiempo1.minutos);
    
        printf("ingrese los segundos del tiempo: \n");
        scanf("%d",&el_tiempo1.segundos);
        
        printf("ingrese cuantos minutos va a sumar: \n");
        scanf("%d",&el_tiempo2.minutos);
        
        el_tiempo2.horas = 0;
        el_tiempo2.segundos = 0;
        
        tiempo_final = suma_tiempo( el_tiempo1, el_tiempo2);
        mostrar_tiempo(tiempo_final);
      
    }
    else if (opcion == 4)
    {
        printf("ingrese la hora del tiempo: \n");
        scanf("%d",&el_tiempo1.horas);
    
        printf("ingrese los minutos del tiempo: \n");
        scanf("%d",&el_tiempo1.minutos);
    
        printf("ingrese los segundos del tiempo: \n");
        scanf("%d",&el_tiempo1.segundos);
        
        printf("ingrese cuantas horas va a sumar: \n");
        scanf("%d",&el_tiempo2.horas);
        
        el_tiempo2.minutos = 0;
        el_tiempo2.segundos = 0;
        
        tiempo_final = suma_tiempo( el_tiempo1, el_tiempo2);
        mostrar_tiempo(tiempo_final);
        
    }
    else
    {
        printf(" %d no corresponde a ninguna opcion!! \n",opcion);
    }

}

tiempo_t suma_tiempo(tiempo_t el_tiempo1, tiempo_t el_tiempo2)
{
    tiempo_t tiempo_final;
    
    tiempo_final.horas = el_tiempo1.horas + el_tiempo2.horas;
    tiempo_final.minutos = el_tiempo1.minutos + el_tiempo2.minutos;
    tiempo_final.segundos = el_tiempo1.segundos + el_tiempo2.segundos;
    
    return tiempo_final;
}



void mostrar_tiempo(tiempo_t tiempo_final )
{
    
    while (tiempo_final.segundos >= 60) 
    {
        tiempo_final.segundos = tiempo_final.segundos - 60;
        tiempo_final.minutos = tiempo_final.minutos + 1;
    }

    while (tiempo_final.minutos >= 60) 
    {
        tiempo_final.minutos = tiempo_final.minutos - 60;
        tiempo_final.horas = tiempo_final.horas + 1;
        
    }
   
    printf("El tiempo total es: %d°, %d', %d'' \n",tiempo_final.horas, tiempo_final.minutos, tiempo_final.segundos);
}