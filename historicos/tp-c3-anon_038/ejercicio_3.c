

#include <stdio.h>
#include <stdlib.h>


typedef struct tiempo{
    int horas;
    int minutos;
	int segundos;
} tiempo_t;


tiempo_t sumar_segundos(tiempo_t t1)
{
	tiempo_t res;
	
	printf("Ingrese los SEGUNDOS que desea agregar \n");
	scanf("%d", &res.segundos);
	
	res.segundos = t1.segundos + res.segundos;
	
	return res;
}



tiempo_t sumar_minutos(tiempo_t t1)
{
	tiempo_t res;
	
	printf("Ingrese los MINUTOS que desea agregar \n");
	scanf("%d", &res.minutos);
	
	res.minutos = t1.minutos + res.minutos;
	
	return res;
}



tiempo_t sumar_horas(tiempo_t t1)
{
	tiempo_t res;
	
	printf("Ingrese las HORAS que desea agregar \n");
	scanf("%d", &res.horas);
	
	res.horas = t1.horas + res.horas;
	
	return res;
}



tiempo_t simplificar(tiempo_t t1)
{
	tiempo_t res;
	res.horas = t1.horas;
	res.minutos = t1.minutos;
	res.segundos = t1.segundos;

	while (res.segundos >= 60)
	{
		res.segundos = res.segundos - 60;
		res.minutos = res.minutos + 1;
	}
	while (res.minutos >= 60)
	{
		res.minutos = res.minutos - 60;
		res.horas = res.horas + 1;	
	}
	
	return res;
}



tiempo_t sumar_dos(tiempo_t t1, tiempo_t t2)
{
	tiempo_t res;
	
	res.horas = t1.horas + t2.horas;
	res.minutos = t1.minutos + t2.minutos;
	res.segundos = t1.segundos + t2.segundos;
	
	return res;
}


int main()
{
	int eleccion_1;
	int eleccion_2;
	int eleccion_3;
	int eleccion_4;	
	
	tiempo_t t1;
	tiempo_t t2;
	tiempo_t res_suma_segundos;
	tiempo_t res_suma_minutos;
	tiempo_t res_suma_horas;
	tiempo_t res_suma_dos;
	
	printf("Ingrese las HORAS de su tiempo \n");
	scanf("%d", &t1.horas);
	
	printf("Ingrese los MINUTOS de su tiempo \n");
	scanf("%d", &t1.minutos);
	
	printf("Ingrese los SEGUNDOS de su tiempo \n");
	scanf("%d", &t1.segundos);
	
	t1 = simplificar(t1);
	
	printf("Su primer tiempo es: %d:%d,%d \n", t1.horas, t1.minutos, t1.segundos);
		
	printf("Ahora ingrese los valores de su SEGUNDO tiempo \n");
		
	printf("Ingrese las HORAS de su tiempo \n");
	scanf("%d", &t2.horas);
	
	printf("Ingrese los MINUTOS de su tiempo \n");
	scanf("%d", &t2.minutos);
	
	printf("Ingrese los SEGUNDOS de su tiempo \n");
	scanf("%d", &t2.segundos);
	
	t2 = simplificar(t2);
	
	printf("Su segundo tiempo es: %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
	
	
	printf("Si quiere sumarle SEGUNDOS a el tiempo 1, escriba 1, si desea sumarle segundos al tiempo 2, escriba 2, y si no desea hacer nada escriba 0 \n");
	scanf("%d", &eleccion_1);
	
	if(eleccion_1 == 1)
	{
		printf("Su primer tiempo es %d:%d,%d \n", t1.horas, t1.minutos, t1.segundos);
		
		res_suma_segundos = sumar_segundos(t1);
		t1.segundos = res_suma_segundos.segundos;
		t1 = simplificar(t1);
		
		printf("Su tiempo queda como %d:%d,%d \n", t1.horas, t1.minutos, t1.segundos);
	}
	else if(eleccion_1 == 2)
	{
		printf("Su primer tiempo es %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
		
		res_suma_segundos = sumar_segundos(t2);
		t2.segundos = res_suma_segundos.segundos;
		t2 = simplificar(t2);
		
		printf("Su tiempo queda como %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
	}
	else if (eleccion_1 == 0)
	{
		printf("No se realizara nada \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
		exit(-1);
	}
	
	
	
	printf("Si quiere sumarle MINUTOS a el tiempo 1, escriba 1, si desea sumarle MINUTOS al tiempo 2, escriba 2, y si no desea hacer nada escriba 0 \n");
	scanf("%d", &eleccion_2);
	
	if(eleccion_2 == 1)
	{
		printf("Su primer tiempo es %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
		
		res_suma_minutos = sumar_minutos(t2);
		t2.minutos = res_suma_minutos.minutos;
		t2 = simplificar(t2);
		
		printf("Su tiempo queda como %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
	}
	else if(eleccion_2 == 2)
	{
		printf("Su primer tiempo es %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
		
		res_suma_minutos = sumar_minutos(t2);
		t2.minutos = res_suma_minutos.minutos;
		t2 = simplificar(t2);
		
		printf("Su tiempo queda como %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
	}
	else if (eleccion_2 == 0)
	{
		printf("No se realizara nada \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
		exit(-1);
	}
		
	
	printf("Si quiere sumarle HORA/S a el tiempo 1, escriba 1, si desea sumarle HORA/S al tiempo 2, escriba 2, y si no desea hacer nada escriba 0 \n");
	scanf("%d", &eleccion_3);
	
	if(eleccion_3 == 1)
	{
		printf("Su primer tiempo es %d:%d,%d \n", t1.horas, t1.minutos, t1.segundos);
		
		res_suma_horas = sumar_horas(t1);
		t1.horas = res_suma_horas.horas;
		t1 = simplificar(t1);
		
		printf("Su tiempo queda como %d:%d,%d \n", t1.horas, t1.minutos, t1.segundos);
	}
	else if(eleccion_3 == 2)
	{
		printf("Su primer tiempo es %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
		
		res_suma_horas = sumar_horas(t2);
		t2.horas = res_suma_horas.horas;
		t2 = simplificar(t2);
		
		printf("Su tiempo queda como %d:%d,%d \n", t2.horas, t2.minutos, t2.segundos);
	}
	else if (eleccion_3 == 0)
	{
		printf("No se realizara nada \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
		exit(-1);
	}
	
	\
	
		printf("Si quiere sumar los dos struct, escriba 1, y si no desea hacer nada escriba 0 \n");
	scanf("%d", &eleccion_4);
	
	if(eleccion_4 == 1)
	{
		res_suma_dos = sumar_dos(t1, t2);
		res_suma_dos = simplificar(res_suma_dos);
	
		printf("Su tiempo queda como %d:%d,%d \n", res_suma_dos.horas, res_suma_dos.minutos,res_suma_dos.segundos);
	}
	else if (eleccion_4 == 0)
	{
		printf("No se realizara nada \n");
	}
	else
	{
		printf("Ingreso un valor no valido \n");
		exit(-1);
	}
}
