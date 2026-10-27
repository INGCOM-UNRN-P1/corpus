
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define LARGO_NOMBRE_USUARIO 100
 #define MAX_CADENA 100
 #define MAX_TELEFONO 20
 #define MAX_CONTACTOS 100


 struct contacto
 {
     char nombre[MAX_CADENA];
     char apellido[MAX_CADENA];
     char telefono[MAX_TELEFONO];
     char email[MAX_CADENA];
 };

 struct agenda
 {
     struct contacto contactos[MAX_CONTACTOS];
     int cantidad_contactos;
 };

 struct agenda bullet_journal;
 void mostrar_contactos(struct agenda bullet_journal);
 void mostrar_informacion(struct agenda *bullet_journal);
 void agregar_contacto(struct agenda *bullet_journal);
 void modificar_contacto(struct agenda *bullet_journal);
 void mos_contacto_seleccionado(struct agenda *bullet_journal);
 void eliminar_contacto(struct agenda *bullet_journal);
 void cartel_de_referencias_main();
 void cuadro_referencias_dentro_contactos();
 void borrar_por_nombre(struct agenda *bullet_journal);
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
 void mostrar_contactos(struct agenda bullet_journal)
 {
     printf("\nEjecutando Mostrar Contactos\n");
      if (bullet_journal.cantidad_contactos == 0)
      {
          printf("\n\tTiene  %d contacto(s) almacenados.\n\n", bullet_journal.cantidad_contactos);
      }
      else
      {
          printf("\nMostrando contactos almacenados...\n");
          printf("\tOrdenados por orden de ingreso:\n");
          for (int contador_para_mostrar = 1; contador_para_mostrar <= bullet_journal.cantidad_contactos;contador_para_mostrar++)
          {
            printf("\t\t%d. %s %s\n", contador_para_mostrar, bullet_journal.contactos[contador_para_mostrar-1].nombre,bullet_journal.contactos[contador_para_mostrar-1].apellido);
          }
      }
      cuadro_referencias_dentro_contactos();

 }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
void mostrar_informacion(struct agenda *bullet_journal)
{
    if(bullet_journal->cantidad_contactos == 0)
    {
        printf("\n\tAun tiene contacto para mostrar informacion :)\n");
    }
    else
    {
        mos_contacto_seleccionado(bullet_journal);
    }
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void mos_contacto_seleccionado(struct agenda *bullet_journal)
{
    int posicion_seleccionada;
    printf("\n\n->Elije el contacto el cual deseas ver su informacion: ");
    scanf("%d",&posicion_seleccionada);
    getchar();
    if (posicion_seleccionada <= 0 || posicion_seleccionada > bullet_journal->cantidad_contactos)
    {
        printf("\tNumero de posicion invalido.\n");
        printf("\tMataste a Spider-Man x_x y \n\tatrasaste a la entrega de Matrix 4 hasta el anon_002.\n\tQue mal.");
    }
    else
    {
        printf("\tHas seleccionado %d a %s %s\n", posicion_seleccionada, bullet_journal->contactos[posicion_seleccionada-1], bullet_journal->contactos[posicion_seleccionada-1].apellido);
        printf("\tMostrando informacion de %s %s...\n", bullet_journal->contactos[posicion_seleccionada-1].nombre, bullet_journal->contactos[posicion_seleccionada-1].apellido);
        printf("\n\tEmail: %s\n",bullet_journal->contactos[posicion_seleccionada-1].email);
        printf("\tTelefono: %s\n",bullet_journal->contactos[posicion_seleccionada-1].telefono);
    }

}
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 void agregar_contacto(struct agenda *bullet_journal)
 {
     printf("\n\tEjecutando Agregar Contacto\n");

     printf("\nIngrese el nombre: ");
     fgets(bullet_journal->contactos[bullet_journal->cantidad_contactos].nombre,MAX_CADENA,stdin);
     int largo_de_nombre = strlen(bullet_journal->contactos[bullet_journal->cantidad_contactos].nombre);
     bullet_journal->contactos[bullet_journal->cantidad_contactos].nombre[largo_de_nombre-1] = '\0';

     printf("Ingrese el apellido: ");
     fgets(bullet_journal->contactos[bullet_journal->cantidad_contactos].apellido,MAX_CADENA,stdin);
     int largo_de_apellido = strlen(bullet_journal->contactos[bullet_journal->cantidad_contactos].apellido);
     bullet_journal->contactos[bullet_journal->cantidad_contactos].apellido[largo_de_apellido-1] = '\0';

     printf("Ingrese el telefono: ");
     fgets(bullet_journal->contactos[bullet_journal->cantidad_contactos].telefono,MAX_TELEFONO,stdin);
     int largo_de_telefono = strlen(bullet_journal->contactos[bullet_journal->cantidad_contactos].telefono);
     bullet_journal->contactos[bullet_journal->cantidad_contactos].telefono[largo_de_telefono-1] = '\0';

     printf("Ingrese el mail: ");
     fgets(bullet_journal->contactos[bullet_journal->cantidad_contactos].email,MAX_CADENA,stdin);
     int largo_de_mail = strlen(bullet_journal->contactos[bullet_journal->cantidad_contactos].email);
     bullet_journal->contactos[bullet_journal->cantidad_contactos].email[largo_de_mail-1] = '\0';

     bullet_journal->cantidad_contactos++;

     printf("\n\tHabemus contacto #%d.", bullet_journal->cantidad_contactos);
 }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
void modificar_contacto(struct agenda *bullet_journal)
{
    if(bullet_journal->cantidad_contactos == 0)
    {
        printf("\n\tAun tiene contactos para modificar :)\n");
    }
    else
    {
        int posicion_seleccionada;
        int accion;
        char nuevo_nombre[MAX_CADENA];
        char nuevo_apellido[MAX_CADENA];
        char nuevo_telefono[MAX_TELEFONO];
        char nuevo_mail[MAX_CADENA];
        printf("\n\n->Elije el contacto el cual deseas modicar su informacion: ");
        scanf("%d",&posicion_seleccionada);
        getchar();
        if (posicion_seleccionada <= 0 || posicion_seleccionada > bullet_journal->cantidad_contactos)
        {
            printf("\tNumero de posicion invalido.\n");
            printf("\tChasqueaste los dedos.\n\tMataste a la mitad de la cursada de programacion x_x.\n\tQue mal.");
        }
        else
        {
            printf("\tHas seleccionado %d a %s %s\n", posicion_seleccionada, bullet_journal->contactos[posicion_seleccionada-1], bullet_journal->contactos[posicion_seleccionada-1].apellido);
            printf("\n\n|---------------------------------------------|\n");
            printf("|\tMenu de modificacion                  |\n");
            printf("|--> Que deseas modificar?                    |\n");
            printf("|                                             |\n");
            printf("|\t(1) Modificar nombre                  |\n");
            printf("|\t(2) Modificar apellido                |\n");
            printf("|\t(3) Modificar telefono                |\n");
            printf("|\t(4) Modificar email                   |\n");
            printf("|\t(5) Modificar *TODO*                  |\n");
            printf("|\t(0) Hacia atras <------               |\n");
            printf("|---------------------------------------------|\n");
            printf("\nIngrese la accion: ");
            scanf("%d",&accion);
            getchar();
            switch (accion)
            {

                case 0:
                printf("Modificacion anulada o_0.");
                break;

                case 1:
                printf("Ingrese el nuevo nombre: ");
                fgets(nuevo_nombre,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].nombre, nuevo_nombre);
                int largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].nombre);
                bullet_journal->contactos[posicion_seleccionada-1].nombre[largo_de_cadena_nueva-1] = '\0';
                printf("Hecho.");
                break;

                case 2:
                printf("Ingrese el nuevo apellido: ");
                fgets(nuevo_apellido,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].apellido, nuevo_apellido);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].apellido);
                bullet_journal->contactos[posicion_seleccionada-1].apellido[largo_de_cadena_nueva-1] = '\0';
                printf("Hecho.");
                break;

                case 3:
                printf("Ingrese el nuevo telefono: ");
                fgets(nuevo_telefono,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].telefono, nuevo_telefono);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].telefono);
                bullet_journal->contactos[posicion_seleccionada-1].telefono[largo_de_cadena_nueva-1] = '\0';
                printf("Hecho.");
                break;

                case 4:
                printf("Ingrese el nuevo email: ");
                fgets(nuevo_mail,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].email, nuevo_mail);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].email);
                bullet_journal->contactos[posicion_seleccionada-1].email[largo_de_cadena_nueva-1] = '\0';
                printf("Hecho.");
                break;

                case 5:
                printf("Ingrese el nuevo nombre: ");
                fgets(nuevo_nombre,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].nombre, nuevo_nombre);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].nombre);
                bullet_journal->contactos[posicion_seleccionada-1].nombre[largo_de_cadena_nueva-1] = '\0';

                printf("Ingrese el nuevo apellido: ");
                fgets(nuevo_apellido,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].apellido, nuevo_apellido);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].apellido);
                bullet_journal->contactos[posicion_seleccionada-1].apellido[largo_de_cadena_nueva-1] = '\0';

                printf("Ingrese el nuevo telefono: ");
                fgets(nuevo_telefono,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].telefono, nuevo_telefono);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].telefono);
                bullet_journal->contactos[posicion_seleccionada-1].telefono[largo_de_cadena_nueva-1] = '\0';

                printf("Ingrese el nuevo email: ");
                fgets(nuevo_mail,MAX_CADENA,stdin);
                strcpy(bullet_journal->contactos[posicion_seleccionada-1].email, nuevo_mail);
                largo_de_cadena_nueva = strlen(bullet_journal->contactos[posicion_seleccionada-1].email);
                bullet_journal->contactos[posicion_seleccionada-1].email[largo_de_cadena_nueva-1] = '\0';
                printf("Hecho.");
                break;
            }
        }
    }
}
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 void eliminar_contacto(struct agenda *bullet_journal)
 {
     int posicion_seleccionada;
     if(bullet_journal->cantidad_contactos == 0)
     {
         printf("\n\tAun tiene contacto para eliminar x_x.\n");
     }
     else
     {
         printf("\n\tMostrando los contactos almacenados...\n");
         for (int contador_para_mostrar = 1; contador_para_mostrar <= bullet_journal->cantidad_contactos;contador_para_mostrar++)
         {
           printf("\t\t%d. %s %s\n", contador_para_mostrar, bullet_journal->contactos[contador_para_mostrar-1].nombre,bullet_journal->contactos[contador_para_mostrar-1].apellido);
         }
         printf("\nQue contacto desea eliminar (por posicion): ");
         scanf("%d", &posicion_seleccionada);
         getchar();
         // memset(bullet_journal->contactos[posicion_seleccionada-1].nombre, 0,MAX_CADENA);
         // memset(bullet_journal->contactos[posicion_seleccionada-1].apellido, 0,MAX_CADENA);
         // memset(bullet_journal->contactos[posicion_seleccionada-1].telefono, 0,MAX_TELEFONO);
         // memset(bullet_journal->contactos[posicion_seleccionada-1].email, 0,MAX_CADENA);
         if (bullet_journal->cantidad_contactos == 0)
         {
             printf("No quedan contactos x_x.");
         }
         else
         {
             // Copia de nombre
             strcpy(bullet_journal->contactos[posicion_seleccionada-1].nombre, bullet_journal->contactos[bullet_journal->cantidad_contactos-1].nombre);
             bullet_journal->contactos[bullet_journal->cantidad_contactos-1].nombre[0] = '\0';

             // Copia de apellido
             strcpy(bullet_journal->contactos[posicion_seleccionada-1].apellido, bullet_journal->contactos[bullet_journal->cantidad_contactos-1].apellido);
             bullet_journal->contactos[bullet_journal->cantidad_contactos-1].apellido[0] = '\0';
             // Copia de telefono
             strcpy(bullet_journal->contactos[posicion_seleccionada-1].telefono, bullet_journal->contactos[bullet_journal->cantidad_contactos-1].telefono);
             bullet_journal->contactos[bullet_journal->cantidad_contactos-1].telefono[0] = '\0';
             // Copia de email
             strcpy(bullet_journal->contactos[posicion_seleccionada-1].email, bullet_journal->contactos[bullet_journal->cantidad_contactos-1].email);
             bullet_journal->contactos[bullet_journal->cantidad_contactos-1].email[0] = '\0';
         }
         bullet_journal->cantidad_contactos--;
         printf("Hecho.");
     }
 }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 void cartel_de_referencias_main()
 {
     printf("\n\n|---------------------------------------------|\n");
     printf("|\tMenu principal                        |\n");
     printf("|--> Que desea hacer?                         |\n");
     printf("|                                             |\n");
     printf("|\t(1)Mostrar contacto(s)                |\n");
     printf("|\t(2)Agregar contacto(s)                |\n");
     printf("|\t(3)Modificar contacto(s)              |\n");
     printf("|\t(4)Eliminar contacto(s)               |\n");
     printf("|\t(0)Cerrar agenda(s)                   |\n");
     printf("|---------------------------------------------|\n");
 }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 void cuadro_referencias_dentro_contactos()
 {
     int accion_contactos;
     printf("\n\n|---------------------------------------------|\n");
     printf("|\tMenu de contacto(s)                   |\n");
     printf("|--> Desea hacerle algo a los contacto(s)     |\n");
     printf("|                                             |\n");
     printf("|\t(1) Mostrar contacto(s) nuevamente    |\n");
     printf("|\t(2) Mostrar informacion de contacto(s)|\n");
     printf("|\t(3) Agregar contacto(s)               |\n");
     printf("|\t(4) Modificar contacto(s)             |\n");
     printf("|\t(5) Eliminar contacto(s)              |\n");
     printf("|\t(0) Hacia atras <------               |\n");
     printf("|---------------------------------------------|\n");
     printf("Ingrese la accion: ");
     scanf("%d",&accion_contactos);
     getchar();

     switch (accion_contactos)
     {
         case 0 :
         break;

         case 1:
         mostrar_contactos(bullet_journal);
         break;

         case 2:
         mostrar_informacion(&bullet_journal);
         break;

         case 3:
         agregar_contacto(&bullet_journal);
         break;

         case 4:
         modificar_contacto(&bullet_journal);
         break;

         case 5:
         eliminar_contacto(&bullet_journal);
         break;
     }
 }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 void borrar_por_nombre(struct agenda *bullet_journal)
 {
     printf("\n\tAun no se ha programado\n\tVuelva mas tarde");
 }
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 ///////////////////////////////////////////////////////////////////////////////
 int main()
 {
     printf("Ejercicio 4: AGENDA!!!!!!!!!!\n\n");
     bullet_journal.cantidad_contactos = 0;
     char nombre_de_usuario[LARGO_NOMBRE_USUARIO];
     int accion = 1;
     int programa_activo = 1;
     printf("Ingrese su nombre: ");
     fgets(nombre_de_usuario,LARGO_NOMBRE_USUARIO, stdin);

     printf("////////----------------------------\\\\\\\\\n");
     printf("\tBuenas tardes, %s\tEsta es su agenda.\n", nombre_de_usuario);
     printf("\\\\\\\\----------------------------////////\n\n\n");

     while (programa_activo != 0)
     {
         cartel_de_referencias_main();
         printf("\nIngrese la accion: ");
         scanf("%d",&accion);
         getchar();

         switch (accion){
             case 0 :
             programa_activo = 0;
             printf("\nAgenda finalizada ;).\n");
             break;

             case 1:
             mostrar_contactos(bullet_journal);
             break;

             case 2:
             agregar_contacto(&bullet_journal);
             break;

             case 3:
             modificar_contacto(&bullet_journal);
             break;

             case 4:
             eliminar_contacto(&bullet_journal);
             break;
         }
     }
     return 0;
 }
