/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
#define MAX_CONTACTOS 100
#define MAX_CADENA 40
#define MAX_TELEFONO 30
#define MAX_CADENA_A_SOLICITAR 20
#define MAX_CADENA_TELEFONO_SOLICITAR 15
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i=0;
    int largo=0;
    for (i=0;i<capacidad_cadena;i++){
        if(cadena[largo]!='\0')
        {
            largo=largo+1;
        }else{
            break;
        }
    }
	return largo;
}
struct contacto{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
} contactos_a_guardar[MAX_CONTACTOS];

struct agenda{
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
} datos_agenda;
int agregar_contacto_al_final(struct agenda *agenda_actual, struct contacto contacto_a_agregar)
{
    int cantidad_contactos;
    if(agenda_actual->cantidad_contactos==MAX_CONTACTOS)
    {
        printf("No se pudo guardar el contacto\n");
        return 0;
    }
    cantidad_contactos=agenda_actual->cantidad_contactos;
    agenda_actual->cantidad_contactos=cantidad_contactos+1;
    printf("cntactos antse %d\n", cantidad_contactos); 
    agenda_actual->contactos[cantidad_contactos] = contacto_a_agregar;   
printf("cntactos %d\n", agenda_actual->cantidad_contactos);    
    printf("Contacto guardado\n");
    return 1;   
}
void borrar_caracteres(char *dato, int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++){
        dato[i]='\0';
    }
}
void borrar_por_posición(struct agenda *agenda_actual, int posicion)
{
    int tamanio_nombre,tamanio_apellido,tamanio_email,tamanio_telefono;
    if(posicion>=0 && posicion<MAX_CONTACTOS)
    {
        tamanio_nombre = largo_cadena(agenda_actual->contactos[posicion].nombre,MAX_CADENA);
        tamanio_apellido = largo_cadena(agenda_actual->contactos[posicion].apellido,MAX_CADENA);
        tamanio_email = largo_cadena(agenda_actual->contactos[posicion].telefono,MAX_CADENA);
        tamanio_telefono = largo_cadena(agenda_actual->contactos[posicion].email,MAX_TELEFONO);
        borrar_caracteres(agenda_actual->contactos[posicion].nombre,tamanio_nombre);
        borrar_caracteres(agenda_actual->contactos[posicion].apellido,tamanio_apellido);
        borrar_caracteres(agenda_actual->contactos[posicion].email,tamanio_email);
        borrar_caracteres(agenda_actual->contactos[posicion].telefono,tamanio_telefono);
    }  
}
void mostrar_por_posición(struct agenda *agenda_actual, int posicion)
{
    if(posicion>=0 && posicion<MAX_CONTACTOS)
    {
        printf("Los datos en a posicion %d son:\nNombre: %s\nApellido: %s\nTelefono: %s\nEmail: %s\n",posicion,agenda_actual->contactos[posicion].nombre,agenda_actual->contactos[posicion].apellido,agenda_actual->contactos[posicion].telefono,agenda_actual->contactos[posicion].email);
    }else{
        printf("No se pueden mostrar los datos");
    }
}
void asignar_nombre(struct contacto *contacto_actual,int posicion, char *nombre, int tamanio_nombre)
{
    int i;
    for(i=0;i<tamanio_nombre;i++)
    {
        contacto_actual[posicion].nombre[i]=nombre[i];
    }
}
void asignar_apellido(struct contacto *contacto_actual,int posicion, char *apellido, int tamanio_apellido)
{
    int i;
    for(i=0;i<tamanio_apellido;i++)
    {
        contacto_actual[posicion].apellido[i]=apellido[i];
    }
}
void asignar_telefono(struct contacto *contacto_actual,int posicion, char *telefono, int tamanio_telefono)
{
    int i;
    for(i=0;i<tamanio_telefono;i++)
    {
        contacto_actual[posicion].telefono[i]=telefono[i];
    }
}
void asignar_email(struct contacto *contacto_actual,int posicion, char *email, int tamanio_email)
{
    int i;
    for(i=0;i<tamanio_email;i++)
    {
        contacto_actual[posicion].email[i]=email[i];
    }
}
int main(int argc, char *argv[])
{
    int i,j,k,mostrar,seguir,tamanio_caracteres_nombre,tamanio_caracteres_apellido,tamanio_caracteres_telefono,tamanio_caracteres_email;
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
    char mensaje_error[70]="\nDato no cumple con el ancho de caracteres";
    datos_agenda.cantidad_contactos = 0;
    for(i=0;i<MAX_CONTACTOS;i++)
    {
        printf("Ingrese un nombre (menor a %d caracteres): ",MAX_CADENA_A_SOLICITAR);
        scanf("%s",&nombre);
        tamanio_caracteres_nombre=largo_cadena(nombre,MAX_CADENA);
        if(tamanio_caracteres_nombre>MAX_CADENA_A_SOLICITAR)
        {
            printf("%s",mensaje_error);
        }else{
            asignar_nombre(contactos_a_guardar,i,nombre,tamanio_caracteres_nombre);
        }
        printf("\nIngrese un apellido (menor a %d caracteres): ",MAX_CADENA_A_SOLICITAR);
        scanf("%s",&apellido);
        tamanio_caracteres_apellido=largo_cadena(apellido,MAX_CADENA);
        if(tamanio_caracteres_apellido>MAX_CADENA_A_SOLICITAR)
        {
            printf("%s",mensaje_error);
        }else{
            asignar_apellido(contactos_a_guardar,i,apellido,tamanio_caracteres_apellido);
        }
        printf("\nIngrese un telefono (menor a %d caracteres): ",MAX_CADENA_TELEFONO_SOLICITAR);
        scanf("%s",&telefono);
        tamanio_caracteres_telefono=largo_cadena(telefono,MAX_TELEFONO);
        if(tamanio_caracteres_telefono>MAX_CADENA_TELEFONO_SOLICITAR)
        {
            printf("%s",mensaje_error);
        }else{
            asignar_telefono(contactos_a_guardar,i,telefono,tamanio_caracteres_telefono);
        }
        printf("\nIngrese un email (menor a %d caracteres): ",MAX_CADENA_A_SOLICITAR);
        scanf("%s",&email);
        tamanio_caracteres_email=largo_cadena(email,MAX_CADENA);
        if(tamanio_caracteres_email>MAX_CADENA_A_SOLICITAR)
        {
            printf("%s",mensaje_error);
        }else{
            asignar_email(contactos_a_guardar,i,email,tamanio_caracteres_email);
        }
        agregar_contacto_al_final(&datos_agenda, contactos_a_guardar[i]);
        printf("\nIngrese\n1 Para seguir insertando\n0 Para no seguir\n");
        scanf("%d",&seguir);
        if(seguir==0)
        {
            break;
        }
    }
    printf("\nDatos ingresados:\n");
    j=0;
    for (k=0; k<=i; k++)
    {
        j=k+1;
        printf ("#%d Nombre, apellido, telefono, email: %s,%s,%s,%s \n",j,contactos_a_guardar[k].nombre, contactos_a_guardar[k].apellido,contactos_a_guardar[k].telefono,contactos_a_guardar[k].email);
    } 
    printf("\nCantidad de contactos: %d\n",datos_agenda.cantidad_contactos);
    printf("\nDatos en la agenda:\n");
    for (i=0; i<datos_agenda.cantidad_contactos; i++)
    {
        j=i+1;
        printf ("#%d Nombre, apellido, telefono, email: %s,%s,%s,%s \n",j,datos_agenda.contactos[i].nombre, datos_agenda.contactos[i].apellido,datos_agenda.contactos[i].telefono,datos_agenda.contactos[i].email);
    }
    borrar_por_posición(&datos_agenda,1);
    printf("\nDatos en la agenda despues de borrar :\n");
    for (i=0; i<datos_agenda.cantidad_contactos; i++)
    {
        j=i+1;
        printf ("#%d Nombre, apellido, telefono, email: %s,%s,%s,%s \n",j,datos_agenda.contactos[i].nombre, datos_agenda.contactos[i].apellido,datos_agenda.contactos[i].telefono,datos_agenda.contactos[i].email);
    }
    printf("\nIngrese un numero entre 0 y %d:\n",k-1);
    scanf("%d",&mostrar);
    mostrar_por_posición(&datos_agenda,mostrar);
	return 0;
}
