
#include <stdio.h>
#include <ctype.h>
 
int compara_fechas(char fecha1[], char fecha2[]);//compara las fechas empezando primero por los años hasta terminar en los dias.

int main(int argc, char *argv[])
{
    printf("%i\n", compara_fechas("14/09/1999", "10/08/2001"));
}


int compara_fechas(char fecha1[], char fecha2[])
{
    

    for (int i = 6; i < 10; i++) //Compara los años 
    {
        if (fecha1[i] > fecha2[i])
        {
            return 1;
        } 
        else if (fecha1[i] < fecha2[i])
        {
            return -1;
        }
    }
    for (int j = 3; j < 5; j++) //compara los meses
    {
        if (fecha1[j] > fecha2[j])
        {
            return 1;
        } 
        else if (fecha1[j] < fecha2[j])
        {
            return -1;
        }
    }
    for (int k = 0; k < 2; k++) //compara los dias
    {
        if (fecha1[k] > fecha2[k])
        {
            return 1;
        } 
        else if (fecha1[k] < fecha2[k])
        {
            return -1;
        }
        
    }
    
    

    return 0;
}