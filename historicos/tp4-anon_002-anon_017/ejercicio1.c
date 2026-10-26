
#include <stdio.h>

int main()
{
    double numero_double = 9.0;
    int numero_entero = 10;
    char letra = 'A';
    
    double *ptr_double = &numero_double;
    int *ptr_entero = &numero_entero;
    char *ptr_char = &letra;
    

    
    printf("La direccion del char		letra           es %p\n",&letra);
    printf("La direccion del int		numero_entero   es %p \n",&numero_entero);
    printf("La direccion del double		numero_double	es %p \n",&numero_double);
    printf("La direccion del char*		ptr_char	es %p \n",&ptr_char);
    printf("La direccion del int*		ptr_entero	es %p \n",&ptr_entero);
    printf("La direccion del double*	ptr_double	es %p \n",&ptr_double);
    
    printf("\n");
    
    printf("El valor del char letra           \t es %c\n",letra);
    printf("El valor del int numero_entero    \t es %d\n",numero_entero);
    printf("El valor del double numero_double \t es %f\n",numero_double);
    printf("El valor del char*  ptr_char      \t es %c\n",*ptr_char);
    printf("El valor del int* ptr_entero      \t es %d\n",*ptr_entero);
    printf("El valor del double* ptr_double   \t es %f\n",*ptr_double);
    
    printf("\n");
    
    printf("El tamaño del char letra           \t es %d bytes\n",sizeof(letra));
    printf("El tamaño del int numero_entero    \t es %d bytes\n",sizeof(numero_entero));
    printf("El tamaño del double numero_double \t es %d bytes\n",sizeof(numero_double));
    printf("El tamaño del char* ptr_char       \t es %d bytes\n",sizeof(ptr_char));
    printf("El tamaño del int* ptr_entero      \t es %d bytes\n",sizeof(ptr_entero));
    printf("El tamaño del double* ptr_double   \t es %d bytes\n",sizeof(ptr_double));

    
}