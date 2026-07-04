/**
Fazer dois programas em linguagem C, que permitam "criptografar" e descriptografar" um arquivo texto, para criptografar, somar 1 a cada um dos caracteres (ASCII) e
descriptografar subtrair um de cada um dos caracteres.
*/
#include <stdio.h>

void main()
{
    char carac;
    char nome_orig[100], nome_dest[100];

    FILE *origem, *destino;

    printf("Digite o nome do arquivo de origem...: ");
    gets(nome_orig);

    printf("Digite o nome do arquivo de destino..: ");
    gets(nome_dest);

    origem = fopen(nome_orig, "r");

    destino = fopen(nome_dest, "w");

    if(origem == NULL)
    {
        printf("Nao foi possivel abrir o arquivo %s\n", nome_orig);
    }
    else if(destino == NULL)
    {
        printf("Nao foi possivel abrir o arquivo %s\n", nome_dest);
    }
    else
    {
        carac = fgetc(origem);

        while(carac != EOF)
        {
            if(carac >= 'a' && carac <= 'z' || carac >= 'A' && carac <= 'Z')
            {
                carac = carac - 1;
                fputc(carac, destino);
            }

            carac = fgetc(origem);
        }

        fclose(origem);
        fclose(destino);
    }
}

