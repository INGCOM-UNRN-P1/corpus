

#include "funciones_seguras.h"
#include <stdio.h>

#define MAX_CADENA 50
#define MAX_TELEFONO 20
#define MAX_CONTACTOS 100
#define SIN_INTENTOS -1

struct contacto{
    char nombres[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
};

typedef struct{
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
}agenda;

//Prototipo
int agregar(struct contacto *micontacto,char *nombre,char *apellido,char *telefono,char *email);
void borrar_posicion(agenda *agen, int lugar, int total);
int borrar_nombre(agenda *agen, char *buscador);
void imprime_todo(agenda *agen, int total);

int main(int argc, char *argv[])
{
    agenda agen;
    char nombre_in[MAX_CADENA];
    char apellido_in[MAX_CADENA];
    char telefono_in[MAX_TELEFONO];
    char email_in[MAX_CADENA];
    agen.cantidad_contactos = 0;
    printf("\n[Agenda de Contactos]");
    int opcion = 0;
    int pos = 0;
    do
    {
        printf("\nMenu de Opciones:\n");
        printf("la agenda tiene %d contactos\n", agen.cantidad_contactos);
        printf("\t1)Agregar un contacto.\n");
        printf("\t2)Eliminar un contacto por posicion.\n");
        printf("\t3)Buscar un contacto por posicion.\n");
        printf("\t4)Eliminar un contacto por nombre.\n");
        printf("\t5)Imprimir todos los contactos.\n");
        printf("\t6)Cerrar el Programa.\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("\n---[Agendar Contacto]---\n");
            agen.cantidad_contactos++;
            int i = agen.cantidad_contactos;
            int res = 0;
            printf("Ingresar el nombre: ");
            fgets(nombre_in, MAX_CADENA, stdin);
            fgets(nombre_in, MAX_CADENA, stdin);
            fflush(stdin);
            printf("Ingresar el apellido: ");
            fgets(apellido_in, MAX_CADENA, stdin);
            fflush(stdin);
            printf("Ingresar telefono: ");
            fgets(telefono_in, MAX_CADENA, stdin);
            fflush(stdin);
            printf("Ingresar el E-Mail: ");
            fgets(email_in, MAX_CADENA, stdin);
            fflush(stdin);
            res = agregar(&agen.contactos[i], nombre_in, apellido_in, telefono_in, email_in);
            if(res != -1)
            {
                printf("Contacto agregado en la posicion %d\n", i);
            }
            else
            {
                printf("Error al ingresar los datos, la cadena ingresada es muy larga.\n");
            }
            break;
        case 2:
            printf("\n---[Eliminar Contacto]---\n");
            printf("Ingrese el numero de posicion del contacto a borrar: ");
            scanf("%d", &pos);
            if(pos > agen.cantidad_contactos)
            {
                printf("\nNo hay un contacto en la posicion %d,\n", pos);
                printf("la agenda tiene %d posiciones utilizadas.\n", agen.cantidad_contactos);
            }
            else
            {
                borrar_posicion(&agen, pos, agen.cantidad_contactos);
                printf("El contacto en la posicion %d se elimino.\n", pos);
                agen.cantidad_contactos--;
            }
            break;
        case 3:
            printf("\n---[Buscar Contacto]---\n");
            printf("Ingrese el numero de posicion que desea buscar: ");
            scanf("%d", &pos);
            if(pos > agen.cantidad_contactos)
            {
                printf("\nNo hay un contacto en la posicion %d,\n", pos);
                printf("la agenda tiene %d posiciones utilizadas.\n", agen.cantidad_contactos);
            }
            else
            {
                printf("\t%s\t%s", agen.contactos[pos].nombres, agen.contactos[pos].apellido);
                printf("\t%s\t%s\n", agen.contactos[pos].telefono, agen.contactos[pos].email);
            }
            break;
        case 4:
            printf("\n---[Eliminar Contacto]---\n");
            printf("Ingrese el nombre del contacto a eliminar: ");
            fgets(nombre_in, MAX_CADENA, stdin);
            fgets(nombre_in, MAX_CADENA, stdin);
            fflush(stdin);
            res = borrar_nombre(&agen, nombre_in);
            if (res != 0)
            {
                printf("Se elimino el contacto correctamente.\n");
                agen.cantidad_contactos--;
            }
            else
            {
                printf("No existe un contacto con ese nombre.\n");
            }
            break;
        case 5:
            printf("\n---[Todos los Contactos]---\n");
            imprime_todo(&agen, agen.cantidad_contactos);
            break;
        case 6:
            printf("\n---[Cerrando Programa]---\n");
            opcion = -1;
            break;
        default:
            printf("\nEl numero no corresponde a ninguna de las opciones, intente nuevamente.\n");
            break;
        }
    } while (opcion != -1);
    return 0;
}


int agregar(struct contacto *micontacto,char *nombre,char *apellido,char *telefono,char *email)
{
    int res = 0;
    res = copiadora(nombre, micontacto->nombres, MAX_CADENA);
    res = copiadora(apellido, micontacto->apellido, MAX_CADENA);
    res = copiadora(telefono, micontacto->telefono, MAX_CADENA);
    res = copiadora(email, micontacto->email, MAX_CADENA);
    return res;
}

void borrar_posicion(agenda *agen, int lugar, int total)
{
    for(lugar;lugar<= total-1;lugar++)
    {
        agen->contactos[lugar] = agen->contactos[lugar+1];
    }
}

int borrar_nombre(agenda *agen, char *buscador)
{
    int i = 1;
    int total = agen->cantidad_contactos;
    int res = 0;
    for(i;i<=total;i++)
    {
        char *puntero = busqueda(agen->contactos[i].nombres, MAX_CADENA, buscador);
        if (puntero != NULL)
        {
            res = i;
            break;
        }
        else
        {
            res = 0;
        }
    }
    if (res != 0)
    {
        for(res;res<= total-1;res++)
        {
            agen->contactos[res] = agen->contactos[res+1];
        }
    }
    return res;
}

void imprime_todo(agenda *agen, int total)
{
    int i = 1;
    for(i;i<=total;i++)
    {
        printf("Posicion %d\n", i);
        printf("\t%s\t%s", agen->contactos[i].nombres, agen->contactos[i].apellido);
        printf("\t%s\t%s\n", agen->contactos[i].telefono, agen->contactos[i].email);
    }
}