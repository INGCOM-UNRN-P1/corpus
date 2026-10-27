

#include <stdio.h>
#include <stdbool.h>

#define MAX_CADENA 20
#define MAX_TELEFONO 18
#define MAX_CONTACTOS 100
#define FUERA_DE_RANGO -1
#define AGENDA_LLENA -2

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
        struct contacto nuevo_contacto;
        
        printf("\n----------------------------------------------\n");
        printf("\n-- Ingrese los datos del contacto a agregar --\n");

        printf("\nNombre: ");
        fgets(nuevo_contacto.nombre, MAX_CADENA, stdin);
        fflush(stdin);

        printf("\nApellido: ");
        fgets(nuevo_contacto.apellido, MAX_CADENA, stdin);
        fflush(stdin);

        printf("\nTeléfono: ");
        fgets(nuevo_contacto.telefono, MAX_TELEFONO, stdin);
        fflush(stdin);

        printf("\nEmail: ");
        fgets(nuevo_contacto.mail, MAX_CADENA, stdin);
        fflush(stdin);
        
        agenda->contactos[agenda->cantidad_contactos] = nuevo_contacto;
        agenda->cantidad_contactos++;
        
        printf("\nContacto agregado correctamente.\n");
        return 0;
    }
    
    return AGENDA_LLENA;
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
        
        printf("\nContacto nro. %d borrado correctamente.\n",posicion);
        return 0;
    }
    
    return FUERA_DE_RANGO;
}

int mostrarContacto(struct agenda * agenda, int posicion)
{
    if (posicion > 0 && posicion <= agenda->cantidad_contactos)
    {
        printf("\n----------------------------------------------\n");
            
        printf("CONTACTO NUMERO: %d\n", posicion);
        
        posicion--; //Para que el usuario ingrese posicion comenzando en 1
        
        printf("\nNombre: %s", agenda->contactos[posicion].nombre);
        printf("\nApellido: %s", agenda->contactos[posicion].apellido);
        printf("\nTeléfono: %s", agenda->contactos[posicion].telefono);
        printf("\nEmail: %s\n", agenda->contactos[posicion].mail);
        
        return 0;
    }
    
    return FUERA_DE_RANGO;
}

int main()
{
    int seleccion=0;
    int posicion=0;
    struct agenda agenda;
    agenda.cantidad_contactos = 0;
    
    while (seleccion != 4)
    {
        printf("\n\n-------AGENDA-------\n");
        printf("\nOPCIONES:\n");
        printf("\n1- Agregar contacto");
        printf("\n2- Borrar contacto");
        printf("\n3- Buscar contacto por posicion");
        printf("\n4- Salir\n");
        printf("Seleccion: ");
        scanf("%d",&seleccion);
        getchar();
        switch (seleccion)
        {
            case 1:
                agregarContacto(&agenda);
                break;
            
            case 2:
                printf("\n----------------------------------------------\n");
                printf("Borrar contacto nro (empezando por 1): ");
                scanf("%d",&posicion);
                borrarContacto(&agenda,posicion);
                break;
            
            case 3:
                printf("\n----------------------------------------------\n");
                printf("Buscar contacto nro (empezando por 1): ");
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