

#include <stdio.h>
#include <stdbool.h>
#define MAX_CADENA 40
#define MAX_CONTACTOS 100
#define MAX_TELEFONO 18
#define FUERA_DE_RANGO -1
#define AGENDA_COMPLETA -2

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
    if (agenda->cantidad_contactos < MAX_CONTACTOS)
    {
        struct contacto nuevo;

        printf("\n\tAgregar Contacto\n");

        printf("\nNombre: ");
        fgets(nuevo.nombre, MAX_CADENA, stdin);

        printf("\nApellido: ");
        fgets(nuevo.apellido, MAX_CADENA, stdin);

        printf("\nNumero de Telefono: ");
        fgets(nuevo.telefono, MAX_TELEFONO, stdin);

        printf("\nEmail: ");
        fgets(nuevo.mail, MAX_CADENA, stdin);

        printf("\n\t Contacto agregado.\n");

        agenda->contactos[agenda->cantidad_contactos] = nuevo;
        agenda->cantidad_contactos++;

        return 0;
    }
    return AGENDA_COMPLETA;
}
int borrarContacto(struct agenda * agenda, int posicion)
{
    if (posicion > 0 && posicion <= agenda->cantidad_contactos)
    {
        for(int i=posicion-1; i<agenda->cantidad_contactos-1; i++)
        {
            agenda->contactos[i] = agenda->contactos[i + 1];
        }

        agenda->cantidad_contactos--;

        printf("\n EL contacto #%d se borro correctamente.\n",posicion);
        return 0;
    }

    return FUERA_DE_RANGO;
}
int mostrarContacto(struct agenda * agenda, int posicion)
{
	if (posicion > 0 && posicion <= agenda->cantidad_contactos)
    {
        printf("\n----------------------------------------------\n");

        printf("Contacto a mostrar: #%d\n", posicion);

        posicion--;

        printf("\nNombre: %s", agenda->contactos[posicion].nombre);
        printf("\nApellido: %s", agenda->contactos[posicion].apellido);
        printf("\nNumero de Telefono: %s", agenda->contactos[posicion].telefono);
        printf("\nEmail: %s\n", agenda->contactos[posicion].mail);

        return 0;
    }
    printf("No se encontro un contacto en la posicion: #%d\n", posicion);
    return FUERA_DE_RANGO;
}

int main()
{
	int seleccionar=0;
    int posicion=0;
    struct agenda agenda;
    agenda.cantidad_contactos = 0;

    while (seleccionar != 4)
    {
        printf("\t\t\t\t\t");
        for(int i=0;i<25;i++)
        {
          printf("*");
        }
        printf("\n\t\t\t\t\t*\t AGENDA \t*");
        printf("\n\t\t\t\t\t");
        for(int i=0;i<25;i++)
        {
          printf("*");
        }

        printf("\nOperaciones:\n");
        printf("\ningrese 1 para agregar contacto");
        printf("\ningrese 2 para borrar contacto por posicion");
        printf("\ningrese 3 para mostrar contacto por posicion");
        printf("\ningrese 4 para salir\n");
        printf("Seleccione: ");
        scanf("%d",&seleccionar);
        getchar();
        switch (seleccionar)
        {
            case 1:
                agregarContacto(&agenda);
                break;

            case 2:
                printf("\n----------------------------------------------\n");
                printf("Borrar contacto de la posicion: #");
                scanf("%d",&posicion);
                borrarContacto(&agenda,posicion);
                break;

            case 3:
                printf("\n----------------------------------------------\n");
                printf("Buscar contacto de la posicion: #");
                scanf("%d",&posicion);
                mostrarContacto(&agenda,posicion);
                break;

            case 4:
                break;

            default:
                printf("\nOpción incorrecta.\n");
        }
    }

    return 0;
}
