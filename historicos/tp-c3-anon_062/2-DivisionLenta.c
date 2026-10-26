

//Con dos valores enteros se resolverá una división
//indicando sus partes fundamentales (dividendo, divisor, cociente y resto)

#include <stdio.h>

typedef struct operaciondivision{
    int dividendo;
    int cociente;
    int resto;
    int divisor;
}la_division;


// -------------------- resto ---------------
int resto_lento(la_division numeroa)
// calcula el resto de la división entre dos valores ingresados
// recibe un número con estructura ´operaciondivision´
// DEVUELVE un valor entero (o cero) seguún corresponda.
{
    int sustraendo = 0;
    int minuendo = 0;

    minuendo = numeroa.dividendo + 1;       //el número que voy a dividir lo llamo minuendo y
    sustraendo = numeroa.divisor;           //y le agrego un 1 para que al menos opere UNA VEZ.

    while (sustraendo < minuendo)          // mientras el dividendo sea mayor que el divisor
    {                                      // le saca en cada iteracion la cantidad indicada por el 
    minuendo = minuendo - sustraendo;      // divisor - hasta que el dividendo es menor que el divisor
    }

    minuendo = minuendo - 1;               // le saco UNA UNIDAD que le agregué al principio de la rutina.
    return minuendo;
}


// --------------------- cociente -------------
int cociente_lento(la_division numeroa)
// Calcula el cociente de la division entre dos  valores ingresados
// recibe un con estructura ´operaciondivision´
// DEVUELVE un valor entero (o cero) seguún corresponda.
{
    int cociente = 0;
    int sustraendo = 0;
    int minuendo = 0;
    
    minuendo = numeroa.dividendo + 1;       //el número que voy a dividir lo llamo minuendo y
    sustraendo = numeroa.divisor;           //y le agrego un 1 para que al menos opere UNA VEZ.

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
    int elcociente = 0;
    int elresto = 0;

    la_division numeroa;

    printf("Ingrese un dividendo : ");
    scanf("%d", &numeroa.dividendo);
    printf("Ingrese un divisor : ");
    scanf("%d", &numeroa.divisor);

    if (numeroa.divisor == 0)
    {
        printf("  No es posible realizar la división pedida\n  Verifique el denominador");
    }
    else
    {
        elcociente = cociente_lento(numeroa);
        elresto = resto_lento(numeroa);
        printf("resulta %d \n", elcociente);
        printf("con resto %d \n", elresto);
    }

    return 0;
}