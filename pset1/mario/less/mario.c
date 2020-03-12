#include <stdio.h>
#include <cs50.h>

int main(void) {
    int n;
    do
    {
     n=get_int("Height: ");

    }
    while(n<=0 || n>=23);

    n++;
    for (int i=2; i<=n; i++){


    for (int k=n; k>=i; k--){
       printf(" ");
    }

      for(int j=1; j<=i; j++){
        printf("#");

       }

        printf("\n");
    }

}