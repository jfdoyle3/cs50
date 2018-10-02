#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    if (argc !=4)
    {
        printf("Usage: ./walkthru rows columns");
        return 1;
    }
    int rows= atoi(argv[1]);
    int columns= atoi(argv[2]);
    int size=atoi(argv[3]);
    for (int i=0; i<rows*size+(rows*size%2); i++)
    {
        for (int j=0; j<columns*size+(columns*size%2); j++)
        {
            printf("o ");
        }
        printf ("\n");
    }
}