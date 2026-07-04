#include <stdio.h>

void main()
{
    char caracter;
    char nomeorigem[30], nomedestino[30];
    int i, j;

    FILE *origem, *destino; /// dois identificadores para
               /// manipulação de arquivos

    printf("Digite o nome do arquivo origem..: ");
    gets(nomeorigem);

    printf("Digite o nome do arquivo destino.: ");
    gets(nomedestino);

    /// abre o arquivo origem para leitura
    origem = fopen(nomeorigem, "r");

    /// criando o arquivo de destino
    destino = fopen(nomedestino, "w");

    /// testando se foi possível criar o arquivo
    if (origem == NULL) /// não conseguiu criar
    {
        printf("Nao foi possivel abrir o arquivo %s\n", nomeorigem);
    }
    else if (destino == NULL) /// não conseguiu criar o arquivo
    {
        printf("Nao foi possivel criar o arquivo %s\n", nomedestino);
    }
    else   /// conseguiu abrir os dois arquivos
    {

        caracter = fgetc(origem); /// leio o caracter da origem
        while (caracter != EOF)
        {
            fputc(caracter, destino); /// gravo o caracter lido no destino
            caracter = fgetc(origem); /// leio o caracter da origem
        }

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(origem);
        fclose (destino);
    }
}
