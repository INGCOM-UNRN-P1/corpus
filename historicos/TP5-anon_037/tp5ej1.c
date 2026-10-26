/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>

int main()
{
	double vardouble = 12;
	int varint = 27;
	char varchar = 4;
	
	
	double* punteroa = &vardouble;
	int* punterob = &varint;
	char* punteroc = &varchar;
	
	
	int tamanioa = sizeof(vardouble);
	int tamaniob = sizeof(varint);
	int tamanioc = sizeof(varchar);
	
	int tamaniop_a = sizeof(punteroa);
	int tamaniop_b = sizeof(punterob);
	int tamaniop_c = sizeof(punteroc);
	

	printf("La direccion del double vardouble es 0x%p\n", &vardouble);
	printf("La direccion del int varint \t  es 0x%p\n", &varint);
	printf("La direccion del char varchar \t  es 0x%p\n", &varchar);
	
	printf("La direccion del double* punteroa es 0x%p\n", &punteroa);
	printf("La direccion del int* punterob \t  es 0x%p\n", &punterob);
	printf("La direccion del char* punteroc\t  es 0x%p\n\n", &punteroc);
	
	
	printf("El valor del double vardouble \t  es %f\n", vardouble);
	printf("El valor del int varint \t  es %d\n", varint);
	printf("El valor del char varchar \t  es %d\n", varchar);
	
	printf("El valor del double* punteroa \t  es %f\n", *punteroa);
	printf("El valor del int* punterob \t  es %d\n", *punterob);
	printf("El valor del char* punteroc \t  es %d\n\n", *punteroc);
	
	
	printf("El tamanio del double vardouble\t  es %d bytes\n", tamanioa);
	printf("El tamanio del int varint \t  es %d bytes\n", tamaniob);
	printf("El tamanio del char varchar \t  es %d bytes\n", tamanioc);
	
	printf("El tamanio del double* punteroa\t  es %d bytes\n", tamaniop_a);
	printf("El tamanio del int* punterob \t  es %d bytes\n", tamaniop_b);
	printf("El tamanio del char* punteroc \t  es %d bytes\n", tamaniop_c);
}