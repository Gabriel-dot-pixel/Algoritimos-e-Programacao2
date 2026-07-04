#include <stdio.h>

void main()
{
    char texto[200], nomearq[30];

    FILE *arq; /// identificador para uma estrutura de manipulação
               /// de arquivos

    printf("Qual o nome do arquivo...: ");
    gets(nomearq);

    /// cria a estrutura de manipulação de arquivo associada
    /// ao arquivo para gravação, criando um novo arquivo
    arq = fopen(nomearq, "w");

    /// testando se o arquivo foi criado
    if (arq == NULL) /// não conseguiu criar o arquivo
    {
        printf("Nao foi possivel criar o arquivo\n");
    }
    else  /// conseguiu abrir o arquivo
    {
        printf("Digite o texto a salvar, deixe uma linha em branco para finalizar\n");
        do
        {
            gets(texto); /// leio o texto do teclado

            /// Salvo o texto no arquivo
            if (strlen(texto) != 0)
            {
                fputs(texto, arq);
                fputc('\n', arq);
            }
        }
        while (strlen(texto) != 0); /// verifica se linha está em branco

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(arq);
    }
}
