
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int casillero = 1;
	unsigned long long int cantidad_granos = 1;
	unsigned long long int kilos = 1;
	while (casillero <= 64)
    {
    	if (casillero == 1)
	    {
			printf("Casillero 1 = 1 \n");
			casillero = casillero +1;
	    }
	    else
	    {    
            cantidad_granos = cantidad_granos*2;
			printf("Casillero %d = %llu \n",casillero,cantidad_granos);
			casillero = casillero +1;
		}
	}
	kilos = (cantidad_granos +1)/20000;
    printf("El rey debe entregarle %llu kg de trigo \n",kilos );	
    return 0;
}


