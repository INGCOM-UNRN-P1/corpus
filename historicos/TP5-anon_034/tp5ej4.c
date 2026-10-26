/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * Hanchut -- anon_034
 *************************/

#include <stdio.h>
#include <stdbool.h>

#define MAX_CADENA 32
#define MAX_CONTACTOS 100

struct contacto
{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_CADENA];
    char mail[MAX_CADENA];
};

struct agenda
{
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
};

int agregarContacto(struct agenda * agenda)
{
    struct contacto nuevo;
	
	printf("\n\tSISTEMA DE AGREGADO DE CONTACTO/S\n");

    printf("\nIngrese el nombre de su nuevo contacto: ");
    fgets(nuevo.nombre, MAX_CADENA, stdin);

    printf("\nIngrese el apellido de su nuevo contacto: ");
    fgets(nuevo.apellido, MAX_CADENA, stdin);

    printf("\nIngrese el telefono de su nuevo contacto: ");
    fgets(nuevo.telefono, MAX_CADENA, stdin);

    printf("\nIngrese la direccion de email de su nuevo contacto: ");
    fgets(nuevo.mail, MAX_CADENA, stdin);

    printf("\n\tSu contacto ha sido agregado exitosamente!\n");
	
	agenda->contactos[agenda->cantidad_contactos] = nuevo;
	agenda->cantidad_contactos++;

    return 0;
}

int borrarContacto(struct agenda * agenda, int pos_contacto)
{
	int i;
	
	printf("\n\tSISTEMA DE ELIMINADO DE CONTACTOS\t\n");
	printf("\n---------------------------------------------\n");
	
	if (pos_contacto > 0 && pos_contacto <= agenda->cantidad_contactos)
	{
		for (i = pos_contacto - 1; i < agenda->cantidad_contactos - 1; i++)
		{
			agenda->contactos[i] = agenda->contactos[i + 1];
		}
		
		agenda->cantidad_contactos--;
	}
	
	printf("\n\tSu contacto ha sido eliminado exitosamente!\n");
	
    return 0;
}

int mostrarContacto(struct agenda * agenda)
{
	int i;
	int j = 1;

	for (i = 0; i < agenda->cantidad_contactos; i++)
	{	
		printf("\n---------------------------------------------\n");
		
		printf("\nCONTACTO NUMERO: %d\n", j);
		
		printf("\nNombre y apellido: %s,%s", agenda->contactos[i].nombre, agenda->contactos[i].apellido);
		printf("\nNumero Telefonico: %s", agenda->contactos[i].telefono);
		printf("\nDireccion de email: %s\n", agenda->contactos[i].mail);
		
		j++;		
	}
	
	printf("---------------------------------------------");
	printf("\nCANTIDAD DE CONTACTOS: %d -- MAXIMO = 100\n", agenda->cantidad_contactos);
	
    return 0;
}

int main()
{
	struct agenda registro;
	int ingreso;
	int pos_contacto;
	
	registro.cantidad_contactos = 0;

	while (ingreso >= 0)
	{
		printf("\n----Menu----\n");
		printf("\nBIENVENID@ A SU AGENDA DIGITAL\n");
		printf("\nIngrese que operacion desea realizar: \t");
		printf("\n\n1 - MOSTRAR CONTACTO/S\n");
		printf("2 - AGREGAR CONTACTO/S\n");
		printf("3 - BORRAR CONTACTO/S\n");
		printf("-1 - FINALIZAR PROGRAMA\n\n");
	
		scanf("%d", &ingreso);
		getchar();
		
		switch(ingreso)
		{
			case 1:
				mostrarContacto(&registro);
				break;
				
			case 2:
				agregarContacto(&registro);
				break;
				
			case 3:
				printf("\nIngrese que contacto desea eliminar: \n");
				scanf("%d", &pos_contacto);
				getchar();
				borrarContacto(&registro, pos_contacto);
				break;
			
			case 0:
				printf("\nHasta la proxima!\n");
				break;
				
			default:
				printf("\nNo ha ingresado una opcion valida.\n");
		}
	}

    return 0;
}