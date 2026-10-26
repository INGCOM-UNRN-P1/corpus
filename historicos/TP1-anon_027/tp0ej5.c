/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_027
*************************/

#include <stdio.h>  
  
int main()  
{  
    int numA, numB;  
  
    printf("Ingresa dos numeros\n");  
    scanf("%d%d", &numA, &numB);  
	
	printf("-------------\n");
	
	//No encontré rápido otra forma de hacerlo sin el IF
		
	if (numA<numB)
	{	
		while(numA <= numB)  
		{  
			printf("%d\n", numA);  
			numA++;  
		}  
    }
	
	else
	{
		while(numA >= numB)  
		{  
			printf("%d\n", numA);  
			numA--;  
		}  
	}
	
    return 0;  
}  