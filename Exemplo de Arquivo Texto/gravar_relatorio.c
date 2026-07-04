#include <stdio.h>

void main()
{
    char nomearq[30];

    int quant_pessoas = 50;
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

        fprintf(arq, "Nome do arquivo....: %s\n", nomearq);
        fprintf(arq, "Quantidade de pessoas...: %d\n", quant_pessoas);
        fprintf(arq, "Media salarial....: %10.2f\n", media_salario);

        /// fecha o arquivo e quebra a ligação com o arquivo em disco
        fclose(arq);
    }
}
