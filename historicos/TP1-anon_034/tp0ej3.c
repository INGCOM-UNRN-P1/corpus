
 
 #include <stdio.h>
 
 int main()
 {
	int ingreso_uno;
	int ingreso_dos;
	int multiplicacion;
	double division;
	int resto;
	
	printf("ingrese el primer numero:");
	scanf("%d", &ingreso_uno);
	printf("Ingrese el segundo numero:");
	scanf("%d", &ingreso_dos);
	
	multiplicacion = ingreso_uno * ingreso_dos;
	division = (float)ingreso_uno / ingreso_dos;
	resto = ingreso_uno % ingreso_dos;
	
	printf("Primer numero: A = %d \n", ingreso_uno);
	printf("Segundo numero: B = %d \n", ingreso_dos);
	printf("Operador multiplicacion: A*B = %d \n", multiplicacion);
	printf("Operador division: A/B = %f \n", division);
	printf("Operador resto: A%B = %d \n", resto);
	 
	return 0;
 }