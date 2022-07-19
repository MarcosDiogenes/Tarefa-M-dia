/*
Criado e Editado por Marcos Diógenes;

Referências:
https://stackoverflow.com/questions/38173177/how-to-pipe-output-to-another-program-in-c-using-read
https://pubs.opengroup.org/onlinepubs/009695399/functions/popen.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buf[4];
    FILE *fp;
    int i = 0;
    int valor;
    int soma = 0;
    int media;

    fp = popen("./a", "r");
    while( !feof(fp)) {
        fscanf(fp, "%s", buf);
        if(i <=2)
        {
            valor = atoi(buf);
            soma += valor;
            //printf("soma é: %d", soma);
            //printf("%s\n", buf);
        }
        i++;
    }
    pclose(fp);

    media = soma / 3;
    printf("%d", media);
    

    return 0;
}