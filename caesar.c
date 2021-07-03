#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include  <ctype.h>
#include <stdlib.h>

int main(int argc,string argv[])
{


    int key ;
    string keyString;
if(argc==2){
     keyString= argv[1];
int keylen= strlen(keyString);

for (int i = 0 ; i < keylen; i++)
{
    char num = keyString[i];
 if(!isdigit(num)||atoi(keyString)<=0||argc!=2){
    printf("Usage : ./caesar key\n");
    return 1;
 }
}

}
key = atoi(keyString);
 string text=get_string("plaintext: ");

 const int lengt=strlen(text);
 for (int i =0; i<lengt ; i++)
 {
     if(isupper(text[i]))
     {
      int p=text[i]-'A';
    text[i]=((p+key)%26)+'A';

     }
     else if(islower(text[i]))
     {
  int p=text[i]-'a';
    text[i]=((p+key)%26)+'a';
     }


 }
  printf("ciphertext: %s\n",text);
  return 0;
}