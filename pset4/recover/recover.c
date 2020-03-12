#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main (int numOfArguments, string argValues[])
{
    if (numOfArguments == 2)
    {
        char* file = argValues[1];
        FILE* card = fopen(file, "r");
        if (!card)
        {
         printf("No file or nothing in file.");
         fclose(card);
         return 1;
        }
     // define buffer
     unsigned char buffer[512];
    // keep count
    int imgcount=0;
    FILE* jpg = NULL;
    char filename[8] = "0";

    while (fread (buffer,512,1,card) == 1)
    {
        if ( buffer[0]==0xff && buffer[1]== 0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0)
        {

        sprintf(filename,"%03d.jpg",imgcount);
       // printf("after sprintf\n");
        jpg = fopen(filename,"w");
        fwrite(buffer, 512,1,jpg);

        imgcount++;
        }
        else if (jpg != NULL)
        {

             fwrite(buffer, 512,1,jpg);
        }
    }
    printf ("Total number of JPG images in file: %i\n",imgcount);
    fclose(card);
    return 0;
    }
    else
    {
        printf("Usage: ./getJPG filename");
        return 1;
    }

}


