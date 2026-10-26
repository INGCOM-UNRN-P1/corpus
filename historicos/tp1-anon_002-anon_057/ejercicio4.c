

#include <stdio.h>



#define MENOR -1
#define IGUAL 0
#define MAYOR 1


int compara(int numero, int otro_numero)
{
    int resultado = 0;
    if (numero < otro_numero)
    {
        resultado = 1;
    }
    else if (numero > otro_numero)
    {
        resultado = -1;
    }
    else
    {
        resultado = 0;
    }
    return resultado;
}

int main() {
    int valor_uno;
    int valor_dos;
    int resultado;
    
    valor_uno = 10;
    valor_dos = 5;
    
    resultado = compara(valor_uno, valor_dos);
    
    printf("numero_dos(%d) menor que numero_uno(%d) => %d\n", \
                valor_dos, valor_uno, resultado);

    valor_uno = 10;
    valor_dos = 10;
    
    resultado = compara(valor_uno, valor_dos);
    
    printf("numero_dos(%d) igual que numero_uno(%d) => %d\n", \
                valor_dos, valor_uno, resultado);
                
    valor_uno = 5;
    valor_dos = 10;
    
    resultado = compara(valor_uno, valor_dos);
    
    printf("numero_dos(%d) mayor que numero_uno(%d) => %d\n", \
                valor_dos, valor_uno, resultado);

    return 0;
}


