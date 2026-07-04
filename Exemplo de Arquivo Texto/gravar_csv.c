#include <stdio.h>

void main()
{
    char nomearq[30];

    int i, quant_pessoas = 5;
    float media_salario = 2850.00;

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

        for(i=1;i<10;i++)
           fprintf(arq, "\"%s\", %d, %.2f\n", nomearq, quant_pessoas*i, media_salario/i);

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(arq);
    }
}
