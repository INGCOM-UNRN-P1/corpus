 /*************************
  * Ingenieria en Computación - UNRN Andina
  * Programación 1
  * @anon_056
  *************************/

#include <stdio.h>


 int main(int argc, char const *argv[])
 {
    char ch = 'A';
    int numint = 9;
    double numdouble = 1.23;

    char *pchar;
    int *pint;
    double *pdouble;

    pchar = &ch;
    pint = &numint;
    pdouble = &numdouble;

    printf("\nLa direccion del char \t\tch es %p\n",&ch);
    printf("La direccion del int \t\tnumint es %p\n",&numint);
    printf("La direccion del double \tnumdouble es %p\n",&numdouble);
    printf("La direccion del char* \t\tpchar es %p\n", &pchar);
    printf("La direccion del int* \t\tpint es %p\n", &pint);
    printf("La direccion del double* \tpdouble es %p\n",&pdouble);
    printf("\n");
    printf("La valor del char \t\tch es %c\n", ch);
    printf("La valor del int \t\tnumint es %d\n", numint);
    printf("La valor del double \t\tnumdouble es %.2f\n",numdouble);
    printf("La valor del char* \t\tch es %p\n", pchar);
    printf("La valor del int* \t\tnumint es %p\n", pint);
    printf("La valor del double* \t\tnumdouble es %p\n",pdouble);
    printf("\n");
    printf("El tamaño del char \t\tes %zu bytes\n", sizeof(ch));
    printf("El tamaño del int \t\tes %zu bytes\n", sizeof(numint));
    printf("El tamaño del double \t\tes %zu bytes\n", sizeof(numdouble));
    printf("El tamaño del char* \t\tch es %zu bytes\n",sizeof(pchar));
    printf("El tamaño del int* \t\tnumint es %zu bytes\n", sizeof(pint));
    printf("El tamaño del double* \t\tnumdouble es %zu bytes\n",sizeof(pdouble));

     
     return 0;
 }
 