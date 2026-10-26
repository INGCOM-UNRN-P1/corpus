#include <stdio.h>
#define X 2
#define Y 3

int main()
{
    char hila[2][3];
    int i=0,j=0;
    for (; i <= X; i++)
    {
        hila[i][j] = '*';
        for (; j < Y; j++)
        {
            hila[i][j] = '+';
        }
    }
    printf("\");
}
