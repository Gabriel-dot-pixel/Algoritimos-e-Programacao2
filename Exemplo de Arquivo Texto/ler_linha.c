#include <stdio.h>

void main()
{
    char texto[200];

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
        /// Lê uma linha do arquivo arq
        fgets(texto, 199, arq);

        /// Fazer enquanto não for final de arquivo
        /// EOF - caracter que indica o final do arquivo
        while(!feof(arq))
        {
            printf("%s", texto);

            /// Lê a proxima linha do arquivo
            fgets(texto, 199, arq);
        }

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(arq);
    }
}
