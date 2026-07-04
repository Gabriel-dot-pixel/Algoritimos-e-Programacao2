#include <stdio.h>

void main()
{
    int col, lin; // controle dos laços

    int mat[4][4]; // matriz

    int linha_selecionada;
    int coluna_selecionada;

    srand(time(NULL));

    for(lin=0; lin<4; lin++) // faz a leitura de todas as linhas
    {
        for(col=0; col<4; col++) // fazer a leitura de todos os elementos de uma linha
        {
            mat[lin][col] = rand()%100+1; // gera um numero aleatorio entre 1 e 100
            printf("Mat[%d][%d] = %d \n", lin, col, mat[lin][col]);
        }
    }

    // apresentação total da matriz
    for(lin=0; lin<4; lin++) // todas as linhas
    {
        for(col=0; col<4; col++) // todas as colunas
        {
            printf("\t%d", mat[lin][col]); // apresenta um inteiro
        }
        printf("\n");
    }

    printf("Qual linha voce quer visualizar?: ");
    scanf("%d", &linha_selecionada);

    for(col=0; col<4; col++)
    {
        printf("\t%d", mat[linha_selecionada][col]);
    }

    printf("\n\nQual coluna voce quer visualizar?: ");
    scanf("%d", &coluna_selecionada);

    for(lin=0; lin<4; lin++)
    {
        printf("\n\t%d", mat[lin][coluna_selecionada]);
    }

    printf("\n\nApresentando uma matriz parcial\n");
    for(lin=1; lin<3; lin++) // todas as linhas
    {
        for(col=1; col<4; col++) // todas as colunas
        {
            printf("\t%d", mat[lin][col]); // apresenta um inteiro
        }
        printf("\n");
    }


}

