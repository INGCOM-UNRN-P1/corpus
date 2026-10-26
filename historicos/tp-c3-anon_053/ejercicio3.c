

#include <stdio.h>

typedef struct{
    int horas;
    int minutos;
    float min, segundos;
}tiempo_t;

tiempo_t converter(int min);

int main()
{
    tiempo_t tempo;    
    float min;
    
    tiempo_t converter;
    printf("Ingrese cantidad de minutos: ");
    scanf("%f",&min);
    converter(min);
    printf("\nEsto es igual a %d h, %d min y %.2f s\n\n", tempo.horas, tempo.minutos, tempo.segundos);
    return 0;
}

tiempo_t converter(int min)
{
    tiempo_t tempo;
    tempo.horas     =      min  / 60;
    tempo.minutos   =      min  % 60;
    tempo.segundos  = (min - min) * 60;
    return tempo;
}
