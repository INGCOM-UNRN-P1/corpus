

#include <stdio.h>
#include <string.h>

#define MAX_CADENA     32
#define MAX_TELEFONO   16
#define MAX_CONTACTOS  5
#define FALSE          0
#define TRUE           1
#define ERROR         -1

//void crear_contacto(struct contacto *mi_contacto, char nombre, char apellido, char telefono, char email);
//void agregar_contacto(struct contacto *mi_contacto,struct agenda *mi_agenda);


struct contacto{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
};

struct agenda {
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
};

int main(int argc, char *argv[])
{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];

    struct contacto mi_temporal;

    printf("\n\n\tIngrese nombre\n\n");
    scanf("%s", nombre);
    printf("\n\n\tIngrese apellido\n\n");
    scanf("%s", apellido);
    printf("\n\n\tIngrese telefono\n\n");
    scanf("%s", telefono);
    printf("\n\n\tIngrese email\n\n");
    scanf("%s", email);

    crear_contacto(&mi_temporal, nombre, apellido, telefono, email);

}

void crear_contacto(struct contacto *mi_contacto, char *nombre, char *apellido, char *telefono, char *email)
{
    strcpy(mi_contacto -> nombre, nombre);
    strcpy(mi_contacto -> apellido, apellido);
    strcpy(mi_contacto -> telefono, telefono);
    strcpy(mi_contacto -> email, email);

    printf("\n\nLlegué hasta aca\n\n");

    imprimir_contacto(mi_contacto);

    agregar_contacto(mi_contacto);

    

}

int agregar_contacto(struct contacto *mi_contacto)
{
    struct agenda mi_agenda;


    if (hay_lugar(&mi_agenda) == FALSE || hay_lugar(&mi_agenda) == ERROR)
    {
        return 0;
    }

    int ultimo = ultimo_lugar(&mi_agenda);

    mi_agenda.contactos[ultimo] = mi_contacto;
    mi_agenda.cantidad_contactos = ultimo - 1;  

}

void imprimir_contacto( struct contacto *mi_contacto )
{

   printf( "Nombre   \t : \t %s\n",       mi_contacto -> nombre);
   printf( "Apellido \t : \t %s\n",       mi_contacto -> apellido);
   printf( "Telefono \t : \t %s\n",       mi_contacto -> telefono);
   printf( "Email    \t : \t %s\n\n\n",   mi_contacto -> email);
}

int ultimo_lugar(struct agenda *mi_agenda)
{
    int ultimo = mi_agenda -> cantidad_contactos;

    if(ultimo < 0){ return MAX_CONTACTOS; }

    return MAX_CONTACTOS - ultimo;
}

int hay_lugar(struct agenda *mi_agenda)
{
    int cantidad_contactos = mi_agenda -> cantidad_contactos;

    if(cantidad_contactos == MAX_CONTACTOS)
    {
        return FALSE;
    }
    else if (cantidad_contactos < MAX_CONTACTOS)
    {
        return TRUE;
    }
    else
    {
        return ERROR;
    }
}

