#include <stdio.h>
#include <cs50.h>

int main(void){
   int s;
   float c;
    do
    {
   c=get_float("Change Owed: ");
     s=0;
    }
     while(c<=0);

    c=c+.001;

   while(c>=.25){
      s=s+1;
      c=c-.25;
   }
  while(c>=.10){
      s=s+1;
      c=c-.10;
  }
  while(c>=.05){
      s=s+1;
      c=c-.05;
  }
  while (c>=.01){
      s=s+1;
      c=c-.01;
  }
    printf("%d\n",s);

}