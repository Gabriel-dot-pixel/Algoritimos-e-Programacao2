/**
Faça um programa em linguagem C capaz de ler e analisar um arquivo texto, apresentando:
Quantidade de linhas; - x
Quantidade de espaços em branco; - x
Quantidade de letras e números. - x
Quantidade total de caracteres. - x
*/
#include <stdio.h>

void main()
{
    char carac;
    int linhas = 0, espaco = 0;
    int letra = 0, num = 0;
    int tot;

    FILE *arq;

    arq = fopen("teste.txt", "r");

    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else
    {
        carac = fgetc(arq);

        while(carac != EOF)
        {
            if(carac == '\n')
            {
                linhas++;
            }

            if(carac == ' ')
            {
                espaco++;
            }

            if(carac >= 'a' && carac <= 'z' || carac >= 'A' && carac <= 'Z')
            {
                letra++;
            }

            if(carac >= '0' && carac <= '9')
            {
                num++;
            }

            tot = espaco + letra + num;

            carac = fgetc(arq);
        }

        fclose(arq);

        printf("Quantidade de linhas...: %d\n", linhas);
        printf("Quantidade de espacos..: %d\n", espaco);
        printf("Quantidade de letras...: %d\n", letra);
        printf("Quantidade de numeros..: %d\n", num);
        printf("Quantidade de caracteres..: %d\n", tot);
    }
}
