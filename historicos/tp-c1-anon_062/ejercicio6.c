

#include <stdio.h>

// -------------------- resto ---------------
int resto_lento(int dividendo, int divisor)
// calcula el resto de la división entre dos valores ingresados
// recibe un dividendo y un divisor enteros POSITIVOS
// DEVUELVE un valor entero (o cero) seguún corresponda.
{
    int sustraendo = 0;
    int minuendo = 0;
    
    minuendo = dividendo + 1;       //el número que voy a dividir lo llamo minuendo y
    sustraendo = divisor;           //y le agrego un 1 para que al menos opere UNA VEZ.

    while (sustraendo < minuendo)          // mientras el dividendo sea mayor que el divisor
    {                                      // le saca en cada iteracion la cantidad indicada por el 
    minuendo = minuendo - sustraendo;      // divisor - hasta que el dividendo es menor que el divisor
    }

    minuendo = minuendo - 1;               // le saco UNA UNIDAD que le agregué al principio de la rutina.
    return minuendo;
}


// --------------------- cociente -------------
int cociente_lento(int dividendo, int divisor)
// Calcula el cociente de la division entre dos  valores ingresados
// recibe un dividendo y un divisor enteros POSITIVOS
// DEVUELVE un valor entero (o cero) seguún corresponda.
{
    int cociente = 0;
	int sustraendo = 0;
	int minuendo = 0;
    
	minuendo = dividendo + 1;       //el número que voy a dividir lo llamo minuendo y
    sustraendo = divisor;           //y le agrego un 1 para que al menos opere UNA VEZ.

    while (sustraendo < minuendo)          // mientras el dividendo sea mayor que el divisor
    {                                      // le saca en cada iteracion la cantidad indicada por el 
    minuendo = minuendo - sustraendo;      // divisor - hasta que el dividendo es menor que el divisor
	cociente = cociente + 1;
    }
     
    return cociente;
}


//-------------------- MAIN ----------------------------
int main(int argc, char *argv[])
{
    int eldividendo = 0;
    int eldivisor = 0;
    int elcociente = 0;
    int elresto = 0;

    printf("Ingrese un dividendo : ");
    scanf("%d", &eldividendo);
    printf("Ingrese un divisor : ");
    scanf("%d", &eldivisor);

    if (eldivisor == 0)
    {
        printf("   No es posible realizar la división pedida\n   Verifique el denominador");
	}
	else
    {
        elcociente = cociente_lento(eldividendo, eldivisor);
        elresto = resto_lento(eldividendo, eldivisor);
        printf("resulta %d \n", elcociente);
        printf("con resto %d \n", elresto);
	}

    return 0;
}
