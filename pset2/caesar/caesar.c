#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    int key;

    if (argc == 2){

     key=atoi(argv[1]);
    printf("Key is: %i\n",key);

    } else {
        return 1;
    };

    string plain_text=get_string("plaintext:  ");
    printf("ciphertext: ");

    for(int i=0, n=strlen(plain_text); i<n; i++)
     {

        int text_num=(int)plain_text[i];

        if (islower(plain_text[i]))
         {
            int lcipher=((text_num-97)+key)%26;
            int clowltr='a'+ lcipher;
            printf("%c",clowltr);
         }

        if (isalpha(plain_text[i]) == false)
        {
            printf("%c",plain_text[i]);
        }

         if (isupper(plain_text[i]))
         {
            int ucipher=((text_num-65)+key)%26;
            int cupltr='A'+ ucipher;
            printf("%c",cupltr);
         }

      };
 printf ("\n");


}
