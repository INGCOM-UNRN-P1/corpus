
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 // Progama principal
int main()
{
  srand(time(NULL));
  char valorTexto[20];
  // Declaracion de variable
  int nNatural = rand() %100 ;
  double nReal = rand() %100 ;
  char caracter = 58 + rand() %140 ;

  // Declaracion de pointers
  int *naturalP = &nNatural ;
  double *realP = &nReal ;
  char *charP = &caracter ;

  // Prints

  printf("La direccion del char    \t 'caracter' es 0x% x\n",&caracter);
  printf("La direccion del int     \t 'nNatural' es 0x% x\n",&nNatural);
  printf("La direccion del double  \t 'nReal' es 0x% x\n",&nReal);
  printf("La direccion del char*   \t 'charP' es 0x% x\n",*charP);
  printf("La direccion del int*    \t 'naturalP' es 0x% x\n",*naturalP);
  printf("La direccion del double* \t 'realP' es 0x% x\n\n",*realP);

  printf("El valor del char        \t 'caracter' es %c\n",&caracter);
  printf("El valor del int         \t 'nNatural' es %d\n",&nNatural);
  printf("El valor del double      \t 'nReal' es &f\n",&nReal);
  printf("El valor del char*       \t 'charP' es &c\n",*charP);
  printf("El valor del int*        \t 'naturalP' es %d\n",*naturalP);
  printf("El valor del double*     \t 'realP' es %f\n\n",*realP);

  printf("El tamano del char       \t 'caracter' es %d bytes\n",sizeof(caracter));
  printf("El tamano del int        \t 'nNatural' es %d bytes\n",sizeof(nNatural));
  printf("El tamano del double     \t 'nReal' es %d bytes\n",sizeof(nReal));
  printf("El tamano del char*      \t 'charP' es %d bytes\n",sizeof(*charP));
  printf("El tamano del int*       \t 'naturalP' es %d bytes\n",sizeof(*naturalP));
  printf("El tamano del double*    \t 'realP' es %d bytes\n\n",sizeof(*realP));

  return 0;
}
