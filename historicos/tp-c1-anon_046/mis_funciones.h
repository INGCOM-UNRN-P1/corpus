
#include <stdio.h>



#define OK     0
#define ERROR -1


int parse_float(const char *cadena, float *pfloat);


int parse_long(const char *cadena, long *pentero, const int base);


int ingreso_sin_newline(char *entrada, int size_of_entrada, FILE *stream);

