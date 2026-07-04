#include <stdio.h>

void main()
{
    char caracter;
    int linhas = 0;

    FILE *arq; /// identificador para uma estrutura de manipulação
               /// de arquivos

    /// cria a estrutura de manipulação de arquivo associada
    /// ao arquivo teste.txt para leitura ("r") e atribui a arq
    arq = fopen("teste.txt", "r");

    /// testando se o arquivo existe e foi aberto
    if (arq == NULL) /// não conseguiu abrir o arquivo
    {
        printf("Nao foi possivel abrir o arquivo\n");
    }
    else  /// conseguiu abrir o arquivo
    {
        /// Lê um caracter do arquivo (primeiro)
        caracter = fgetc(arq);

        /// Fazer enquanto não for final de arquivo
        /// EOF - caracter que indica o final do arquivo
        while(caracter != EOF)
        {
            if (caracter == '\n') /// procurando salto de linha
            {
                linhas++;
            }

            /// Lê o próximo caracter do arquivo (primeiro)
            caracter = fgetc(arq);
        }

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(arq);

        printf("Quantidade de linhas...: %d\n", linhas);
    }
}
