
 
 #include <stdio.h>
 
 int main()
 {
	int ingreso;
	
	printf("\nIngrese un numero entero correspondido a un dia de la semana: ");
	scanf("%d", &ingreso);
	
	switch(ingreso)
	{
		case 1:
		printf("\nLunes\n");
		break;
		
		case 2:
		printf("\nMartes\n");
		break;
		
		case 3:
		printf("\nMiercoles\n");
		break;
		
		case 4:
		printf("\nJueves\n");
		break;
		
		case 5:
		printf("\nViernes\n");
		break;
		
		case 6:
		printf("\nSabado\n");
		break;
		
		case 7:
		printf("\nDomingo\n");
		break;
		
		default:
		printf("\nNo ingresaste un numero correspondiente a un dia de la semana!\n");
		return 0;
	}
	 
	return 0;
 }