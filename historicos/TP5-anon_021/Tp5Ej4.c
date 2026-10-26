/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_CADENA 50
#define MAX_TELEFONO 20
#define MAX_CONTACTOS 99

struct contacto{
    
    char nombre[MAX_CADENA];
    char apellido[MAX_CADENA];
    char telefono[MAX_TELEFONO];
    char email[MAX_CADENA];
    
};

struct agenda {
    
    struct contacto contactos[MAX_CONTACTOS];
    
    int cantidad_contactos;
    
}la_agenda; 

void crear_contacto(struct agenda *una_agenda);

void borrar_por_posicion(struct agenda *una_agenda, int cual);
 
void mostrar_por_posicion(struct agenda *una_agenda, int cual);

void eliminar_por_nombre(struct agenda *una_agenda, char el_nombre[MAX_CADENA]);

void remplaza(char *donde, char *concual);

void cambia_entre_si(char *donde, char *concual);

void ordenar(struct agenda *una_agenda);

int compara_nombres(char nombre_A[MAX_CADENA], char nombre_B[MAX_CADENA]);

int compara(char* primera, char *segunda);

void muestra_todo(struct agenda cualquier_agenda);
 
int main(int argc, char *argv[])
{
    
    int seleccion;
    
    char repetir[MAX_CADENA], nombre_pa_eliminar_de_la_agenda_asi_no_esta_mas[MAX_CADENA];
    
    la_agenda.cantidad_contactos = 0;
    
    do{
        
        printf("\n Bienvenido a 'mi_agenda', desea operar? si/no \n ");
        
        fgets(repetir, MAX_CADENA, stdin); 
        
        if (repetir[0] == 's' && repetir[1] == 'i'){
        
            printf("\n\n Agregar un contacto : 1'");
            
            printf("\n\n Borrar un contacto por pocicion : 2'");
            
            printf("\n\n Mostrar un contacto por pocision : 3'");
            
            printf("\n\n Borrar un contacto por nombre : 4'");
            
            printf("\n\n Mostrar todos los contactos : 5'");
            
            printf("\n\n Mostrar el futuro : 6'\n\n decicion: ");
            
            scanf("%d",&seleccion);
            
            getchar();
            
            switch(seleccion){
            
                case 1:
                    
                    crear_contacto(&la_agenda);
            
                    ordenar(&la_agenda);
                    
                break;
                
                case 2:
                
                    printf("\n\n Elija un contacto a eliminar del 0 al %d : ",la_agenda.cantidad_contactos - 1);
                
                    scanf("%d",&seleccion);
            
                    getchar();
                
                    borrar_por_posicion(&la_agenda, seleccion);
                        
                break;
            
                case 3:
                    
                    printf("\n\n Que contacto desea ver? elija del 0 al %d : ",la_agenda.cantidad_contactos - 1);
                
                    scanf("%d",&seleccion);
            
                    getchar();
                    
                    mostrar_por_posicion(&la_agenda, seleccion);
                
                break;
            
                case 4:
                
                    printf("\n A quien desea eliminar de la agenda? : ");
                
                    fgets(nombre_pa_eliminar_de_la_agenda_asi_no_esta_mas, MAX_CADENA, stdin);
                    
                    eliminar_por_nombre(&la_agenda, nombre_pa_eliminar_de_la_agenda_asi_no_esta_mas);
                
                break;
                
                case 5:
                    
                    muestra_todo(la_agenda);
                    
                break;
                
                case 6:
      
                    system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ&feature=youtu.be");
                
                break;
            
            }
        
        }
    
    }
    while(repetir[0] == 's' && repetir[1] == 'i');
    
    return 0;
}

void crear_contacto(struct agenda *una_agenda){
    
    printf("\n ingrese el nombre para el contacto Nro %d : ",una_agenda->cantidad_contactos);
    fgets(una_agenda->contactos[una_agenda->cantidad_contactos].nombre, MAX_CADENA, stdin); 
    
    printf("\n ingrese el apellido para el contacto Nro %d : ",una_agenda->cantidad_contactos);
    fgets(una_agenda->contactos[una_agenda->cantidad_contactos].apellido, MAX_CADENA, stdin); 
    
    printf("\n ingrese el telefono para el contacto Nro %d : ",una_agenda->cantidad_contactos);
    fgets(una_agenda->contactos[una_agenda->cantidad_contactos].telefono, MAX_CADENA, stdin); 
    
    printf("\n ingrese el email para el contacto Nro %d : ",una_agenda->cantidad_contactos);
    fgets(una_agenda->contactos[una_agenda->cantidad_contactos].email, MAX_CADENA, stdin); 
    
    una_agenda->cantidad_contactos += 1;
    
}

void borrar_por_posicion(struct agenda *una_agenda, int cual){
        
    for(;cual<una_agenda->cantidad_contactos;cual ++){

        remplaza(una_agenda->contactos[cual].nombre, una_agenda->contactos[cual + 1].nombre); 
        
        remplaza(una_agenda->contactos[cual].apellido, una_agenda->contactos[cual + 1].apellido);
        
        remplaza(una_agenda->contactos[cual].telefono, una_agenda->contactos[cual + 1].telefono);
        
        remplaza(una_agenda->contactos[cual].email, una_agenda->contactos[cual + 1].email);      
        
    }
    
    una_agenda->cantidad_contactos -= 1;
    
}

void remplaza(char *donde, char *concual){
    
    int A = 0,B = 0;
    
    for(; donde[A] != '\0'; A++){
    }
    for(; concual[B] != '\0'; B++){
    }
    
    if(A > B){
       
        for(int i = 0; donde[i] != '\0'; i++){
        
        donde[i] = concual[i];
        
        }
        
    }
    else{
    
        for(int i = 0; concual[i] != '\0'; i++){
        
            donde[i] = concual[i];
        
        }
    
    }
    
}

void mostrar_por_posicion(struct agenda *una_agenda, int cual){
    
    printf("\n\n Contacto Nro %d : ",cual);
    
    printf("\n\n nombre : %s",una_agenda->contactos[cual].nombre);
    
    printf("\n\n apellido : %s",una_agenda->contactos[cual].apellido);
    
    printf("\n\n telefono : %s",una_agenda->contactos[cual].telefono);
    
    printf("\n\n email : %s",una_agenda->contactos[cual].email);
    
}

void eliminar_por_nombre(struct agenda *una_agenda, char el_nombre[MAX_CADENA]){
    
    int esta = 0;
    
    for(int i = 0; i<una_agenda->cantidad_contactos;i++){
        
        if(compara_nombres(el_nombre,una_agenda->contactos[i].nombre) == 1){
            
            borrar_por_posicion(una_agenda,i);
            
            esta = 1;
            
        }
        
    }
    
}

int compara_nombres(char nombre_A[MAX_CADENA], char nombre_B[MAX_CADENA]){
    
    int i = 0, contador = 0;
    
    for(; nombre_A[i] != '\0';i++){
        
        if(nombre_A[i] == nombre_B[i]){
            
            contador ++;
            
        }
        
    }
    
    if(contador == i){
        
        return 1;
        
    }
    else{
        
        return 0;
        
    }
    
}

void ordenar(struct agenda *una_agenda){
    
    int resultado = 0;
    
    for(int i = 0; i<una_agenda->cantidad_contactos;i++){
    
        resultado = compara(una_agenda->contactos[i].nombre,una_agenda->contactos[una_agenda->cantidad_contactos-1].nombre);
    
        if(resultado == 1){
            
            printf("pockos");
            
            cambia_entre_si(una_agenda->contactos[i].nombre,una_agenda->contactos[una_agenda->cantidad_contactos-1].nombre);
            
            cambia_entre_si(una_agenda->contactos[i].apellido,una_agenda->contactos[una_agenda->cantidad_contactos-1].apellido);
            
            cambia_entre_si(una_agenda->contactos[i].telefono,una_agenda->contactos[una_agenda->cantidad_contactos-1].telefono);
            
            cambia_entre_si(una_agenda->contactos[i].email,una_agenda->contactos[una_agenda->cantidad_contactos-1].email);
            
        }
    
    }
    
}

int compara(char* primera, char *segunda){
	
	int orden,i = 0,ciclo = 0;
	
	while(ciclo == 0){
        
		if(primera[i]>= 65 && primera[i] <= 90){
			
			primera[i] += 32;
			
		}
		if(segunda[i]>= 65 && segunda[i] <= 90){
			
			segunda[i] += 32;
			
		}
		if(primera[i] >= 97 && primera[i] <= 122 && segunda[i] >= 97 && segunda[i] <= 122){
			
			if(primera[i] > segunda[i]){
			
				orden = 1;
				
				ciclo = 1;
			
			}
			else if(primera[i] < segunda[i]){
			
				orden = -1;
			
				ciclo = 1;
				
			}
			
		}
        else if(primera[i] < 97 || primera[i] > 122){
            
            if(segunda[i] < 97 || segunda[i] > 122){
                
                orden = 0;
			
                ciclo = 1;
                
            }
            else{
                
                orden = -1;
			
                ciclo = 1;
                
            }
            
            
        }   
        else if(segunda[i] < 97 || segunda[i] > 122){
            
            orden = 1;
			
			ciclo = 1;
            
        }
        
		i++;
	}
	
	return orden;
	
}

void cambia_entre_si(char *donde, char *concual){
    
    int tamano_A,tamano_B;
    
    char *aux;
    
    for(int i = 0;donde[i] != '\0'; i++){
        
        tamano_A ++;
        
    }
    for(int i = 0;donde[i] != '\0'; i++){
        
        tamano_B ++;
        
    }
    if(tamano_A <= tamano_B){
        
        aux = (char*)malloc(sizeof(char)*tamano_B);
        
    }
    else{
        
        aux = (char*)malloc(sizeof(char)*tamano_A);
        
    }
    
    remplaza(aux,donde);
    
    remplaza(donde,concual);
    
    remplaza(concual,aux);
    
    free(aux);
    
}

void muestra_todo(struct agenda cualquier_agenda){
    
    for(int i = 0; i< cualquier_agenda.cantidad_contactos; i++){
        
        printf("\n\n__________________________________ ");
        
        printf("\n\n Contacto Nro %d : ",i);
    
        printf("\n\n nombre : %s",cualquier_agenda.contactos[i].nombre);
    
        printf("\n\n apellido : %s",cualquier_agenda.contactos[i].apellido);
    
        printf("\n\n telefono : %s",cualquier_agenda.contactos[i].telefono);
    
        printf("\n\n email : %s",cualquier_agenda.contactos[i].email);
    
        printf("\n\n__________________________________ ");
         
    }
    
}