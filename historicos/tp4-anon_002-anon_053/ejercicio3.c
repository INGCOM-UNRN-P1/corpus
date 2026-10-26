

#include <stdio.h>


void duplicarValor(int *ptr);

int main() {
    int numero = 10;
    
    printf("Valor original: %d\n", numero);
    
    // Llamar a la función para duplicar el valor
    duplicarValor(&numero);
    
    printf("Valor duplicado: %d\n", numero);
    
    return 0;
}


void duplicarValor(int *ptr) 
{
    *ptr *= 2; // Duplicar el valor a la direccion que apunta el puntero
}
