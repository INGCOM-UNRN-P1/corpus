
#include <stdio.h>

typedef struct tiempo
{
    int horas;
    int minutos;
    int segundos;
}tiempo_t;

tiempo_t sumartodo(tiempo_t crear, tiempo_t sumar, tiempo_t almacenar)
{
    
    almacenar.segundos = crear.segundos;
    almacenar.minutos = crear.minutos;
    almacenar.horas = crear.horas;
    almacenar.segundos = almacenar.segundos + sumar.segundos;
    while (almacenar.segundos > 59)
    { 
        almacenar.minutos = almacenar.minutos + 1;
        almacenar.segundos = almacenar.segundos - 60;
        while (almacenar.minutos > 59)
        { 
            almacenar.horas = almacenar.horas + 1;
            almacenar.minutos = almacenar.minutos - 60;   
        }   
        
    }
    almacenar.minutos = almacenar.minutos + sumar.minutos;
    while (almacenar.minutos > 59)
    {
        almacenar.horas = almacenar.horas + 1;
        almacenar.minutos = almacenar.minutos -60;
    }
    almacenar.horas = almacenar.horas + sumar.horas;
    return almacenar;
}
tiempo_t sumartiempos(tiempo_t crear2, tiempo_t almacenar)
{
    
    tiempo_t sumadetiempos;
    sumadetiempos.segundos = almacenar.segundos;
    sumadetiempos.minutos = almacenar.minutos;
    sumadetiempos.horas = almacenar.horas;
    sumadetiempos.segundos = sumadetiempos.segundos + crear2.segundos;
    while (sumadetiempos.segundos > 59)
    { 
        sumadetiempos.minutos = sumadetiempos.minutos + 1;
        sumadetiempos.segundos = sumadetiempos.segundos - 60;
        while (sumadetiempos.minutos > 59)
        { 
            sumadetiempos.horas = sumadetiempos.horas + 1;
            sumadetiempos.minutos = sumadetiempos.minutos - 60;   
        }   
    }
    sumadetiempos.minutos = sumadetiempos.minutos + crear2.minutos;
    while (sumadetiempos.minutos > 59)
    {
        sumadetiempos.horas = sumadetiempos.horas + 1;
        sumadetiempos.minutos = sumadetiempos.minutos -60;
    }
    sumadetiempos.horas = sumadetiempos.horas + crear2.horas;
    return sumadetiempos;
}
int main()
{   
    tiempo_t crear;
    tiempo_t crear2;
    tiempo_t sumar;
    tiempo_t almacenar;
    tiempo_t sumadetiempos;
    crear.horas = -1;
    crear.minutos = 60;
    crear.segundos = 60;
    crear2.horas = -1;
    crear2.minutos = 60;
    crear2.segundos = 60;
    while (crear.horas < 0)
    {
        printf("Ingrese una hora (en numero entero positivo): \n");
        scanf(" %d", &crear.horas);
    }
    while (crear.minutos < 0 || crear.minutos > 59)
    {
        printf("Ingrese minutos (0 - 59): \n");
        scanf(" %d", &crear.minutos);
    }
    while (crear.segundos < 0 || crear.segundos > 59)
    {
        printf("Ingrese segundos (0 - 59): \n");
        scanf(" %d", &crear.segundos);
    }
    
    printf("El tiempo ingresado es de %d horas %d minutos %d segundos \n", crear.horas, crear.minutos, crear.segundos);
    
    printf("Ingrese segundos para sumar al tiempo actual: \n");
    scanf(" %d", &sumar.segundos);
    
    printf("Ingrese minutos para sumar al tiempo actual: \n");
    scanf(" %d", &sumar.minutos);
    
    printf("Ingrese horas para sumar al tiempo actual: \n");
    scanf(" %d", &sumar.horas);
    
    almacenar = sumartodo(crear, sumar, almacenar);
    printf("El tiempo actual con la suma es de %d horas %d minutos %d segundos \n", almacenar.horas, almacenar.minutos, almacenar.segundos);
    
    while (crear2.horas < 0)
    {
        printf("Ingrese otra hora (en numero entero positivo): \n");
        scanf(" %d", &crear2.horas);
    }
    while (crear2.minutos < 0 || crear2.minutos > 59)
    {
        printf("Ingrese otros minutos (0 - 59): \n");
        scanf(" %d", &crear2.minutos);
    }
    while (crear2.segundos < 0 || crear2.segundos > 59)
    {
        printf("Ingrese otros segundos (0 - 59): \n");
        scanf(" %d", &crear2.segundos);
    }
    sumadetiempos = sumartiempos(crear2, almacenar);
    printf("La suma de los dos tiempos da como resultado %d horas %d minutos %d segundos \n", sumadetiempos.horas, sumadetiempos.minutos, sumadetiempos.segundos);
    return 0;
    
}