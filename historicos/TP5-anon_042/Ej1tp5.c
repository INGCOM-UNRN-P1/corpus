
 #include <stdio.h>
 
int main()
{
    int entero = 23;
    char palabra[] = "Hola";
    double f = 503;
    int *pentero = &entero;
    double *pf = &f;
    char *ppalabra = palabra;
    printf("la direccion de memoria de entero es \t 0x%x\n", &entero);
    printf("la direccion de memoria de double es \t 0x%x\n", &f);
    printf("la direccion de memoria de palabra es \t 0x%x\n", &palabra);
    printf("la direccion de memoria de entero es \t 0x%x\n", &pentero);
    printf("la direccion de memoria de double* es \t 0x%x\n", &pf);
    printf("la direccion de memoria de palabra* es \t 0x%x\n", &ppalabra);
    
    printf("El tamanio del char %zd bytes \n", sizeof (palabra));
    printf("El tamanio del entero %zd bytes \n", sizeof (entero));
    printf("El tamanio del double %zd bytes \n", sizeof (f));
    printf("El tamanio del puntero char %zd bytes \n", sizeof (ppalabra));
    printf("El tamanio del puntero entero %zd bytes \n", sizeof (pentero));
    printf("El tamanio del puntero double %zd bytes \n", sizeof (pf));
    
    printf("El valor del char 'Palabra' es %p\n", palabra);
    printf("El valor del int 'Entero' es %p\n", entero);
    printf("El valor del double 'f' es %p\n", f);
    printf("El valor del char 'PPalabra' es %p\n", *ppalabra);
    printf("El valor del int 'PEntero' es %p\n", *pentero);
    printf("El valor del double 'Pf' es %p", *pf);
    
    return 0;
}