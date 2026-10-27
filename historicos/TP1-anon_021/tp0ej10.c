
#include <stdio.h>
 
int main(int argc, char *argv[])
{
int number;

printf("\n ingrese numero del 1 al 7 :");

scanf("%d",&number);

while(number > 7 || number <=0)
{
	
	printf(" \n del 1 al 7 dije :");
	
	scanf("%d",&number);
	
}

switch(number)
{
	
	case 1:
		
		printf("\n lunes\n");
		
	break;
	
	case 2:
		
		printf("\n martes\n");
		
	break;
	
	case 3:
		
		printf("\n miercoles\n");
		
	break;
	
	case 4:
		
		printf("\n jueves\n");
		
	break;
	
	case 5:
		
		printf("\n viernes\n");
		
	break;
	
	case 6:
		
		printf("\n sabado\n");
		
	break;
	
	case 7:
		
		printf("\n\n domingo\n");
		
	break;
	
}

return 0;
}
