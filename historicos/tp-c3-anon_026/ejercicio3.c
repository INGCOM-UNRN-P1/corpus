


#include <stdio.h>

typedef struct{
    int horas;
    int minutos;
    int segundos;
}tiempo_t;

tiempo_t suma_segundos(tiempo_t segundo1, tiempo_t segundo2);
tiempo_t en_horas(int segundos);
void mostrar_tiempo_t (tiempo_t time);

int main()
{
    int segundos;
    tiempo_t tempo;
    tiempo_t segundo1; 
    tiempo_t segundo2;
        
    //printf("Ingrese una cantidad de segundos: ");
    //scanf("%d",&segundos);
   
   
   
	
    printf("Ingrese segundo 1: ");
    scanf("%d", &segundo1.segundos);
    
    printf("Ingrese segundo 2: ");
    scanf("%d", &segundo2.segundos);
        
	
	
    tiempo_t guardarsuma = suma_segundos(segundo1, segundo2);
	segundos = guardarsuma;  // Quiero guardar en segundos, el resultado de la suma, para después convertir ese resultado a en_horas. Acá comparo peras con manzanas pero no sé cómo corregir eso (INT == tiempo_t)
    tempo= en_horas(segundos);

	

    printf("La hora ingresada es: \n");
    mostrar_tiempo_t(tempo);  
        
    printf("La suma de segundos es: \n");
    
    return 0;
}
tiempo_t tempo;

tiempo_t en_horas(int segundos){
    tiempo_t tempo_aux;
    tempo_aux.horas     =  segundos  / 3600;
    segundos  =  segundos % 3600;
    tempo_aux.minutos   =  segundos  / 60;
    tempo_aux.segundos  =  segundos % 60;
    return tempo_aux;
}

//función para mostrar por pantalla la hora/

void mostrar_tiempo_t (tiempo_t time)
{ 
    printf("%02d horas:%02d minutos:%02d segundos\n", time.horas, time.minutos, time.segundos);
}
//Funcion suma de segundos
tiempo_t suma_segundos(tiempo_t segundo1, tiempo_t segundo2)
{
    tiempo_t suma;
    suma.segundos = segundo1.segundos + segundo2.segundos;
        
    return suma;
}    


