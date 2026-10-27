

#include <stdio.h>
#include <string.h>

int comparar_fechas(char *primera, char *segunda)
{
    int comparacion = strcmp(primera, segunda);

    if (comparacion == 0)
    {
        return 0;
    }
    
    if (comparacion < 0)
    {
        return -1;
    }
    if (comparacion > 0)
    {
        return 1;
    }

}

int main(int argc, char const *argv[])
{

    char primera[20], segunda[20];
    int result = 0;

    printf("Ingrese primera fecha en formato dd/mm/aaaa: \n");
    scanf("%s", primera);

    printf("Ingrese segunda fecha en formato dd/mm/aaaa: \n");
    scanf("%s", segunda);

    result = comparar_fechas(primera, segunda);
    printf("%d", result);

    return 0;

}
