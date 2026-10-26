

#include <stdio.h>

int main()
{
    double doble;
    int ent;
    char cara;

    double* p_doble;
    int* p_ent;
    char* p_cara;

    doble = 3.1415;
    ent = 8086;
    cara = 'A';

    p_doble = &doble;
    p_ent = &ent;
    p_cara = &cara;

    printf("La dirección del double doble \t\t es \t0x%p.\n", &doble);
    printf("La dirección del int ent \t\t es \t0x%p.\n", &ent);
    printf("La dirección del char cara \t\t es \t0x%p.\n", &cara);
    printf("La dirección del *double p_doble \t es \t0x%p.\n", &p_doble);
    printf("La dirección del *int p_ent \t\t es \t0x%p.\n", &p_ent);
    printf("La dirección del *char p_cara \t\t es \t0x%p.\n\n", &p_cara);

    printf("El valor del double doble \t\t es \t%f.\n", doble);
    printf("El valor del int ent \t\t\t es \t%d.\n", ent);
    printf("El valor del char cara \t\t\t es \t%c.\n", cara);
    printf("El valor del *double p_doble \t\t es \t0x%p.\n", p_doble);
    printf("El valor del *int p_ent \t\t es \t0x%p.\n", p_ent);
    printf("El valor del *char p_cara \t\t es \t0x%p.\n\n", p_cara);

    printf("El tamaño del double doble \t\t es \t%d bytes.\n", sizeof(doble));
    printf("El tamaño del int ent \t\t\t es \t%d bytes.\n", sizeof(ent));
    printf("El tamaño del char cara \t\t es \t%d bytes.\n", sizeof(cara));
    printf("El tamaño del *double p_doble \t\t es \t%d bytes.\n", sizeof(p_doble));
    printf("El tamaño del *int p_ent \t\t es \t%d bytes.\n", sizeof(p_ent));
    printf("El tamaño del *char p_cara \t\t es \t%d bytes.\n\n", sizeof(p_cara));

    return 0;
}