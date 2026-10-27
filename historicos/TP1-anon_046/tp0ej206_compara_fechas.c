
#include <stdio.h>
#include "mis_funciones.h"

#define MAX_CARACTERES 11

int es_fecha(char *fecha){
    
    int id = 0;
    int date[3] = {0};

    while(*fecha != '\0'){
        switch(*fecha){
	    case '/':
	        id++;
		break;
	    case '0':
	    case '1':
	    case '2':
	    case '3':
	    case '4':
	    case '5':
	    case '6':
	    case '7':
	    case '8':
	    case '9':
	        date[id] = date[id] * 10 + (*fecha - '0');
		break;
	    default:
	        return 0;
	}
	if (id > 2)
	    return 0;
        fecha++;
    }

    
    if (date[1] > 12)
        return 0;
    
    if (date[1] == 2 && date[0] > 28)
        return 0;
    
    if ((date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11) && date[0] > 30)
        return 0;
    
    if (date[0] > 31)
        return 0;

    return 1;
}

int compara_fechas(char *primera, char *segunda){
    
    int id = 0;
    int date[3] = {0};
    int numero[2];
    char *fecha = primera;

    for (int i = 0; i < 2; i++){
        while(*fecha != '\0'){
            switch(*fecha){
	        case '/':
	            id++;
		    break;
	        case '0':
	        case '1':
	        case '2':
	        case '3':
	        case '4':
	        case '5':
	        case '6':
	        case '7':
	        case '8':
	        case '9':
	            date[id] = date[id] * 10 + (*fecha - '0');
		    break;
	        default:
	            return 0;
	    }
	    if (id > 2)
	        return 0;
            fecha++;
        }
        numero[i] = date[2]*10000 + date[1]*100 + date[0]*1;
	id = 0;
	date[0] = 0;
	date[1] = 0;
	date[2] = 0;
	fecha = segunda;
    }

    if (numero[0] < numero[1])
        return -1;
    if (numero[0] > numero[1])
        return  1;
    
    return 0;
}

int main(int argc, char *argv[])
{
    char entrada[2][MAX_CARACTERES + 1] = {"\0"};
    char valor[3][12] = {"es anterior", "es igual", "es posterior"};

    printf("Ingrese dos fechas de a una (dd/mm/yy)\n");
    for (int i = 0; i < 2; i++){
        printf("\t%d: ", i + 1);
        if (ingreso_sin_newline(entrada[i],
            sizeof(entrada[i]), stdin) ||
	    !es_fecha(entrada[i])){
            printf("\n*** Error en ingreso de fecha\n");
            return (-1);
        }
    }

    printf("*** %s %s a %s\n", entrada[0],
           valor[(compara_fechas(entrada[0], entrada[1])) + 1],
           entrada[1]);

    return 0;
}
