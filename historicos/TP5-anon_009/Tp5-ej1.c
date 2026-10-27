
#include <stdio.h>

 
int main()
{
    char a = 'a';
    int b = 1;
    double c = 5;
    char* pa = &a;
    int* pb = &b;
    double* pc = &c;


    printf("La direccion del char\t\t  a es %p \n", pa);
    printf("La direccion del int\t\t  b es %p \n", pb);
    printf("La direccion del double\t\t  c es %p \n", pc);
    printf("La direccion del char*\t\t pa es %p \n", &pa);
    printf("La direccion del int*\t\t pb es %p \n", &pb);
    printf("La direccion del double*\t pc es %p \n\n\n", &pc);

    printf("El valor del char\t\t a es %c \n", a);
    printf("El valor del int\t\t b es %d \n", b);
    printf("El valor del double\t\t c es %.2f \n", c);
    printf("El valor del char*\t\t pa es %p \n", pa);
    printf("El valor del int*\t\t pb es %p \n", pb);
    printf("El valor del double*\t\t pc es %p \n\n\n", pc);

    printf("El tamaño del char\t\t a es %lu bytes \n", sizeof(a));
    printf("El tamaño del int\t\t b es %lu bytes \n", sizeof(b));
    printf("El tamaño del double\t\t c es %lu bytes \n", sizeof(c));
    printf("El tamaño del char*\t\t pa es %lu bytes \n", sizeof(pa));
    printf("El tamaño del int*\t\t pb es %lu bytes \n", sizeof(pb));
    printf("El tamaño del double*\t\t pc es %lu bytes \n\n", sizeof(pc));
}