#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
    int count=0,espaco=0,especial=0;
    char email[70];

    setlocale(LC_ALL,"Portuguese");

    puts("Digite o e-mail:");
    gets(email);

    while(email[count] != '\0') //O '\0 significa o final ou seja quando ele encontrar esse caracter que representa o fim ele encerra'
    {
        switch (email[count])
        {
        case ' ': espaco++;break;
        case '.': ;
        case '-': especial++;
        break;
        
        default:;break;
        }
        count++;
    }
    printf("espaço -> %d\n especial-> %d ",espaco,especial);
}