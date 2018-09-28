#include<stdio.h>

/*
zenit polar
*/

int main(){

    char frase[100];
    char* c;

    printf("digite uma frase:\n");
    scanf("%[^\n]", frase);

    c = frase;

    while(*c != '\0'){
      
      if(*c == 'z')
        *c = 'p';
      if(*c == 'e')
        *c = 'o';
      if(*c == 'n')
        *c = 'l';
      if(*c == 'i')
        *c = 'a';
      if(*c == 't')
        *c = 'r';
      c++;
    }
    
    printf("%s", frase);

    return 0;
}