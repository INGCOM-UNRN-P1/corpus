 


#include <stdio.h>
#include <string.h>

#define MAX_CADENA 50
#define MAX_TELEFONO 20
#define MAX_CONTACTOS 100


struct contacto{
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
} datos;

struct agenda {
    struct contacto contactos[MAX_CONTACTOS];
    int cantidad_contactos;
} mi_agenda;


void agregar_contacto(struct contacto *datos, struct agenda *mi_agenda,int* pos){
	char contacto_nombre[MAX_CADENA];
	char contacto_apellido[MAX_CADENA];
	char contacto_telefono[MAX_CADENA];
	char contacto_email[MAX_CADENA];


	printf("Ingrese nombre: ");
	scanf("%s", contacto_nombre);
	printf("Ingrese apellido: ");
	scanf("%s", contacto_apellido);
	printf("Ingrese telefono: ");
	scanf("%s", contacto_telefono);
	printf("Ingrese el email: ");
	scanf("%s", contacto_email);

	strcpy(datos[*pos].nombre, contacto_nombre);
	strcpy(datos[*pos].apellido, contacto_apellido);
	strcpy(datos[*pos].telefono, contacto_telefono);
	strcpy(datos[*pos].email, contacto_email);

	printf("Datos agregados correctamente en la posicion %d!\n", *pos);
	*pos = *pos+1;

	mi_agenda->cantidad_contactos++;

}

void borrar_contacto(struct contacto *datos, struct agenda *mi_agenda, int* pos){
	int posicion;
	char eleccion = '\0';

	printf("Ingrese posicion del contacto a eliminar: ");
	scanf("%d", &posicion);

	if (posicion < *pos)
	{
		printf("Nombre: %s\tApellido: %s\tTelefono: %s\tEmail: %s\n", datos[posicion].nombre, datos[posicion].apellido, datos[posicion].telefono, datos[posicion].email);
		printf("Desea eliminar al contacto? (s/n): ");
		scanf(" %c", &eleccion);

		if (eleccion == 's')
		{
			for (int i = posicion; i < *pos; i++)
			{
				strcpy(datos[i].nombre, datos[i+1].nombre);
				strcpy(datos[i].apellido, datos[i+1].apellido);
				strcpy(datos[i].telefono, datos[i+1].telefono);
				strcpy(datos[i].email, datos[i+1].email);
			}

			printf("Contacto eliminado :)\n");
			mi_agenda->cantidad_contactos--;
			*pos = *pos-1;
			
		}
		else if (eleccion == 'n')
		{
			printf("El contacto no fue borrado\n");
		}
		else
		{
			printf("Opcion incorrecta! (s/n)\n");
		}
	}
	else
	{
		printf("El valor ingresado esta fuera de los limites!\n");
	}
}

void mostrar_contacto(struct contacto *datos){

	int posicion;
	printf("Ingrese la posicion a buscar en la agenda: ");
	scanf("%d", &posicion);


	if (posicion < posicion)
	{
		printf("\tNombre: %s\n\tApellido: %s\n\ttelefono: %s\n\temail: %s\n", datos[posicion].nombre, datos[posicion].apellido, datos[posicion].telefono, datos[posicion].email);
	}
	else
	{
		printf("La posicion especificada no se encuentra en el registro.\n");
	}
	
}


int main(int argc, char const *argv[])
{

	struct contacto datos[MAX_CADENA];
	struct agenda mi_agenda[MAX_CONTACTOS];

	int value = 1;
	int* posicion_de_agendado = &value;

	int choice;

	printf("------------------------------------------\n");
	printf("		AGENDA			  \n");
	printf("------------------------------------------\n");
	printf("	1) Agregar contacto			  \n");
	printf("	2) Borrar conctacto (por posicion)\n");
	printf("	3) Mostrar contacto (por posicion)\n");
	printf("	0) salir			  		  \n");
	printf("------------------------------------------\n");

	while (mi_agenda->cantidad_contactos < MAX_CONTACTOS)
	{

		printf("\nElija una opcion: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			agregar_contacto(datos, mi_agenda, posicion_de_agendado);
		}
		else if (choice == 2)
		{
			borrar_contacto(datos, mi_agenda, posicion_de_agendado);
		}

		else if (choice == 3)
		{
			mostrar_contacto(datos);
		}
		else if (choice == 0)
		{
			printf("Saliendo del programa...\n");
			break;
		}
		else
		{
			printf("Usted ingreso una opcion equivocada!\n");
		}
	}

	printf("Se alcanzo la cantidad maxima de contactos en la agenda :(\n");

    return 0;
}
