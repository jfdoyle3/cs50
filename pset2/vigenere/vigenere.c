#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    int kyidx,key, text_num;
    if (argc !=2)
    {
        return 1;
    }
    string strkey=argv[1];
        for (int w=0, e=strlen(strkey); w<e; w++)
        {
        char si=strkey[w];
          if ((islower(si) || isupper(si))==false)
            {
                return 1;
             }
        }

   string plain_text=get_string("plaintext:  ");

    // key: ABC  Text: HELLO   CIPHER: HFNLP

    printf("ciphertext: ");

   kyidx=0;

    for (int i=0, n=strlen(plain_text); i<n; i++)
    {

        text_num=(int)plain_text[i];
        if(islower(strkey[kyidx])){
            key=(int) strkey[kyidx]-97;
        } else {
            key=(int) strkey[kyidx]-65;
        }

       if (islower(plain_text[i]))
     {
          int lcipher=((text_num-97)+(key))%26;
          int clowltr='a'+ lcipher;
      //  printf("----> %i\n",lcipher);
          printf("%c",clowltr);
            if (isalpha(strkey[kyidx+1])== false){
                kyidx=0;
            } else {
                kyidx++;
            }
      };

           if (isalpha(plain_text[i]) == false)
            {
                printf("%c",plain_text[i]);
            }

          if (isupper(plain_text[i]))
            {
            int ucipher=((text_num-65)+(key))%26;
            int cupltr='A'+ ucipher;
            printf("%c",cupltr);
              if (isalpha(strkey[kyidx+1])== false){
                kyidx=0;
            } else {
                kyidx++;
            }
         };

    };

 printf ("\n");

};