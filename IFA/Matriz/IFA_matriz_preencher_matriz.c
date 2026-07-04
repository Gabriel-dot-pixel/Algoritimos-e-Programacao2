#include <stdio.h>

void main()
{
    int c, l; //controle dos laços

    int mat[4][4]; //matriz

    int linha_selecionada;

    int coluna_selecionada;

    srand(time(NULL));

    for(l=0; l<4; l++) //fazer a leitura de todas as linhas
    {
        for(c=0; c<4; c++) //fazer a leitura de todos os elementos de uma linha
        {
            mat[l][c] = rand() % 100 + 1; //gera um numero aleatorio entre 1 e 100
            printf("Mat[%d][%d] = %d\n", l, c, mat[l][c]);
        }
    }

    //apresentação total da matriz
    for(l=0; l<4; l++) //todas as colunas
    {
        for(c=0; c<4; c++) //todas as colunas
        {
            printf("\t%d", mat[l][c]);
        }
        printf("\n");
    }

    printf("Qual linha voce quer vizualizar? ");
    scanf("%d", &linha_selecionada);

    for(c=0; c<4; c++)
    {
        printf("\t%d", mat[linha_selecionada][c]);
    }

    printf("\nQual coluna voce quer vizualizar? ");
    scanf("%d", &coluna_selecionada);

    for(l=0; l<4; l++)
    {
        printf("\t%d\n", mat[l][coluna_selecionada]);
    }

    printf("\n\nMatriz parcial da matiz original\n");
    for(l=1; l<3; l++) //todas as linhas
    {
        for(c=1; c<3; c++) //todas as colunas
        {
            printf("\t%d", mat[l][c]);
        }
        printf("\n");
    }
}

