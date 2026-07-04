#include <stdio.h>

void main()
{
    char caracter;
    char nomearq[30];
    int i, j;

    FILE *arq; /// identificador para uma estrutura de manipulação
               /// de arquivos

    printf("Digite o nome do arquivo a criar..: ");
    gets(nomearq);

    /// cria a estrutura de manipulação de arquivo associada
    /// ao arquivo teste.txt para gravação("w"),
    /// criando um novo arquivo no disco e atribui a arq
    arq = fopen(nomearq, "w");

    /// testando se foi possível criar o arquivo
    if (arq == NULL) /// não conseguiu criar
    {
        printf("Nao foi possivel criar o arquivo %s\n", nomearq);
    }
    else  /// conseguiu criar o arquivo
    {
        for(i=0;i<10;i++) /// linha
        {
            for(j=0;j<10;j++) /// coluna
            {
                fputc('*', arq);  /// gravando o * em arq
            }
            fputc('\n', arq);
        }

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(arq);

    }
}
