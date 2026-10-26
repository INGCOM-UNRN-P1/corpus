/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>

#define MAX_CADENA 30
#define MAX_TELEFONO 17
#define MAX_CONTACTOS 100

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

//defino los structs a usar
struct agenda agenda1;
struct contacto contacto[MAX_CONTACTOS];

//funciones a implementar
void nuevo_contacto();
void borrar_contacto();
void mostrar_contacto();

int main()
{
    
    
    nuevo_contacto();  
    nuevo_contacto();  
    printf("Nombre: %s\nApellido: %s\nTelefono: %s\nEmail: %s\nActualmente hay:%d contactos\n\n\n", contacto[0].nombre, contacto[0].apellido, contacto[0].telefono, contacto[0].email, agenda1.cantidad_contactos);

    borrar_contacto();
    printf("Nombre: %s\nApellido: %s\nTelefono: %s\nEmail: %s\nActualmente hay:%d contactos\n\n\n", contacto[0].nombre, contacto[0].apellido, contacto[0].telefono, contacto[0].email, agenda1.cantidad_contactos);

    mostrar_contacto();

    return 0;
}


//Crea un nuevo contacto de acuerdo a la cantidad de contactos ya almacenados para asegurar que sea el ultimo
void nuevo_contacto()
{
    int i = agenda1.cantidad_contactos;

    if(agenda1.cantidad_contactos < MAX_CONTACTOS)
    {
        printf("Ingrese su nombre: ");
        scanf("%[^\n]%*c", contacto[i].nombre);
        printf("Ingrese su apellido: ");
        scanf("%[^\n]%*c", contacto[i].apellido);
        printf("Ingrese su telefono: ");
        scanf("%[^\n]%*c", contacto[i].telefono);
        printf("Ingrese su email: ");
        scanf("%[^\n]%*c", contacto[i].email);
        printf("\n\n");

        agenda1.cantidad_contactos = agenda1.cantidad_contactos + 1;
    }
}

//Pide que se ingrese la posición del contacto que se desea borrar. Si esta no existe, lo vuelve a hacer y luego lo borra;
void borrar_contacto()
{
    int borrar;
    do
    {
        printf("Ingrese la posición del contacto que le gustaría borrar: ");
        scanf("%d", &borrar);
    } while(borrar >= agenda1.cantidad_contactos);
    printf("\n\n");

    contacto[borrar] = contacto[borrar + 1];
    agenda1.cantidad_contactos = agenda1.cantidad_contactos - 1;


}

//Pide que se ingrese la posición del contacto que se desea mostrar. Si esta no existe, lo vuelve a hacer y luego lo muestra
void mostrar_contacto()
{
    int mostrar;
    do
    {
        printf("Ingrese la posición del contacto que desee ver: ");
        scanf("%d", &mostrar);
    }while (mostrar >= agenda1.cantidad_contactos);
    printf("\n\n");

    printf("El contacto de la posición %d es:\n\nNombre: %s\nApellido: %s\nTelefono: %s\nEmail: %s\n", mostrar, contacto[0].nombre, contacto[0].apellido, contacto[0].telefono, contacto[0].email);

}